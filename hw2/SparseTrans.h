#ifndef SPARSETRANS_H
#define SPARSETRANS_H
#include "SparseMatrix.h"

class SparseTrans:public SparseMatrix {
public:
	SparseTrans(int, int, int);
	virtual void newElement(int, int, int);
	virtual void showElement();
	virtual void ExecuteFor50000();
	virtual SparseMatrix* Transpose();
	void resetCapacity();
};
#endif