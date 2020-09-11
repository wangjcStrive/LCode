#pragma once
#include "solutions.h"

/*
	暴力解法 O(m*n). m:stirng长度。 n: vector长度
	边界
		input("abafx", {"bafx", "afx", "ab"}) => true
		"aaaa" ["aaa", "aaaa"] => true
		"aaaaaaa" ["aaaa","aaa"] => true
*/

class WordBreak_139 {
public:
	/*
		DFS
		leetcode"能否break，可以拆分为："l"是否是单词表的单词、剩余子串能否break，"le"是否是单词表的单词、剩余子串能否break……
		"aaaaaaa" ["aaaa","aaa"] => true. 这种情况不适用
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