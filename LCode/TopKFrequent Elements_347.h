#pragma once
#include "solutions.h"
#include <map>

/*
	347. Top K Frequent Elements
*/

class TopKFrequentElements_347 {
public:

    vector<int> topKFrequent(vector<int>& nums, int k)
    {
        vector<int> result;
        //sort(nums.begin(), nums.end());
        map<int, int> myMap;
        for (int i=0; i<nums.size(); i++)
        {
            if (myMap.count(nums[i]) > 0)
            {
                myMap[i]++;
            }
        }
        
    }


    //wangjc. LCode dummy code
    int dummy_reverse(int x)
    {
        long result = 0;
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
            result = result * 10 + x;
        }
        if (result < INT_MIN || result > INT_MAX)
            return 0;
        return result * isNegtive;
    }
    int dummy_reverse_LCode(int x)
    {
        int result = 0;
        while (x != 0)
        {
            int pop = x % 10;
            if (result > INT_MAX / 10 || (result == INT_MAX / 10 && pop > 7))
                return 0;
            if (result < INT_MIN / 10 || (result == INT_MIN / 10 && pop < -8))
                return 0;

            result = result * 10 + pop;
            x /= 10;
        }
        return result;
    }
};
