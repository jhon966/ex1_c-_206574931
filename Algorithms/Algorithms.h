#pragma once
#include "node.h"
#include "Graph.h"
class Algorithms {
public:
	Graph bfs(Graph g, int strat_index);
	Graph dfs(Graph& g, int start_index);
	void dfs_add(Graph& g, int start_index, Graph& g_dfs);
	void prim(Graph& g);
	void Kruskal(Graph& g);
	Graph& dijkstra(Graph &g,int start_index);

	void deepopy_node(node* dest, node* origin); // copy origin to dest
};




