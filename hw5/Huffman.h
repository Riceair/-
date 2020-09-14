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
	TreeNode *top;  //�x�s�`�I�}�Y�άOroot
	string *code;  //�x�s���Y��code
	int size;
};
#endif