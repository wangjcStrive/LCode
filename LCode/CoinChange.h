#pragma once
#include "solutions.h"
#include <map>
class CoinChange {
public:
	int coinChange(vector<int>& coins, int amount) {
		map<int, int> resultList;
		if (coins.size() == 0)
			return 0;
		for (int i = 1; i < amount + 1; i++)
		{
			resultList[0] = 0;
			int minTemp = amount + 1;
			for (auto change : coins)
				for (int change = 0; change < coins.size(); change++)
				{
					if (i - coins[change] >= 0 && minTemp > resultList[i - coins[change]] && resultList[i - coins[change]] != -1)
						minTemp = resultList[i - coins[change]];
				}
			resultList[i] = minTemp == amount + 1 ? -1 : minTemp + 1;
		}
		return resultList[amount];
	}
};
