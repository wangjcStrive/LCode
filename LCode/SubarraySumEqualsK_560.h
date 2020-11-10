#pragma once
#include "solutions.h"
/*
	560. Subarray Sum Equals K
*/

class SubarraySumEqualsK_560 {
public:
	/*
		O(n^2)
	*/
    int subarraySum(vector<int>& nums, int k) {
		int count = 0;
		for (int start = 0; start < nums.size(); ++start) {
			int sum = 0;
			for (int end = start; end >= 0; --end) {
				sum += nums[end];
				if (sum == k) {
					count++;
				}
			}
		}
		return count;
	}
	/*
		https://leetcode-cn.com/problems/subarray-sum-equals-k/solution/dai-ni-da-tong-qian-zhui-he-cong-zui-ben-fang-fa-y/
		ǰ׺��. O(n^2)
		prefixSumΪ��0���x��ĺ�.  prefix[i] = prefix[0]+...+prefixSum[i-1]
		=> nums��ĳ��=��������ǰ׺�͵Ĳ�. nums[x]=prefixSum[x]-prefixSum[x-1]
		=> nums�ĵ�i���j��ĺ�nums[i]+...+sums[j] = prefixSum[j+1]-prefixSum[i]
		
	*/
	int subarraySum_prefixSum(vector<int>& nums, int k)
	{
		int result=0;
		int length = nums.size();
		int prefixLen = length+1;
		vector<int> prefixSum(length + 1, 0);
		//prefixSumƫ��һλ����һλ��Ϊ0. prefix[i] = prefix[0]+...+prefixSum[i-1]
		for (size_t i = 1; i < prefixLen; i++)
		{
			prefixSum[i] = prefixSum[i - 1] + nums[i - 1];
		}
		//nums��[i,j]�����ڵĺ� SUM(nums[i], nums[j]) = prefixSum[j+1]-prefix[i]
		for (size_t i = 0; i < length; i++)
		{
			for (size_t j = i; j < length; j++)
			{
				if (prefixSum[j + 1] - prefixSum[i] == k)
					result++;
			}
		}
		return result;
	}
};
