#ifndef CHAINNODE_H
#define CHAINNODE_H

class ChainNode {
	friend class Chain;
	ChainNode(const char data, ChainNode *link) {
		this->data = data;
		this->link = link;
	}
private:
	char data;
	ChainNode *link;
};
#endif