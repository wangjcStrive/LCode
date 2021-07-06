#pragma once
#include "solutions.h"
#include <map>

/*
	347. Top K Frequent Elements
*/

typedef pair<int, int> PAIR;
bool cmpByValue(const PAIR& lhs, const PAIR& rhs)
{
	return lhs.second > rhs.second;
}
struct CmpByValue {
    bool operator()(const PAIR& lhs, const PAIR& rhs) {
        return lhs.second > rhs.second;
    }
};
class TopKFrequentElements_347 {
public:
    /*
        time: 9.79%. memory: 14.61%
        效率太低了
    */
    vector<int> topKFrequent_map(vector<int>& nums, int k)
    {
        map<int, int> myMap;
        for (int i=0; i<nums.size(); i++)
        {
            if (myMap.count(nums[i]) > 0)
                myMap[nums[i]]++;
            else
                myMap.insert(make_pair(nums[i], 1));
        }
        vector<PAIR> sortedVec(myMap.begin(), myMap.end());
        //sort(sortedVec.begin(), sortedVec.end(), CmpByValue());
        sort(sortedVec.begin(), sortedVec.end(), cmpByValue);
        
        vector<int> result;
        for (int i = 0; i < k; i++)
        {
            result.push_back(sortedVec[i].first);
        }
        
        return result;
    }

    /*
        
    */
    vector<int> topKFrequent(vector<int>& nums, int k)
    {
        vector<int> result;
        sort(nums.begin(), nums.end(), greater<int>());
        int temp = nums[0];
        for(int i=0; i<nums.size() && k>0; i++)
        {
            if (temp = nums[i])
                continue;
            else
            {
                result.push_back(nums[i]);
                k--;
                temp = nums[i];
            }
        }
        return result;
    }


    //wangjc. LCode dummy code
    int dummy_reverse(int x)
    {
        long sortedVec = 0;
        vector<int> arr;
        int isNegtive = x > 0 ? 1 : -1;
        x = abs(x);
        while (x / 10 != 0)
        {
            arr.push_back(x % 10);
            x /= 10;
        }
        arr.push_back(x);
        for (auto x : arr)
        {
            sortedVec = sortedVec * 10 + x;
        }
        if (sortedVec < INT_MIN || sortedVec > INT_MAX)
            return 0;
        return sortedVec * isNegtive;
    }
    int dummy_reverse_LCode(int x)
    {
        int sortedVec = 0;
        while (x != 0)
        {
            int pop = x % 10;
            if (sortedVec > INT_MAX / 10 || (sortedVec == INT_MAX / 10 && pop > 7))
                return 0;
            if (sortedVec < INT_MIN / 10 || (sortedVec == INT_MIN / 10 && pop < -8))
                return 0;

            sortedVec = sortedVec * 10 + pop;
            x /= 10;
        }
        return sortedVec;
    }
};
