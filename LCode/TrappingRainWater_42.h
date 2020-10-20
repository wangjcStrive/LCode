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
		for (size_t current = 1; current < height.size() - 1; current++)
		{
			int maxLeft = 0;
			int maxRight = 0;
			int left;
			for (left = current-1; left >= 0; left--)
			{
				if (left >= 0 && height[left] > maxLeft)
					maxLeft = height[left];
			}
			for (size_t right = current + 1; right < height.size(); right++)
			{
				if (right < height.size() && height[right] > maxRight)
					maxRight = height[right];
			}
			if (height[current] <= maxLeft && height[current] <= maxRight)
			{
				result += min(maxLeft, maxRight) - height[current];
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
		for (size_t current = 1; current < height.size(); current++)
		{
			maxLeft[current] = max(maxLeft[current - 1], height[current - 1]);
		}

		vector<int> maxRight(height.size(), 0);
		maxLeft[height.size() - 1] = 0;
		for (int j = height.size()-2; j >=0; j--)
		{
			maxRight[j] = max(maxRight[j + 1], height[j + 1]);
		}

		for (int current = 1; current < height.size(); current++)
		{
			int minValue = min(maxLeft[current], maxRight[current]);
			if (minValue > height[current])
				result += minValue - height[current];
		}
		return result;
	}

	/*
		双指针
		动态规划中，我们常常可以对空间复杂度进行进一步的优化。
		例如这道题中，可以看到，max_left [ current ] 和 max_right [ current ] 数组中的元素我们其实只用一次，然后就再也不会用到了。所以我们可以不用数组，只用一个元素就行了.
		遍历一遍，用	
	*/
	int trap(vector<int>& height)
	{
		int sum = 0;
		int max_left = 0;
		int max_right = 0;
		int left = 1;
		int right = height.size() - 2;
		for (int current = 1; current < height.size() - 1; current++)
		{

			if (height[left - 1] < height[right + 1]) {
				max_left = max(max_left, height[left - 1]);
				int min = max_left;
				if (min > height[left]) {
					sum = sum + (min - height[left]);
				}
				left++;

			}
			else {
				max_right = max(max_right, height[right + 1]);
				int min = max_right;
				if (min > height[right]) {
					sum = sum + (min - height[right]);
				}
				right--;
			}
		}
		return sum;
	}


	/*
		stack.
		height[current] compare with stack.top()
		这算法最后部分计算sum那里没有看懂...
	*/
	int trap_st(vector<int>& height)
	{
		int sum = 0;
		int len = height.size();
		if (len == 0)
			return sum;
		//stack will save index.
		stack<int> st;
		st.push(height[0]);
		int stTopIndex;
		for (int current = 1; current < height.size(); current++)
		{
			while (!st.empty() && height[current]>st.top())
			{
				stTopIndex = st.top();
				st.pop();
				if (st.empty())
					continue;
				int distance = current - st.top() - 1;
				int minHight = min(height[current], height[st.top()]);
				sum += distance * (minHight - height[stTopIndex]);
			}
			st.push(current);
		}

		return  0;
	}
};