#include "SparseFast.h"

SparseFast::SparseFast(int r, int c, int t) :SparseMatrix(r, c, t) {
	RowSize = new int[c];
	RowStart = new int[c];
	for (int i = 0; i < c; i++) {
		RowSize[i] = 0;
		RowStart[i] = 0;
	}
}

void SparseFast::newElement(int r, int c, int v) {
	smArray[capacity].row = r;
	smArray[capacity].col = c;
	smArray[capacity].value = v;
	capacity++;
}

void SparseFast::showElement() {
	for (int i = 0; i < terms; i++)
		cout << "(" << smArray[i].row << "," << smArray[i].col << "," << smArray[i].value << ")" << endl;
}

void SparseFast::setForFastTransfer(int r,int c,int p,int v) {
	smArray[p].row = r;
	smArray[p].col = c;
	smArray[p].value = v;
}

void SparseFast::ExecuteFor50000() {
	SparseFast *transMatrix = new SparseFast(cols, rows, terms);
	timeStart = clock();
	for (int i = 0; i < 50000; i++) {
		for (int i = 0; i < cols; i++) {
			RowSize[i] = 0;
			RowStart[i] = 0;
		}
		for (int i = 0; i < terms; i++)
			RowSize[smArray[i].col]++;
		int setRowStart = 0;
		for (int i = 0; i < cols; i++) {
			RowStart[i] = setRowStart;
			setRowStart += RowSize[i];
		}
		for (int i = 0; i < terms; i++) {
			transMatrix->setForFastTransfer(smArray[i].col, smArray[i].row, RowStart[smArray[i].col], smArray[i].value);
			RowStart[smArray[i].col]++;
		}
	}
	timeEnd = clock();
}

SparseMatrix *SparseFast::Transpose() {
	fstream file;
	file.open("p2.out", ios::trunc);
	file.close();
	file.open("p2.out", ios::out);
	SparseFast *transMatrix = new SparseFast(cols, rows, terms);
	//start

	for (int i = 0; i < terms; i++)
		RowSize[smArray[i].col]++;
	int setRowStart = 0;
	for (int i = 0; i < cols; i++) {
		RowStart[i] = setRowStart;
		setRowStart += RowSize[i];
	}
	for (int i = 0; i < terms; i++) {
		transMatrix->setForFastTransfer(smArray[i].col,smArray[i].row,RowStart[smArray[i].col],smArray[i].value);
		file << "(" << smArray[i].row << "," << smArray[i].col << "," << smArray[i].value << ")" << " becomes " 
			<< "(" << transMatrix->smArray[RowStart[smArray[i].col]].row << "," << transMatrix->smArray[RowStart[smArray[i].col]].col 
			<< "," << transMatrix->smArray[RowStart[smArray[i].col]].value << ") in the transpose" << endl;
		RowStart[smArray[i].col]++;
	}
	file.close();
	ExecuteFor50000();
	return transMatrix;
}