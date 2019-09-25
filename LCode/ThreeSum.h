#pragma once
#include <algorithm>
#include "solutions.h"
/*
	15. 3Sum
	暴力解法复杂度：nlogn?
	exceptions:
		input [0,0,0] => output [0,0,0]
		input [0,0,0,0] => output [[0,0,0],[0,0,0]]. except [[0,0,0]]
*/

class ThreeSum {
public:
	//sort. 双指针Clamping(夹逼)
	vector<vector<int>> threeSum(vector<int>& nums)
	{
		int i, j;
		vector<vector<int>> result;
		if (nums.size() < 3)
			return result;
		//sort
		sort(nums.begin(), nums.end());

		//front and end pointer.
		for (int k = 0; k < nums.size()-2; k++)
		{
			int kVal = nums[k];
			for (i = k + 1, j = nums.size() - 1; i < j; )
			{
				int iVal = nums[i];
				int jVal = nums[j];

				if (iVal + jVal == abs(kVal))
				{
					result.push_back({ nums[k], nums[i], nums[j] });
					break;
				}
				else if (iVal + jVal > abs(kVal))
					j--;
				else
					i++;
			}
		}
		return result;
	}
};