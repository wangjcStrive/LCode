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
		˫ָ��
		��̬�滮�У����ǳ������ԶԿռ临�ӶȽ��н�һ�����Ż���
		����������У����Կ�����max_left [ current ] �� max_right [ current ] �����е�Ԫ��������ʵֻ��һ�Σ�Ȼ�����Ҳ�����õ��ˡ��������ǿ��Բ������飬ֻ��һ��Ԫ�ؾ�����.
		����һ�飬��	
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
		���㷨��󲿷ּ���sum����û�п���...
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