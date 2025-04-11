#pragma once 

class node {
public:
	int weight;
	int index;
	int color;// 0=white, 1=gray, 2=black
	node* next;
	node* previous;
	node(int w,int i);
	node(); // default constructure 
}; 
 