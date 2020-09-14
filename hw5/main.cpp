#include "Huffman.h"
#include <sstream>
#include <fstream>

int main() {
	ifstream file("p5.in");
	string str;
	stringstream sst;
	int nofData = 0;  //number of data
	while (getline(file, str))
		nofData++;
	file.close();

	nofData -= 2;
	char *myData = new char[nofData];
	double *dataRepTimes = new double[nofData];

	file.open("p5.in");
	for (int i = 0; i < nofData; i++) {  //將字和出現次數寫入
		file >> myData[i];
		file >> dataRepTimes[i];
	}
	file.close();
	file.open("p5.in");
	while (getline(file, str)) {  //將最後一行寫入

	}
	file.close();

	Huffman myHuffman(dataRepTimes, nofData);
	string *myCode = new string[nofData];
	myCode = myHuffman.getCode();
	for (int i = 0; i < nofData; i++) {
		cout << myData[i] << " " << myCode[i] << endl;
	}
	cout << endl;
	for (int i = 0; i < str.length(); i++) {
		for (int j = 0; j < nofData; j++) {
			if (str.at(i) == myData[j])
				cout << myCode[j];
		}
	}
	cout << endl;
	system("pause");
	return 0;
}