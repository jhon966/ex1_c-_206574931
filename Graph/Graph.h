#pragma once
#include "node.h"
class Graph {

	node* arr;
	int arr_size;
public:
	Graph(int size);
	int vecnum();
	node* get_ver(int index);
	~Graph();
	void addEdge_direct(int origin, int dest, int weight=1);
	void addEdge(int origin, int dest, int weight = 1);
	void removeEdge_direct(int origin, int dest);
	void removeEdge(int origin, int dest);
	void print_prim();
	void print_graph();
	void printbfs();
	void printdij();



};
