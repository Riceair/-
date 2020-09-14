#include "SparseTrans.h"

SparseTrans::SparseTrans(int r, int c, int t) :SparseMatrix(r, c, t) {

}

void SparseTrans::newElement(int r, int c, int v) {
	smArray[capacity].row = r;
	smArray[capacity].col = c;
	smArray[capacity].value = v;
	capacity++;
}

void SparseTrans::showElement() {
	for (int i = 0; i < terms; i++)
		cout << "(" << smArray[i].row << "," << smArray[i].col << "," << smArray[i].value << ")" << endl;
}

void SparseTrans::resetCapacity() {
	capacity = 0;
}

void SparseTrans::ExecuteFor50000() {
	SparseTrans *transMatrix = new SparseTrans(cols, rows, terms);
	timeStart = clock();
	for (int a = 0; a < 50000; a++) {
		int newcapacity = 0;
		for (int i = 0; i < cols; i++) {
			for (int j = 0; j < terms; j++) {
				if (smArray[j].row == i) {
					transMatrix->newElement(smArray[j].col, smArray[j].row, smArray[j].value);
				}
			}
		}
		transMatrix->resetCapacity();
	}
	timeEnd = clock();
}

SparseMatrix *SparseTrans::Transpose() {
	int newcapacity = 0;
	fstream file;
	file.open("p2.out", ios::trunc);
	file.close();
	file.open("p2.out", ios::out);
	SparseTrans *transMatrix=new SparseTrans(cols, rows, terms);
	//start
	for (int i = 0; i < cols; i++) {
		for (int j = 0; j < terms; j++) {
			if (smArray[j].row == i) {
				transMatrix->newElement(smArray[j].col, smArray[j].row, smArray[j].value);
				file << "(" << smArray[j].row << "," << smArray[j].col << "," << smArray[j].value << ")" 
					<< " becomes " << "(" << transMatrix->smArray[newcapacity].row << "," << transMatrix->smArray[newcapacity].col 
					<< "," << transMatrix->smArray[newcapacity].value << ") in the transpose" << endl;
				newcapacity++;
			}
		}
	}
	file.close();
	ExecuteFor50000();
	return transMatrix;
}