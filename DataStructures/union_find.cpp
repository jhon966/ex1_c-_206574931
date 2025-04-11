#include "union_find.h"
#include"TwoValues.h"
union_find::union_find(Graph& g)
{
	this->g = &g;
}
void union_find::unite(int startedge, int endedge) {// the func coolr the edge and unite the ver  
	node* temp = g->get_ver(startedge);
	while (temp != nullptr) { //coolor the edge
		if (temp->index == endedge) {
			temp->color = 1;
			
		}
		temp = temp->next;
	}
	if (g->get_ver(startedge)->previous == nullptr) {
		g->get_ver(startedge)->previous = g->get_ver(startedge);
	}
	if (g->get_ver(endedge)->previous == nullptr) {
		g->get_ver(endedge)->previous = g->get_ver(endedge);
	}
	node* pre_ver = g->get_ver(endedge)->previous;// the pointer of the ver we want to unite
				for (int i = 0; i < g->vecnum(); i++) {
					node* temp = g->get_ver(i);
					if (temp->previous == pre_ver) {
						temp->previous = g->get_ver(startedge)->previous;
				}
	}
}

TwoValues union_find::minedge() {
	TwoValues tv;
	tv.end = -1;
	tv.start = -1;
	int minedge= 2147483647;// the max 32_int
	for (int i = 0; i < g->vecnum(); i++) {
		node* temp = g->get_ver(i)->next;// get the first edge of ver[i]
		while (temp!=nullptr) {
			if ( (g->get_ver(i)->previous != g->get_ver(temp->index)->previous) && (temp->weight < minedge) ) {
				minedge = temp->weight;
				tv.start = i;
				tv.end = temp->index;
		}
			temp = temp->next;
		}
	}
	return tv;
}

bool union_find::inside(int startedge, int endedge) {
	node* temp = g->get_ver(startedge);
	while (temp != nullptr) {
		if (temp->index == endedge && temp->color == 1) {
			return true;
		}
		temp = temp->next;
	}  
	return false;
}