#pragma once
#include "solutions.h"

/*
    36. Is Valid Sudoku
	��û��accept!
*/

class IsValidSudoku_36 {
public:
	/*
		3��2ά����ֱ�������row/column/box��
		���б���ÿ������������row/column/box���Ƿ��ظ�
		����i/j�ж�����box j/3+(i/3)*3
	*/
    bool isValidSudoku(vector<vector<char>>& board) {
		int row[9][10];		//��Ϊ'1'ʱ����Ҫ��row[i][1]��ȥcheck�����Եڶ�ά��[10]
		int col[9][10];
		int box[9][10];
		for (size_t i = 0; i < 9; i++)
		{
			for (size_t j = 0; j < 9; j++)
			{
				if (board[i][j] == '.')
					continue;
				int index = board[i][j] - '0';
				if (row[i][index])	//check������
					return false;
				if (col[index][j])	//check������
					return false;
				if (box[j / 3 + (i / 3) * 3][index])	//����box
					return false;
				board[i][index] = 1;
				board[index][j] = 1;
				board[j / 3 + (i / 3) * 3][index] = 1;
			}
		}
		return true;
    }
};
