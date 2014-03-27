#include <stdio.h>
#include <stdlib.h>
#include "noddy.h"

#define DEBUG(X)	X
#define NUM_RUNS    20


extern int noddy (DATA_INPUT, DATA_OUTPUT, int, char *, char *,
                  BLOCK_VIEW_OPTIONS *, GEOPHYSICS_OPTIONS *);
void whereRock( double *xLoc, double *yLoc, double *zLoc, int *rockType, int *index);


int main (int argc, char *argv[])
{
   double x,y,z,x2,y2,z2;
   int rockType,index;

   if (argc < 3)
   {
      printf ("Arguments <historyfile> <outputfile>\n");
      return (-1);
   }

   if (!noddy(INPUT_FILE_HISTORY, OUTPUT_FILE_IMAGE,
              //CALC_MAGNETICS_IMAGE | CALC_GRAVITY_IMAGE | BLOCK_MODEL, //mwj_hack
               BLOCK_MODEL, //mwj_hack
              (char *) argv[1], (char *) argv[2],
              (BLOCK_VIEW_OPTIONS *) NULL, (GEOPHYSICS_OPTIONS *) NULL))
   {
      printf ("\nNoddy Failed.\nSorry.\n");
   }



  /*
   * example code for exporting pre-deformation locations of a volume of points
   * for(z=5000;z>=2000;z-=250)
	   for(y=0;y<=7000;y+=250)
		   for(x=0;x<=10000;x+=250)
		   {
			   x2=x;
			   y2=y;
			   z2=z;
			   whereRock(&x2, &y2, &z2,&rockType,&index);
			   printf("%lf\t%lf\t%lf\t%lf\t%lf\t%lf\t%d\t%d\t%d\t%d\n",x,y,z,x2, y2, z2,rockType,index);
		   }
      */

   return (TRUE);
}


