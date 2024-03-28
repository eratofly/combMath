#include <fstream>
#include <vector>
#include <iostream>

using namespace std;

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

void DepthFirstSearch(int& vertex, vector<vector<int>> graph, vector<bool>& used, vector<int>& order)
{
	used[vertex] = true;
	for (size_t i = 0; i < graph[vertex].size(); i++)
	{
		if (!used[graph[vertex][i]])
		{
			DepthFirstSearch(graph[vertex][i], graph, used, order);
		}
	}

	order.push_back(vertex);
}

void DepthFirstSearchInTransposedGraph(int& vertex, vector<vector<int>> graphTransposed, vector<bool>& used, vector<int>& component)
{
	used[vertex] = true;
	component.push_back(vertex);
	for (size_t i = 0; i < graphTransposed[vertex].size(); i++)	
	{
		if (!used[graphTransposed[vertex][i]])
		{
			DepthFirstSearchInTransposedGraph(graphTransposed[vertex][i], graphTransposed, used, component);
		}
	}
}

vector<vector<int>> FindStrongComponents(istream& inputFile)
{
	vector<vector<int>> graph{}, graphTransposed{};
	vector<bool> used;
	vector<int> order, component;
	vector<vector<int>> result;
	
	size_t vertexesCount;
	int fromVertex, toVertex;

	if (!(inputFile >> vertexesCount))
	{
		return {};
	}
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
			DepthFirstSearch(vertex, graph, used, order);
		}
	}

	used.assign(vertexesCount, false);
	for (int i = 0; i < vertexesCount; i++)
	{
		int vertex = order[vertexesCount - 1 - i];
		if (!used[vertex])
		{
			DepthFirstSearchInTransposedGraph(vertex, graphTransposed, used, component);
			for (auto i = 0; i < component.size(); i++)
			{
				component[i] += 1;
			}
			result.push_back(component);
			component.clear();
		}
	}
	return result;
}

void FindStrongComponentsFromFile(string const& fileName)
{
	ifstream inputFile;
	if (OpenFile(inputFile, fileName))
	{
		FindStrongComponents(inputFile);
	}
}