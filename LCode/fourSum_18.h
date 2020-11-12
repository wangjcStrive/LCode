#pragma once
#include "solutions.h"

/*
	18. Four Sum
	tag: Sort. TwoPointer
*/

class FourSum_18 {
public:
	/*
		refer to 15. three sum. O(n^3)
		边界：
			避免结果有完全相同的子数组(4个数的下标不同，但是值时相同的)
			i/j确定的前提下，后面的解可能未必只有一个，所以后面结束的条件只能是left>=right
	*/
    vector<vector<int>> fourSum(vector<int>& nums, int target) 
    {
		int len = nums.size();
		vector<vector<int>> result;
		if (len < 4)
			return result;
		
		std::sort(nums.begin(), nums.end());

		for (size_t i = 0; i < len-3; i++)
		{
			for (size_t j = i+1; j < len-2; j++)
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
						if(!isExist)
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
