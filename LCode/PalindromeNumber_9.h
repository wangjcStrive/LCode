#pragma once
#include "solutions.h"

class PalindromeNumber_9 {
public:
    /*
        x如果等于其反转后的结果，则为回文数字. refer to [7.reverse integer]
        执行用时：24 ms, 在所有 C++ 提交中击败了29.66%的用户
        内存消耗：6.3 MB, 在所有 C++ 提交中击败了16.78%的用户
    */
    bool isPalindrome(int x) {
        if (x < 0)
            return false;
        return x == reverseInteger(x);
    }

    int reverseInteger(int x)
    {
        long result = 0;// set to long, in case over flow
        while (x != 0)
        {
            result = result * 10 + x % 10;
            x /= 10;
        }
        std::cout << "reversed result: " << result << std::endl;
        return result;
    }

    //wangjc. LCode dummy code
    int reverse(int x)
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
    int reverse_LCode(int x)
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
