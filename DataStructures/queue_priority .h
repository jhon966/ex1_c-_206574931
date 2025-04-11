#pragma once
#include "Graph.h"
#include "node.h"
class queue_priority {
	Graph* g;
public:
	queue_priority(Graph *g);
	int give_minedge();
	int give_min();
};