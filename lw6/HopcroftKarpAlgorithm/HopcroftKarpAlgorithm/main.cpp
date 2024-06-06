#include "HopcroftKarpAlgorithm.h"
#include <iostream>

int main()
{
	BipartiteGraph g(4, 4);
	g.AddEdge(1, 2);
	g.AddEdge(1, 3);
	g.AddEdge(2, 1);
	g.AddEdge(3, 2);
	g.AddEdge(4, 2);
	g.AddEdge(4, 4);

	std::cout << "Size of maximum matching is " << g.FindMaximumMatching();

	return 0;
}