#include "solutions.h"
#include <stack>
/*
	739. Daily Temperatures
	temperatures = [73, 74, 75, 71, 69, 72, 76, 73]
	output = [1, 1, 4, 2, 1, 1, 0, 0].
*/

/*
	边界
	1. 两天温度相同时
*/

/*solution 1
	递减栈
	stack<pair<indexInVector, value>>
*/
class DailyTemperatures {
public:
	vector<int> dailyTemperatures(vector<int>& T)
	{
		// pair<index, value>
		stack <pair<unsigned int, int>> decreaseStack;
		vector<int> result(T.size());
		for (size_t i = 0; i < T.size(); i++)
		{
			if (!decreaseStack.empty())
			{
				while (!decreaseStack.empty())
				{
					pair<unsigned int, int> topItem = decreaseStack.top();
					if (T[i] > topItem.second)
					{
						result[topItem.first] = i - topItem.first;
						decreaseStack.pop();
					}
					else
						break;
				}
			}
			decreaseStack.push(make_pair(i, T[i]));
		}

		while (!decreaseStack.empty())
		{
			pair<unsigned int, int> topItem = decreaseStack.top();
			result[topItem.first] = 0;
			decreaseStack.pop();
		}

		return result;
	}
};