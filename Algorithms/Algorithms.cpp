#include "Algorithms.h"
#include "queue.h"
#include "queue_priority .h"
#include "iostream"
#include "union_find.h"
#include "TwoValues.h" 
// in this algo we use "weight" as distance, and color=0="white", color =1="gray"...
// the right node in the "Adjacency List" represnt the edge and not the ver.

Graph Algorithms::bfs(Graph g, int strat_index)
{  // initializing the start vec 
	node* vec_start = g.get_ver(strat_index); // take the first ver from the Graph
	vec_start->color = 1;
	vec_start->weight = 0;

	queue q = queue(); 
	q.push(vec_start);

	node* temp;
	node* next_temp;

	while ((temp = q.pop()) != nullptr){// while the q isnt empty
		int index = temp->index; // keep the index  to change the color later
		node* ogv = g.get_ver(index);
		while (temp->next !=nullptr) { // run all the adjv
			next_temp = temp->next;
			node* v = g.get_ver(next_temp->index);
			if( v->color ==0){ 
				q.push(v); // take the ver from the adj list 
				v->color = 1;
				v->weight = ogv->weight + 1;
			}
			temp = temp->next;
		}
		ogv->color = 2;
		//temp = g.get_ver(temp->index + 1);
	}
	g.printbfs();
	return g;
}

Graph Algorithms::dfs(Graph& g, int start_index)
{
	Graph g_dfs = Graph(1);
	dfs_add(g, start_index, g_dfs);
	return (g_dfs); // using NRVO
}


 void Algorithms::dfs_add(Graph &g, int start_index, Graph &g_dfs)
{
	node* ver = g.get_ver(start_index); // get  original ver from the graph
	ver->color = 1;// color gray 
	node* temp = ver->next; // the node to run for  all the adj
	while (temp != nullptr) {
		node* real_vec = g.get_ver(temp->index);
		if (real_vec->color == 0) { // if node is white (tree edge only!) 
			g_dfs.addEdge_direct(0, temp->index,0);
			dfs_add(g,temp->index,g_dfs);
		}
		temp = temp->next;
	}
	ver->color = 2;  // change the color to black
	//g_dfs.print_graph();
}
 void Algorithms::prim(Graph& g) {
	 node* temp;
	 node* temp_Neighbors;
	 for (int i = 0; i < g.vecnum(); i++) { // initialiazing 
		 temp = g.get_ver(i);
		 temp->color = 0;// not visted
		 temp->previous = nullptr;
		 temp->weight =0;// no meaning 
		 temp_Neighbors=temp;
			 while(temp_Neighbors != nullptr) { // run all the Neigbors
				 temp_Neighbors->color = 0;
				 temp_Neighbors->previous = nullptr;
				 temp_Neighbors = temp_Neighbors->next;
		 }
	 }
	 g.get_ver(0)->color = 1;
	 //start algo 
	 queue_priority qd  = queue_priority(&g) ;
	 int eror_check = 0;
	 for (int i = 0; i < g.vecnum()-1; i++) {
		eror_check= qd.give_minedge();    // because its pointer qd also
		if (eror_check == -1) {
			std::cout << "eror index problem " <<i<< std:: endl;
		}
	 }
 }
 // the func try to find the min edge that not create a circle 
 void Algorithms::Kruskal(Graph& g)
 {
	 node* temp;
	 node* temp_Neighbors;
	 for (int i = 0; i < g.vecnum(); i++) { // initialiazing 
		 temp = g.get_ver(i);
		 temp->previous = g.get_ver(i);
		 temp_Neighbors = temp;
		 while (temp_Neighbors != nullptr) { // run all the Neigbors
			 temp_Neighbors->color = 0;
			 temp_Neighbors->previous = temp_Neighbors;
			 temp_Neighbors = temp_Neighbors->next;
		 }
	 }
	 // start of algo
	 union_find un = union_find(g);
	 TwoValues tv;
	 for(int i=0;i<g.vecnum() - 1; i++) {
		  union_find un = union_find(g);
		  tv = un.minedge(); // give the index of the min edge that not create a circle 
		  un.unite(tv.start, tv.end); // unite the ver with union find 
	 }
 }

 Graph& Algorithms::dijkstra(Graph& g, int start_index)
 {
	 int int_max32 = 2147483647; //  same as infinty
	 node* temp;
	 node* temp_Neighbors;
	 for (int i = 0; i < g.vecnum(); i++) { // initialiazing 
		 temp = g.get_ver(i);
		 temp->color = 0;
		 temp->previous = nullptr;
		 temp->weight = int_max32;
	 }
	 temp = g.get_ver(start_index);
	 temp->weight = 0;// the start point have a 0 distance 
	 queue_priority qp = queue_priority(&g);
	 while (qp.give_min() != -1) {// run until the queue not empty
		 temp = g.get_ver(qp.give_min());// pop the min from the queue
		 temp_Neighbors = temp->next;
		 while (temp_Neighbors != nullptr) {// run all Neighbors
			 int distance = temp->weight + temp_Neighbors->weight;// calucate the road
			 node* courent = g.get_ver(temp_Neighbors->index);
			 if (courent->weight > distance) {
				 courent->weight = distance;
				 courent->previous = temp;
			 }
			 temp_Neighbors = temp_Neighbors->next;
		 }
		 temp->color = 1;
	 }
	 return g;
 }

void Algorithms::deepopy_node(node* dest, node* origin) // copy origin to dest 
{
	dest->color = origin->color;
	dest->weight = origin->weight;
	dest->index = origin->index;
}

