#pragma once
#include "solutions.h"

/*
	121. Best Time to Buy and Sell Stock
*/

class BestTimeToBuyAndSellStock_121 {
public:
	/*
		DP[i]: 第i天买入，能够赚到的最多的钱

		200 / 200 test cases passed, but took too long.
		O(N^2)
	*/
	int maxProfit_DP(vector<int>& prices) {
		int len = prices.size();
		if (len < 2)
			return 0;
		vector<int> DP(len, 0);
		for (int i = 0; i < len; i++)
		{
			for (int j = i; j < len; j++)
			{
				int tempMoneyEarn = prices[j] - prices[i];
				if (tempMoneyEarn > DP[i])
				{
					DP[i] = tempMoneyEarn;
				}
			}
		}
		return *(std::max_element(DP.begin(), DP.end()));
	}

	/*
		倒序遍历一遍，记录每个位置右边的最大值
		Runtime: 16 ms, faster than 39.45% of C++ online submissions for Best Time to Buy and Sell Stock.
		Memory Usage: 13.1 MB, less than 50.51% of C++ online submissions for Best Time to Buy and Sell Stock.
		O(2n)
	*/
	int maxProfit(vector<int>& prices)
	{
		int length = prices.size();
		vector<int> maxRight(length, INT_MIN);
		int max_right_value = INT_MIN;
		int maxValue = 0;
		for (int i = length - 2; i >= 0; i--)
		{
			if (prices[i + 1] > max_right_value)
			{
				max_right_value = prices[i+1];
			}
			maxRight[i] = max_right_value;
		}
		for (int i = 0; i < length - 1; i++)
		{
			int temp = maxRight[i] - prices[i];
			if (temp > maxValue)
				maxValue = temp;
		}
		return maxValue;
	}
	/*
		求出最大值后，直接用右边的最大值减去当前的值就好了，不需要遍历两边
		Runtime: 8 ms, faster than 96.69% of C++ online submissions for Best Time to Buy and Sell Stock.
		Memory Usage: 13.1 MB, less than 55.87% of C++ online submissions for Best Time to Buy and Sell Stock.	
	*/
	int maxProfit_optimize(vector<int>& prices)
	{
		int length = prices.size();
		int max_right_value = INT_MIN;
		int maxValue = 0;
		for (int i = length - 2; i >= 0; i--)
		{
			if (prices[i + 1] > max_right_value)
			{
				max_right_value = prices[i + 1];
			}

			int temp = max_right_value - prices[i];
			if (temp > maxValue)
				maxValue = temp;
		}
		return maxValue;
	}
};
