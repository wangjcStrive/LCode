#pragma once
#include "solutions.h"
#include <unordered_set>
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
		�Լ�д�ģ����Ե�
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


	/*
		DP[j]����j��β��ǰj���ַ��Ƿ��ǿɷָ��
		DP[j] = ����[0,j]�Ƿ����iʹ�ã�DP[i] && s.substr(i,j-i)�������ֵ���
		O(N^2)

		Runtime: 48 ms, faster than 20.52% of C++ online submissions for Word Break.
		Memory Usage: 12.9 MB, less than 53.36% of C++ online submissions for Word Break.
	*/
	bool wordBreak_DP(string s, const vector<string>& wordDict)
	{
		int length = s.size();
		vector<bool> DP(length, false);
		for (int j = 0; j < length; j++)
		{
			for (int i = 0; i <= j; i++)
			{
				// [0, j]����������пɷָ�ģ�������iλ�ã���ô�����ж�[i, j]֮���Ƿ�Ϊ�ɷָ�ġ�
				if (DP[i])
				{
					if (wordDict.end() != find(wordDict.begin(), wordDict.end(), s.substr(i + 1, j - i)))
						DP[j] = true;
				}
			}
			if (wordDict.end() != find(wordDict.begin(), wordDict.end(), s.substr(0, j+1)))
				DP[j] = true;
		}
		return DP[length-1];
	}

	/*
		Runtime: 40 ms, faster than 27.60% of C++ online submissions for Word Break.
		Memory Usage: 13.5 MB, less than 33.82% of C++ online submissions for Word Break.
		����unordered_set������˵��set���ұ�vector�죬Ӧ�û��һ�㣬����ò��û�п�ܶ�
	*/
	bool wordBreak_DP_set(string s, const vector<string>& wordDict)
	{
		int length = s.size();
		vector<bool> DP(length, false);
		unordered_set<string> wordDictSet;
		for (auto x : wordDict)
			wordDictSet.insert(x);

		for (int j = 0; j < length; j++)
		{
			for (int i = 0; i <= j; i++)
			{
				// [0, j]����������пɷָ�ģ�������iλ�ã���ô�����ж�[i, j]֮���Ƿ�Ϊ�ɷָ�ġ�
				if (DP[i])
				{
					if(wordDictSet.find(s.substr(i + 1, j - i)) != wordDictSet.end())
						DP[j] = true;
				}
			}
			if (wordDictSet.find(s.substr(0, j+1)) != wordDictSet.end())
				DP[j] = true;
		}
		return DP[length - 1];
	}
};