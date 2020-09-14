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
	//k為好(壞)人個數，n為所求
	//計算數字，從n=2開始往上找，一次加一
	//position紀錄現在數到第幾人
	//0為好人，1為壞人
	int n = 2;

	Insert(0, 0);  //先放置所有好人
	for (int i = 0; i < k - 1; i++)
		Insert(1, 0);
	
	for (int i = 0; i < k; i++)  //在第一個好人後面安插k個壞人
		Insert(1, 1);

////////////////////////////////////////////以下開始嘗試殺掉所有壞人/////////////////////////////////////////////////////
	int position = 1;  //紀錄目前位置(初始化為n-1)
	int kill = 0;  //紀錄殺了幾個人

	while (1) {
		if (kill == k)  //殺光壞人結束迴圈
			break;

		if (Get(position) == 1) {  //到position項為壞人，殺掉
			Delete(position);
			kill++;
			position += n-1;  //下一個位置是[position+(n-1)] %total
			position %= total;
		}
		else {  //數到n為好人，n為錯誤，重新尋找n
			for (kill; kill>0; kill--)  //將殺掉的壞人還原
				Insert(1, 1);
			n++;  //n為n+1，重新嘗試
			position = n - 1;  //重設位置
			position %= total;
		}
	}
	return n;
}