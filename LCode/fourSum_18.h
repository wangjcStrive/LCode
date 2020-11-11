#pragma once
#include "solutions.h"

/*
	18. Four Sum
*/

class FourSum_18 {
public:
	/*
		refer to 「15. three sum」
		避免结果有完全相同的子数组(4个数的下标不同，但是值时相同的)
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
					if (abs(target - twoSum) == lVal + rVal)
					{
						vector<int> tempVec = { nums[i],nums[j],nums[left],nums[right] };
						bool isExist = false;
						for (auto item : result)
						{
							if (item == tempVec)
								isExist = true;
						}
						if(!isExist)
							result.push_back({ nums[i],nums[j],nums[left],nums[right] });
						break;
					}
					else if (abs(twoSum) < lVal + rVal)
						right--;
					else
						left++;
				}
			}
		}
		return result;
    }
};
