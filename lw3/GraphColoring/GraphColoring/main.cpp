int main()
{
	return 0;
}
//
//#include "GraphColoring.h"
//#include <iostream>
//
//DualGraph GraphColoring::ConvertPlanarToDualGraph(PlanarGraph planarGraph)
//{
//	DualGraph dualGraph;
//	dualGraph.vertexes = {};
//	dualGraph.edges = {};
//	auto n = planarGraph.faces.size();
//	std::vector<std::vector<std::pair<int, int>>> t(n);
//	planarGraph.edges = t;
//	// i - итерироваться по face, чтобы менять грани
//	// j - итерироваться по вршинам i-ой грани
//	// k - итерироватся по внешней грани
//	// std::vector<int> externalFace = planarGraph.faces[n - 1];
//	// auto externalFaceSize = externalFace.size();
//	// for (auto i = 0; i < n; i++)
//	//{
//	//	for (auto j = 0; j < planarGraph.faces[i].size() - 1; j++)
//	//	{
//	//		if ((planarGraph.faces[i][0] == externalFace[externalFaceSize - 1]) && (planarGraph.faces[i][planarGraph.faces[i].size() - 1] == (externalFace[0])))
//	//		{
//	//			dualGraph.edges.push_back({ planarGraph.faces[i][0], planarGraph.faces[i][planarGraph.faces[i].size() - 1] });
//	//		}
//	//		for (auto k = externalFace.size() - 1; k > 0; k--)
//	//		{
//	//			if ((planarGraph.faces[i][j] == externalFace[k - 1]) && ((planarGraph.faces[i][j + 1] == externalFace[k])))
//	//			{
//	//				dualGraph.edges.push_back({ planarGraph.faces[i][j], planarGraph.faces[i][j + 1] });
//	//			}
//	//		}
//	//	}
//	//}
//
//	//
//	for (int i = 0; i < n; i++)
//	{
//		for (int j = 0; j < planarGraph.faces[i].size() - 1; j++)
//		{
//			planarGraph.edges[i].push_back(std::make_pair(planarGraph.faces[i][j], planarGraph.faces[i][j + 1]));
//			std::cout << planarGraph.faces[i][j] << " " << planarGraph.faces[i][j + 1] << std::endl;
//		}
//		planarGraph.edges[i].push_back(std::make_pair(planarGraph.faces[i][planarGraph.faces[i].size() - 1], planarGraph.faces[i][0]));
//		std::cout << planarGraph.faces[i][planarGraph.faces[i].size() - 1] << " " << planarGraph.faces[i][0] << std::endl;
//		std::cout << std::endl;
//	}
//
//	// инициализирую вершины двойственного графа по граня планарного графа
//	for (int i = 0; i < n; i++)
//	{
//		dualGraph.vertexes[i + 1] = planarGraph.edges[i];
//	}
//
//	// ищу одинаковые рёбра у граней
//	// for (int i = 0; i < planarGraph.edges.size() - 1; i++)
//	//{
//	//	for (int j = i + 1; j < planarGraph.edges.size(); j++)
//	//	{
//	//		for (int k = 0; k < planarGraph.edges[i].size(); k++)
//	//		{
//	//			for (int l = 0; l < planarGraph.edges[j].size(); l++)
//	//			{
//	//				if (planarGraph.edges[i][k] == planarGraph.edges[j][l] || (planarGraph.edges[i][k].first == planarGraph.edges[j][l].second && planarGraph.edges[i][k].second == planarGraph.edges[j][l].first))
//	//				{
//	//					if (dualGraph.vertexes[i][planarGraph.f[i] == )
//	//				}
//	//			}
//	//		}
//
//	//
//	//	}
//	//}
//
//	// буду брать по 2 вершины двойственного графа и искать одинаковые рёбра у ни
//
//	for (int i = 1; i <= dualGraph.vertexes.size() - 1; i++)
//	{
//		for (int j = i + 1; j <= dualGraph.vertexes.size(); j++)
//		{
//			for (int k = 0; k < dualGraph.vertexes[i].size(); k++)
//			{
//				for (int l = 0; l < dualGraph.vertexes[j].size(); l++)
//				// std::cout << dualGraph.vertexes[i][k].first << std::endl;
//				{
//					if (dualGraph.vertexes[i][k] == dualGraph.vertexes[j][l] || (dualGraph.vertexes[i][k].first == dualGraph.vertexes[j][l].second && dualGraph.vertexes[i][k].second == dualGraph.vertexes[j][l].first))
//					{
//						dualGraph.edges.push_back(std::make_pair(i, j));
//					}
//				}
//			}
//		}
//	}
//
//	// for (int i = 0; i < n - 1; i++)
//	//{
//	//	for (int j = i + 1; j < n; j++)
//	//	{
//	//		for (int k = 0; k < planarGraph.edges[i].size() - 1; k++)
//	//		{
//	//			for (int l = 0; l < planarGraph.edges[j].size() - 1; l++)
//	//			{
//	//				if (planarGraph.edges[i][k] == planarGraph.edges[j][l])
//	//				{
//	//					dualGraph.edges[i].push_back(planarGraph.edges[i][k]);
//	//				}
//	//			}
//	//		}
//	//	}
//	// }
//
//	// for (int i = 0; i < n - 1; i++)
//	//{
//	//	for (int j = i + 1; j < n; j++)
//	//	{
//	//		for (int k = 0; k < planarGraph.faces[i].size() - 1; k++)
//	//		{
//	//			for (int l = 0; l < planarGraph.faces[j].size() - 1; l++)
//	//			{
//	//				if ((planarGraph.faces[i][k] == planarGraph.faces[j][l + 1]))
//	//				{
//	//					if ((planarGraph.faces[i][k + 1] == planarGraph.faces[j][l + 1]))
//	//					{
//	//						dualGraph.edges.push_back({ planarGraph.faces[i][k], planarGraph.faces[i][k + 1] });
//	//						if ((k == 0 && planarGraph.faces[i][0] == planarGraph.faces[j][0]) && (planarGraph.faces[i][planarGraph.faces[i].size() - 1] == planarGraph.faces[j][planarGraph.faces[j].size() - 1]))
//	//						{
//	//							dualGraph.edges.push_back({ planarGraph.faces[i][0], planarGraph.faces[i][planarGraph.faces[i].size() - 1] });
//	//						}
//	//						break;
//	//					}
//	//				}
//	//				if (k == 0 && (planarGraph.faces[i][0] == planarGraph.faces[j][0]) && (planarGraph.faces[i][planarGraph.faces[i].size() - 1] == planarGraph.faces[j][planarGraph.faces[j].size() - 1]))
//	//				{
//	//						if ((planarGraph.faces[i][planarGraph.faces[i].size() - 1] == planarGraph.faces[j][planarGraph.faces[j].size() - 1]))
//	//						{
//	//							dualGraph.edges.push_back({ planarGraph.faces[i][0], planarGraph.faces[i][planarGraph.faces[i].size() - 1] });
//	//							break;
//	//						}
//	//				}
//	//				if (k == 0 && (planarGraph.faces[i][0] == planarGraph.faces[j][0]))
//	//				{
//	//					if ((planarGraph.faces[i][k + 1] == planarGraph.faces[j][planarGraph.faces[j].size() - 1]))
//	//					{
//	//						dualGraph.edges.push_back({ planarGraph.faces[i][0], planarGraph.faces[i][k + 1] });
//	//						break;
//	//					}
//	//					if ((planarGraph.faces[i][planarGraph.faces[i].size() - 1] == planarGraph.faces[j][l + 1]))
//	//					{
//	//						dualGraph.edges.push_back({ planarGraph.faces[i][0], planarGraph.faces[j][l + 1] });
//	//						break;
//	//					}
//	//
//	//				}
//	//				if (l == 0 && (planarGraph.faces[i][k] == planarGraph.faces[j][0]))
//	//				{
//	//					if ((planarGraph.faces[i][k + 1] == planarGraph.faces[j][planarGraph.faces[j].size() - 1]))
//	//					{
//	//						dualGraph.edges.push_back({ planarGraph.faces[j][0], planarGraph.faces[i][k + 1] });
//	//						break;
//	//					}
//	//				}
//	//			}
//	//		}
//	//	}
//	// }
//
//	/*for (auto i = 0; i < n - 1; i++)
//	{
//		for (auto j = i + 1; j < n; j++)
//		{
//			for (int k = 0; k > planarGraph.faces[i].size() - 1; k++)
//			{
//				for (int l = 0; l > planarGraph.faces[j].size() - 1; l++)
//				{
//					if ((planarGraph.faces[i][k] == planarGraph.faces[j][l]))
//					{
//						if ((planarGraph.faces[i][k + 1] == planarGraph.faces[j][l + 1]) ||
//							(k == 0 && (planarGraph.faces[i][planarGraph.faces[i].size() - 1] == planarGraph.faces[j][planarGraph.faces[j].size() - 1])) ||
//							(l == 0 && (planarGraph.faces[i][k + 1] == planarGraph.faces[j][planarGraph.faces[j].size() - 1])))
//						{
//							dualGraph.edges.push_back({ planarGraph.faces[i][j], planarGraph.faces[i][j + 1] });
//							break;
//						}
//					}
//				}
//			}
//			break;
//		}
//	}*/
//
//	return dualGraph;
//}
