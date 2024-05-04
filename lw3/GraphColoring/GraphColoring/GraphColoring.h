#pragma once
#include <vector>
#include <map>

//struct PlanarGraph
//{
//	//std::vector<int> vertexes;
//	std::vector<std::vector<int>> faces;
//	std::vector<std::vector<std::pair<int, int>>> edges; //пока непонятно нужно оно или нет
//};
//
//struct DualGraph
//{
//	std::map <int, std::vector<std::pair<int, int>>> vertexes;
//	std::vector<std::pair<int, int>> edges; // пока непонятно нужно оно или нет
//	std::map<int, int> coloredVertexes;
//};

//сделать приватный метод соотношения грани планарного графа с вершиной двойтсвенного графа через map  

class GraphColoring
{

public:
	struct PlanarGraph
	{
		// std::vector<int> vertexes;
		std::vector<std::vector<int>> faces;
		std::vector<std::vector<std::pair<int, int>>> edges; // пока непонятно нужно оно или нет
	};

	struct DualGraph
	{
		std::map<int, std::vector<std::pair<int, int>>> vertexes;
		std::vector<std::pair<int, int>> edges; // пока непонятно нужно оно или нет
		std::map<int, int> coloredVertexes;
	};
	static DualGraph ConvertPlanarToDualGraph(PlanarGraph planarGraph);
	static DualGraph ColorGraph(DualGraph& dualGraph);
	PlanarGraph ConvertDualToPlanarGraph(DualGraph dualGraph);

private:
	//переменные структур
	PlanarGraph planaGraph;
};
