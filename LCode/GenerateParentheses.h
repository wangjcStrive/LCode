#pragma once
#include "solutions.h"

//22. Generate Parentheses
/*
	����
	�������ȳ��֣�����Ϊ0~n���ȶ������Ž��еݹ鵽�ף�������left<n���ٶ������ŵݹ飬����Ϊ
	right<left
*/
//��left<rightʱ�����Ų�ƥ��

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
