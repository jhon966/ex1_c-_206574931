﻿#include "node.h"
#include "Graph.h"
#include "Algorithms.h"
#include <cassert>
#include <iostream>
int test_bfs()
{
    std::cout << "start test"<<std::endl ;
// initialization
    node n1(2,1);
    node n2(3,2);
    node n3(10,3);
     n1.next = &n2;
     n2.next = &n3;
 // cheack values 
     assert(2 == n1.weight);
     assert(3 == n1.next->weight);
     assert(10 == n1.next->next->weight);
     assert(2 == n2.index);
    std::cout << "finsh test2";
    return 0;
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
