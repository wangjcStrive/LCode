#pragma once
#include "solutions.h"

/*
	https://github.com/MisterBooo/Article gif to show all sort algorithem
	要考虑到有相同值的情况
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
	O( n * log(n) ). 稳定排序
	分治. 递归
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
	冒泡
*/
void Sort::bubbleSort(vector<int>& input)
{
	int i, j;
	int len = input.size();
	/*
		O(n^2) 稳定
		i是第几趟，每趟走完，都会将最大的值排到最后
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
	选择排序
	O(n^2) 不稳定排序
	从剩的里面挑出最小的.
*/
inline void Sort::SelectionSort(vector<int>& array)
{
	int i, j;
	int len = array.size();
	int minVal;
	int minIndex;
	//将最小值存到array[i]处
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
	插入排序
	O(n^2)
	stable
	插入排序。小规模数据或者基本有序时比较高效。
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
	希尔排序。插入排序的升级. https://blog.csdn.net/qq_39207948/article/details/80006224
	对较大规模，相对无序的数据也很高效
	首先它把较大的数据集合分割成若干个小组（逻辑上分组），然后对每一个小组分别进行插入排序，此时，插入排序所作用的数据量比较小（每一个小组），插入的效率比较高
	非稳定排序，虽然插入排序是稳定的，但是有的时候是跳跃性插入的，可能会破坏稳定性
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
	网上的算法还没有搞懂
*/
inline void Sort::shellSort(vector<int> &array, int n)
{
	int i, j, k, gap;
	for (gap = n / 2; gap > 0; gap = gap / 2)
	{ //步长
		for (i = 0; i < gap; i++)
		{  //直接插入排序的次数；也就是在每个分组中需要进行几次直接插入排序；
			//开始进行插入排序，每次加gap的步长；
			for (j = i + gap; j < n; j = j + gap)
			{
				if (array[j] < array[j - gap])
				{
					//保存后面的值；
					int temp = array[j];
					for (k = j - gap; k >= 0 && array[k] > temp; k = k - gap) {
						//先把前面的数往后移；
						array[k + gap] = array[k];
					}
					array[k + gap] = temp;
				}
			}
		}
	}
}