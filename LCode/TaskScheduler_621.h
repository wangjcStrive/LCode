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
		n+1������Ϊһ�֣�ͬһ����һ���������ֻ�ܱ�����һ�Ρ�ÿһ��ѡ��ʣ���������n+1����������ִ��
		��һ��26λ��vector��ÿһλ����һ���ַ�

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
			//ÿһ����n���ַ�������idle
			for (; i <= n; i++)
			{
				//���һ���ַ���������
				if (charCount[0] == 0)
					break;
				if(i<26)
					charCount[i]--;
				result++;
			}
			//�е��ַ��Ѿ���Ϊ0�ˣ��������򣬰Ѻ��滹û�õ��ַ��ŵ���ǰ��λ��
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

	int leastInterval_LC(vector<char>& tasks, int n) {
		/*
			26λ�����飬ÿλ������ַ����ֵĴ���
		*/
		vector<int> freq(26);
		for (char c : tasks) 
			freq[c - 'A']++;

		sort(freq.begin(), freq.end());
		int res = (n + 1) * (freq[25] - 1);
		for (int i = 25; i >= 0; --i)
		{
			if (freq[i] == freq[25])
				res++;
		}
		return max(res, (int)tasks.size());
	}


	int countSubstrings(string s)
	{
		unsigned int result = 0;
		int length = s.size();
		vector<vector<bool>> DP(length, vector<bool>(length, false));
		for (int j = 0; j < length; j++)
		{
			for (int i = 0; i <= j; i++)
			{
				int temp = j - i;
				if (temp == 0)
				{
					DP[i][j] = true;
					result++;
				}
				else if (temp == 1)
				{
					if (s[i] == s[j])
					{
						DP[i][j] = true;
						result++;
					}
				}
				else
				{
					if (s[i] == s[j] && DP[i + 1][j - 1] == true)
					{
						DP[i][j] = true;
						result++;
					}
				}
			}
		}
		return result;
	}

	int countSubstringaaaas(string s)
	{
		unsigned int result = 0;
		int length = s.size();
		vector<vector<bool>> DP(length, vector<bool>(length, false));
		for (int j = 0; j < length; j++)
		{
			for (int i = 0; i <= j; i++)
			{
				int temp = j - i;
				if (temp == 0)
				{
					DP[i][j] = true;
					result++;
				}
				else if (temp == 1)
				{
					if (s[i] == s[j])
					{
						DP[i][j] = true;
						result++;
					}
				}
				else
				{
					if (s[i] == s[j] && DP[i + 1][j - 1] == true)
					{
						DP[i][j] = true;
						result++;
					}
				}
			}
		}
		return result;
	}
};
