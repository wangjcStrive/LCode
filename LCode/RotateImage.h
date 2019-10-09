#pragma once
#include "solutions.h"

/*
	48. Rotate Image
*/

class RotateImage {
public:
	void rotate(vector<vector<int>>& matrix) {
		vector<vector<int>> copy = matrix;
		int n = matrix[0].size();
		for (int i = 0; i < n; i++)
			for (int j = 0; j < n; j++)
				matrix[i][j] = copy[n - j - 1][i];
	}
};
