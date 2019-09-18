#pragma once
#include "solutions.h"

class ClimbStairs {
public:
	int climbStairs(int n)
	{
		vector<int> dp;
		dp.push_back(0);
		dp.push_back(1);
		dp.push_back(2);
		for (int i = 3; i < n + 1; i++)
		{
			dp.push_back(dp[i - 1] + dp[i - 2]);
		}
		return dp[n];
	}
};
