#include "graph.h"
#include "node.h"
#include "Algorithms.h"
#include <iostream>
#include <assert.h>

int test_prim(){
	Graph g1 = Graph(4);
	g1.addEdge(0, 1);
	g1.addEdge(0, 2,4);
	g1.addEdge(1,2,2);
	g1.addEdge(1,3,5);
	g1.addEdge(2,3,3);
	Algorithms algo = Algorithms();
	g1.print_graph();
	algo.prim(g1);
	g1.print_prim();
	node* temp = g1.get_ver(0);
	assert(temp->next->color == 1); // suppose to fail
	temp = g1.get_ver(1);
	assert(temp->next->next->color == 1);
	temp = g1.get_ver(2);
	assert(temp->next->next->next->color == 1);
	return 0;
	
}