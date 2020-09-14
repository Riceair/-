#ifndef TRADITIONALMATRIX_H
#define TRADITIONALMATRIX_H
#include "SparseMatrix.h"
class TraditionalMatrix :public SparseMatrix {
public:
	TraditionalMatrix(int, int, int);
	virtual void newElement(int, int, int);
	virtual void showElement();
	virtual void ExecuteFor50000();
	virtual SparseMatrix* Transpose();
private:
	int **matrix;
};
#endif