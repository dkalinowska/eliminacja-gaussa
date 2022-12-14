#include "mat_io.h"
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// return 1 -> nie da się uniknąć dzielenia przez 0
// return 0 -> działa poprawnie
// eliminacja weroniki

int eliminacja (Matrix *mac, Matrix *b, Matrix *x);
