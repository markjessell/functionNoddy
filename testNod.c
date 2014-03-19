#include <stdio.h>
#include <stdlib.h>
#include "noddy.h"

#define DEBUG(X)	X
#define NUM_RUNS    20


extern int noddy (DATA_INPUT, DATA_OUTPUT, int, char *, char *,
                  BLOCK_VIEW_OPTIONS *, GEOPHYSICS_OPTIONS *);


int main (int argc, char *argv[])
{
   double x,y,z;
   int rock1,rock2,breakcode,eventcode;

   if (argc < 2)
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



   /*for(x=0;x<=10000;x+=250)
	   for(y=0;y<=7000;y+=250)
		   for(z=5000;z>=2000;z-=250)
		   {
			   whatDiff(x, y, z, x+250, y, z,&breakcode,&eventcode,&rock1,&rock2);
			   printf("%lf\t%lf\t%lf\t%d\t%d\t%d\t%d\n",x, y, z,breakcode,eventcode,rock1,rock2);
		   }
	*/

   return (TRUE);
}


