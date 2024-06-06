#pragma once
#include <list>
#include <queue>

class BipartiteGraph
{
	int leftVertexes, rightVertexes;

	//adj[u] хранит смежности левой стороны вершины 'u'. Значение u варьируется от 1 до m. 0 используется для фиктивной вершины
	std::list<int>* adj;

	// указатели на массивы вершин
	int *pairLeftVertex, *pairRightVertex, *dist;

public:
	BipartiteGraph(int leftVertexes, int rightVertexes);
	void AddEdge(int leftV, int rightV); 
	bool BreadthFirstSearch();
	bool DepthFirstSearch(int leftV);
	int FindMaximumMatching();
};