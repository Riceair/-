#ifndef MYHUFFMAN_H
#define MYHUFFMAN_H
#include <iostream>
#include <string>
using namespace std;

class TreeNode {
public:
	TreeNode(int indexOfdata, double fofdata) {
		this->indexOfdata = indexOfdata;
		this->fofdata = fofdata;
		leftChild = NULL;
		rightChild = NULL;
		nextNode = NULL;
		preNode = NULL;
	}
	TreeNode(double fofdata, TreeNode *left, TreeNode *right) {
		indexOfdata = -1;
		this->fofdata = fofdata;
		leftChild = left;
		rightChild = right;
		nextNode = NULL;
		preNode = NULL;
	}
	int indexOfdata;
	double fofdata;
	TreeNode *leftChild, *rightChild, *preNode , *nextNode;
};

class Huffman {
public:
	Huffman(double[], int);
	void CreateTree();
	void Traversal(TreeNode*, string);
	string* getCode();
private:
	TreeNode *top;  //儲存節點開頭或是root
	string *code;  //儲存壓縮的code
	int size;
};
#endif