#pragma once
#include "solutions.h"



/*
	3. Longest Substring Without Repeating Characters
	������ȫ���ַ������пո�
	�߽磺
		����Ϊ�ո�
		[d,v,d,f,d] => ���ڶ���d��ʱ�򣬴�V��ʼ���¼���
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



	/// һ��26λ�������¼ÿһλ�Ƿ���ֹ�
	/// ���淽�����ܴ���[d,v,d,f]�������
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