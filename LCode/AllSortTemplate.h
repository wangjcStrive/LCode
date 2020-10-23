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
		由上到下分割直到只有两个元素 -> 把这两个元素排序 -> 由下到上开始merge
		缺点：
			需要占用额外的空间
			递归方法，如果输入比较长，递归的层数太多，造成栈溢出
	*/
	void mergeSort(vector<T>& arr)
	{
		mergeSortRecursive(arr, 0, arr.size() - 1);
	}
private:
	void mergeSortRecursive(vector<T>& arr, int start, int end)
	{
		auto gap = end - start;
		if (gap <= 0)
			return;
		if (gap == 1)
		{
			if (arr[start] > arr[end])
				swap(arr[start], arr[end]);
			return;
		}
		//分两部分，直到分割的只有两个元素
		//auto mid = end/2;
		auto mid = start + (end-start) / 2;		//注意mid的位置
		mergeSortRecursive(arr, start, mid);
		mergeSortRecursive(arr, mid + 1, end);

		//下面的已经排好序，现在merger到一起
		int m = start, n = mid + 1;
		vector<T> tempVec;
		for (int i = start; i <= end; i++)
		{
			if (m > mid)
				tempVec.push_back(arr[n++]);
			else if(n>end)
				tempVec.push_back(arr[m++]);
			else
				tempVec.push_back(arr[m] < arr[n] ? arr[m++] : arr[n++]);

		}
		std::copy(tempVec.begin(), tempVec.end(), arr.begin() + start);
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
