#include "HopcroftKarpAlgorithm.h"
#include <iostream>
#include <list>
#include <queue>

using namespace std;

#define NIL 0
#define INF INT_MAX

int BipartiteGraph::FindMaximumMatching()
{
	// pairLeftVertex[u] хранит пару u в соответствии, где u
	// является вершиной в левой части двудольного графа.
	// Если у u нет пары, то pairLeftVertex[u] равно NILL
	pairLeftVertex = new int[leftVertexes + 1];

	// pairRightVertex[v] сохраняет пару v в соответствии. Если у v
	// нет пары, то pairLeftVertex[v] равно НУЛЮ
	pairRightVertex = new int[rightVertexes + 1];

	// dist[u] хранит расстояние между левыми боковыми вершинами
	// dist[u] на единицу больше, чем dist[u'], если u следующая
	// до u' на дополнительном пути
	dist = new int[leftVertexes + 1];

	//инициализация
	for (int leftV = 0; leftV <= leftVertexes; leftV++)
		pairLeftVertex[leftV] = NIL;
	for (int rightV = 0; rightV <= rightVertexes; rightV++)
		pairRightVertex[rightV] = NIL;
	int result = 0;

	while (BreadthFirstSearch())
	{
		// Ищем свободную вершину
		for (int leftV = 1; leftV <= leftVertexes; leftV++)

			// Если текущая вершина свободна и можем идти дальше
			if (pairLeftVertex[leftV] == NIL && DepthFirstSearch(leftV))
				result++;
	}
	return result;
}

bool BipartiteGraph::BreadthFirstSearch()
{
	queue<int> Q;

	for (int leftV = 1; leftV <= leftVertexes; leftV++)
	{
		if (pairLeftVertex[leftV] == NIL)
		{
			dist[leftV] = 0;
			Q.push(leftV);
		}
		else
			dist[leftV] = INF;
	}

	dist[NIL] = INF;

	while (!Q.empty())
	{
		int leftV = Q.front();
		Q.pop();

		if (dist[leftV] < dist[NIL])
		{
			list<int>::iterator i;
			for (i = adj[leftV].begin(); i != adj[leftV].end(); ++i)
			{
				int rightV = *i;
				if (dist[pairRightVertex[rightV]] == INF)
				{
					dist[pairRightVertex[rightV]] = dist[leftV] + 1;
					Q.push(pairRightVertex[rightV]);
				}
			}
		}
	}
	return (dist[NIL] != INF);
}

bool BipartiteGraph::DepthFirstSearch(int leftV)
{
	if (leftV != NIL)
	{
		list<int>::iterator i;
		for (i = adj[leftV].begin(); i != adj[leftV].end(); ++i)
		{
			int rightV = *i;
			if (dist[pairRightVertex[rightV]] == dist[leftV] + 1)
			{
				if (DepthFirstSearch(pairRightVertex[rightV]) == true)
				{
					pairRightVertex[rightV] = leftV;
					pairLeftVertex[leftV] = rightV;
					return true;
				}
			}
		}
		dist[leftV] = INF;
		return false;
	}
	return true;
}

BipartiteGraph::BipartiteGraph(int leftVertexes, int rightVertexes)
{
	this->leftVertexes = leftVertexes;
	this->rightVertexes = rightVertexes;
	adj = new list<int>[leftVertexes + 1];
}

void BipartiteGraph::AddEdge(int leftV, int rightV)
{
	adj[leftV].push_back(rightV);
}
