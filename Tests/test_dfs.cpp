#include "graph.h"
#include "node.h"
#include "Algorithms.h"
#include <iostream>
#include <assert.h>
int test_dfs() {
	//build graph
	Graph g1 = Graph(5);
	g1.addEdge(0,1);
	g1.addEdge(0, 2);
	g1.addEdge(1, 3);
	g1.addEdge(1, 4);
	g1.print_graph();
	Algorithms algo = Algorithms();
	Graph g2= algo.dfs(g1, 0);
	// test start
	assert(g2.get_ver(0)->next->index == 1);// Fixing the error by calling the function
	assert(g2.get_ver(0)->next->next->index == 3);
	assert( g2.vecnum() == 1);
	g2.print_graph();// for eye check 
	return 0;
}