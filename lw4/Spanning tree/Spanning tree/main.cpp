#include <vector>
#include "SpanningTree.h"
#include <iostream>
int main()
{
	std::vector<std::vector<double>> matrix = {
		{ 2, -1, -1, 0 },
		{ -1, 2, -1, 0 },
		{ -1, -1, 3, -1 },
		{ 0, 0, -1, 1 }
	};

	std::vector<std::vector<double>> matrix2 = {
		{ 1, 2, 3 },
		{ 0, 7, 4 },
		{ 5, 0, 3 },
	};

	std::vector<std::vector<double>> matr = CreateKirchhoffMatrix(matrix);
	matr = AlgebraicComplement(matrix);
	double countSpanningTree = CountSpanningTrees(matr);
	std::cout << "Count of spanning tree = " << countSpanningTree;
}

//for (int i = 0; i < n; ++i)
//{
//	int k = i;
//	for (int j = i + 1; j < n; ++j)
//		if (abs(matrix[j][i]) > abs(matrix[k][i]))
//			k = j;
//	if (abs(matrix[k][i]) < 1E-9)
//	{
//		countSpanningTree = 0;
//		break;
//	}
//	std::swap(matrix[i], matrix[k]);
//	if (i != k)
//		countSpanningTree = -countSpanningTree;
//	countSpanningTree *= matrix[i][i];
//	for (int j = i + 1; j < n; ++j)
//		matrix[i][j] /= matrix[i][i];
//	for (int j = 0; j < n; ++j)
//		if (j != i && abs(matrix[j][i]) > 1E-9)
//			for (int k = i + 1; k < n; ++k)
//				matrix[j][k] -= matrix[i][k] * matrix[j][i];
//}
