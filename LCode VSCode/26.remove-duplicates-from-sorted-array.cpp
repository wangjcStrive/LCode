/*
 * @lc app=leetcode id=26 lang=cpp
 *
 * [26] Remove Duplicates from Sorted Array
 */
#include <iostream>
#include <vector>
using std::vector;


class Solution {
public:
    int removeDuplicates(vector<int>& nums) 
    {
        vector<int> rel;
		if (nums.size() == 1 || nums.size() == 0)
			return nums.size();

		rel.push_back(nums[0]);
		for (size_t i = 1; i < nums.size(); i++)
		{
			if (nums[i] == rel.back())
			{
				continue;
			}
			else
			{
				rel.push_back(nums[i]);
			}
		}
		nums = rel;
		return nums.size();
    }
};

