#include "../scc/SCC.h"
#include "../scc/CoutBufferFixture.h"
#define CATCH_CONFIG_MAIN
#include "../../../catch.hpp"
#include <iostream>


TEST_CASE("an empty input")
{
	std::istringstream input("");
	std::vector<std::vector<int>> result = FindStrongComponents(input);
	std::vector<std::vector<int>> expected = {};
	CHECK(result == expected);
};

TEST_CASE("1 vertex")
{
	std::istringstream input("1");
	std::vector<std::vector<int>> result = FindStrongComponents(input);
	std::vector<std::vector<int>> expected = { { 1 } };
	CHECK(result == expected);
};

TEST_CASE("test from presentation")
{
	std::istringstream input("14\n1 4\n1 6\n2 1\n4 6\n6 4\n4 7\n2 7\n6 9\n9 7\n3 2\n3 5\n5 3\n3 8\n5 8\n8 10\n10 11\n11 8\n8 9\n4 2\n13 14\n12 14\n12 13");
	std::vector<std::vector<int>> result = FindStrongComponents(input);
	std::vector<std::vector<int>> expected = {
		{ 12 },
		{ 13 },
		{ 14 },
		{ 3, 5 },
		{ 8, 11, 10 },
		{ 1, 2, 4, 6 },
		{ 9 },
		{ 7 }
	};
	CHECK(result == expected);
};

TEST_CASE("easy test")
{
	std::istringstream input("9\n7 1\n1 4\n4 7\n9 7\n6 9\n9 3\n3 6\n8 6\n2 8\n8 5\n5 2");
	std::vector<std::vector<int>> result = FindStrongComponents(input);
	std::vector<std::vector<int>> expected = {
		{ 2, 5, 8 },
		{ 6, 3, 9 },
		{ 1, 7, 4 }
	};
	CHECK(result == expected);
};



