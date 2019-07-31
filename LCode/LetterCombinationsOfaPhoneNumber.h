#pragma once
#include <iostream>
#include <string>
#include <vector>
using namespace std;
class LetterCombinationsOfPhoneNumber
{
	/*
	 * [17] Letter Combinations of a Phone Number
	 * DFS: deep frist search
	 * �����������ֵĸ�������forѭ���Ĳ���..
	 */
public:
	vector<string> letterCombinations(string digits)
	{
		vector<string>res;
		if (digits.empty()) return res;

		vector<string>result;
		string path="";
		DFS(digits, path, 0, result);
		return result;
	}

private:
	vector<string> m_letter = { "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz" };

	void DFS(string digits, string path, int deep, vector<string>& result)
	{
		if (deep < digits.size())
		{
			/*
				inputΪ"23"ʱ����for������abc��
				path=a --> ����"def"
					�õ�ad ae af
				path=b --> ����"def"
					�õ�bd be bf
				path=c .....
			*/
			for (auto c : m_letter[digits[deep] - '0' - 1])
			{
				path.push_back(c);
				DFS(digits, path, deep+1, result);
				path.pop_back();
			}
		}
		else  //˵���Ѿ�������������.
		{
			result.push_back(path);
			path.clear();
		}
	}



	vector<string> letterCombinations_reference(string digits) {
		vector<string>res;
		if (digits.empty()) return res;
		vector<string>letter({ "", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz" });
		string path = "";
		DFS_reference(digits, 0, path, res, letter);
		return res;
	}

	void DFS_reference(string digits, int pos, string& path, vector<string>& res, vector<string>& letter) {
		if (pos == digits.size()) {
			res.push_back(path);
			return;
		}
		for (auto c : letter[digits[pos] - '0']) {
			path.push_back(c);
			DFS_reference(digits, pos + 1, path, res, letter);
			path.pop_back();
		}
	}
};
