#include "SparseMatrix.h"
#include "SparseTrans.h"
#include "SparseFast.h"
#include "TraditionalMatrix.h"
#include <sstream>
#include <string>

int main() {
	fstream file;
	file.open("p2.in", ios::in);
	if (!file)
		cout << "開檔失敗" << endl;
	else {
		int RowTotal,ColTotal;  //儲存row以及column
		string inputString;  //使用getline讀檔，並用sstream存入
		stringstream sst;
		getline(file, inputString);
		sst << inputString;
		sst >> RowTotal >> ColTotal;

		int *stArray = new int[3*RowTotal*ColTotal];
		int term = 0;  //非零元素個數
		int row, column, value;
		while (getline(file, inputString)) {  //用stArray儲存p2.in裡的input
			sst.clear();
			sst << inputString;
			sst >> row >> column >> value;
			stArray[0 + term * 3] = row;
			stArray[1 + term * 3] = column;
			stArray[2 + term * 3] = value;
			term++;
		}
		file.close();

		TraditionalMatrix sparseT(RowTotal,ColTotal,term);
		for (int i = 0; i < term; i++) {
			sparseT.newElement(stArray[0 + i * 3], stArray[1 + i * 3], stArray[2 + i * 3]);
		}
		sparseT.showElement();
		cout << endl;
		SparseMatrix *newTMatrix=sparseT.Transpose();
		newTMatrix->showElement();
		cout << endl;


		SparseTrans sparse(RowTotal, ColTotal, term);
		for (int i = 0; i < term; i++) {
			sparse.newElement(stArray[0 + i * 3], stArray[1 + i * 3], stArray[2 + i * 3]);
		}
		sparse.showElement();
		cout << endl;
		SparseMatrix *newTS = sparse.Transpose();
		newTS->showElement();
		cout << endl;

		SparseFast sparseF(RowTotal, ColTotal, term);
		for (int i = 0; i < term; i++) {
			sparseF.newElement(stArray[0 + i * 3], stArray[1 + i * 3], stArray[2 + i * 3]);
		}
		sparseF.showElement();
		cout << endl;
		SparseMatrix *newFS = sparseF.Transpose();
		newFS->showElement();
		cout << endl;

		cout << "三種方法轉移50000次後執行時間 :" << endl;
		file.open("p2.out", ios::app);
		cout << "Traditional transpose :" << endl;
		cout << sparseT.getExecuteTime() << endl;
		cout << "Sparse transpose :" << endl;
		cout << sparse.getExecuteTime() << endl;
		cout << "Sparse transpose for fast case :" << endl;
		cout << sparseF.getExecuteTime() << endl;
		file << sparseT.getExecuteTime() << endl;
		file << sparse.getExecuteTime() << endl;
		file << sparseF.getExecuteTime() << endl;
		file.close();
	}
	system("pause");
	return 0;
}