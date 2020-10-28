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
	void shellSort(vector<int>& array, int n);
	void shellSort_myOwn(vector<int>& array);
	void mergeSort(vector<int>& input);
	void mergeSortRecursive(vector<int> input, int start, int end);
	void mergeSortMerge(vector<int> input, int start, int end, vector<int> mergeResult);
private:

};

/*
	O( n * log(n) ). �ȶ�����
	����. �ݹ�
*/
inline void Sort::mergeSort(vector<int>& input)
{
	int i = 0;
	int j = input.size() / 2;
	mergeSortRecursive(input, i, j);
}

inline void Sort::mergeSortRecursive(vector<int> input, int start, int end)
{
	if (end - start <= 1)
	{
		if(input[start]>input[end])
			swap(input[start], input[end]);
		return;
	}
	mergeSortRecursive(input, start, end / 2);
	mergeSortRecursive(input, end / 2 + 1, start);
	//mergeSortMerge(input, start, end);
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
	�������ѽϴ�����ݼ��Ϸָ�����ɸ�С�飨�߼��Ϸ��飩��Ȼ���ÿһ��С��ֱ���в������򣬴�ʱ���������������õ��������Ƚ�С��ÿһ��С�飩�������Ч�ʱȽϸ�
	���ȶ�������Ȼ�����������ȶ��ģ������е�ʱ������Ծ�Բ���ģ����ܻ��ƻ��ȶ���
*/
inline void Sort::shellSort_myOwn(vector<int>& array)
{
	int len = array.size();
	int gap = len / 2;
	int i, j, k;
	while (gap>0)
	{
		for (i = 0; i < gap; i++) //number of sub goup is gap
		{
			vector<int> subArray;
			for (j=0, k=i+j*gap; k < len; j++, k=i+j*gap) //create subArray to use inset sort
			{
				subArray.push_back(array[k]);
			}
			insertSort(subArray);
			for (j = 0, k=i+j*gap; k < len; j++, k = i + j * gap) // copy sorted sub array to original array
			{
				array[k] = subArray[j];
			}
			
		}
		gap /= 2;
	}
}


/*
	���ϵ��㷨��û�и㶮
*/
inline void Sort::shellSort(vector<int> &array, int n)
{
	int i, j, k, gap;
	for (gap = n / 2; gap > 0; gap = gap / 2)
	{ //����
		for (i = 0; i < gap; i++)
		{  //ֱ�Ӳ�������Ĵ�����Ҳ������ÿ����������Ҫ���м���ֱ�Ӳ�������
			//��ʼ���в�������ÿ�μ�gap�Ĳ�����
			for (j = i + gap; j < n; j = j + gap)
			{
				if (array[j] < array[j - gap])
				{
					//��������ֵ��
					int temp = array[j];
					for (k = j - gap; k >= 0 && array[k] > temp; k = k - gap) {
						//�Ȱ�ǰ����������ƣ�
						array[k + gap] = array[k];
					}
					array[k + gap] = temp;
				}
			}
		}
	}
}