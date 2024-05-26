#include "pch.h"
#include "CppUnitTest.h"
#include <vector>
#include "../Backpack/Backpack.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace KnapsackTest
{
	TEST_CLASS(KnapsackTest)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{
			int n = 5;
			int maxWeight = 100;
			std::vector<size_t> itemsWeight = { 80, 50, 50, 50, 50 };
			std::vector<size_t> itemsValue = { 1000, 550, 550, 550, 550 };
			std::vector<size_t> itemsInKnapsack(n, 1);
			std::vector<size_t> expected = { 2, 3 };
			std::vector<size_t> result = GetValuableItemsInKnapsack(itemsInKnapsack, itemsWeight, itemsValue, maxWeight); 
			for (unsigned int i = 0; i < expected.size(); ++i)
				Assert::AreEqual(expected[i], result[i]);
		}

		TEST_METHOD(TestMethod2)
		{
			int n = 2;
			int maxWeight = 10;
			std::vector<size_t> itemsWeight = { 10, 9 };
			std::vector<size_t> itemsValue = { 100, 80 };
			std::vector<size_t> itemsInKnapsack(n, 1);
			std::vector<size_t> expected = { 1 };
			std::vector<size_t> result = GetValuableItemsInKnapsack(itemsInKnapsack, itemsWeight, itemsValue, maxWeight);
			for (unsigned int i = 0; i < expected.size(); ++i)
				Assert::AreEqual(expected[i], result[i]);
		}

		TEST_METHOD(TestMethod3)
		{
			int n = 6;
			int maxWeight = 100;
			std::vector<size_t> itemsWeight = { 80, 50, 50, 50, 50, 100 };
			std::vector<size_t> itemsValue = { 1000, 549, 549, 549, 549, 1100 };
			std::vector<size_t> itemsInKnapsack(n, 1);
			std::vector<size_t> expected = { 6 };
			std::vector<size_t> result = GetValuableItemsInKnapsack(itemsInKnapsack, itemsWeight, itemsValue, maxWeight);
			for (unsigned int i = 0; i < expected.size(); ++i)
				Assert::AreEqual(expected[i], result[i]);
		}

		TEST_METHOD(TestMethod4)
		{
			int n = 24;
			int maxWeight = 6404180;
			std::vector<size_t> itemsWeight = { 
			382745,
				799601,
				909247,
				729069,
				467902,
				44328,
				34610,
				698150,
				823460,
				903959,
				853665,
				551830,
				610856,
				670702,
				488960,
				951111,
				323046,
				446298,
				931161,
				31385,
				496951,
				264724,
				224916,
				169684,
			};
			std::vector<size_t> itemsValue = { 
				825594,
				1677009,
				1676628,
				1523970,
				943972,
				97426,
				69666,
				1296457,
				1679693,
				1902996,
				1844992,
				1049289,
				1252836,
				1319836,
				953277,
				2067538,
				675367,
				853655,
				1826027,
				65731,
				901489,
				577243,
				466257,
				369261
			};
			std::vector<size_t> itemsInKnapsack(n, 1);
			std::vector<size_t> expected = { 1, 2, 4, 5, 6, 10, 11, 13, 16, 22, 23, 24 };
			std::vector<size_t> result = GetValuableItemsInKnapsack(itemsInKnapsack, itemsWeight, itemsValue, maxWeight);
			for (unsigned int i = 0; i < expected.size(); ++i)
				Assert::AreEqual(expected[i], result[i]);
		}

		TEST_METHOD(AgainstGreedyAlgorithm)
		{
			int n = 4;
			int maxWeight = 100;
			std::vector<size_t> itemsWeight = { 60, 40, 50, 50 };
			std::vector<size_t> itemsValue = { 100, 20, 75, 75 };
			std::vector<size_t> itemsInKnapsack(n, 1);
			std::vector<size_t> expected = { 3, 4 };
			std::vector<size_t> result = GetValuableItemsInKnapsack(itemsInKnapsack, itemsWeight, itemsValue, maxWeight);
			for (unsigned int i = 0; i < expected.size(); ++i)
				Assert::AreEqual(expected[i], result[i]);
		}
	};
}
