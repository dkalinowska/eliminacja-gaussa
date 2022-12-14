#include "backsubst.h"

/* 
 * Zwraca 0 - wsteczne podstawienie zakonczone sukcesem
 * Zwraca 1 - błąd dzielenia przez 0 (element na diagonali = 0)
 * Zwraca 2 - błąd nieprawidłowych rozmiarów macierzy
 * 
 * */

int backsubst( Matrix *x, Matrix *mat, Matrix *b ) 
{
	/* sprawdzenie wymiarów macierzy */

	if (mat -> r != mat -> c || mat -> r != b -> r) 
		return 2;

	double **A = mat->data;
	double **B = b->data;
	double **X = x->data;
	int w;

	for( w = mat -> r - 1; w >= 0; w-- )
	{
        	double s = 0;
        	for(int k = w + 1; k < mat -> r; k++)
		{
            		s += A[w][k] * X[k][0];
        	}

		/* jeśli element na przekątnej jest zerowy */
        	if (A[w][w] == 0)
        		return 1;

        	X[w][0] = ((B[w][0] - s) / A[w][w]);
    	}			
	return 0;
}
