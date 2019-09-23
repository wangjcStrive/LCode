#pragma once
#include "solutions.h"
#include <limits.h>

/*
	121. Best Time to Buy and Sell Stock
*/


class BestTimetoBuyandSellStock {
public:
	//暴力解法.算法复杂度
	int maxProfit_notFast(vector<int>& prices)
	{
		int max = 0;
		vector<int> DP(prices.size(), 0);
		int tempMin = 0;
		for (int i = 0; i < prices.size(); i++)
		{
			for (int j = i; j < prices.size(); j++)
			{
				if (prices[j] - prices[i] > DP[i])
					DP[i] = prices[j] - prices[i];
			}
			if (DP[i] > max)
				max = DP[i];
		}
		return max;
	}

	//遍历一次，同时记下前面的最小值
	int maxProfit(vector<int>& prices)
	{
		if (prices.size() <= 1)
			return 0;
		int minValue = prices[0];
		int maxValue = INT_MIN;
		vector<int> dp(prices.size(), 0);
		for (size_t i = 1; i < prices.size(); i++)
		{
			dp[i] = prices[i] - minValue > 0 ? prices[i] - minValue : 0;

			minValue = minValue < prices[i] ? minValue : prices[i];
				
			maxValue = maxValue > dp[i] ? maxValue : dp[i];
		}
		return maxValue;
	}
};
