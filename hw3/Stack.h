#ifndef STACK_H
#define STACK_H
#include <iostream>
using namespace std;

struct Items {
	int x, y, dir;
};

class Stack {
public:
	Stack(int = 20);
	bool isEmpty();
	bool isFull();
	void push(const Items*);
	void pop();
	Items* getTop();
	void printStack();
private:
	int top;
	Items *stack;
	int MaxSize;
};
#endif
