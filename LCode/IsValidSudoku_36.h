#pragma once
#include "solutions.h"

/*
    36. Is Valid Sudoku
	还没有accept!
*/

class IsValidSudoku_36 {
public:
	/*
		3个2维数组分别用来存row/column/box。
		逐行遍历每个数，看其在row/column/box中是否重复
		根据i/j判断所属box j/3+(i/3)*3
	*/
    bool isValidSudoku(vector<vector<char>>& board) {
		int row[9][10];		//当为'1'时，需要到row[i][1]里去check，所以第二维是[10]
		int col[9][10];
		int box[9][10];
		for (size_t i = 0; i < 9; i++)
		{
			for (size_t j = 0; j < 9; j++)
			{
				if (board[i][j] == '.')
					continue;
				int index = board[i][j] - '0';
				if (row[i][index])	//check所在行
					return false;
				if (col[index][j])	//check所在列
					return false;
				if (box[j / 3 + (i / 3) * 3][index])	//所在box
					return false;
				board[i][index] = 1;
				board[index][j] = 1;
				board[j / 3 + (i / 3) * 3][index] = 1;
			}
		}
		return true;
    }
};
