#pragma once
#include "solutions.h"
#include <unordered_map>

/*
 * @lc app=leetcode.cn id=49 lang=cpp
 *
 * [49] ×ÖÄ¸ÒìÎ»´Ê·Ö×é
	tag: hash
 */

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
		vector<vector<string>> result;
		unordered_map<string, int> myMap;
		size_t index = 0;
		for (auto x : strs)
		{
			string tempStr = x;
			sort(tempStr.begin(), tempStr.end());
			if (myMap.count(tempStr))
			{
				result[]
			}
			else
			{
				myMap[tempStr] = index++;
				
			}
		}
    }

	int subarraySum(vector<int>& nums, int k) {
		std::unordered_map<int, int> seen = { {0, 1} };
		int count = 0, sum = 0;
		for (auto n : nums) {
			sum += n;
			count += seen[sum - k];
			seen[sum]++;
		}
		return count;
	}
	int subarraySum(vector<int>& nums, int k) {
		std::unordered_map<int, int> seen = { {0, 1} };
		int count = 0, sum = 0;
		for (auto n : nums) {
			sum += n;
			count += seen[sum - k];
			seen[sum]++;
		}
		return count;
	}
	int subarraySum(vector<int>& nums, int k) {
		std::unordered_map<int, int> seen = { {0, 1} };
		int count = 0, sum = 0;
		for (auto n : nums) {
			sum += n;
			count += seen[sum - k];
			seen[sum]++;
		}
		return count;
	}
	int subarraySum(vector<int>& nums, int k) {
		std::unordered_map<int, int> seen = { {0, 1} };
		int count = 0, sum = 0;
		for (auto n : nums) {
			sum += n;
			count += seen[sum - k];
			seen[sum]++;
		}
		return count;
	}
};
