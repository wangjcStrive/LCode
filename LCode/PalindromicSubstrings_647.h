#pragma once
#include "solutions.h"
/*
	647. Palindromic Substrings
	refer toL 5. Longest Palindromic Substring
*/

class  PalindromicSubstrings_647 {
public:
	/*
		DP. O(N^2)
		使用矩阵右上角，但是不能是[0,0][0,1][0,2][0,3],应该是[0,0][0,1][1,1][0,2][1,2][2,3][0,3][1,3][2,3]。
		比如求[0,0][0,1][0,2],求[0,2]时就需要使用DP[1][1],这时DP[1][1]还没初始化

		Runtime: 56 ms, faster than 22.97% of C++ online submissions for Palindromic Substrings.
		Memory Usage: 7.5 MB, less than 50.10% of C++ online submissions for Palindromic Substrings.
	*/
    int countSubstrings(string s)
	{
		unsigned int result = 0;
		int length = s.size();
		vector<vector<bool>> DP(length, vector<bool>(length, false));
		for (int j = 0; j < length; j++)
		{
			for (int i = 0; i <= j; i++)
			{
				int temp = j - i;
				if (temp == 0)
				{
					DP[i][j] = true;
					result++;
				}
				else if (temp == 1)
				{
					if (s[i] == s[j])
					{
						DP[i][j] = true;
						result++;
					}
				}
				else
				{
					if (s[i] == s[j] && DP[i + 1][j - 1] == true)
					{
						DP[i][j] = true;
						result++;
					}
				}
			}
		}
		return result;
    }

	/*
		上面DP方法空间复杂度为O(N^2). => 优化为O(N)
		当竖向便利矩阵上三角时，每一列只需要左边一列的DP值。比如：
		求[0,5] <= [1,4]
		求[1,5] <= [2,4]
		求[2,5] <= [3,4]
		求[3,5] <= [4,4]
		所以考虑简化为一维DP数组
	*/
	int countSubstrings_1D_DP(string s)
	{
		int length = s.size();
		int result = 0;
		bool* DP = new bool[length];

		for (int j = 0; j < length; j++)
		{
			for (int i = 0; i <= j; i++)
			{
				int temp = j - i;
				if (temp == 0)
				{
					DP[i] = true;
					result++;
				}
				else if (temp == 1)
				{
					if (s[i] == s[j])
					{
						DP[i] = true;
						result++;
					}
				}
				else
				{
					if (s[i] == s[j] && DP[i + 1] == true)
					{
						DP[i] = true;
						result++;
					}
				}
			}
		}
		delete[] DP;
		return result;
	}
};
