#include "node.h"

	node::node(int w,int i) {
		this->weight = w;
		this->index=i;
		this->next = nullptr;
		this->color = 0;
		this->previous = nullptr;
	}

	node::node() // default empty constructr 
	{
		this->next = nullptr;
		this->index = -1;
		this->weight = 0;
		this->previous = nullptr;
	}
	 