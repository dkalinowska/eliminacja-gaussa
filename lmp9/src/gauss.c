#include <math.h>
#include "gauss.h"

int eliminate (Matrix *mac, Matrix *b, Matrix *x)
{
	int n = mac->r;
	int k, w, i;
	double m;
	double *temp;
	double *tymb; /*zmienna tymczasowa dla b*/

	for (k=0; k<n-1; k++)
	{
		int kmax;

		for (w = k+1; w < n; w++)
		{
			if ( fabs(mac->data[w][k]) > fabs(mac->data[kmax][k]) )
				kmax = w;

			if( kmax != k )
			{
				temp = mac->data[k];
				mac->data[k] = mac->data[kmax];
				mac->data[kmax] = temp;

				tymb = b->data[k];
				b->data[k] = b->data[kmax];
				b->data[kmax] = tymb;		
			}
		}
		for (w = k+1; w < n; w++)
		{
			if(mac->data[k][k] == 0)
				return 1;
			m = mac->data[w][k] / mac->data[k][k];
			for (i = k; i < n; i++)
				mac->data[w][i] -= m * mac->data[k][i];
			b->data[w][0] -= m*b->data[k][0];
			
		}
	}

	return 0;
}

