#include "Huffman.h"

Huffman::Huffman(double fofdata[],int size) {
	this->size = size;
	code = new string[size];
	string codeStr = "";

	top = new TreeNode(0, fofdata[0]);  //籹硑秨繷竊翴
	top->preNode = new TreeNode('0', 0);
	top->preNode->nextNode = top;
	top = top->preNode;

	TreeNode *p = top->nextNode;
	for (int i = 1; i < size; i++) {  //盢┮Τ璶溃罽ノpreNode㎝nextNode﹃癬
		p->nextNode = new TreeNode(i, fofdata[i]);
		p->nextNode->preNode = p;
		p = p->nextNode;
	}
	CreateTree();
	Traversal(top->nextNode, codeStr);
}

void Huffman::CreateTree() {
	TreeNode *min;  //纗程纔
	TreeNode *maximum = new TreeNode(-1,2147483647);  //砞竚纔程竊翴
	TreeNode *less;  //纗材纔
	TreeNode *p;
	for (int i = 0; i < size - 1 ; i++) {  //羆穦硈絬size-1Ω
		p = top->nextNode;
		min = maximum;  //盢min㎝less箇砞程竊翴
		less = maximum;
		while (p != NULL) {  //碝т程纔
			if (p->fofdata < min->fofdata)
				min = p;
			p = p->nextNode;
		}
		p = top->nextNode;
		while (p != NULL) {  //碝тΩ纔
			if (p->fofdata < less->fofdata && p != min)
				less = p;
			p = p->nextNode;
		}

		if (min->preNode != NULL)
			min->preNode->nextNode = min->nextNode;
		if (min->nextNode != NULL)
			min->nextNode->preNode = min->preNode;
		min->preNode = NULL;
		min->nextNode = NULL;

		if (less->preNode != NULL)
			less->preNode->nextNode = less->nextNode;
		if (less->nextNode != NULL)
			less->nextNode->preNode = less->preNode;
		less->preNode = NULL;
		less->nextNode = NULL;

		TreeNode *newNode = new TreeNode((min->fofdata + less->fofdata), less, min);  //盢程のΩ竊翴硈ダ竊翴

		if (top->nextNode != NULL) {
			newNode->nextNode = top->nextNode;  //盢穝竊翴程玡
			top->nextNode->preNode = newNode;
			newNode->preNode = top;
			top->nextNode = newNode;
		}
		else
			top->nextNode = newNode;
	}
	delete maximum;
}

void Huffman::Traversal(TreeNode *p,string codeString) {
	if (p == NULL)
		return;
	Traversal(p->leftChild,codeString+"1");
	Traversal(p->rightChild,codeString+"0");
	if (p->indexOfdata != -1)
		code[p->indexOfdata] = codeString;
}

string* Huffman::getCode() {
	return code;
}