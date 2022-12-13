#include "gauss.h"
// pierwsza zmiana
/**
 * Zwraca 0 - elimnacja zakonczona sukcesem
 * Zwraca 1 - macierz osobliwa - dzielenie przez 0
 */
int eliminate(Matrix *mat, Matrix *b){
    		int row = mat->r;
		int i;
		int j;
		int z;
		double m;
		for (i=0; i<row-1; i++){
			for(j=i+1; j<row; j++){
				if(mat->data[i][i]==0)
					return 1;
				m=mat->data[j][i]/mat->data[i][i];
				for(z=i; z<row; z++)
					mat->data[j][z]-=m*mat->data[i][z];
				b->data[j][0]-=m * b->data[i][0];
			}
		}
		return 0;
}

