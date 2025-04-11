#pragma once
#include "Graph.h"
#include "TwoValues.h"
class union_find
{
public:
	union_find(Graph &g );
	void unite(int startedge, int endedge);
	TwoValues minedge();
	bool inside(int startedge, int endedge);
private:
	Graph* g;
};



