#pragma once
#include "solutions.h"
#include <algorithm>

/*
	42. Trapping Rain Water
	input = [0,1,0,2,1,0,1,3,2,1,2,1]
	output = 6
*/

class TrappingRainWater
{
public:
	/*
		求每一列的水，我们只需要关注当前列，以及左边最高的墙，右边最高的墙就够了.
		装水的多少，当然根据木桶效应，我们只需要看左边最高的墙和右边最高的墙中较矮的一个就够了。
	*/
	int trap1(vector<int>& height)
	{
		int result = 0;
		if (height.size() == 0)
			return result;
		for (size_t i = 1; i < height.size() - 1; i++)
		{
			int maxLeft = 0;
			int maxRight = 0;
			int left;
			for (left = i-1; left >= 0; left--)
			{
				if (left >= 0 && height[left] > maxLeft)
					maxLeft = height[left];
			}
			for (size_t right = i + 1; right < height.size(); right++)
			{
				if (right < height.size() && height[right] > maxRight)
					maxRight = height[right];
			}
			if (height[i] <= maxLeft && height[i] <= maxRight)
			{
				result += min(maxLeft, maxRight) - height[i];
			}
		}

		return result;
	}
	
	/*
		trap1()中，计算两边的最大值，每次都要重新遍历一遍所有高度，可以优化一下
		先从左边遍历一遍，计算每个位置上的左边的最大值，更新到vector maxLeft.
		再从右边往左边遍历一遍，计算每个位置上右边的最大值，更新到vector maxRight;
		然后再遍历一遍就好了
		时间复杂度：O(3n)
		空间复杂度：O(2n)
	*/
	int trap2_DP(vector<int> height)
	{
		int result = 0;
		if (height.size() == 0)
			return result;
		
		vector<int> maxLeft(height.size(), 0);
		maxLeft[0]=0;
		for (int i = 1; i < height.size(); i++)
		{
			maxLeft[i] = max(maxLeft[i - 1], height[i - 1]);
		}

		vector<int> maxRight(height.size(), 0);
		maxLeft[height.size() - 1] = 0;
		for (int j = height.size()-2; j >=0; j--)
		{
			maxRight[j] = max(maxRight[j + 1], height[j + 1]);
		}

		for (int i = 1; i < height.size(); i++)
		{
			int minValue = min(maxLeft[i], maxRight[i]);
			if (minValue > height[i])
				result += minValue - height[i];
		}
		return result;
	}

	/*
		双指针
	*/
};