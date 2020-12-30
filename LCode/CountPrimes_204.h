#pragma once
#include "solutions.h"


/*
	204. Count Primes.小于n的质数数量
*/


class CountPrimes_204 {
public:
	/*
		遍历小于n的每个数，看是否为质数(如果n%[n-1, 1)都不是0，则n为质数)
	*/
	int countPrimes(int n) {
		int count = 0;
		for (; n > 1; n--)
		{
			int subVal = n - 1;
			for (; subVal > 1; subVal--)
			{
				if (n % subVal == 0)
					break;
			}
			if (subVal == 1)
				count++;
		}
		return count;
	}

	/*
		自底向上的思路
		执行用时：328 ms, 在所有 C++ 提交中击败了31.75%的用户
		内存消耗：6.7 MB, 在所有 C++ 提交中击败了62.81%的用户
	*/
	int countPrimesDP(int n)
	{
		int count = 0;
		vector<bool> table(n + 1, true);
		for (int i = 2; i < n; i++)
		{
			if (table[i] == false)
				continue;
			for (int  j = i*2; j < n; j+=i) 
			{
				table[j] = false;
			}
		}
		for (int i = 2; i < n; i++)
		{
			if (table[i] == true)
				count++;
		}
		return count;
	}
};
