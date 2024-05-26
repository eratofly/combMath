#define CATCH_CONFIG_MAIN
#include "../../../catch.hpp"

#include <vector>
#include "../Spanning tree/SpanningTree.h"

TEST_CASE("Test with 4x4")
{
	std::vector<std::vector<double>> adjacencyMatrix = {
		{ 0, 1, 1, 0 },
		{ 1, 0, 1, 0 },
		{ 1, 1, 0, 1 },
		{ 0, 0, 1, 0 }
	};
	
	std::vector<std::vector<double>> kirchhoffMatrix = CreateKirchhoffMatrix(adjacencyMatrix);
	std::vector<std::vector<double>> matr = AlgebraicComplement(kirchhoffMatrix);
	double result = FindDet(matr);

	double expected = 3.0;

	REQUIRE(result == expected);
}

TEST_CASE("Test with hard 4x4")
{
	std::vector<std::vector<double>> adjacencyMatrix = {
		{ 0, 1, 1, 0 },
		{ 1, 0, 1, 1 },
		{ 1, 1, 0, 1 },
		{ 0, 1, 1, 0 }
	};

	std::vector<std::vector<double>> kirchhoffMatrix = CreateKirchhoffMatrix(adjacencyMatrix);
	std::vector<std::vector<double>> matr = AlgebraicComplement(kirchhoffMatrix);
	double result = FindDet(matr);
	double expected = 8;

	REQUIRE(result == expected);
}

TEST_CASE("Test with 5x5")
{
	std::vector<std::vector<double>> adjacencyMatrix = {
		{ 0, 1, 1, 0, 1 },
		{ 1, 0, 1, 1, 0 },
		{ 1, 1, 0, 1, 1 },
		{ 0, 1, 1, 0, 0 },
		{ 1, 0, 1, 0, 0 }
	};

	std::vector<std::vector<double>> kirchhoffMatrix = CreateKirchhoffMatrix(adjacencyMatrix);
	std::vector<std::vector<double>> matr = AlgebraicComplement(kirchhoffMatrix);
	double result = FindDet(matr);

	double expected = 21;

	REQUIRE(result == expected);
}
