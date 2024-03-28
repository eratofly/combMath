#include <fstream>
#include <vector>
#include <iostream>

using namespace std;

vector<vector<int>> graph, graphTransposed;
vector<bool> used;
vector<int> order, component;

bool OpenFile(ifstream& inputFile, string filePath)
{
	inputFile.open(filePath);

	if (!inputFile.is_open())
	{
		cout << "Failed to open file for reading \n";

		return false;
	}

	return true;
}

void DepthFirstSearch(int& vertex)
{
	used[vertex] = true;
	for (size_t i = 0; i < graph[vertex].size(); i++)
	{
		if (!used[graph[vertex][i]])
		{
			DepthFirstSearch(graph[vertex][i]);
		}
	}

	order.push_back(vertex);
}

void DepthFirstSearchInTransposedGraph(int& vertex)
{
	used[vertex] = true;
	component.push_back(vertex);
	for (size_t i = 0; i < graphTransposed[vertex].size(); i++)
	{
		if (!used[graphTransposed[vertex][i]])
		{
			DepthFirstSearchInTransposedGraph(graphTransposed[vertex][i]);
		}
	}
}

void FindStrongComponents(istream& inputFile)
{
	size_t vertexesCount;
	int fromVertex, toVertex;

	inputFile >> vertexesCount;
	graph.assign(vertexesCount, {});
	graphTransposed.assign(vertexesCount, {});
	order = {};
	component = {};
	while ((inputFile >> fromVertex) && (inputFile >> toVertex))
	{
		fromVertex--;
		toVertex--;
		graph[fromVertex].push_back(toVertex);
		graphTransposed[toVertex].push_back(fromVertex);
	}

	used.assign(vertexesCount, false);
	for (int vertex = 0; vertex < vertexesCount; vertex++)
	{
		if (!used[vertex])
		{
			DepthFirstSearch(vertex);
		}
	}

	used.assign(vertexesCount, false);
	for (int i = 0; i < vertexesCount; i++)
	{
		int vertex = order[vertexesCount - 1 - i];
		if (!used[vertex])
		{
			DepthFirstSearchInTransposedGraph(vertex);
			for (auto i = 0; i < component.size(); i++)
			{
				cout << component[i] + 1 << " ";
			}
			cout << endl;
			component.clear();
		}
	}
}

void FindStrongComponentsFromFile(string const& fileName)
{
	ifstream inputFile;
	if (OpenFile(inputFile, fileName))
	{
		FindStrongComponents(inputFile);
	}
}