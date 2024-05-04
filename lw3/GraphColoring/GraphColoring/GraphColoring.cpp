#include "GraphColoring.h"
#include <algorithm>
#include <iostream>

GraphColoring::DualGraph GraphColoring::ConvertPlanarToDualGraph(PlanarGraph planarGraph)
{
	DualGraph dualGraph;
	dualGraph.vertexes = {};
	dualGraph.edges = {};
	// dualGraph.coloredVertexes = {};
	auto n = planarGraph.faces.size();
	std::vector<std::vector<std::pair<int, int>>> t(n);
	planarGraph.edges = t;
	// i - итерироваться по face, чтобы менять грани
	// j - итерироваться по вршинам i-ой грани
	// k - итерироватся по внешней грани

	//
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < planarGraph.faces[i].size() - 1; j++)
		{
			planarGraph.edges[i].push_back(std::make_pair(planarGraph.faces[i][j], planarGraph.faces[i][j + 1]));
			// std::cout << planarGraph.faces[i][j] << " " << planarGraph.faces[i][j + 1] << std::endl;
		}
		planarGraph.edges[i].push_back(std::make_pair(planarGraph.faces[i][planarGraph.faces[i].size() - 1], planarGraph.faces[i][0]));
		/*std::cout << planarGraph.faces[i][planarGraph.faces[i].size() - 1] << " " << planarGraph.faces[i][0] << std::endl;
		 */ std::cout << std::endl;
	}

	// инициализирую вершины двойственного графа по граня планарного графа
	for (int i = 0; i < n; i++)
	{
		dualGraph.vertexes[i + 1] = planarGraph.edges[i];
	}

	// буду брать по 2 вершины двойственного графа и искать одинаковые рёбра у ни
	for (int i = 1; i <= dualGraph.vertexes.size() - 1; i++)
	{
		for (int j = i + 1; j <= dualGraph.vertexes.size(); j++)
		{
			for (int k = 0; k < dualGraph.vertexes[i].size(); k++)
			{
				for (int l = 0; l < dualGraph.vertexes[j].size(); l++)
				// std::cout << dualGraph.vertexes[i][k].first << std::endl;
				{
					if (dualGraph.vertexes[i][k] == dualGraph.vertexes[j][l] || (dualGraph.vertexes[i][k].first == dualGraph.vertexes[j][l].second && dualGraph.vertexes[i][k].second == dualGraph.vertexes[j][l].first))
					{
						dualGraph.edges.push_back(std::make_pair(i, j));
					}
				}
			}
		}
	}
	sort(dualGraph.edges.begin(), dualGraph.edges.end());
	auto it = unique(dualGraph.edges.begin(), dualGraph.edges.end());
	dualGraph.edges.erase(it, dualGraph.edges.end());

	return dualGraph;
}

GraphColoring::DualGraph ColorVertex(GraphColoring::DualGraph& dualGraph, int color, int vertex)
{
	if (dualGraph.coloredVertexes[vertex] == 0)
	{
		dualGraph.coloredVertexes[vertex] = color;
		std::vector<int> firstLocality = {};
		std::vector<int> secondLocality = {};
		for (int j = vertex + 1; j <= dualGraph.vertexes.size(); j++)
		{
			if (dualGraph.coloredVertexes[j] == 0)
			{
				secondLocality.push_back(j);
			}
		}

		for (int j = 0; j < dualGraph.edges.size(); j++)
		{
			if ((vertex == dualGraph.edges[j].first || vertex == dualGraph.edges[j].second) && dualGraph.coloredVertexes[dualGraph.edges[j].second] == 0)
			{
				firstLocality.push_back(dualGraph.edges[j].second);
			}
		} 

		//secondLocality.erase(std::remove(secondLocality.begin(), secondLocality.end(), vertex), secondLocality.end());
		for (int j = 0; j < firstLocality.size(); j++)
		{
			secondLocality.erase(std::remove(secondLocality.begin(), secondLocality.end(), firstLocality[j]), secondLocality.end());
		}

		/*for (int j = 0; j < firstLocality.size(); j++)
		{
			for (int k = 0; k < dualGraph.edges.size(); k++)
			{
				std::cout << vertex << " " << dualGraph.edges[k].second << std::endl;
				if (firstLocality[j] == dualGraph.edges[k].first && (std::count(dualGraph.edges.begin(), dualGraph.edges.end(), std::make_pair(vertex, dualGraph.edges[k].second)) > 0) && dualGraph.edges[k].second != vertex && dualGraph.coloredVertexes[dualGraph.edges[k].second] == 0)
				{
					std::cout << vertex << " " << dualGraph.edges[k].second << std::endl;
					std::cout << std::count(dualGraph.edges.begin(), dualGraph.edges.end(), std::make_pair(vertex, dualGraph.edges[k].second)) << std::endl;

					secondLocality.push_back(dualGraph.edges[k].second);
				}
			}
		}*/

		// если секонд локалити пустой, то это граф - звездочка
		if (secondLocality.empty())
		{
			return dualGraph;
		}
		else
		{

			// dualGraph.coloredVertexes[secondLocality[0]] = color;
			for (int k = 0; k < secondLocality.size(); k++)
			{
				for (int l = 0; l < dualGraph.edges.size(); l++)
				{
					if (dualGraph.edges[l].first == secondLocality[k])
						dualGraph.edges[l].first = vertex;
					if (dualGraph.edges[l].second == secondLocality[k])
						dualGraph.edges[l].second = vertex;
				}
				ColorVertex(dualGraph, color, secondLocality[k]);
			}
		}
	}
	return dualGraph;
}

GraphColoring::DualGraph GraphColoring::ColorGraph(DualGraph& dualGraph)
{
	// инициализирую цвета вершин
	for (int i = 1; i <= dualGraph.vertexes.size(); i++)
	{
		dualGraph.coloredVertexes[i] = 0;
	}

	int color = 1;

	for (int i = 1; i <= dualGraph.coloredVertexes.size(); i++)
	{
		ColorVertex(dualGraph, color, i);
		color++;
	}

	for (auto const& [key, val] : dualGraph.coloredVertexes)
	{
		std::cout << key // string (key)
				  << ':'
				  << val // string's value
				  << std::endl;
	}

	return dualGraph;
}
