#include "solutions.h"

/*
        Input: [10,9,2,5,3,7,101,18]
        Output: 4 
    Explanation: The longest increasing subsequence is [2,3,7,101], therefore the length is 4. 

    "以第k项结尾的最长递归子序列的长度是：保证第i项比第k项小的情况下，以第i项结尾的LIS长度加1的最大值。"
    自下向上。D[i]=max(D[j] | Input[i]>Input[j]). D[i]=找到前面D[1]~D[i-1] 并且值小于Input[i]

    边界: 有相等元素
*/

class LongestIncreasingSubsequence_300
{
public:
    /*
        O(n^2)
        Runtime: 136 ms, faster than 12.35% of C++ online submissions for Longest Increasing Subsequence.
        Memory Usage: 7.7 MB, less than 98.67% of C++ online submissions for Longest Increasing Subsequence.
        不够快
    */
    int lengthOfLIS(vector<int>& nums)
    {
        int len = nums.size();
        if (len == 0)
            return 0;
        vector<int> DP(len);
        DP[0] = 1;
        int result = 1;
        for (int i = 0; i < nums.size(); i++)
        {
            int preMaxValue = INT_MIN;
            int preMaxValueIndex = -1;
            for (int j = 0; j < i; j++)
            {
                if (nums[j] < nums[i] && DP[j]>preMaxValue)
                {
                    preMaxValue = DP[j];
                }
            }
            if (preMaxValue != INT_MIN)
                DP[i] = preMaxValue + 1;
            else
                DP[i] = 1;

            if (DP[i] > result)
                result = DP[i];
        }
        return result;
    }

    /*
        O(n^2)
        Runtime: 108 ms, faster than 23.98% of C++ online submissions for Longest Increasing Subsequence.
        Memory Usage: 8 MB, less than 16.60% of C++ online submissions for Longest Increasing Subsequence.
    */
    int lengthOfLIS_vectorMinMax(vector<int>& nums)
    {
        if (nums.size() == 0)
            return 0;
        vector<int> DP(nums.size() + 1, 1);
        int result = 1;
        for (int i = 1; i < nums.size(); i++)
        {
            for (int j = 0; j < i; j++)
            {
                if (nums[j] < nums[i])
                {
                    DP[i] = max(DP[i], DP[j] + 1);  //相对于上边的解法，精髓在这里
                }
            }
        }
        vector<int>::iterator iMax = max_element(DP.begin(), DP.end());
        return *iMax;
    }
    /*
        1. 不要每次都获取vector长度
        2. 获取DP vector的最大值
        时间从上面的108变为76..
        Runtime: 76 ms, faster than 52.75% of C++ online submissions for Longest Increasing Subsequence.
        Memory Usage: 8 MB, less than 28.32% of C++ online submissions for Longest Increasing Subsequence.
    */
    int lengthOfLIS_vectorMinMax_faster(vector<int>& nums)
    {
        int len = nums.size();
        if (len == 0)
            return 0;
        vector<int> DP(len + 1, 1);
        int result = 1;
        for (int i = 1; i < len; i++)
        {
            for (int j = 0; j < i; j++)
            {
                if (nums[j] < nums[i])
                {
                    DP[i] = max(DP[i], DP[j] + 1);
                }
            }
        }
        return *max_element(DP.begin(), DP.end());
    }



    /*
        计算DP[i]时的算法复杂度为O(N). 重新设计状态定义使得整个DP为一个排序列表，计算每个DP[i]时，通过二分法遍历
        [0, i]区间，复杂度降为O(logN)
    */
    int lengthOfLIS_vectorMinMax_faster(vector<int>& nums)
    {

    }
};