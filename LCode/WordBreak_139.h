#pragma once
#include "solutions.h"

/*
	�����ⷨ O(m*n). m:stirng���ȡ� n: vector����
	�߽�
		input("abafx", {"bafx", "afx", "ab"}) => true
		"aaaa" ["aaa", "aaaa"] => true
		"aaaaaaa" ["aaaa","aaa"] => true
*/

class WordBreak_139 {
public:
	/*
		DFS
		leetcode"�ܷ�break�����Բ��Ϊ��"l"�Ƿ��ǵ��ʱ�ĵ��ʡ�ʣ���Ӵ��ܷ�break��"le"�Ƿ��ǵ��ʱ�ĵ��ʡ�ʣ���Ӵ��ܷ�break����
		"aaaaaaa" ["aaaa","aaa"] => true. �������������
	*/
	bool wordBreak(string s, const vector<string>& wordDict)
	{
		if (s.size() == 0)
			return true;

		int startPosition = 0;
		int strLen = s.size();
		bool result = false;
		for (int i = 0; i < strLen; i++)
		{
			string tempStr = s.substr(startPosition, i - startPosition + 1);
			auto findResult = find(wordDict.begin(), wordDict.end(), tempStr);
			if (findResult == wordDict.end())
				continue;
			else
			{
				startPosition = i + 1;
				result = wordBreak(s.substr(startPosition, strLen - startPosition), wordDict);
			}
		}
		if (startPosition == strLen)
			result = true;
		else
			result = false;

		return result;
	}

	bool wordBreak_DFS(string s, vector<string>& wordDict) {
		set<string> word(wordDict.begin(), wordDict.end());
		vector<int> memo(s.size(), -1);
		return dfs(s, word, memo, 0);
	}

	bool dfs(string s, set<string>& word, vector<int>& memo, int start)
	{
		if (start > s.size() - 1)
			return true;
		if (memo[start] != -1)
			return memo[start];
		for (int end = start + 1; end <= s.size(); ++end)
		{
			if (word.find(s.substr(start, end - start)) != word.end() && dfs(s, word, memo, end))
			{
				memo[start] = 1;
				return true;
			}
		}
		memo[start] = 0;
		return false;
	}
};