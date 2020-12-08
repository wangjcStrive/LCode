#pragma once
#include "solutions.h"

/*
*   不可以使用long型
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

    /*
        执行用时：4 ms, 在所有 C++ 提交中击败了51.86%的用户
        内存消耗：6.2 MB, 在所有 C++ 提交中击败了26.29%的用户
        溢出条件
			从ans * 10 + pop > MAX_VALUE这个溢出条件来看
				当出现 ans > MAX_VALUE / 10 且 还有pop需要添加 时，则一定溢出
				当出现 ans == MAX_VALUE / 10 且 pop > 7 时，则一定溢出，7是2^31 - 1的个位数
			从ans * 10 + pop < MIN_VALUE这个溢出条件来看
				当出现 ans < MIN_VALUE / 10 且 还有pop需要添加 时，则一定溢出
				当出现 ans == MIN_VALUE / 10 且 pop < -8 时，则一定溢出，8是-2^31的个位数
    */
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
