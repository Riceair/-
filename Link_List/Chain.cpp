#include "Chain.h"

void Chain::Delete(int theIndex) {
	ChainNode *deleteNode;
	if (theIndex == 0) {
		deleteNode = first;
		first = first->link;
	}
	else {
		ChainNode *p = first;
		for (int i = 0; i < theIndex - 1; i++) {
			p = p->link;
		}
		deleteNode = p->link;
		p->link = p->link->link;
	}
	delete deleteNode;
}

Chain::~Chain() {
	while (first != NULL) {
		ChainNode *next = first->link;
		delete first;
		first = next;
	}
}

void Chain::Insert(int theIndex, const char &theElement) {
	if (theIndex < 0)
		cout << "Bad insert index" << endl;
	if (theIndex == 0) {
		first = new ChainNode(theElement, first);
	}
	else {
		ChainNode *p = first;
		for (int i = 0; i < theIndex - 1; i++) {
			p = p->link;
		}
		p->link = new ChainNode(theElement, p->link);
	}
}

void Chain::Print() {
	if (!IsEmpty()) {
		ChainNode *p = first;
		while (p != NULL) {
			cout << p->data << " -> ";
			p = p->link;
		}
		cout << " NULL" << endl;
	}
}