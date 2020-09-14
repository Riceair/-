#include "Huffman.h"

Huffman::Huffman(double fofdata[],int size) {
	this->size = size;
	code = new string[size];
	string codeStr = "";

	top = new TreeNode(0, fofdata[0]);  //�s�y�}�Y�`�I
	top->preNode = new TreeNode('0', 0);
	top->preNode->nextNode = top;
	top = top->preNode;

	TreeNode *p = top->nextNode;
	for (int i = 1; i < size; i++) {  //�N�Ҧ��n���Y���r��preNode�MnextNode��b�@�_
		p->nextNode = new TreeNode(i, fofdata[i]);
		p->nextNode->preNode = p;
		p = p->nextNode;
	}
	CreateTree();
	Traversal(top->nextNode, codeStr);
}

void Huffman::CreateTree() {
	TreeNode *min;  //�x�s�̤p�u��
	TreeNode *maximum = new TreeNode(-1,2147483647);  //�]�m�u���׬��̤j���`�I
	TreeNode *less;  //�x�s�ĤG�p�u��
	TreeNode *p;
	for (int i = 0; i < size - 1 ; i++) {  //�`�@�u�|�s�usize-1��
		p = top->nextNode;
		min = maximum;  //�Nmin�Mless�w�]���̤j���`�I
		less = maximum;
		while (p != NULL) {  //�M��̤p�u��
			if (p->fofdata < min->fofdata)
				min = p;
			p = p->nextNode;
		}
		p = top->nextNode;
		while (p != NULL) {  //�M�䦸�p�u��
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

		TreeNode *newNode = new TreeNode((min->fofdata + less->fofdata), less, min);  //�N�̤p�H�Φ��p���`�I�s��P�@�ӥ��`�I

		if (top->nextNode != NULL) {
			newNode->nextNode = top->nextNode;  //�N�s�`�I�[�J�̫e��
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