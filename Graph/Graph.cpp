#include "Graph.h"
#include <stdexcept>
#include <iostream>
Graph::Graph(int size)
{
	this->arr_size = size;
	this-> arr = new node[size]; 
	for (int i = 0; i < this->arr_size; i++) {
		arr[i].index = i;
		arr[i].weight = 0;
		arr[i].next = nullptr;
		arr[i].color = 0;
	}
}

Graph::~Graph()
{
	for (int i = 0; i < arr_size; i++) {// delete all the edges and only after delete arr
		node* current = arr[i].next;
		node* next;
		while (current!=nullptr) {
			next = current->next;
			delete current;
			 current = next;
		}
	}
	delete [] this->arr; // delete arr
}

int Graph::vecnum() {
	return arr_size;
}
node* Graph::get_ver(int index) {
	return &arr[index];
}

void Graph::addEdge_direct(int origin, int dest, int weight) 
{   
	node* vec =  new node(weight, dest);
	node* temp = &arr[origin];
	while (temp->next != nullptr) {
		temp = temp->next;
	}
	temp->next = vec;
	// addEdge(dest, origin, weight); // add the same edge twice e because isnt directional,and it is clearer if it appears at both vertices.
}

void Graph::addEdge(int origin, int dest, int weight)
{
	this->addEdge_direct(origin, dest, weight);
	this->addEdge_direct(dest, origin, weight);
}

void Graph::removeEdge_direct(int origin, int dest)
{ 
	if (dest >= arr_size)(throw" The source vector does not exist. Please note that the first vector starts from zero. ");
	node* ver = &arr[origin];
	while (true) { // run anyway until "retun" or "throw"
		if (ver->next == nullptr) {
			throw std::runtime_error("edge not found");
		}

		if (ver->next->index == dest) {
			node* del = ver->next;
			if (ver->next->next != nullptr) {
				node* temp = ver->next->next;
				ver->next = temp;
			}
			else
			{
				ver->next = nullptr;
			}
			delete del;
			
			return;
		}
		ver = ver->next;
	}
}

void Graph::removeEdge(int origin, int dest)
{
	this->removeEdge_direct(origin, dest);
	this->removeEdge_direct(dest, origin);
}

void Graph::print_graph()
{
 for(int i=0;i<arr_size;i++){
	 node* temp = &arr[i];
	 std::cout << "vertex" << i << " : ";
	 while(temp->next!=NULL){
		 std::cout << temp->next->index << ",";
		 temp = temp->next;
	 }
	 std::cout << std::endl;
	
 }
 std::cout << std::endl;
}

void Graph::print_prim()
{
	for (int i = 0; i < arr_size; i++) {
		node* temp = &arr[i];
		std::cout << "vertex" << i << " : ";
		while (temp->next != NULL) {
			if (temp->next->color == 1) {
				std::cout << temp->next->index << ",";
			}
			temp = temp->next;
			
		}
		std::cout << std::endl;
	}
}
// can run only after bfs algo run on the Graph
void Graph::printbfs() {
	
	for (int i = 0; i < arr_size; i++) {
		std::cout << "level " << i << ": ";
		for (int j = 0; j < arr_size; j++) {
			if (arr[j].weight == i) {
				std::cout << arr[j].index << " ";
			}
		}
		std::cout << std::endl;
	}
}

void Graph::printdij() {

	for (int i = 0; i < arr_size; i++) {
		node* temp = &this->arr[i];
		if (arr[i].previous == nullptr) // if i am the starting point print...
		{
			std::cout << "the starting point is: "<<i<<std::endl;
		}
		else
		{
			std::cout << "finsh point: " << temp->index;
		}


		while (temp->previous != nullptr) { // print the road of each ver
			temp = (temp->previous);
			std::cout << "<-" << temp->index;

		}
		if (arr[i].previous != nullptr)
		{
			std::cout <<  std::endl;
		}
	}
	std::cout << std::endl;
}
