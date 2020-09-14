#ifndef SPARSEFAST_H
#define SPARSEFAST_H
#include "SparseMatrix.h"

class SparseFast:public SparseMatrix {
public:
	SparseFast(int, int, int);
	virtual void newElement(int, int, int);
	virtual void showElement();
	virtual void ExecuteFor50000();
	void setForFastTransfer(int,int,int,int);
	virtual SparseMatrix* Transpose();
private:
	int *RowSize, *RowStart;
};
#endif