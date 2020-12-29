#pragma once
#include "solutions.h"
#include <unordered_set>

/*
    结果要么是无限循环，要么是1
    input=19 output: true
        1^2 + 9^2 = 82
        8^2 + 2^2 = 68
        6^2 + 8^2 = 100
        1^2 + 0^2 + 0^2 =  1
    把计算过的结果存起来
*/

class HappyNumber_202 {
public:
    int myPow(int input)
    {
        return input * input;
    }
    /*
        执行用时：0 ms, 在所有 C++ 提交中击败了100.00%的用户
        执行用时：4 ms, 在所有 C++ 提交中击败了64.51%的用户
        内存消耗：6.5 MB, 在所有 C++ 提交中击败了33.16%的用户
    */
    bool isHappy(int n)
    {
        unordered_set<int> tempResult;
        bool result = true;
		while (n != 1)
        {
            int temp = n;
            n = 0;
            while (temp/10>0)
            {
                n += myPow(temp % 10);
                temp /= 10;
            }
            n += myPow(temp);

            if (tempResult.count(n) != 0)
            {
                result = false;
                break;
            }
            else
                tempResult.insert(n);
        }
        return result;
    }
};
