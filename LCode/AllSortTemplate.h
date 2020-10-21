#pragma once
#include "solutions.h"

template <typename T>
inline void swap(T const& a, T const& b)
{
	T temp = a;
	a = b;
	b = temp;
}

template <class T>
class AllSort {
public:
	/*
		归并
	*/
	void mergeSort(vector<T>& arr)
	{
		vector<T> tempArr(arr);
		mergeSortRecuive(arr, tempArr, 0, arr.size()-1);
	}
private:
	void mergeSortRecuive(vector<T>&originArr, vector<T> & arr, int start, int end)
	{
		auto gap = end - start;
		if (gap<=0)
			return;
		if (gap == 1)
		{
			if (arr[start] > arr[end])
				swap(arr[start], arr[end]);
		}
		//分成两部分，分别把两部分排好序
		mergeSortRecuive(originArr, arr, start, end / 2);
		mergeSortRecuive(originArr, arr, end / 2 + 1, end);
		//下面一层的已经排好序了，后面需要把分好的两部分合并到一起
		int i = start;
		int j = start, k = end/2+1;
		while (i <= end)
		{
			originArr[i] = arr[j] < arr[k] ? arr[j] : arr[k];
			if (arr[j] < arr[k])
				j++;
			else
				k++;
		}
	}


public:
/*
	void mergeSort(vector<T>& arr)
	{
		mergeSortRecursive(arr, 0, arr.size()-1);
	}
	void mergeSortRecursive(vector<T>& arr, int start, int end)
	{
		if (end - start == 1)
		{
			if (arr[start] > arr[end])
				swap(arr[start], arr[end]);
		}
		else if (end - start == 0)
			return;
		mergeSortRecursive(arr, start, end / 2);
		mergeSortRecursive(arr, end/2+1, end);
	}
*/
	/*
		冒泡. 5 4 3 2 1 -> 4 5 3 2 1 -> ... -> 4 3 2 1 5
		O(N^2)
		stable
	*/
	void bubbleSort(vector<T>& arr)
	{
		for (int i = 0; i < arr.size(); i++)
		{
			for (int j = i+1; j < arr.size(); j++)
			{
				if (arr[i] > arr[j])
					swap(arr[i], arr[j]);
			}
		}
	}


	/*
		选择
		unstable
		O(N^2)
		从剩的里面挑出最小的.
	*/
	void selectionSort(vector<T>& arr)
	{
		int minVal, minIndex;
		
		for (int i = 0; i < arr.size(); i++)
		{
			minVal = arr[i];
			minIndex = i;
			for(int j=i; j<arr.size(); j++)
			{
				if (arr[j] < minVal)
				{
					minVal = arr[j];
					minIndex = j;
				}
			}
			swap(arr[i], arr[minIndex]);
		}
	}


	/*
		插入
		O(N^2)
		stabe
		小规模数据或基本有序时比较高效
	*/
	void insertSort(vector<T>& arr)
	{
		for (int i = 1; i < arr.size(); i++)
		{
			for (int j = 0; j < i; j++)
			{
				if (arr[i] < arr[j])
				{
					T temp = arr[i];
					for (int k = i; k > j; k--)
					{
						swap(arr[k - 1], arr[k]);
					}
					arr[j] = temp;
				}
			}
		}
	}
};
