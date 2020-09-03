/*
	53. Maximum Subarray
*/

#include "solutions.h"

class MaximumSubarray_53 {
public:
    /*
        DP[i][j]:从i~j 的sum. DP[I][J] = DP[I+1][J-1]+nums[i]+nums[j]
        与5. Longest Palindromic Substring一样解法
        O(n^2)
        输入很长时，超时...
    */
    int maxSubArray_notFast(vector<int>& nums) {
        int len = nums.size();
        if (len == 0)
            return 0;
        vector<vector<int>> DP(len, vector<int>(len, 0));
        int result = INT_MIN;
        for (int i = 0; i < len; i++)
        {
            DP[i][i] = nums[i];
            if (result < DP[i][i])
                result = DP[i][i];
        }
        for (int j = 1; j < len; j++)
        {
            for (int i = 0; i < j; i++)
            {
                if(j-i==1)
                    DP[i][j] = nums[i] + nums[j];
                else
                    DP[i][j] = DP[i + 1][j - 1] + nums[i] + nums[j];

                if (result < DP[i][j])
                    result = DP[i][j];
            }
        }
        return result;
    }


    /*
        DP[i]表示以i结尾的subarray的最大值
        DP[i] = nums[i] + (DP[i-1]>0?DP[i-1]:0)

        O(n)
        Runtime: 16 ms, faster than 53.39% of C++ online submissions for Maximum Subarray.
        Memory Usage: 13.4 MB, less than 19.24% of C++ online submissions for Maximum Subarray.
    */
    int maxSubArray(vector<int>& nums)
    {
        int len = nums.size();
        vector<int> DP(len, 0);
        DP[0] = nums[0];
        int result = nums[0];

        for (int i = 1; i < len; i++)
        {
            DP[i] = nums[i] + (DP[i - 1] > 0 ? DP[i - 1] : 0);
            if (DP[i] > result)
                result = DP[i];
        }
        return result;
    }
};