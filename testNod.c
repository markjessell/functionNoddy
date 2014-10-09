#include <stdio.h>
#include <stdlib.h>
#include "noddy.h"

#define DEBUG(X)	X
#define NUM_RUNS    20


extern int noddy (DATA_INPUT, DATA_OUTPUT, int, char *, char *,
                  BLOCK_VIEW_OPTIONS *, GEOPHYSICS_OPTIONS *);


int main (int argc, char *argv[])
{

   char calc_model[100];
   int mode=0;
   double x,y,z,x2,y2,z2;
   int rockType,index;
   int restauration = 0;/* GL: restauration mode, outputs original position*/

	char exportname[250];

   if (argc < 4)
   {
      printf ("Arguments <historyfile> <outputfile> <calc_mode>:\nBLOCK\nGEOPHYSICS\nSURFACES\nBLOCK_GEOPHYS\nBLOCK_SURFACES\nRESTORATION\nALL\n");
      return (-1);
   }


   if(!strcmp(argv[3],"BLOCK"))
	   mode=1;
   else if(!strcmp(argv[3],"GEOPHYSICS"))
	   mode=2;
   else if(!strcmp(argv[3],"SURFACES"))
	   mode=8;
   else if(!strcmp(argv[3],"BLOCK_GEOPHYS"))
	   mode=16;
   else if(!strcmp(argv[3],"ALL"))
	   mode=32;
   else if(!strcmp(argv[3],"BLOCK_SURFACES"))
	   mode=64;   /*GL:file for exporting initial locations*/
   else if(!strcmp(argv[3],"RESTORATION")){
	    mode=1;
		restauration=1;
		sprintf((char *) exportname,"%s.csv",argv[2]);
   }   else
   {
	   printf("Calculation mode %s not recognised\n", argv[3]);
	   return(-1);
   }

   if (!noddy(INPUT_FILE_HISTORY, OUTPUT_FILE_IMAGE,
              //CALC_MAGNETICS_IMAGE | CALC_GRAVITY_IMAGE | BLOCK_MODEL, //mwj_hack
               mode, //mwj_hack
              (char *) argv[1], (char *) argv[2],
              (BLOCK_VIEW_OPTIONS *) NULL, (GEOPHYSICS_OPTIONS *) NULL))
   {
      printf ("\nNoddy Failed.\nSorry.\n");
	return (FALSE);
   }

   /*GL: exporting initial locations */
   if(restauration){
	FILE * pFile=NULL;

	/* dimension of the grid*/
	BLOCK_VIEW_OPTIONS *viewOptions = NULL;

	/* opening the file*/
	pFile = fopen(exportname,"w");
	if( pFile == NULL ){
		printf("Error while opening the output file: %s\n",exportname);
		return (FALSE);
	}
	printf("\nWriting to file: %s\n",exportname);

	viewOptions = getViewOptions();
	if( viewOptions == NULL ){
		printf("Error while getting the dimensions.\n");
		return (FALSE);
	}
	printf("Writing grid dimensions...\n");
	printf("%lf\t%lf\t%lf\n",viewOptions->originX,viewOptions->originY,(viewOptions->originZ - viewOptions->lengthZ));
	printf("%lf\t%lf\t%lf\n",viewOptions->lengthX,viewOptions->lengthY,viewOptions->lengthZ);
	printf("%lf\t%lf\t%lf\n",viewOptions->geologyCubeSize,viewOptions->geologyCubeSize,viewOptions->geologyCubeSize);
	fprintf(pFile,"%lf\t%lf\t%lf\n",viewOptions->originX,viewOptions->originY,(viewOptions->originZ - viewOptions->lengthZ));
	fprintf(pFile,"%lf\t%lf\t%lf\n",viewOptions->lengthX,viewOptions->lengthY,viewOptions->lengthZ);
	fprintf(pFile,"%lf\t%lf\t%lf\n",viewOptions->geologyCubeSize,viewOptions->geologyCubeSize,viewOptions->geologyCubeSize);
	printf("Writing grid dimensions... Done.\n");

	printf("Writing original coordinates...\n");
	for(z = viewOptions->originZ + viewOptions->lengthZ; z>= viewOptions->originZ; z-= viewOptions->geologyCubeSize ){
	    for(y=viewOptions->originY; y<= viewOptions->originY + viewOptions->lengthY; y+= viewOptions->geologyCubeSize ){
		    for(x=viewOptions->originX; x<= viewOptions->originX + viewOptions->lengthX; x+= viewOptions->geologyCubeSize ){
			   x2=x;y2=y;z2=z;
			   whereRock(&x2, &y2, &z2,&rockType,&index);
			   fprintf(pFile,"%d\t%d\t%lf\t%lf\t%lf\n",index,rockType,x2,y2,z2);
		    }
	    }      
    }
	printf("Writing original coordinates... Done.\n");
	
	fclose(pFile);
    }

   return (TRUE);
}


