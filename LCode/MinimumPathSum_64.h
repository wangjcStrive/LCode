#pragma once
#include "solutions.h"

/*
	64. Minimum Path Sum
*/
class MinimumPathSum_64
{
public:
	/*
		DP[i][j]，到(i,j)位置的最小路径和

		Runtime: 20 ms, faster than 75.74% of C++ online submissions for Minimum Path Sum.
		Memory Usage: 10.2 MB, less than 34.23% of C++ online submissions for Minimum Path Sum.
	*/
	int minPathSum(vector<vector<int>>& grid)
	{
		int m = grid.size();
		if (0 == m)
			return 0;
		int n = grid[0].size();
		vector<vector<int>> DP(m, vector<int>(n, 0));

		//先把两边的计算出来
		DP[0][0] = grid[0][0];
		for (int j = 1; j < n; j++)
			DP[0][j] = DP[0][j - 1] + grid[0][j];
		for (int i = 1; i < m; i++)
			DP[i][0] = DP[i - 1][0] + grid[i][0];

		//在计算下边的
		for (int i = 1; i < m; i++)
		{
			for (int j = 1; j < n; j++)
			{
				DP[i][j] = min(DP[i - 1][j], DP[i][j - 1]) + grid[i][j];
			}
		}
		return DP[m - 1][n - 1];
	}


	/*
		递归
		超时。当二维数组比较大时，耗时太严重了
	*/
	int minPathSum_recursive(vector<vector<int>>& grid)
	{
		int m = grid.size();
		if (0 == m)
			return 0;
		int n = grid[0].size();
		return recursive(grid, m - 1, n - 1);
	}


	int recursive(vector<vector<int>>& grid, int row, int column)
	{
		if (row == 0 && column == 0)
		{
			return grid[0][0];
		}

		int topValue = 0;
		if (row == 0)
		{
			for (int j = 0; j < column; j++)
			{
				topValue += grid[0][j];
			}
		}
		else
		{
			topValue = recursive(grid, row - 1, column);
		}

		int leftValue = 0;
		if (column == 0)
		{
			for (int i = 0; i < row; i++)
			{
				leftValue += grid[i][0];
			}
		}
		else
		{
			leftValue = recursive(grid, row, column - 1);
		}

		return min(topValue, leftValue) + grid[row][column];
	}
};