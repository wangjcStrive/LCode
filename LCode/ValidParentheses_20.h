#pragma once
#include "solutions.h"

/*
	20. Valid Parentheses. 有效的括号
	边界：input= "(" => false
	如果长度为奇数，直接返回false
*/


class ValidParentheses {
public:
	/*
		Runtime: 4 ms, faster than 39.40% of C++ online submissions for Valid Parentheses.
		Memory Usage: 6.4 MB, less than 23.25% of C++ online submissions for Valid Parentheses.
	*/
    bool isValid(string s) 
	{
		if (s.length() == 0)
		{
			return true;
		}

		stack<char> myStack;
		for (size_t i = 0; i < s.length(); i++)
		{
			if (s[i] == '(' || s[i] == '[' || s[i] == '{')
			{
				myStack.push(s[i]);
			}
			else
			{
				if (myStack.empty())
					return false;
				char top = myStack.top();
				myStack.pop();
				if ((s[i] == ')' && top == '(') || (s[i] == ']' && top == '[') || (s[i] == '}' && top == '{'))
					continue;
				else
					return false;
			}
		}
		if (myStack.empty())
			return true;
		else
			return false;
    }
};