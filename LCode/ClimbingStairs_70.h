#pragma once
#include "solutions.h"

/*
	70. Climbing Stairs
*/

class ClimbingStairs_70 {
public:
	/*
		DP[i] = DP[i-1] + DP[i-2]
		×¢Òâinput = 0/1/2,·ÀÖ¹Ô½½ç

		Runtime: 0 ms, faster than 100.00% of C++ online submissions for Climbing Stairs.
		Memory Usage: 6.2 MB, less than 24.20% of C++ online submissions for Climbing Stairs.
	*/
	int climbStairs(int n) {
		if (n < 3)
			return n;
		vector<int> DP(n + 1, 0);
		DP[1] = 1;
		DP[2] = 2;
		for (int i = 3; i < n + 1; i++)
			DP[i] = DP[i - 1] + DP[i - 2];
		return DP[n];
	}
};