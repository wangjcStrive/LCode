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
	int maxProfit(vector<int>& prices) {
		int len = prices.size();
		if (len < 2)
			return 0;
		vector<int> DP(len, 0);
		for (int i = 0; i < len ; i++)
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
};
