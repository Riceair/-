#include "Chain.h"

int main() {
	Chain *personChain = new Chain();
	int k = 0;  //�n(�a)�H�ƥ�
	cout << "�п�J�n(�a)�H�ƥ�:" << endl;
	cin >> k;
	cout << personChain->kill_people(k) << endl;
	system("pause");
	return 0;
}