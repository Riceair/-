#include "Chain.h"

int main() {
	Chain *personChain = new Chain();
	int k = 0;  //好(壞)人數目
	cout << "請輸入好(壞)人數目:" << endl;
	cin >> k;
	cout << personChain->kill_people(k) << endl;
	system("pause");
	return 0;
}