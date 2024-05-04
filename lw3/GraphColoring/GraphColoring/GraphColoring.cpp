#include "GraphColoring.h"
#include <algorithm>
#include <iostream>
#include <set>

GraphColoring::GraphColoring(GraphColoring::PlanarGraph planarGraph)
	: m_planarGraph(planarGraph)
	, m_dualGraph({})
{
	m_dualGraph.vertexes = {};
	m_dualGraph.edges = {};
	m_dualGraph.coloredVertexes = {};
}

std::set<int> GetLocality(GraphColoring::DualGraph const& dualGraph, std::set<int> vertexes)
{
	std::set<int> locality = {};

	for (auto& edge : dualGraph.edges)
	{
		for (auto& vertex : vertexes)
		{
			auto nextVertex = vertex == edge.first
				? edge.second
				: vertex == edge.second
				? edge.first
				: vertex;

			if (!vertexes.contains(nextVertex))
				locality.insert(nextVertex);
		}
	}

	return locality;
}

void GraphColoring::ConvertPlanarToDualGraph()
{
	auto n = m_planarGraph.faces.size();
	std::vector<std::vector<std::pair<int, int>>> t(n);
	m_planarGraph.edges = t;
	// i - итерироваться по face, чтобы менять грани
	// j - итерироваться по вршинам i-ой грани
	// k - итерироватся по внешней грани

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m_planarGraph.faces[i].size() - 1; j++)
		{
			m_planarGraph.edges[i].push_back(std::make_pair(m_planarGraph.faces[i][j], m_planarGraph.faces[i][j + 1]));
		}
		m_planarGraph.edges[i].push_back(std::make_pair(m_planarGraph.faces[i][m_planarGraph.faces[i].size() - 1], m_planarGraph.faces[i][0]));
		std::cout << std::endl;
	}

	// инициализирую вершины двойственного графа по граням планарного графа
	for (int i = 0; i < n; i++)
	{
		m_dualGraph.vertexes[i + 1] = m_planarGraph.edges[i];
	}

	// буду брать по 2 вершины двойственного графа и искать одинаковые рёбра у них
	for (int i = 1; i <= m_dualGraph.vertexes.size() - 1; i++)
	{
		for (int j = i + 1; j <= m_dualGraph.vertexes.size(); j++)
		{
			for (int k = 0; k < m_dualGraph.vertexes[i].size(); k++)
			{
				for (int l = 0; l < m_dualGraph.vertexes[j].size(); l++)
				{
					if (m_dualGraph.vertexes[i][k] == m_dualGraph.vertexes[j][l] || (m_dualGraph.vertexes[i][k].first == m_dualGraph.vertexes[j][l].second && m_dualGraph.vertexes[i][k].second == m_dualGraph.vertexes[j][l].first))
					{
						m_dualGraph.edges.push_back(std::make_pair(i, j));
					}
				}
			}
		}
	}
	sort(m_dualGraph.edges.begin(), m_dualGraph.edges.end());
	auto it = unique(m_dualGraph.edges.begin(), m_dualGraph.edges.end());
	m_dualGraph.edges.erase(it, m_dualGraph.edges.end());
}

bool ColorVertex(GraphColoring::DualGraph& dualGraph, int color, int vertex)
{
	if (dualGraph.coloredVertexes[vertex] == 0)
	{
		std::set<int> firstLocality = GetLocality(dualGraph, { vertex });

		for (auto firstLocalityVertex : firstLocality)
		{
			for (auto& edge : dualGraph.edges)
			{
				auto secondLocalityVertex = firstLocalityVertex == edge.first
					? edge.second
					: firstLocalityVertex == edge.second
					? edge.first
					: firstLocalityVertex;

				if (vertex != secondLocalityVertex && !firstLocality.contains(secondLocalityVertex) && dualGraph.coloredVertexes[secondLocalityVertex] == 0)
				{
					for (int l = 0; l < dualGraph.edges.size(); l++)
					{
						auto& edge = dualGraph.edges[l];
						if (edge.first == secondLocalityVertex)
							edge.first = vertex;
						if (edge.second == secondLocalityVertex)
							edge.second = vertex;
					}
					dualGraph.coloredVertexes[secondLocalityVertex] = color;
					ColorVertex(dualGraph, color, vertex);
					dualGraph.coloredVertexes[vertex] = color;
					return true;
				}
			}
		}
		dualGraph.coloredVertexes[vertex] = color;
		return true;
	}
	return false;
}

void GraphColoring::ColorGraph()
{
	// инициализирую цвета вершин
	for (int i = 1; i <= m_dualGraph.vertexes.size(); i++)
	{
		m_dualGraph.coloredVertexes[i] = 0;
	}

	int color = 1;

	for (int i = 1; i <= m_dualGraph.coloredVertexes.size(); i++)
	{
		auto isColored = ColorVertex(m_dualGraph, color, i);
		if (isColored)
			color++;
	}
}

void GraphColoring::ColorPlanarGraph()
{
	for (auto& vertex : m_dualGraph.coloredVertexes)
	{
		m_planarGraph.coloredFaces[m_planarGraph.faces[vertex.first - 1]] = vertex.second;
	}
}

GraphColoring::PlanarGraph GraphColoring::GetPlanarGraph()
{
	return m_planarGraph;
}

GraphColoring::DualGraph GraphColoring::GetDualGraph()
{
	return m_dualGraph;
}
