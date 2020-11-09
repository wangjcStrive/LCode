#pragma once
#include "solutions.h"
/*
	560. Subarray Sum Equals K
*/

class SubarraySumEqualsK_560 {
public:
	/*
		O(n^2)
	*/
    int subarraySum(vector<int>& nums, int k) {
        int result = 0;
		int len = nums.size();
		for (size_t i = 0; i < len; i++)
		{
			size_t j = i;
			int whatLeft = k;
			for (; j < len && whatLeft!=0; j++)
			{
				whatLeft -= nums[j];
			}
			if (whatLeft == 0)
				result++;
		}
		return result;
    }
};
