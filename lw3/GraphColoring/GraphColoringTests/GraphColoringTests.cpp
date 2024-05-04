#define CATCH_CONFIG_MAIN
#include "../../../catch.hpp"
#include "../GraphColoring/GraphColoring.h"

//
// TEST_CASE("Get prime numbers with upper bound less than 2")
//{
//	GraphColoring::PlanarGraph planarGraph;
//	planarGraph.faces = {
//		{ 1, 3, 4 },
//		{ 1, 2, 3 },
//		{ 4, 3, 2, 1 }
//	};
//	GraphColoring::DualGraph expectedDualGraph;
//	expectedDualGraph.edges = {
//		std::make_pair(1, 2),
//		std::make_pair(1, 3),
//		std::make_pair(1, 3),
//		std::make_pair(2, 3),
//		std::make_pair(2, 3)
//	};
//	GraphColoring::DualGraph result = GraphColoring::ConvertPlanarToDualGraph(planarGraph);
//	CHECK(result.edges == expectedDualGraph.edges);
//}

//TEST_CASE("2")
//{
//	GraphColoring::PlanarGraph planarGraph;
//	planarGraph.faces = {
//		{ 1, 2, 6 },
//		{ 2, 3, 4, 5, 6 },
//		{ 6, 5, 4, 3, 2, 1 }
//	};
//	GraphColoring::DualGraph expectedDualGraph;
//	expectedDualGraph.coloredVertexes = {
//		{ 1, 1 },
//		{ 2, 2 },
//		{ 3, 3 },
//	};
//	GraphColoring::DualGraph dualGraph = GraphColoring::ConvertPlanarToDualGraph(planarGraph);
//	GraphColoring::DualGraph result = GraphColoring::ColorGraph(dualGraph);
//	for (int i = 1, j = 1; i <= dualGraph.coloredVertexes.size(), j <= result.coloredVertexes.size(); i++, j++)
//	{
//		CHECK(result.coloredVertexes[j] == expectedDualGraph.coloredVertexes[i]);
//	}
//}
//}

// TEST_CASE("3")
//{
//	GraphColoring::PlanarGraph planarGraph;
//	planarGraph.faces = {
//		{ 1, 5, 13, 15, 10 },
//		{1, 4, 5},
//		{4, 3, 5},
//		{ 4, 9, 3 },
//		{ 13, 5, 3, 11 },
//		{1, 10, 15, 13, 11, 3, 9, 4}
//	};
//	GraphColoring::DualGraph expectedDualGraph;
// expectedDualGraph.edges = {
/*	{
		std::make_pair(1, 2),
		std::make_pair(1, 5),
		std::make_pair(1, 6),
		std::make_pair(1, 6),
		std::make_pair(1, 6),
	},
	{
		std::make_pair(2, 3),
		std::make_pair(2, 6),
	},
	{
		std::make_pair(3, 4),
		std::make_pair(3, 5),
	},
	{
		std::make_pair(4, 6),
		std::make_pair(4, 6),
	},
	{
		std::make_pair(5, 6),
		std::make_pair(5, 6),
	},*/
/*std::make_pair(1, 2),
std::make_pair(1, 5),
std::make_pair(1, 6),
std::make_pair(1, 6),
std::make_pair(1, 6),
std::make_pair(2, 3),
std::make_pair(2, 6),
std::make_pair(3, 4),
std::make_pair(3, 5),
std::make_pair(4, 6),
std::make_pair(4, 6),
std::make_pair(5, 6),
std::make_pair(5, 6),*/
//};

/*expectedDualGraph.coloredVertexes = {
	{1, 1}
}
GraphColoring::DualGraph result = GraphColoring::ConvertPlanarToDualGraph(planarGraph);
CHECK(result.edges == expectedDualGraph.edges);	*/
//}
//
//TEST_CASE("4")
//{
//	GraphColoring::PlanarGraph planarGraph;
//	planarGraph.faces = {
//		{ 1, 2, 3 },
//		{ 3, 2, 1 },
//	};
//	GraphColoring::DualGraph expectedDualGraph;
//	expectedDualGraph.coloredVertexes = {
//		{ 1, 1 },
//		{ 2, 2 }
//	};
//	GraphColoring::DualGraph dualGraph = GraphColoring::ConvertPlanarToDualGraph(planarGraph);
//	GraphColoring::DualGraph result = GraphColoring::ColorGraph(dualGraph);
//	CHECK(result.coloredVertexes == expectedDualGraph.coloredVertexes);
//}
//
//TEST_CASE("5")
//{
//	GraphColoring::PlanarGraph planarGraph;
//	planarGraph.faces = {
//		{ 1, 4, 5 },
//		{ 1, 3, 4 },
//		{ 1, 2, 3 },
//		{ 3, 6, 4 },
//		{ 5, 4, 6, 3, 2, 1 },
//	};
//	GraphColoring::DualGraph expectedDualGraph;
//	expectedDualGraph.coloredVertexes = {
//		{ 1, 1 },
//		{ 2, 2 },
//		{ 3, 1 },
//		{ 4, 1 },
//		{ 5, 5 },
//	};
//	GraphColoring::DualGraph dualGraph = GraphColoring::ConvertPlanarToDualGraph(planarGraph);
//	GraphColoring::DualGraph result = GraphColoring::ColorGraph(dualGraph);
//	for (int i = 1, j = 1; i <= dualGraph.coloredVertexes.size(), j <= result.coloredVertexes.size(); i++, j++)
//	{
//		CHECK(result.coloredVertexes[j] == expectedDualGraph.coloredVertexes[i]);
//	}
//	// CHECK(result.coloredVertexes == expectedDualGraph.coloredVertexes);
//}

TEST_CASE("6")
{
	GraphColoring::PlanarGraph planarGraph;
	planarGraph.faces = {
		{ 1, 4, 5 },
		{ 1, 3, 4 },
		{ 1, 2, 3 },
		{ 3, 6, 4 },
		{ 1, 5, 4, 6, 3, 2 },
	};
	GraphColoring::DualGraph expectedDualGraph;
	expectedDualGraph.coloredVertexes = {
		{ 1, 1 },
		{ 2, 2 },
		{ 3, 1 },
		{ 4, 1 },
		{ 5, 5 },
	};
	GraphColoring::DualGraph dualGraph = GraphColoring::ConvertPlanarToDualGraph(planarGraph);
	GraphColoring::DualGraph result = GraphColoring::ColorGraph(dualGraph);
	for (int i = 1, j = 1; i <= dualGraph.coloredVertexes.size(), j <= result.coloredVertexes.size(); i++, j++)
	{
		CHECK(result.coloredVertexes[j] == expectedDualGraph.coloredVertexes[i]);
	}
	// CHECK(result.coloredVertexes == expectedDualGraph.coloredVertexes);
}

