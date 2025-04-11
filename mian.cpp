#include "Algorithms.h"
#include "queue.h"
#include "queue_priority .h"
#include "iostream"
#include "union_find.h"
#include "TwoValues.h" 
#include <cassert>

int test_dijkstra();
int test_dfs();
int test_kruskal();
int test_bfs();
int test_prim();

int main() {

	/* For each algorithm, a test is created that performs an in-depth demonstration of the algorithms.
	Each test includes building a graph (there can be more than one) that is checked by assert if the algorithm is correct.
	In addition, by printing, there is also a clear demonstration of the input of the function (neighborhood graph) and printing of the result.*/

	/* we can run the test from here! */

	test_dijkstra();
	test_dfs();
	test_kruskal();
	test_bfs();
	test_prim();
	
}