#pragma once
#include "node.h"
struct qnode;// we need a new strcut, bceacuse which node may contain a lot of edges 

class queue {
public:
	queue();
	~queue();
	void push(node* vec);
	node* pop();
private:
	qnode* qn;

};