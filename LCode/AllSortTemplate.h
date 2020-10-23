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
		���ϵ��·ָ�ֱ��ֻ������Ԫ�� -> ��������Ԫ������ -> ���µ��Ͽ�ʼmerge
		ȱ�㣺
			��Ҫռ�ö���Ŀռ�
			�ݹ鷽�����������Ƚϳ����ݹ�Ĳ���̫�࣬���ջ���
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
		//�������֣�ֱ���ָ��ֻ������Ԫ��
		//auto mid = end/2;
		auto mid = start + (end-start) / 2;		//ע��mid��λ��
		mergeSortRecursive(arr, start, mid);
		mergeSortRecursive(arr, mid + 1, end);

		//������Ѿ��ź�������merger��һ��
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
		ð��. 5 4 3 2 1 -> 4 5 3 2 1 -> ... -> 4 3 2 1 5
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
		ѡ��
		unstable
		O(N^2)
		��ʣ������������С��.
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
		����
		O(N^2)
		stabe
		С��ģ���ݻ��������ʱ�Ƚϸ�Ч
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
