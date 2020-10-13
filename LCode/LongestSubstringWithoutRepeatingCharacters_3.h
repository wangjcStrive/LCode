#pragma once
#include "solutions.h"



/*
	3. Longest Substring Without Repeating Characters
	并不是全是字符，还有空格
	边界：
		输入为空格
		[d,v,d,f,d] => 到第二个d的时候，从V开始重新计算
*/
class LongestSubstringWithoutRepeatingCharacters_3
{
public:
	int lengthOfLongestSubstring(string s) {
		unordered_set<char> mySet;
		int left = 0;
		int result = 0;
		for (int i = 0; i < s.size(); i++)
		{
			while (mySet.find(s[i]) != mySet.end())
			{
				result = mySet.size() > result ? mySet.size() : result;
				mySet.erase(s[left]);
				left++;
			}
			mySet.insert(s[i]);
		}
		result = mySet.size() > result ? mySet.size() : result;
		return result;
	}
	int lengthOfLongestSubstring_obsolete2(string s) {
		map<char, int> hash;
		int result = 0;
		int length = s.size();

		for (int i = 0; i < length; i++)
		{
			auto it = hash.find(s[i]);
			if (it != hash.end())
			{
				result = hash.size() > result ? hash.size() : result;
				hash[s[i]] = i;
			}
			else
			{
				hash.insert(make_pair(s[i], i));
			}
		}
		result = hash.size() > result ? hash.size() : result;
		return result;
	}



	/// 一个26位的数组记录每一位是否出现过
	/// 下面方法不能处理[d,v,d,f]这种情况
	int lengthOfLongestSubstring_obsolete(string s) {
		int result = 0;
		int length = s.size();
		vector<int> charList(128, 0);
		int tempMaxLen = 0;
		for (int i = 0; i < length; i++)
		{
			if (charList[s[i] - ' '] == 1)
			{
				if (tempMaxLen > result)
					result = tempMaxLen;
				std::fill(charList.begin(), charList.end(), 0);
				tempMaxLen = 1;
			}
			else
			{
				tempMaxLen++;
			}
			charList[s[i] - ' '] = 1;
		}
		result = result < tempMaxLen ? tempMaxLen : result;
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