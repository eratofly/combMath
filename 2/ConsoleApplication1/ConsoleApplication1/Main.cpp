#include "SCC.h"
#include <iostream>
#include <vector>

using namespace std;

int main()
{
	/*std::vector<std::vector<int>> g = {
		{1, 4},
		{1, 6},
		{2, 1},
		{2, 7},
		{3, 5},
		{3, 2},
		{3, 8},
		{4, 2},
		{4, 6},
		{4, 7},
		{5, 3},
		{5, 8},
		{6, 4},
		{6, 9},
		{8, 9},
		{8, 10},
		{9, 7},
		{10, 11},
		{11, 8},
		{12, 14},
		{12, 15},
		{14, 15}
	};*/

	/*std::vector<std::vector<int>> g = {
		{7, 1},
		{1, 4},
		{4, 7},
		{9, 7},
		{6, 9},
		{9, 3},
		{3, 6},
		{8, 6},
		{2, 8},
		{8, 5},
		{5, 2},
	};*/

	std::vector<std::vector<int>> g = {
		{ 1, 0 },
		{ 0, 2 },
		{ 4, 7 },
		{ 9, 7 },
		{ 6, 9 },
		{ 9, 3 },
		{ 3, 6 },
		{ 8, 6 },
		{ 2, 8 },
		{ 8, 5 },
		{ 5, 2 },
	};

	vector<vector<int>> result = FindStronglyConnectedComponents(g);
	/*for (auto i = 0; i < result.size(); ++i)
	{
		for (auto j = 0; j < result[i].size(); ++j)
		{
			cout << result[i][j] << " ";
		}
		cout << endl;
	}*/
}