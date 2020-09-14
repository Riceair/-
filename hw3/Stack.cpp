#include "Stack.h"

Stack::Stack(int max) :MaxSize(max) {
	top = -1;
	stack = new Items[MaxSize];
}

bool Stack::isEmpty() {
	if (top >= 0)
		return false;
	else
		return true;
}

bool Stack::isFull() {
	if (top == (MaxSize - 1))
		return true;
	else
		return false;
}

void Stack::push(const Items *newItem) {
	if (!isFull()) {
		top++;
		stack[top].x = newItem->x;
		stack[top].y = newItem->y;
		stack[top].dir = newItem->dir;
	}
}

void Stack::pop() {
	if (!isEmpty()) {
		stack[top].x = 0;
		stack[top].y = 0;
		stack[top].dir = 0;
		top--;
	}
}

Items* Stack::getTop() {
	if (!isEmpty()) {
		Items *topStack = new Items;
		topStack->x = stack[top].x;
		topStack->y = stack[top].y;
		topStack->dir = stack[top].dir;
		return topStack;
	}
}

void Stack::printStack() {
	for (int i = top; i >= 0; i--) {
		cout << "(" << stack[i].x << "," << stack[i].y << "," << stack[i].dir << ")" << endl;
	}
}