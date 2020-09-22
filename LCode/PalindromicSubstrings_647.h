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
		ʹ�þ������Ͻǣ����ǲ�����[0,0][0,1][0,2][0,3],Ӧ����[0,0][0,1][1,1][0,2][1,2][2,3][0,3][1,3][2,3]��
		������[0,0][0,1][0,2],��[0,2]ʱ����Ҫʹ��DP[1][1],��ʱDP[1][1]��û��ʼ��

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
		����DP�����ռ临�Ӷ�ΪO(N^2). => �Ż�ΪO(N)
		�������������������ʱ��ÿһ��ֻ��Ҫ���һ�е�DPֵ�����磺
		��[0,5] <= [1,4]
		��[1,5] <= [2,4]
		��[2,5] <= [3,4]
		��[3,5] <= [4,4]
		���Կ��Ǽ�ΪһάDP����
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
