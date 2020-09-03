#include "solutions.h"
#include <stack>

/*
	394. Decode String
	Example:
		s = "3[a]2[bc]", return "aaabcbc".
		s = "3[a2[c]]", return "accaccacc".
		s = "2[abc]3[cd]ef", return "abcabccdcdcdef".
	边界:
		1. 数字不止一位 -> 数字非常大，越界
		2. 3[a2[bc]d] -> ]后面还有字母
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
		递归，其实跟用stack差不多，递归也是在栈里
	*/
	string decodeString_recursive(string s)
	{
		for (size_t i = 0; i < s.length(); i++)
		{

		}
	}

	string func(string s, int i, int step, int count)
	{
		if (s[i] == '[')
			func(s, i + 1, step++, count);
		else if (s[i] >= '0' && s[i] <= '9')
			count = count * 10 + (s[i] - '0');
	}



	/*
	 * input =  3[a]2[bc] => 3 * {a + 2 *(bc) }
	 * 遇到'['时push到stack
	 * 遇到']'时用上面公式pop
	 */
	string decodeString_stack(string s)
	{
		stack<pair<string, int>> myStack;
		string str = "";
		string result = "";
		string tempResult = "";
		unsigned int num = 0;
		for (size_t i = 0; i < s.length(); i++)
		{
			if (s[i] >= '0' && s[i] <= '9')
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
			else if (s[i] == ']')
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

	/*
		两个stack
		Info:
			字符可能是：数字、字母、括号
			遇到数字 => tempStr非空，tempStr入栈
			遇到'['  => 数字入栈
			遇到']'  => 之前存下的str + tempStr
		边界：
			数字不止一位的问题
			2[a3[b]c]里的c的处理

	*/
	string decodeString(string s)
	{
		string res = "";
		stack <int> nums;
		stack <string> strs;
		int num = 0;
		int len = s.size();
		for (int i = 0; i < len; ++i)
		{
			if (s[i] >= '0' && s[i] <= '9')
			{
				num = num * 10 + s[i] - '0';
			}
			else if ((s[i] >= 'a' && s[i] <= 'z') || (s[i] >= 'A' && s[i] <= 'Z'))
			{
				res = res + s[i];
			}
			else if (s[i] == '[') //将‘[’前的数字压入nums栈内， 字母字符串压入strs栈内. 第一次遇到'['时，res是空，也需要push到strs里去!!!
			{
				nums.push(num);
				num = 0;
				strs.push(res);
				res = "";
			}
			else //遇到‘]’时，操作与之相配的‘[’之间的字符，使用分配律
			{
				int times = nums.top();
				nums.pop();
				for (int j = 0; j < times; ++j)
					strs.top() += res;
				res = strs.top(); //之后若还是字母，就会直接加到res之后，因为它们是同一级的运算
								  //若是左括号，res会被压入strs栈，作为上一层的运算
				strs.pop();
			}
		}
		return res;
	}
};