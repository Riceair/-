#ifndef MATRIXTERM_H
#define MATRIXTERM_H
class MatrixTerm{
	friend class SparseMatrix;
	friend class SparseTrans;
	friend class SparseFast;
private:
	int row, col, value;
};
#endif