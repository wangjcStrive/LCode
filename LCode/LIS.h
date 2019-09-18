#pragma once
#include "solutions.h"


class LIS {
public:
	int lengthOfLIS(vector<int>& nums) {
		vector<int> arr(nums.size(), 1);
		int len = 1;
		for (size_t i = 0; i < nums.size(); i++)
		{
			for (size_t j=0; j < i; j++)
			{
				if (nums[j]<nums[i] && arr[j] + 1 > arr[i])
					arr[i] = arr[j] + 1;
			}
			if (arr[i] > len)
				len = arr[i];
		}
		return len;
	}
};
