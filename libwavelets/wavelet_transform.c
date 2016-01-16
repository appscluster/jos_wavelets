#include "bio.h"
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


int wavelet_transform3D(FLOAT *inspacevector,
		       int xlength,
		       int ylength,
		       int zlength,
		       int Filterlength, /* 1,3,5,7 or 9 */
		       int levels,
			FLOAT *waveletcoefficients
			      			){
int co_length;
			
return wavelet_decompose3(inspacevector,
			   xlength,
			   ylength,
			   zlength,
	 		  (char)Filterlength,
			   (char)levels,
			   (char)0, /*char Skip */
			   waveletcoefficients,
			   &co_length, 
			   0 /* char ifnotSilent: 1 for printing */
			   );
}						



int invwavelet_transform3D(FLOAT * waveletcoefficients,
                         int xlength,
			 int ylength,
                         int zlength,
			   int Filterlength, /* 1,3,5,7 or 9 */
			   int levels,  
			   FLOAT  *outvector){

return  wavelet_reconstruct3(waveletcoefficients,
			     xlength*ylength*zlength,/*coeffcient_length*/
                             outvector,
			     xlength,
			     ylength,
			     zlength, 
			    (char) Filterlength,
			     (char)levels,
			     (char)0,  /* Skip: general skiplevel
				    (changes coeff_length)*/ 
			     0 /*ifnotSilent  set 1 for printing */
			     );
}
 


int wavelet_transform2D(FLOAT *inspacevector,
		       int xlength,
		       int ylength,
		       int Filterlength, /* 1,3,5,7 or 9 */
		       int levels,		       
		       FLOAT *waveletcoefficients
			      			){
int co_length;
			
return wavelet_decompose3(inspacevector,
			   xlength,
			   ylength,
			   1,/*zlength,*/
			  (char)Filterlength,
			   (char)levels,
			   (char)0, /*char Skip */
			   waveletcoefficients,
			   &co_length, 
			   0 /* char ifnotSilent: 1 for printing */
			   );
}						



int invwavelet_transform2D(FLOAT * waveletcoefficients,
                         int xlength,
			 int ylength,
		       int Filterlength, /* 1,3,5,7 or 9 */
		       int levels,		       
			 FLOAT  *outvector){

return  wavelet_reconstruct3(waveletcoefficients,
			     xlength*ylength,/*coeffcient_length*/
                             outvector,
			     xlength,
			     ylength,
			     1, /* zlength*/ 
			  (char)Filterlength,
			     (char)levels,
			     (char)0,  /* Skip: general skiplevel
				    (changes coeff_length)*/ 
			     0 /*ifnotSilent  set 1 for printing */
			     );
}
 




int wavelet_transform1D(FLOAT *inspacevector,
		       int xlength,
		       int Filterlength, /* 1,3,5,7 or 9 */
		       int levels,		       
			FLOAT *waveletcoefficients
			      			){
int co_length;
			
return wavelet_decompose3(inspacevector,
			   xlength,
			  1,/*ylength*/
			   1,/*zlength,*/
			  (char)Filterlength,
			  (char)levels,
			   (char)0, /*char Skip */
			   waveletcoefficients,
			   &co_length, 
			   0 /* char ifnotSilent: 1 for printing */
			   );
}						


int invwavelet_transform1D(FLOAT * waveletcoefficients,
                         int xlength,
		       int Filterlength, /* 1,3,5,7 or 9 */
		       int levels,		       
			  FLOAT  *outvector){

return  wavelet_reconstruct3(waveletcoefficients,
			     xlength,/*coeffcient_length*/
                             outvector,
			     xlength,
			     1, /*ylength*/
			     1, /* zlength*/ 
			  (char)   Filterlength,
			     (char)levels,
			     (char)0,  /* Skip: general skiplevel
				    (changes coeff_length)*/ 
			     0 /*ifnotSilent  set 1 for printing */
			     );
}
 
