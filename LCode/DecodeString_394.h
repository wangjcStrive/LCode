#include "solutions.h"
#include <stack>

/*
	394. Decode String
	Example:
		s = "3[a]2[bc]", return "aaabcbc".
		s = "3[a2[c]]", return "accaccacc".
		s = "2[abc]3[cd]ef", return "abcabccdcdcdef".
	边界:
		1. 数字不止一位
		2. 3[a2[bc]d]
	思路：
		需要从内向外生成与拼接字符串，这与栈的先入后出特性对应。
*/

class DecodeString {
	enum  characterType
	{
		Unknown = 0,
		Number,
		charType,
		LeftsquareBrackets,
		RightSquarebrackets
	};
public:
	/*
	 * input =  3[a]2[bc] => 3 * {a + 2 *(bc) }
	 * 遇到'['时push到stack
	 * 遇到']'时用上面公式pop
	 */
	string decodeString(string s)
	{
		stack<pair<string, int>> myStack;
		string str = "";
		string result = "";
		string tempResult = "";
		unsigned int num = 0;
		for (size_t i = 0; i < s.length(); i++)
		{
			if (s[i]>='0' && s[i]<='9')
			{
				num = num * 10 + (s[i] - '0');
			}
			else if (s[i] == '[')
			{
				myStack.push(make_pair(str, num));
				num = 0;
				str = "";
			}
			else if (s[i] == ']')
			{
				pair<string, int> stackTop = myStack.top();
				myStack.pop();
				string temp = "";
				for (size_t i = 0; i < stackTop.second; i++)
				{
					temp += str;
				}
				str = stackTop.first + temp;
				//str = "";
			}
			else // string
			{
				str += s[i];
			}
		}
		if (str != "")
		{
			result += str;
		}
		return result;
	}

	string decodeString_NotAccept(string s)
	{
		unsigned int layerCount = 0;
		characterType type = Unknown;
		stack<string> myStack;
		string result = "";
		string subStr = "";
		for (size_t i = 0; i < s.length(); i++)
		{
			if (isNum(s[i]))
			{
				if (type != Number && subStr != "")
				{
					myStack.push(subStr);
					subStr = "";
				}
				subStr += s[i];
				type = Number;
			}
			else if (s[i] == '[')
			{
				myStack.push(subStr);
				subStr = "";
				type = Unknown;
				layerCount++;
			}
			else if(s[i] == ']')
			{
				layerCount--;
				int count = stoi(myStack.top());
				for (size_t i = 0; i < count; i++)
				{
					subStr += subStr;
				}
				if (layerCount > 0)
				{
					myStack.pop();
					myStack.push(subStr);

				}
					subStr = "";
					type = Unknown;
				result = subStr + result;
			}
			else
			{
				if (type != charType && subStr != "")
				{
					myStack.push(subStr);
					subStr = "";
				}
				type = charType;
				subStr += s[i];
			}
		}
		if (subStr != "")
		{
			result = result + subStr;
		}
		return result;
	}

	bool isNum(char letter)
	{
		if (letter >= '0' && letter <= '9')
			return true;
		else
			return false;
	}
};