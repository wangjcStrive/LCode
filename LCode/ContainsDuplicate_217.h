#pragma once
#include "solutions.h"
#include <unordered_set>

/*
	217. Contains Duplicate
*/


class ContainsDuplicate_217 {
public:
    /*
    * time: 31.27%
    * memory: 46.99%
    */
    bool containsDuplicate(vector<int>& nums)
    {
        unordered_set<int> mySet;
        for (auto x : nums)
        {
            if (mySet.count(x))
                return true;
            else
                mySet.insert(x);
        }
        return false;
    }

    /*
        超时
    */
    bool containsDuplicate_sort(vector<int>& nums)
    {
        sort(nums.begin(), nums.end());
        for (int i = 0; i < nums.size()-1; i++)
        {
            if (nums[i] == nums[i + 1])
                return true;
        }
        return false;
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
