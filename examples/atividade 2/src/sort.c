/*
 * Rafael Basso
 * Tiago Gambim
 */
#include "sort.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int cmpfunc (const void * a, const void * b) {
	if(*(int*)a > *(int*)b)
		return 1;
	if(*(int*)a < *(int*)b)
		return -1;
	else 
		return 0;
}

void sort(int *v, int size){
	qsort(v, size, sizeof(int), cmpfunc);
}


