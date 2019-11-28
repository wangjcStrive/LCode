#pragma once
#include "solutions.h"

/*
	https://github.com/MisterBooo/Article gif to show all sort algorithem
	Ҫ���ǵ�����ֵͬ�����
*/

class Sort
{
public:
	Sort() {};
	~Sort() {};
	void swap(int& a, int& b);
	void bubbleSort(vector<int>& input);
	void SelectionSort(vector<int>& array);
	void insertSort(vector<int>& array);
	void shellSort(vector<int>& array);
	vector<int> mergeSort(vector<int> input);
	void shellSort(vector<int> input);
private:

};

/*
	O( n * log(n) )
*/
inline vector<int> Sort::mergeSort(vector<int> input)
{
	return vector<int>();
}

void Sort::swap(int& a, int& b)
{
	int x = a;
	a = b;
	b = x;
}

/*
	ð��
*/
void Sort::bubbleSort(vector<int>& input)
{
	int i, j;
	int len = input.size();
	/*
		O(n^2) �ȶ�
		i�ǵڼ��ˣ�ÿ�����꣬���Ὣ����ֵ�ŵ����
	*/
	for (i = 0; i < len - 1; i++)
	{
		for (j = 0; j < len - 1 - i; j++)
		{
			if (input[j] > input[j + 1])
				swap(input[j], input[j + 1]);
		}
	}
}

/*
	ѡ������
	O(n^2) ���ȶ�����
	��ʣ������������С��.
*/
inline void Sort::SelectionSort(vector<int>& array)
{
	int i, j;
	int len = array.size();
	int minVal;
	int minIndex;
	//����Сֵ�浽array[i]��
	for (i = 0; i < len; i++)
	{
		minVal = array[i];
		minIndex = i;
		for (j = i; j < len; j++)
		{
			if (array[j] < minVal)
			{
				minVal = array[j];
				minIndex = j;
			}
		}
		swap(array[i], array[minIndex]);
	}
}

/*
	��������
	O(n^2)
	stable
	��������С��ģ���ݻ��߻�������ʱ�Ƚϸ�Ч��
*/
inline void Sort::insertSort(vector<int>& array)
{
	int i, j, len=array.size();
	int currentMin;
	
	for ( i = 1; i < len; i++)
	{
		for ( j = 0; j < i; j++)
		{
			if (array[i] < array[j])
			{
				currentMin = array[i];
				for (int k = i; k > j; k--)
				{
					swap(array[k - 1], array[k]);
				}
				array[j] = currentMin;
			}
		}
	}
}

/*
	ϣ�����򡣲������������. https://blog.csdn.net/qq_39207948/article/details/80006224
	�Խϴ��ģ��������������Ҳ�ܸ�Ч
*/
inline void Sort::shellSort(vector<int>& array)
{
}


