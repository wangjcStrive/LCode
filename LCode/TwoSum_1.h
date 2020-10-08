#pragma once
#include "solutions.h"
#include <map>

/*
	1. Two Sum
	each input would have exactly one solution
	[3,3] => [0,1]

*/


class TwoSum_1 {
public:
	/*
		multimap不支持下标访问
		Runtime: 20 ms, faster than 59.68% of C++ online submissions for Two Sum.
		Memory Usage: 10.5 MB, less than 11.68% of C++ online submissions for Two Sum.
	*/
    vector<int> twoSum(vector<int>& nums, int target)
	{
		// map<value, index>
		multimap<int, int> myMap;
		vector<int> result;
		for (int i = 0; i < nums.size(); i++)
		{
			myMap.insert(make_pair(nums[i], i));
		}

		for (auto x : myMap)
		{
			auto findResult = myMap.equal_range(target - x.first);
			if (findResult.first != findResult.second)
			{
				for (auto iter = findResult.first; iter != myMap.end(); iter++)
				{
					if ((*iter).second != x.second)
					{
						result.push_back(x.second);
						result.push_back((*iter).second);
						break;
					}
				}
			}
			if (result.size() != 0)
				break;
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
				for (int j = 0; count <= n && i + j < myVec.size(); j++)
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

	int leastInterval_obsoleteaaaaaa(vector<char>& tasks, int n)
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
				for (int j = 0; count <= n && i + j < myVec.size(); j++)
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
