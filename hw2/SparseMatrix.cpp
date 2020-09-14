#include "SparseMatrix.h"

SparseMatrix::SparseMatrix(int r, int c, int t):rows(r),cols(c),terms(t) {
	smArray = new MatrixTerm[terms];
	capacity = 0;
}

double SparseMatrix::getExecuteTime() {
	return (timeEnd - timeStart)/CLOCKS_PER_SEC;
}