#include "TraditionalMatrix.h"

TraditionalMatrix::TraditionalMatrix(int r, int c, int t) :SparseMatrix(r, c, t) {
	matrix = new int*[r];
	for (int i = 0; i < r; i++)
		matrix[i] = new int[c];
	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++)
			matrix[i][j] = 0;
	}
}

void TraditionalMatrix::newElement(int r, int c, int v) {
	matrix[r][c] = v;
}

void TraditionalMatrix::showElement() {
	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < cols; j++) {
			cout << matrix[i][j] << " ";
		}
		cout << endl;
	}
}

void TraditionalMatrix::ExecuteFor50000() {
	TraditionalMatrix *transMatrix = new TraditionalMatrix(cols, rows, terms);
	timeStart = clock();
	for (int a = 0; a < 50000; a++) {
		for (int i = 0; i < rows; i++) {
			for (int j = 0; j < cols; j++) {
				transMatrix->newElement(j, i, matrix[i][j]);
			}
		}
	}
	timeEnd = clock();
}

SparseMatrix* TraditionalMatrix::Transpose() {
	fstream file;
	file.open("p2.out", ios::trunc);
	file.close();
	file.open("p2.out", ios::out);
	TraditionalMatrix *transMatrix = new TraditionalMatrix(cols, rows, terms);
	//start
	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < cols; j++) {
			transMatrix->newElement(j, i, matrix[i][j]);
			file << "(" << i << "," << j << "," << matrix[i][j] << ")" << " becomes " 
				<< "(" << j << "," << i << "," << transMatrix->matrix[j][i] << ") in the transpose" << endl;
		}
	}
	file.close();
	ExecuteFor50000();
	return transMatrix;
}