#include <algorithm>
#include <iostream>
#include <vector>
#include <boost/timer.hpp>

size_t CalculateTotalCost(const std::vector<std::vector<size_t>>& facilities, const std::vector<std::vector<size_t>>& locations, const std::vector<size_t>& assignment)
{
	size_t totalCost = 0;
	size_t n = facilities.size();

	for (size_t i = 0; i < n; i++)
	{
		for (size_t j = 0; j < n; j++)
		{
			size_t facility1 = assignment[i];
			size_t facility2 = assignment[j];
			size_t location1 = i;
			size_t location2 = j;
			totalCost += facilities[facility1][facility2] * locations[location1][location2];
		}
	}

	return totalCost;
}

struct Data
{
	std::vector<size_t>assignment;
	size_t totalCost;
};

Data CalculateMinAssignment(const std::vector<std::vector<size_t>>& facilities, const std::vector<std::vector<size_t>>& locations)
{
	size_t dim = facilities.size();

	std::vector<size_t> assignment(dim);
	for (size_t i = 0; i < dim; i++)
	{
		assignment[i] = i;
	}

	size_t minCost = CalculateTotalCost(facilities, locations, assignment);
	std::vector<size_t> minAssignment = assignment;

	while (next_permutation(assignment.begin(), assignment.end()))
	{
		size_t cost = CalculateTotalCost(facilities, locations, assignment);
		if (cost < minCost)
		{
			minCost = cost;
			minAssignment = assignment;
		}
	}

	return Data{ minAssignment, minCost };
}

int main()
{
	std::vector<std::vector<size_t>> facilities = {
		{ 0, 1, 1, 2 },
		{ 3, 0, 5, 8 },
		{ 13, 21, 0, 34 },
		{ 55, 89, 144, 0 }
	};

	std::vector<std::vector<size_t>> locations = {
		{ 0, 1, 10, 10 },
		{ 1, 0, 10, 10 },
		{ 10, 10, 0, 10 },
		{ 10, 10, 10, 0 }
	};

	boost::timer timer;
	timer.restart();

	Data minDataAssignment = CalculateMinAssignment(facilities, locations);
	
	double time = timer.elapsed();

	size_t dim = facilities.size();

	std::cout << "Facilities order: ";
	for (size_t i = 0; i < dim; i++)
	{
		std::cout << (minDataAssignment.assignment[i] + 1) << " ";
	}
	std::cout << std::endl;
	std::cout << "Total Cost: " << minDataAssignment.totalCost << std::endl;
	std::cout << "Time: " << time << std::endl;

	return 0;
}