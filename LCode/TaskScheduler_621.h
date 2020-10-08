#pragma once
#include "solutions.h"
#include <map>

/*
	621. Task Scheduler
*/
bool cmpVec(pair<char, int> left, pair<char, int> right)
{
	return left.second > right.second;
}

class TaskScheduler_621 {
public:
	/*
		应当尽早安排出现次数较多的任务
		n+1个任务为一轮，同一轮中一个任务最多只能被安排一次。每一轮选择剩余次数最多的n+1个任务依次执行
		用一个26位的vector，每一位代替一个字符

		Runtime: 208 ms, faster than 39.30% of C++ online submissions for Task Scheduler.
		Memory Usage: 34.5 MB, less than 76.66% of C++ online submissions for Task Scheduler.
	*/
	int leastInterval(vector<char>& tasks, int n)
	{
		int result = 0;
		vector<int> charCount(26);
		for (auto x : tasks)
			charCount[x - 'A']++;

		sort(charCount.begin(), charCount.end(), greater<int>());

		while (charCount[0]!=0)
		{
			int i = 0;
			//每一轮有n个字符，包含idle
			for (; i <= n; i++)
			{
				//最后一个字符处理完了
				if (charCount[0] == 0)
					break;
				if(i<26)
					charCount[i]--;
				result++;
			}
			//有的字符已经变为0了，重新排序，把后面还没用的字符排到靠前的位置
			sort(charCount.begin(), charCount.end(), greater<int>());
		}
		return result;
	}


    int leastInterval_obsolete(vector<char>& tasks, int n)
	{
		int result = 0;
		vector<pair<char, int>> myVec;
		bool isFind = false;
		for (auto x : tasks)
		{
			isFind = false;
			for (int i = 0; i < myVec.size(); i++)
			{
				if (myVec[i].first == x)
				{
					myVec[i].second++;
					isFind = true;
					break;
				}
			}
			if (!isFind)
				myVec.push_back(make_pair(x, 1));
		}

		sort(myVec.begin(), myVec.end(), cmpVec);

		for (int i = 0; i < myVec.size(); i++)
		{
			while (myVec[i].second != 0)
			{
				int count = 0;
				for (int j = 0; count <= n && i+j<myVec.size(); j++)
				{
					if (myVec[i + j].second > 0)
					{
						myVec[i + j].second--;
						if (myVec[i + j].second == 0)
							myVec.erase(myVec.begin() + i + j);
						count++;
						result++;
					}
				}
				while (count <= n)
				{
					result++;
					count++;
				}
			}
		}
		return result;
    }
};
