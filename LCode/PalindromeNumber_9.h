#pragma once
#include "solutions.h"

class PalindromeNumber_9 {
public:
    /*
        x%10->取最后一位. x/10->去除最后一位。变为100同理
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

    /*
        O(n)
        根据取余和除运算求出第一位与最后一位进行比较。然后通过取余和除运算去掉第一位与最后一位
        需要先计算出输入的长度
            通过计算 1221 / 1000， 得首位1
            通过计算 1221 % 10， 可得末位 1
        执行用时：24 ms, 在所有 C++ 提交中击败了29.67%的用户
        内存消耗：6.1 MB, 在所有 C++ 提交中击败了45.24%的用户
    */
    bool isPalindrome_LCode(int x)
    {
        int div = 1;
        if (x < 0)
            return false;
        while (x / div >= 10)
            div *= 10;

        while (x>0)
        {
            int left = x / div;
            int right = x % 10;
            if (left != right)
                return false;
            //去掉首位两位!
            x = (x % div) / 10;
            div /= 100; //因为去掉了两位，所以
        }
        return true;
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
