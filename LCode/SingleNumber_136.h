#pragma once
#include "solutions.h"
#include <map>

/*
	136. Single Number
*/


class SingleNumber_136 {
public:
    int singleNumber(vector<int>& nums) {
        map<int, int> myMap;
        for (auto x : nums)
        {
            if (myMap.find(x) != myMap.end())
                myMap.erase(x);
            else
                myMap.insert(make_pair(x, 1));
        }
        return (*(myMap.begin())).first;

    }
};
