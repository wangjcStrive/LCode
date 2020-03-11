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
		��ÿһ�е�ˮ������ֻ��Ҫ��ע��ǰ�У��Լ������ߵ�ǽ���ұ���ߵ�ǽ�͹���.
		װˮ�Ķ��٣���Ȼ����ľͰЧӦ������ֻ��Ҫ�������ߵ�ǽ���ұ���ߵ�ǽ�нϰ���һ���͹��ˡ�
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
		trap1()�У��������ߵ����ֵ��ÿ�ζ�Ҫ���±���һ�����и߶ȣ������Ż�һ��
		�ȴ���߱���һ�飬����ÿ��λ���ϵ���ߵ����ֵ�����µ�vector maxLeft.
		�ٴ��ұ�����߱���һ�飬����ÿ��λ�����ұߵ����ֵ�����µ�vector maxRight;
		Ȼ���ٱ���һ��ͺ���
		ʱ�临�Ӷȣ�O(3n)
		�ռ临�Ӷȣ�O(2n)
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
		˫ָ��
	*/
};