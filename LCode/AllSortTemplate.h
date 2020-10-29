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
	* https://www.cnblogs.com/chengxiao/p/6129630.html
		heap.��һ��ѡ��������ã����ƽ�����ӶȾ�ΪO(nlogn). ���ȶ�
		�������������ʵ���ȫ��������ÿ���ڵ��ֵ�����ڻ���������Һ��ӽڵ��ֵ���󶥶�
		�����ӽڵ�ֱ���2i+1/2i+2
		˼·
			1. �����������й����һ���󶥶ѣ���ʱ�������е����ֵ���ǶѶ��ĸ��ڵ㡣
			2. �ظ������ڵ���ĩβԪ�ؽ�������ʱĩβ�������ֵ.ĩβԪ�ػ������ڵ����Ҫ������������"���ڵ���ӽڵ��"�����Ǵ�ʱ���г��ȼ�1
			3. 
	*/
	void heapSort(vector<T>& arr)
	{
		int length = arr.size();
		// ԭ���й����һ���󶥶�. O(n/2)
		for (auto i = length / 2 - 1; i>=0; i--)
			adjustArrToSatisfyHeap(arr, length, i);

		// �ظ��������ڵ��ĩβ�ڵ�. O(logn)?
		for (int tail = length - 1; tail > 0; tail--)
		{
			swap(arr[0], arr[tail]);
			adjustArrToSatisfyHeap(arr, tail, 0);
		}

	}
	/*
		len: �޶����г��ȡ�
		index: ʹ��index���µ����нڵ�����"���ڵ���ӽڵ��"
	*/
	void adjustArrToSatisfyHeap(vector<T>& arr, int len, int index)
	{
		int leftSon = 2 * index+1, rightSon = 2 * index + 2;
		int maxIndex = index;
		if (leftSon < len && arr[leftSon] > arr[index])
			maxIndex = leftSon;
		if (rightSon < len && arr[rightSon] > arr[maxIndex])
			maxIndex = rightSon;
		if (maxIndex != index)
		{
			swap(arr[index], arr[maxIndex]);
			// ������Ҫ����,���µ��������������ӽڵ�
			adjustArrToSatisfyHeap(arr, len, maxIndex);
		}
	}

	/*
		quick sort.  ���Ρ�
		ƽ��O(nlogn),�O(n^2)��ͨ�����Ŷ���Ҫ��O(nlogn)��ġ�
		�Ǵ���������������򷽷���O(nlogn) �Ǻ��������ĳ������Ӻ�С���ȸ��Ӷ��ȶ����� O(nlogn) �Ĺ鲢����ҪС�ܶࡣ���ԣ��Ծ������˳���Խ�����������ж��ԣ����������������ڹ鲢����
	*/
	void quickSort(vector<T>& arr, int low, int high)
	{
		if (low < high)
		{
			int pivot = partition(arr, low, high); //������һ��󣬴���pivot��ֵ���ں��棬С��pivot��ֵ���ں�����
			quickSort(arr, low, pivot - 1);
			quickSort(arr, pivot + 1, high);
		}
	}

	int partition(vector<T>& arr, int low, int high)
	{
		int pivot = arr[low];
		while (low < high)
		{
			// ���������ҵ�С��pivot��Ԫ�أ�Ȼ�󽻻���low��λ��
			while (low < high && arr[high] >= pivot)
				high--;
			arr[low] = arr[high];
			// �������ң��ҵ�����pivot��Ԫ�أ�������high��λ��
			while (low < high && arr[low] <= pivot)
				low++;
			arr[high] = arr[low];
		}
		arr[low] = pivot;

		return low;
	}

	/*
		shell
	*/
	void shellSort(vector<T>& arr)
	{
		size_t length = arr.size();
		for (size_t gap = length / 2; gap != 0; gap /= 2)
		{
			for (size_t i = 0; i < gap; i++)	//����
			{
				for (size_t j = i; j < length; j += gap)	//��ÿ����в�������
				{
					for (size_t k = i; k < j; k += gap)
					{
						if (arr[k] > arr[j])
							swap(arr[k], arr[j]);
					}
				}
			}
		}
	}

	/*
		�鲢����
		���ϵ��·ָ�ֱ��ֻ������Ԫ�� -> ��������Ԫ������ -> ���µ��Ͽ�ʼmerge
		���Ӷ�
			ʱ�䣺O(nlogn):ʹ���˶��ַ�������ָ�
			�ռ䣺O(n)
		�ȶ�����
		ȱ�㣺
			��Ҫռ�ö���Ŀռ�
			�ݹ鷽�����������Ƚϳ����ݹ�Ĳ���̫�࣬���ջ���
	*/
	// todo. no recursive solution
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
	//todo. �����д�����������ŵ�...��3��forѭ��
	// ��Ϊ�Ǵ�0��ʼ��index���������Ǵ�index��������
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

	// ��index=1��ʼ����indexλ�õ�Ԫ�ز��뵽ǰ��ȥ����indexλ�ÿ�ʼ�����ƶ��Բ���
	void insertSortNew(vector<T>& arr)
	{
		int length = arr.size();
		for (size_t i = 1; i < length; i++)
		{
			int temp = arr[i];
			int j = i;
			while (j > 0 && temp < arr[j - 1])
			{
				arr[j] = arr[j - 1];
				j--;
			}
			if (j != i)
				arr[j] = temp;
		}
	}



};
