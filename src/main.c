#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <math.h>

#include "sort.h"
#include "cell_diff.h"

#define RANDOM_MIN 2
#define RANDOM_MAX 5


#define SI_METHOD    1
#define EULER_METHOD 2
#define CRANK_METHOD 3

#define MAXGRID 6


float random_float_between(float a , float b);

int main ( int argc , char* argv[]){

	int method;

	float width = 0.8f;
	float dt;
	float center;
	float ddt;
	int ab_1 = -5;
	int ab_2 = 5;
	int i;
	int mm;

	int flag = 0;
	int flagmin;

	int times = 1;				// grid counter

	float *w;
	float *l;

	float** y;

	srand((int)time(NULL));


	/* default 'y' code */
	mm     = RANDOM_MIN + rand() % ( RANDOM_MAX - RANDOM_MIN );
	dt     = 2 + random_float_between( 0.0 , 1.0 );
	center = -4 + 3 * random_float_between( 0.0 , 1.0 ) ;

	w = (float*) malloc( sizeof(float) * mm );
	if( !w ){
		printf("Out of memory..\n");
		return -1;
	}


	for( i  = 0 ; i < mm ; i++)
		w[i] = ab_1 + ( ab_2 - ab_1 ) * random_float_between( 0.0 , 1.0 );
	
	sort(w , 0 , mm - 1 );


	/*
	 * Setting the local variables of the problem
	 */

	int m = mm;

	l = (float*) malloc( sizeof( float ) * ( m + 1) );
	if( !l ){
		printf("Out of memory..\n");
		return -1;
	}

	l[0] = w[0] - ab_1;
	for( i = 1 ; i < m ; i++)
		l[i] = w[i] - w[i-1];

	l[m] = ab_2 - w[m-1];

	if( dt > 4 || dt < 0 )
		dt = 4;


	method = SI_METHOD;
	float LL,h;
	float NN;
	float *N;


	LL = ab_2 - ab_1;
	h  = 1 / (float) 8;
	NN = ceilf(LL/h);
	
	N = (float*) malloc(sizeof(float) * (m+1));
	if( !N ){
		printf("Out of memory...\n" );
		return -1;
	}

	for( i = 0 ; i < (m+1) ; i++)
		N[i] = ceilf( (NN * l[i]) /LL );


	ddt = 0.5f;								//time step

	if( method == SI_METHOD ){
		/* call matlab 'main' */
		y = cell_diff_main(ab_1 , ab_2 , w , N , mm , center , times , dt , ddt);
		if( !y ){
			printf("Cell diff main failed\n");
			exit(1);
		}

	}
	else if( method == EULER_METHOD ){

		/* call gen_disc_coll_ab */
	}
	else if( method == CRANK_METHOD ){

		/* call gen_disc_crank_ab */

	}
	else {
		printf("No method specified\n");
		return -1;
	}





	free(l);
	free(w);
	free(N);

	return 0;
}


float random_float_between(float a, float b) {
    float random = ((float) rand()) / (float) RAND_MAX;
    float diff = b - a;
    float r = random * diff;
    return a + r;
}