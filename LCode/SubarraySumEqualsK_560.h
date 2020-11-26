#pragma once
#include <unordered_map>
#include "solutions.h"
/*
	560. Subarray Sum Equals K
*/

class SubarraySumEqualsK_560 {
public:
	/*
		O(n^2)
		上轮迭代求了 i 到 j - 1 的和，这轮就没必要从头求 i 到 j 的和
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
		前缀和. O(n^2)
		prefixSum为第0项到第x项的和.  prefix[i] = prefix[0]+...+prefixSum[i-1]
		=> nums的某项=两个相邻前缀和的差. nums[x]=prefixSum[x]-prefixSum[x-1]
		=> nums的第i项到第j项的和nums[i]+...+sums[j] = prefixSum[j+1]-prefixSum[i]
		
	*/
	int subarraySum_prefixSum(vector<int>& nums, int k)
	{
		int result=0;
		int length = nums.size();
		int prefixLen = length+1;
		vector<int> prefixSum(length + 1, 0);
		//Solution::printVec(nums, k);
		//prefixSum偏移一位，第一位置为0. prefix[i] = prefix[0]+...+prefixSum[i-1]
		for (size_t i = 1; i < prefixLen; i++)
		{
			prefixSum[i] = prefixSum[i - 1] + nums[i - 1];
		}
		//nums的[i,j]区间内的和 SUM(nums[i], nums[j]) = prefixSum[j+1]-prefix[i]
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

	/*
		prefixSum + hash
		Your runtime beats 17.64 % of cpp submissions
		Your memory usage beats 5.01 % of cpp submissions (41.6 MB)
		没有想太明白这个思路
	*/
	int subarraySum(vector<int>& nums, int k) {
		std::unordered_map<int, int> seen = { {0, 1} };
		int count = 0, sum = 0;
		for (auto n : nums) {
			sum += n;
			count += seen[sum - k];
			seen[sum]++;
		}
		return count;
	}
};
