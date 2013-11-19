/*
 * main.m
 */

#include <stdlib.h>

#include "cell_diff.h"

 /*
  * w has size elements
  * n has size+1 elements
  */

float** cell_diff_main(int a , int b , float* w , float *n , int size ,  int center ,  int times , float maxt , float dt ){

	float* h;
	float g = 0.5f;

	int i;

	h = (float*) malloc(sizeof(float) * (size + 1) );
	if( !h )
		return NULL;

	h[0] = ( (w[0]-a) / n[0] );
	for( i = 1 ; i < size ; i++)
		h[i] = ( (w[i]-w[i-1])/n[i] );

	h[size+1] = ( (b-w[size]) / n[size+1] );

	/* call disk_maka0*/




	free(h);
	return NULL;
}