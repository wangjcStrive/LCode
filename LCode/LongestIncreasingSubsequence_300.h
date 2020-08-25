#include "solutions.h"

/*
        Input: [10,9,2,5,3,7,101,18]
        Output: 4 
    Explanation: The longest increasing subsequence is [2,3,7,101], therefore the length is 4. 

    "�Ե�k���β����ݹ������еĳ����ǣ���֤��i��ȵ�k��С������£��Ե�i���β��LIS���ȼ�1�����ֵ��"
    �������ϡ�D[i]=max(D[j] | Input[i]>Input[j]). D[i]=�ҵ�ǰ��D[1]~D[i-1] ����ֵС��Input[i]

    �߽�: �����Ԫ��
*/

class LongestIncreasingSubsequence_300
{
public:
    /*
        O(n^2)
        Runtime: 136 ms, faster than 12.35% of C++ online submissions for Longest Increasing Subsequence.
        Memory Usage: 7.7 MB, less than 98.67% of C++ online submissions for Longest Increasing Subsequence.
        ������
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
                    DP[i] = max(DP[i], DP[j] + 1);  //������ϱߵĽⷨ������������
                }
            }
        }
        vector<int>::iterator iMax = max_element(DP.begin(), DP.end());
        return *iMax;
    }
    /*
        1. ��Ҫÿ�ζ���ȡvector����
        2. ��ȡDP vector�����ֵ
        ʱ��������108��Ϊ76..
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
        ����DP[i]ʱ���㷨���Ӷ�ΪO(N). �������״̬����ʹ������DPΪһ�������б�����ÿ��DP[i]ʱ��ͨ�����ַ�����
        [0, i]���䣬���ӶȽ�ΪO(logN)
    */
    int lengthOfLIS_vectorMinMax_faster(vector<int>& nums)
    {

    }
};