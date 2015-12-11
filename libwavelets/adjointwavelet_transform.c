#include "bio.h"
#define HIGH_PRECISION 1
#ifndef HIGH_PRECISION
#define FLOAT float
#else
#define FLOAT double
#endif
//#include "../include/wavelet_transform.h"



/* NOTE that  MaxZLevels and MaxXYLevels should be at least as
Levels   in the parameterchoice, this means they have no effect,
and the only the 3d filters will be used.
the 2d and 2dy filters are not updated yet with the adjoint filters  */


int adjointinvwavelet_transform3D(FLOAT *inspacevector,
		       int xlength,
		       int ylength,
		       int zlength,
     		       FLOAT *waveletcoefficients
			      			){
int co_length;
 /*
  printf("\ninspacevector5:\n");
  
  for(v=0;v<xlength*ylength*zlength;v++)printf(" %f ",inspacevector[v]);
 */

			
return wavelet_invadjoint3(inspacevector,
			   xlength,
			   ylength,
			   zlength,
			   9, /* char Filterlength */
			   10, /* char Levels */
			   0,  /* char minZLevels */ 
			   10, /* char MaxZLevels */ 
			   0,  /* char minXYLevels */ 
			   10,  /*char MaxXYLevels */
			   0, /*char Skip */
			   waveletcoefficients,
			   &co_length, 
			   0 /* char ifnotSilent: 1 for printing */
			   );
}						



int adjointwavelet_transform3D(FLOAT * waveletcoefficients,
                         int xlength,
			 int ylength,
                         int zlength,
                         FLOAT  *outvector){

return  wavelet_adjoint3(waveletcoefficients,
			     xlength*ylength*zlength,/*coeffcient_length*/
                             outvector,
			     xlength,
			     ylength,
			     zlength, 
			     9, /*Filterlength*/
			     10, /*Levels of transforms*/
			     0,  /* min ZLevel (changes coeff_length) */
			     10, /* maxZLevels */ 
			      0, /* minXYLevels (changes coeff_length)*/ 
			     10, /* maxXYLevels */ 
			     0,  /* Skip: general skiplevel
				    (changes coeff_length)*/ 
			     0 /*ifnotSilent  set 1 for printing */
			     );
}
 


int adjointinvwavelet_transform2D(FLOAT *inspacevector,
		       int xlength,
		       int ylength,
		       FLOAT *waveletcoefficients
			      			){
int co_length;
			
return wavelet_invadjoint3(inspacevector,
			   xlength,
			   ylength,
			   1,/*zlength,*/
			   9, /* char Filterlength */
			   10, /* char Levels */
			   0,  /* char minZLevels */ 
			   0, /* char MaxZLevels */ 
			   0,  /* char minXYLevels */ 
			   10,  /*char MaxXYLevels */
			   0, /*char Skip */
			   waveletcoefficients,
			   &co_length, 
			   0 /* char ifnotSilent: 1 for printing */
			   );
}						



int adjointwavelet_transform2D(FLOAT * waveletcoefficients,
                         int xlength,
			 int ylength,
			 FLOAT  *outvector){

return  wavelet_adjoint3(waveletcoefficients,
			     xlength*ylength,/*coeffcient_length*/
                             outvector,
			     xlength,
			     ylength,
			     1, /* zlength*/ 
			     9, /*Filterlength*/
			     10, /*Levels of transforms*/
			     0,  /* min ZLevel (changes coeff_length) */
			     0, /* maxZLevels */ 
			      0, /* minXYLevels (changes coeff_length)*/ 
			     10, /* maxXYLevels */ 
			     0,  /* Skip: general skiplevel
				    (changes coeff_length)*/ 
			     0 /*ifnotSilent  set 1 for printing */
			     );
}
 




int adjointinvwavelet_transform1D(FLOAT *inspacevector,
		       int xlength,
			FLOAT *waveletcoefficients
			      			){
int co_length;
			
return wavelet_invadjoint3(inspacevector,
			   xlength,
			  1,/*ylength*/
			   1,/*zlength,*/
			   9, /* char Filterlength */
			   10, /* char Levels */
			   0,  /* char minZLevels */ 
			   0, /* char MaxZLevels */ 
			   0,  /* char minXYLevels */ 
			   10,  /*char MaxXYLevels */
			   0, /*char Skip */
			   waveletcoefficients,
			   &co_length, 
			   0 /* char ifnotSilent: 1 for printing */
			   );
}						


int adjointwavelet_transform1D(FLOAT * waveletcoefficients,
                         int xlength,
			  FLOAT  *outvector){

return  wavelet_adjoint3(waveletcoefficients,
			     xlength,/*coeffcient_length*/
                             outvector,
			     xlength,
			     1, /*ylength*/
			     1, /* zlength*/ 
			     9, /*Filterlength*/
			     10, /*Levels of transforms*/
			     0,  /* min ZLevel (changes coeff_length) */
			     0, /* maxZLevels */ 
			      0, /* minXYLevels (changes coeff_length)*/ 
			     10, /* maxXYLevels */ 
			     0,  /* Skip: general skiplevel
				    (changes coeff_length)*/ 
			     0 /*ifnotSilent  set 1 for printing */
			     );
}
 