#include "Graph.h"
#include "node.h"
#include "Algorithms.h"
#include <iostream>
#include <assert.h>
int test_dijkstra() {
	//build graph
	Graph g1 = Graph(5);
	g1.addEdge(0, 1);
	g1.addEdge(0, 2);
	g1.addEdge(1, 3);
	g1.addEdge(1, 4);
	g1.print_graph();
	Algorithms algo = Algorithms();
	int start_index = 2;
	g1 = algo.dijkstra(g1, start_index);
	g1.printdij();
	node* temp = g1.get_ver(start_index);
	assert(nullptr == temp->previous);
	assert(temp->weight == 0);// distance supposed to be 0
	temp = g1.get_ver(0);
	assert(temp->weight == 1);
	temp = g1.get_ver(1);
	assert(temp->weight == 2);
	temp = g1.get_ver(3);
	assert(temp->weight == 3);
	Graph g2 = Graph(5);
	g2.addEdge(0, 1,60000);
	g2.addEdge(0, 2, 20);
	g2.addEdge(0,3,3200);
	g2.addEdge(0, 4,4300);
	g2.addEdge(1, 2,30);
	g2.addEdge(1, 3, 23);
	g2.addEdge(1, 4, 57);
	g2.addEdge(2, 3, 89);
	g2.addEdge(2, 4, 45);
	g2.addEdge(3, 4, 10);
	g2.print_graph();
	algo.dijkstra(g2, 0);
	g2.printdij();
	temp = g2.get_ver(0);
	assert(temp->weight == 0);
	temp = g2.get_ver(2);
	assert(temp->weight == 20);
	temp = g2.get_ver(1);
	assert(temp->weight == 50);
	temp = g2.get_ver(1);
	assert(temp->weight == 50);
	return 0;
}