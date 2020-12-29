#pragma once
#include "solutions.h"

/*
	438. Find All Anagrams in a String
*/

class  FindAllAnagramsinAString_438 {
public:
    vector<int> findAnagrams(string s, string p)
    {
        int pLen = p.length();
        int sLen = s.length();
        
        int counts[26]{};
        for (char x : s)
        {
            counts[x-'a']++;
        }
    }
    // 超时
    vector<int> findAnagrams_own_overTime(string s, string p)
    {
        string sortedStr = p;
        int pLen = p.length();
        vector<int> result;
        sort(sortedStr.begin(), sortedStr.end());
        int temp = s.length() - pLen;
        for (int i = 0; i <= temp; i++)
        {
            string tempStr = s.substr(i, pLen);
            sort(tempStr.begin(), tempStr.end());
            if (sortedStr == tempStr)
                result.push_back(i);
        }
        return result;
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
