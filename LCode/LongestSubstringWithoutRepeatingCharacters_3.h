#pragma once
#include "solutions.h"



/*
	3. Longest Substring Without Repeating Characters
*/
class LongestSubstringWithoutRepeatingCharacters_3
{
public:
	int lengthOfLongestSubstring(string s) {
		int result = 0;
		int length = s.size();
		if (length == 0)
			return result;
		vector<int> charList(26, 0);
		int tempMaxLen = 0;
		for (int i = 0; i < length; i++)
		{
			if (charList[s[i] - 'a'] == 1)
			{
				if (tempMaxLen > result)
					result = tempMaxLen;
			}
			else
			{
				tempMaxLen++;
				charList[s[i] - 'a'] = 1;
			}

		}
		return result;
	}

	vector<vector<int>> threeSumaaaaaaaaa(vector<int>& nums)
	{
		int i, j;
		vector<vector<int>> result;
		if (nums.size() < 3)
			return result;
		//sort
		sort(nums.begin(), nums.end());

		//front and end pointer.
		for (int k = 0; k < nums.size() - 2; k++)
		{
			int kVal = nums[k];
			for (i = k + 1, j = nums.size() - 1; i < j; )
			{
				int iVal = nums[i];
				int jVal = nums[j];

				if (iVal + jVal == abs(kVal))
				{
					result.push_back({ nums[k], nums[i], nums[j] });
					break;
				}
				else if (iVal + jVal > abs(kVal))
					j--;
				else
					i++;
			}
		}
		return result;
	}


	vector<vector<int>> threeSumaaaaa(vector<int>& nums)
	{
		int i, j;
		vector<vector<int>> result;
		if (nums.size() < 3)
			return result;
		//sort
		sort(nums.begin(), nums.end());

		//front and end pointer.
		for (int k = 0; k < nums.size() - 2; k++)
		{
			int kVal = nums[k];
			for (i = k + 1, j = nums.size() - 1; i < j; )
			{
				int iVal = nums[i];
				int jVal = nums[j];

				if (iVal + jVal == abs(kVal))
				{
					result.push_back({ nums[k], nums[i], nums[j] });
					break;
				}
				else if (iVal + jVal > abs(kVal))
					j--;
				else
					i++;
			}
		}
		return result;
	}
};