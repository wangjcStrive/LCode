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
		�߽磺
			����������ȫ��ͬ��������(4�������±겻ͬ������ֵʱ��ͬ��)
			i/jȷ����ǰ���£�����Ľ����δ��ֻ��һ�������Ժ������������ֻ����left>=right
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
						//break;	//can't break, ��ǰi/j��ǰ���£��Ӻ���ѡ�����������ܲ�ֹһ����
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
