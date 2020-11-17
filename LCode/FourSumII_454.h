#pragma once
#include "solutions.h"

/*
	454. Four Sum II. refer to <18.Four Sum>.
	相比于<18. FourSum>. 这个不能排序
*/

class FourSumII_454 {
public:
    int fourSumCount(vector<int>& A, vector<int>& B, vector<int>& C, vector<int>& D)
	{
		int len = A.size();
    }
	vector<vector<int>> fourSum(vector<int>& nums, int target)
	{
		int len = nums.size();
		vector<vector<int>> result;
		if (len < 4)
			return result;

		std::sort(nums.begin(), nums.end());

		for (size_t i = 0; i < len - 3; i++)
		{
			for (size_t j = i + 1; j < len - 2; j++)
			{
				int left = j + 1;
				int right = len - 1;
				int twoSum = nums[i] + nums[j];
				while (left < right)
				{
					int lVal = nums[left];
					int rVal = nums[right];
					if (target - twoSum == lVal + rVal)
					{
						vector<int> tempVec = { nums[i],nums[j],nums[left],nums[right] };
						bool isExist = false;
						for (auto item : result)	//exclude same result. value same, but index not same
						{
							if (item == tempVec)
								isExist = true;
						}
						if (!isExist)
							result.push_back({ nums[i],nums[j],nums[left],nums[right] });
						//break;	//can't break, 当前i/j的前提下，从后面选两个数，可能不止一个解
						left++;
						right--;
						continue;
					}
					else if (target - twoSum < lVal + rVal)
						right--;
					else
						left++;
				}
			}
		}
		return result;
	}
	vector<vector<int>> fourSum(vector<int>& nums, int target)
	{
		int len = nums.size();
		vector<vector<int>> result;
		if (len < 4)
			return result;

		std::sort(nums.begin(), nums.end());

		for (size_t i = 0; i < len - 3; i++)
		{
			for (size_t j = i + 1; j < len - 2; j++)
			{
				int left = j + 1;
				int right = len - 1;
				int twoSum = nums[i] + nums[j];
				while (left < right)
				{
					int lVal = nums[left];
					int rVal = nums[right];
					if (target - twoSum == lVal + rVal)
					{
						vector<int> tempVec = { nums[i],nums[j],nums[left],nums[right] };
						bool isExist = false;
						for (auto item : result)	//exclude same result. value same, but index not same
						{
							if (item == tempVec)
								isExist = true;
						}
						if (!isExist)
							result.push_back({ nums[i],nums[j],nums[left],nums[right] });
						//break;	//can't break, 当前i/j的前提下，从后面选两个数，可能不止一个解
						left++;
						right--;
						continue;
					}
					else if (target - twoSum < lVal + rVal)
						right--;
					else
						left++;
				}
			}
		}
		return result;
	}
};
