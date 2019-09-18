#pragma once
#include "solutions.h"
#include <algorithm>
//53. Maximum Subarray
/*
	A = { -2,1,-3,4,-1,2,1,-5,4 }
	DP(i)表示以i结尾的subarray的最大值
	dp[i] = nums[i] + (dp[i - 1] > 0 ? dp[i - 1] : 0);
*/

class MaxSubarray {
public:
	int maxSubArray(vector<int>& nums)
	{
		int n = nums.size();
		vector<int> dp(nums.size());
		dp[0] = nums[0];
		int max = dp[0];
		for (int i = 1; i < n; i++)
		{
			dp[i] = nums[i] + (dp[i - 1] > 0 ? dp[i - 1] : 0);
			max = Max(max, dp[i]);
		}
		return max;
	}
private:
	int Max(int a, int b)
	{
		return a > b ? a : b;
	}
};
