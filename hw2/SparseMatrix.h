#ifndef MATRIX_H
#define MATRIX_H
#include "MatrixTerm.h"
#include <iostream>
#include <fstream>
#include <time.h>
using namespace std;

class SparseMatrix {
public:
	SparseMatrix(int, int, int);
	double getExecuteTime();
	virtual void ExecuteFor50000() = 0;
	virtual void showElement() = 0;
	virtual SparseMatrix* Transpose() = 0;
protected:
	int rows, cols, terms, capacity;
	double timeStart, timeEnd;
	MatrixTerm *smArray;
};
#endif