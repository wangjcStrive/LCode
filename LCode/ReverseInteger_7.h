#pragma once
#include "solutions.h"

/*
    假设我们的环境只能存储得下 32 位的有符号整数，则其数值范围为 [−231,  231 − 1]。请根据这个假设，如果反转后整数溢出那么就返回0
*/

class ReverseInteger_7 {
public:
    /*
        这个太蠢了。时间复杂度O(n). 空间复杂度O(n)
        执行用时：8 ms, 在所有 C++ 提交中击败了6.22%的用户
        内存消耗：6.4 MB, 在所有 C++ 提交中击败了6.64%的用户
    */
    int reverse(int x)
    {
        long result=0;
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
};
