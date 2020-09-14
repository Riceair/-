#ifndef CHAIN_H
#define CHAIN_H
#include "ChainNode.h"
#include <iostream>
using namespace std;

class Chain {
public:
	Chain() { first = NULL; };
	~Chain();
	bool IsEmpty() const { return first == NULL; };
	void Delete(int);
	void Insert(int,const char&);
	void Print();
private:
	ChainNode *first;
};
#endif