#pragma once
#include "solutions.h"
#include <map>

/*
	136. Single Number
*/


class SingleNumber_136 {
public:
	/*
		异或满足结合律
	*/
	int singleNumber_LCode(vector<int>& nums)
	{
		int len = nums.size(), result = 0;
		for (int i = 0; i < len; ++i)
		{
			result ^= nums[i];
		}
		return result;
	}

	int singleNumber(vector<int>& nums) {
		map<int, int> myMap;
		for (auto x : nums)
		{
			if (myMap.find(x) != myMap.end())
				myMap.erase(x);
			else
				myMap.insert(make_pair(x, 1));
		}
		return (*(myMap.begin())).first;

	}
};
