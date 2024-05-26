#include <algorithm>
#include <iostream>
#include <limits>
#include <vector>

bool DecItemsInKnapsack(std::vector<size_t>& items)
{
	for (int i = items.size() - 1; i >= 0; i--)
	{
		if (items[i] == 1)
		{
			items[i] = 0;
			for (int j = i + 1; j < items.size(); j++)
			{
 				items[j] = 1;
			}
			return 1;
		}
	}
	int count = 0;
	for (int i = 0; i < items.size(); i++)
	{
		if (items[i] == 0)
		{
			count++;
		}
	}
	if (count = items.size())
	{
		return 0;
	}
}

int CalcWeight(const std::vector<size_t>& items, const std::vector<size_t>& itemsWeight)
{
	int weight = 0;
	for (int i = 0; i < items.size(); i++)
	{
		if (items[i] == 1)
		{
			weight += itemsWeight[i];
		}
	}
	return weight;
}

int CalcValue(const std::vector<size_t>& items, const std::vector<size_t>& itemsValue)
{
	int value = 0;
	for (int i = 0; i < items.size(); i++)
	{
		if (items[i] == 1)
		{
			value += itemsValue[i];
		}
	}
	return value;
}

std::vector<size_t> GetValuableItemsInKnapsack(std::vector<size_t>& items, const std::vector<size_t>& itemsWeight, const std::vector<size_t>& itemsValue, const int maxWeight)
{
	std::vector<size_t> bestSet = {};
	std::vector<size_t> itemsInKnapsack = {};
	int currWeight = 0;
	int currValue = 0;
	int maxValue = -1;

	do
	{
		currWeight = CalcWeight(items, itemsWeight);
		currValue = CalcValue(items, itemsValue);
		if (currWeight <= maxWeight && maxValue < currValue)
		{
			maxValue = currValue;
			bestSet = items;

		}
	} while (DecItemsInKnapsack(items) != 0);

	for (int i = 0; i < bestSet.size(); i++)
	{
		if (bestSet[i] == 1)
		{
			itemsInKnapsack.push_back(i + 1);
		}
	}

	return itemsInKnapsack;
}

int main()
{
	int n = 6;
	int maxWeight = 100;
	std::vector<size_t> itemsWeight = { 80, 50, 50, 50, 50, 100 };
	std::vector<size_t> itemsValue = { 1000, 549, 549, 549, 549, 1100 };
	std::vector<size_t> itemsInKnapsack(n, 1);
	
	std::vector<size_t> resultItems = GetValuableItemsInKnapsack(itemsInKnapsack, itemsWeight, itemsValue, maxWeight);
	std::cout << "The best items in knapsack: ";
	for (int i = 0; i < resultItems.size(); i++)
	{
		std::cout << resultItems[i] << " ";
	}
	std::cout << std::endl;

	return 0;

}