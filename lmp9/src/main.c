#include "gauss.h"
#include "backsubst.h"
#include "mat_io.h"
#include <stdlib.h>
#include <stdio.h>


int main(int argc, char ** argv) {
	
	Matrix * A = readFromFile(argv[1]);
	Matrix * b = readFromFile(argv[2]);
	Matrix * x = NULL;

	if (A == NULL) return -1;
	if (b == NULL) return -2;
	printToScreen(A);
	printToScreen(b);

	
	if( eliminate(A,b) == 0)
	{
		x = createMatrix(b->r, 1);
		if (x != NULL) 
		{
			backsubst(x, A, b);
			printToScreen(x);
	  		freeMatrix(x);
		} 
		else 
		{
			fprintf(stderr,"Błąd! Nie mogłem utworzyć wektora wynikowego x.\n");
		}
	}
	else fprintf(stderr, "Nie udało się wykonać eliminacji\n");

	freeMatrix(A);
	freeMatrix(b);

	return 0;
}
