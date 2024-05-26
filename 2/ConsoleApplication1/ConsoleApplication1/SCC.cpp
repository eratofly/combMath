#include "SCC.h"
#include <fstream>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

void dfs1(int v, vector<vector<int>> g, vector<char>& used, vector<int>& order)
{
	used[v] = true;
	for (int i = 0; i < g[v].size(); ++i)
		if (!used[g[v][i]])
			dfs1(g[v][i], g, used, order);
	order.push_back(v);
}

void dfs2(int v, vector<vector<int>> gt, vector<char>& used, vector<int>& component)
{
	used[v] = true;
	component.push_back(v);
	for (size_t i = 0; i < gt[v].size(); ++i)
		if (!used[gt[v][i]])
			dfs2(gt[v][i], gt, used, component);
}

vector<vector<int>> transposingGraph(vector<vector<int>>& G)
{
	int n = G.size();
	vector<vector<int>> GT(n);
	for (int i = 0; i < n; i++)
	{
		GT[i].push_back(G[i][1]);
		GT[i].push_back(G[i][0]);
	}
	return GT;
}

vector<vector<int>> FindStronglyConnectedComponents(vector<vector<int>>& g)
{
	vector<char> used;
	vector<int> order, component;
	vector<vector<int>> result{};

	int n = g.size();

	used.assign(n, false);
	for (int i = 0; i < n; ++i)
		if (!used[i])
			dfs1(i, g, used, order);

	vector<vector<int>> gt = transposingGraph(g);

	used.assign(n, false);

	for (int i = 0; i < n; ++i)
	{
		int v = order[n - 1 - i]; // в прямом порядке, поменять порядок
		if (!used[v])
		{
			dfs2(v, gt, used, component);
			result.push_back(component);
			for (int j = 0; j < component.size(); ++j)
				cout << component[j] << " ";
			cout << endl;
			component.clear();
		}
	}

	return result;
}
