#include "pch.h"
#include <vector>
#include "CppUnitTest.h"
#include "../QuadraticAssignmentProblem/QuadraticAssignmentProblem.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace QuadraticAssignmentsProblemTests
{
	TEST_CLASS(QuadraticAssignmentsProblemTests)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{
			std::vector<std::vector<size_t>> facilities = 
			{
				{ 0, 1, 6, 4 },
				{ 1, 0, 9, 5 },
				{ 6, 9, 0, 3 },
				{ 4, 5, 3, 0 } 
			};

			std::vector<std::vector<size_t>> locations = 
			{
				{ 0, 1, 6, 4 },
				{ 1, 0, 9, 5 },
				{ 6, 9, 0, 3 },
				{ 4, 5, 3, 0 } 
			};

			Data assignmentData = CalculateMinAssignment(facilities, locations);
			std::vector<size_t> expectedAssignments = {2, 1, 0, 3};
			size_t expectedTotalCost = 206;

			Assert::IsTrue(assignmentData.assignment == expectedAssignments, L"unexpected assignmen");
			Assert::AreEqual(assignmentData.totalCost, expectedTotalCost);
		}

		TEST_METHOD(TestMethod2)
		{
			std::vector<std::vector<size_t>> facilities = {
				{ 0, 1, 1, 1 },
				{ 1, 0, 1, 1 },
				{ 1, 1, 0, 1 },
				{ 1, 1, 1, 0 }
			};

			std::vector<std::vector<size_t>> locations = {
				{ 0, 1, 1, 1 },
				{ 1, 0, 1, 1 },
				{ 1, 1, 0, 1 },
				{ 1, 1, 1, 0 }
			};

			Data assignmentData = CalculateMinAssignment(facilities, locations);
			std::vector<size_t> expectedAssignments = { 0, 1, 2, 3 };
			size_t expectedTotalCost = 12;

			Assert::IsTrue(assignmentData.assignment == expectedAssignments, L"unexpected assignmen");
			Assert::AreEqual(assignmentData.totalCost, expectedTotalCost);
		}

		TEST_METHOD(TestMethod3)
		{
			std::vector<std::vector<size_t>> facilities = {
				{ 0, 5, 20, 30 },
				{ 5, 0, 10, 15 },
				{ 20, 10, 0, 200 },
				{ 30, 15, 200, 0 }
			};

			std::vector<std::vector<size_t>> locations = {
				{ 0, 10, 15, 15 },
				{ 10, 0, 2, 50 },
				{ 15, 2, 0, 20 },
				{ 15, 50, 20, 0 }
			};

			Data assignmentData = CalculateMinAssignment(facilities, locations);
			std::vector<size_t> expectedAssignments = { 0, 2, 3, 1 };
			size_t expectedTotalCost = 3850;

			Assert::IsTrue(assignmentData.assignment == expectedAssignments, L"unexpected assignment");
			Assert::AreEqual(assignmentData.totalCost, expectedTotalCost);
		}

		TEST_METHOD(TestMethod4)
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

			Data assignmentData = CalculateMinAssignment(facilities, locations);
			std::vector<size_t> expectedAssignments = { 2, 3, 0, 1 };
			size_t expectedTotalCost = 2158;

			Assert::IsTrue(assignmentData.assignment == expectedAssignments, L"unexpected assignmen");
			Assert::AreEqual(assignmentData.totalCost, expectedTotalCost);
		}
	};
}
