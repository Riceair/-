#ifndef CHAIN_H
#define CHAIN_H
#include <iostream>
using namespace std;

class ChainNode {
public:
	ChainNode(const int&, ChainNode*);
	~ChainNode();
	int data;
	ChainNode *link;
};

class Chain {
public:
	Chain();
	bool IsEmpty();
	int Get(int);
	void Delete(const int);
	void Insert(const int,const int&);
	void show();
	int kill_people(const int);  //輸入好(壞)人的數量
private:
	ChainNode *first;
	int total;  //目前資料總數
};
#endif