#pragma once
#include "solutions.h"

/*
	42. Trapping Rain Water
	input = [0,1,0,2,1,0,1,3,2,1,2,1]
	output = 6
*/

class TrappingRainWater
{
public:
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

private:

};