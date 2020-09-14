#include "Chain.h"

ChainNode::ChainNode(const int& data, ChainNode *link) {
	this->data = data;
	this->link = link;
}

ChainNode::~ChainNode() {
	cout << "Oh, wow" << endl;
}

Chain::Chain() {
	first = NULL;
	this->total = 0;
}

bool Chain::IsEmpty() {
	if (first == NULL)
		return true;
	else
		return false;
}

int Chain::Get(int theIndex) {
	if (!IsEmpty() && theIndex < total) {
		ChainNode *p = first;
		for (int i = 0; i < theIndex; i++) {
			p = p->link;
		}
		return p->data;
	}
	else
		return -1;
}

void Chain::Insert(const int theIndex,const int &theElement) {
	if (theIndex < 0 || theIndex>total)
		cout << "Bad insert index" << endl;
	else if (theIndex == 0 && total==0) {
		first=new ChainNode(theElement,first);
		first->link = first;
		total++;
	}
	else if (theIndex == 0 ) {
		ChainNode *p = new ChainNode(theElement, first);
		first = p;
		for (int i = 0; i < total; i++) {
			p = p->link;
		}
		p->link = first;
		total++;
	}
	else {
		ChainNode *p = first;
		for (int i = 0; i < theIndex-1; i++) {
			p = p->link;
		}
		p->link = new ChainNode(theElement, p->link);
		total++;
	}
}

void Chain::Delete(const int theIndex) {
	if (IsEmpty())
		cout << "The chain with no element" << endl;
	else if (theIndex >= total)
		cout << "The index is larger than the element amounts of the chain." << endl;
	else {
		ChainNode *deleteNode;
		ChainNode *p = first;
		if (theIndex == 0) {
			deleteNode = first;
			first = first->link;
			delete deleteNode;
			total--;
			for (int i = 0; i < total-1; i++) {
				p = p->link;
			}
			p->link = first;
		}
		else {
			for (int i = 0; i < theIndex - 1; i++) {
				p = p->link;
			}
			deleteNode = p->link;
			p->link = p->link->link;
			total--;
		}
	}
}

void Chain::show() {
	if (!IsEmpty()) {
		ChainNode *p = first;
		for (int i = 0; i < total; i++) {
			cout << p->data << " -> ";
			p = p->link;
		}
		cout << "NULL" << endl;
	}
}

int Chain::kill_people(const int k) {
	//k���n(�a)�H�ӼơAn���ҨD
	//�p��Ʀr�A�qn=2�}�l���W��A�@���[�@
	//position�����{�b�ƨ�ĴX�H
	//0���n�H�A1���a�H
	int n = 2;

	Insert(0, 0);  //����m�Ҧ��n�H
	for (int i = 0; i < k - 1; i++)
		Insert(1, 0);
	
	for (int i = 0; i < k; i++)  //�b�Ĥ@�Ӧn�H�᭱�w��k���a�H
		Insert(1, 1);

////////////////////////////////////////////�H�U�}�l���ձ����Ҧ��a�H/////////////////////////////////////////////////////
	int position = 1;  //�����ثe��m(��l�Ƭ�n-1)
	int kill = 0;  //�������F�X�ӤH

	while (1) {
		if (kill == k)  //�����a�H�����j��
			break;

		if (Get(position) == 1) {  //��position�����a�H�A����
			Delete(position);
			kill++;
			position += n-1;  //�U�@�Ӧ�m�O[position+(n-1)] %total
			position %= total;
		}
		else {  //�ƨ�n���n�H�An�����~�A���s�M��n
			for (kill; kill>0; kill--)  //�N�������a�H�٭�
				Insert(1, 1);
			n++;  //n��n+1�A���s����
			position = n - 1;  //���]��m
			position %= total;
		}
	}
	return n;
}