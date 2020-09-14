#include <iostream>
#include <time.h>
using namespace std;

#define ARRSIZE 1250
void SelectionSort(int *a, const int n) {
	for (int i = 0; i < n; i++) {
		int j = i;
		for (int k = i + 1; k < n; k++) {
			if (a[k] < a[j]) j = k;
		}
		swap(a[i], a[j]);
	}
}
void main() {
	int a[ARRSIZE] = { 0 };
	for (int i = 0; i < ARRSIZE; i++) {
		a[i] = ARRSIZE - i;
	}
	/*for (int i = 0; i < ARRSIZE; i++) {
		cout << a[i] << " ";
	}
	cout << endl;*/

	double timeStart = clock(); //時間測試開始

	SelectionSort(a, ARRSIZE);

	double timeEnd = clock(); //時間測試結束

	/*for (int i = 0; i < ARRSIZE; i++) {
		cout << a[i] << " ";
	}*/

	cout << endl << "演算法執行時間: " << (timeEnd - timeStart) / CLOCKS_PER_SEC << endl;
}