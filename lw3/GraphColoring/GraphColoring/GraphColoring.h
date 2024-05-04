#pragma once
#include <map>
#include <vector>

class GraphColoring
{
public:
	struct PlanarGraph
	{
		std::vector<std::vector<int>> faces;
		std::vector<std::vector<std::pair<int, int>>> edges;
		std::map<std::vector<int>, int> coloredFaces;
	};

	struct DualGraph
	{
		std::map<int, std::vector<std::pair<int, int>>> vertexes;
		std::vector<std::pair<int, int>> edges;
		std::map<int, int> coloredVertexes;
	};

	GraphColoring(PlanarGraph planarGraph);

	void ConvertPlanarToDualGraph();
	void ColorGraph();
	void ColorPlanarGraph();

	PlanarGraph GetPlanarGraph();
	DualGraph GetDualGraph();

private:
	PlanarGraph m_planarGraph;
	DualGraph m_dualGraph;
};
