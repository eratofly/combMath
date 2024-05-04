#define CATCH_CONFIG_MAIN
#include "../../../catch.hpp"
#include "../GraphColoring/GraphColoring.h"

TEST_CASE("1")
{
	GraphColoring::PlanarGraph planarGraph;
	planarGraph.faces = {
		{ 1, 4, 5 },
		{ 1, 3, 4 },
		{ 1, 2, 3 },
		{ 3, 6, 4 },
		{ 1, 5, 4, 6, 3, 2 },
	};
	auto gc = new GraphColoring(planarGraph);

	GraphColoring::PlanarGraph expectedPlanarGraph;
	expectedPlanarGraph.coloredFaces = {
		{
			{ 1, 4, 5 },
			1,
		},
		{
			{ 1, 3, 4 },
			2,
		},
		{
			{ 1, 2, 3 },
			1,
		},
		{
			{ 3, 6, 4 },
			1,
		},
		{
			{ 1, 5, 4, 6, 3, 2 },
			2,
		},
	};

	gc->ConvertPlanarToDualGraph();
	gc->ColorGraph();
	gc->ColorPlanarGraph();
	GraphColoring::PlanarGraph result = gc->GetPlanarGraph();

	CHECK(result.coloredFaces == expectedPlanarGraph.coloredFaces);
}
TEST_CASE("2")
{
	GraphColoring::PlanarGraph planarGraph;
	planarGraph.faces = {
		{ 1, 4, 5 },
		{ 1, 3, 4 },
		{ 1, 2, 3 },
		{ 3, 6, 4 },
		{ 5, 6, 7 },
		{ 1, 2, 8, 7, 5 },
		{ 2, 8, 7, 6, 3 },
	};
	auto gc = new GraphColoring(planarGraph);

	GraphColoring::PlanarGraph expectedPlanarGraph;
	expectedPlanarGraph.coloredFaces = {
		{
			{ 1, 4, 5 },
			1,
		},
		{
			{ 1, 3, 4 },
			2,
		},
		{
			{ 1, 2, 3 },
			1,
		},
		{
			{ 3, 6, 4 },
			1,
		},
		{
			{ 5, 6, 7 },
			1,
		},
		{
			{ 1, 2, 8, 7, 5 },
			2,
		},
		{
			{ 2, 8, 7, 6, 3 },
			3,
		},
	};

	gc->ConvertPlanarToDualGraph();
	gc->ColorGraph();
	gc->ColorPlanarGraph();
	GraphColoring::PlanarGraph result = gc->GetPlanarGraph();

	CHECK(result.coloredFaces == expectedPlanarGraph.coloredFaces);
}

TEST_CASE("3")
{
	GraphColoring::PlanarGraph planarGraph;
	planarGraph.faces = {
		{ 1, 2, 3 },
		{ 1, 3, 2 },
	};
	auto gc = new GraphColoring(planarGraph);

	GraphColoring::PlanarGraph expectedPlanarGraph;
	expectedPlanarGraph.coloredFaces = {
		{
			{ 1, 2, 3 },
			1,
		},
		{
			{ 1, 3, 2 },
			2,
		},
	};

	gc->ConvertPlanarToDualGraph();
	gc->ColorGraph();
	gc->ColorPlanarGraph();
	GraphColoring::PlanarGraph result = gc->GetPlanarGraph();

	CHECK(result.coloredFaces == expectedPlanarGraph.coloredFaces);
}

