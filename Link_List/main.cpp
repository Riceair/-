#include "Chain.h"

int main() {
	Chain myChain;
	myChain.Insert(0, 'a');
	myChain.Insert(1, 'b');
	myChain.Insert(2, 'c');
	myChain.Insert(3, 'd');
	myChain.Insert(4, 'e');
	myChain.Print();
	system("pause");
	return 0;
}