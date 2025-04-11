#include "queue.h"

struct qnode { //  struct that hold 2 nodes 
	node* gnode;
	qnode* nnext;
	qnode(node *n) {
		gnode = n;
		nnext = nullptr;
	}
};

queue::queue() {
	qn = nullptr;
}

queue:: ~queue() {
	
	while (qn != nullptr) {
		qnode* n = qn;
		qn = qn->nnext;
		//delete n->gnode; // we use only if we want to delete the node from the graph 
		delete n;
	}
}
void queue::push(node* vec)
{
	if (qn == nullptr) { 
		qn = new qnode(vec);
	}
	else {
		qnode* temp =qn ; // the node we use to  get the last node
		while ( temp->nnext!= nullptr) {
			temp = temp->nnext;
		}
		temp->nnext = new qnode(vec);
	}
}

node* queue::pop()
{
	if ( qn== nullptr) {
		return nullptr;
	}
	qnode* temp = qn;
	qn = qn->nnext;
	node* n = temp->gnode;
	delete temp;
	return n;
}
