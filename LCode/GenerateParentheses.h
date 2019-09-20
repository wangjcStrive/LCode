#pragma once
#include "solutions.h"

//22. Generate Parentheses
/*
	回溯
	左括号先出现，个数为0~n，先对左括号进行递归到底，条件问left<n，再对右括号递归，条件为
	right<left
*/
//当left<right时，括号不匹配

class GenerateParentheses {
public:
	vector<string> generateParenthesis(int n)
	{
		vector<string> result;
		string current = "(";
		int left = 1;
		int right = 0;
		generateParenthesesRecursion(result, current, left, right, n);
		return result;
	}
private:
	void generateParenthesesRecursion(vector<string> &result, string current, int left, int right, int n)
	{
		if (left == n && right == left)
		{
			result.push_back(current);
			return;
		}
		
		if (left < n)
		{
			generateParenthesesRecursion(result, current + "(", left+1, right, n);
		}
		if (right < left)
		{
			generateParenthesesRecursion(result, current + ")", left, right+1, n);
		}
	}
};
