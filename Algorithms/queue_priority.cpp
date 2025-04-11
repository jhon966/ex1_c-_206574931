#include "Graph.h"
#include "node.h"
#include "queue_priority .h"
#include <stdexcept>

queue_priority::queue_priority(Graph *g) {
	this->g = g;
}

int queue_priority::give_minedge() {
	int min = 2147483647;// the max 32_int
	int index = -1; // eror index =-1
	int start_edge = -1;
	for (int i = 0; i < g->vecnum(); i++) {
		node* temp = g->get_ver(i);
		if (temp->color == 1) {// if these ver already visted
			temp = temp->next;// the first edge
			while (temp != nullptr) {
				if (g->get_ver(temp->index)->color == 0 && temp->weight < min) { // check if the dst of the edge is visted 
					min = temp->weight;
					start_edge = i;
					index = temp->index; 
				}
				temp = temp->next;
			}
		}
	}
	if (index == -1 || start_edge == -1) {
		return -1; }
		node* temp = g->get_ver(index);
		temp->color = 1;// change the color of the chosen ver
		temp = g->get_ver(start_edge)->next;
		while (temp != nullptr) {
			if (temp->index == index) {
				temp->color = 1;
				break;
			}
			temp = temp->next;
		}
	
	//throw std::runtime_error("eror -1");
	return index;
}
int queue_priority::give_min() {
	int min = 2147483647; // the max 32_int
	int index = -1;
	node* temp;

	for (int i = 0; i < g->vecnum(); i++) {
		temp = g->get_ver(i);
		if (temp->color == 0 && temp->weight <= min)
		{
			min = temp->weight;
			index = temp->index;
		}
	}
	return index;
}