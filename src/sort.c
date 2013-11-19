#include "sort.h"

int partition( float* a, int l, int r);



/*
 * quick sort
 */

void sort( float *a , int l , int r){

	int j;

	if( l < r ) {
		j = partition( a, l, r);
    	sort( a, l, j-1);
    	sort( a, j+1, r);
    }

} 


int partition( float *a, int l, int r) {

	int pivot, i, j, t;
   	pivot = a[l];
   	i = l; j = r+1;
		
   	while(1){
   	
   		do ++i; while( a[i] <= pivot && i <= r );
   		do --j; while( a[j] > pivot );
   		if( i >= j ) break;
   		t = a[i]; a[i] = a[j]; a[j] = t;
   	}
   	
   	t = a[l]; a[l] = a[j]; a[j] = t;
   	return j;
}