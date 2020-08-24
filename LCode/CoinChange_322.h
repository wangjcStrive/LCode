#include "solutions.h"

/*
    322. Coin Change
    Input: coins = [1, 2, 5], amount = 11
    Output: 3 
    Explanation: 11 = 5 + 5 + 1

    边界：
    Input: coins = [2], amount = 3
    Output: -1
*/
class CoinChangeDP {
public:
    /*
        大的取决于小的，所以从小的开始算
        [1,2,5] => 11:
        D[0] = 0
        D[1] = 1
        D[2] = 1 + D[1]
        D[3] = 1 + min{D(3-1), D(3-2)}
        D[6] = 1 + min{D[6-1], D[6-2], D[6-5]} = ...

        Runtime: 96 ms, faster than 73.40% of C++ online submissions for Coin Change.
        Memory Usage: 14.1 MB, less than 50.40% of C++ online submissions for Coin Change.
    */
    int coinChange(vector<int>& coins, int amount) 
    {
        vector<int> D(amount+1);
        D[0] = 0;
        for (size_t i = 1; i <= amount; i++)
        {
            int minValue = INT_MAX;
            for (int changes:coins)
            {
                if (i>=changes)
                {
                    if (D[i-changes] != -1 && minValue > D[i - changes])
                        minValue = D[i - changes];
                }
            }
            D[i] = minValue == INT_MAX ? -1 : minValue + 1;
        }
        return D[amount];
    }
};