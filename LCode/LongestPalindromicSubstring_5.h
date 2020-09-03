#include "solutions.h"

/*
	5. Longest Palindromic Substring

	Input: "babad"
	Output: "bab"
	Note: "aba" is also a valid answer.
	Example 2:

	Input: "cbbd"
	Output: "bb"
*/


class LongestPalindromicSubstring_5 {
public:
	/*
		���������о����г��ȴ���2���Ӵ����ж����Ƿ�Ϊ����
	*/
	string longestPalindrome_BruteForce(string s)
	{

	}

	/*
		�Լ��ĳ���ⷨ
		O(n^2)
		Runtime: 44 ms, faster than 87.19% of C++ online submissions for Longest Palindromic Substring.
		Memory Usage: 13.9 MB, less than 47.28% of C++ online submissions for Longest Palindromic Substring.
	*/
	string longestPalindrome(string s)
	{
		int len = s.length();
		if (len == 0)
			return "";
		if (len == 1)
			return s;

		string resultStr = "";
		int maxLengh = 0;
		for (int i = 1; i < len; i++)
		{
			int left = i - 1;
			int right = i + 1;
			while (left >= 0 && s[left] == s[i])
				left--;
			while (left >= 0 && right <= len && s[left] == s[right])
			{
				left--;
				right++;
			}
			int tempLen = right - left - 1;
			if (tempLen > maxLengh)
			{
				maxLengh = tempLen;
				resultStr = s.substr(left + 1, maxLengh);
			}
		}
		return resultStr;
	}


	/*
		��ͷβ�ַ���ȵ�����£������Ӵ��Ļ������ʾݶ��������Ӵ��Ļ�������
		DP[i][j]��ʾ[i, j]�����ڵ��ִ��Ƿ��ǻ��ġ��ҳ�DP[][]������ֵ
			1. j-i=1. ����Ԫ�أ�ֻ���ж�s[j] == s[i]
			2. j-i-2. ֻҪs[j] == s[i]��һ������
			3. j-i>2. s[j] == s[i] && DP[i+1][j-1]ʱ���ġ���α�֤�Ե����ϣ���֤DP[i+1][j-1]��DP[i][j]֮ǰ����
		O(n^2)
		Runtime: 280 ms, faster than 29.81% of C++ online submissions for Longest Palindromic Substring.
		Memory Usage: 184.5 MB, less than 5.03% of C++ online submissions for Longest Palindromic Substring.
	*/
	string longestPalindrome_DP(string s)
	{
		int length = s.size();
		if (length == 0)
			return "";
		if (length == 1)
			return s;

		vector<vector<int>> DP(length, vector<int>(length, 0));
		int maxLen = 1;
		int left = 0;
		int right = 0;
		for (int i = 0; i < length; i++)
		{
			DP[i][i] = 1;
		}
		for (int j = 1; j < length; j++)
		{
			for (int i = 0; i < j; i++ )
			{
				int interval = j - i;
				if (s[i] == s[j])
				{
					if (interval == 1)
						DP[i][j] = 2;
					else if (interval == 2)
						DP[i][j] = 3;
					else
						DP[i][j] = DP[i + 1][j - 1] > 0 ? 2 + DP[i + 1][j - 1] : 0;

					if (DP[i][j] > maxLen)
					{
						maxLen = DP[i][j];
						left = i;
					}
				}
			}
		}
		//for (int i = 0; i < length; i++)
		//{
		//	for (int j = i + 1; j < length; j++)
		//	{
		//		...
		//		����ѭ����ʽ����δ��ʼ���ģ�
		//	}
		//}
		return s.substr(left, maxLen);
	}
};