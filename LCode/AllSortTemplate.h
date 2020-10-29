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
		heap.是一种选择排序，最好，最坏，平均复杂度均为O(nlogn). 不稳定
		堆是有以下性质的完全二叉树：每个节点的值都大于或等于其左右孩子节点的值（大顶堆
		两个子节点分别是2i+1/2i+2
		思路
			1. 将待排序序列构造成一个大顶堆，此时整个序列的最大值就是堆顶的根节点。
			2. 重复将根节点与末尾元素交换，此时末尾就是最大值.末尾元素换到根节点后需要重新排序满足"根节点比子节点大"，但是此时序列长度减1
			3. 
	*/
	void heapSort(vector<T>& arr)
	{
		int length = arr.size();
		// 原序列构造成一个大顶堆. O(n/2)
		for (auto i = length / 2 - 1; i>=0; i--)
			adjustArrToSatisfyHeap(arr, length, i);

		// 重复交换根节点跟末尾节点. O(logn)?
		for (int tail = length - 1; tail > 0; tail--)
		{
			swap(arr[0], arr[tail]);
			adjustArrToSatisfyHeap(arr, tail, 0);
		}

	}
	/*
		len: 限定序列长度。
		index: 使得index以下的所有节点满足"根节点比子节点大"
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
			// 交换后不要忘记,重新调整做过交换的子节点
			adjustArrToSatisfyHeap(arr, len, maxIndex);
		}
	}

	/*
		quick sort.  分治。
		平均O(nlogn),最坏O(n^2)。通常快排都是要比O(nlogn)快的。
		是处理大数据最快的排序方法。O(nlogn) 记号中隐含的常数因子很小，比复杂度稳定等于 O(nlogn) 的归并排序要小很多。所以，对绝大多数顺序性较弱的随机数列而言，快速排序总是优于归并排序。
	*/
	void quickSort(vector<T>& arr, int low, int high)
	{
		if (low < high)
		{
			int pivot = partition(arr, low, high); //排完这一遍后，大于pivot的值都在后面，小于pivot的值都在后面了
			quickSort(arr, low, pivot - 1);
			quickSort(arr, pivot + 1, high);
		}
	}

	int partition(vector<T>& arr, int low, int high)
	{
		int pivot = arr[low];
		while (low < high)
		{
			// 由右向左，找到小于pivot的元素，然后交换到low的位置
			while (low < high && arr[high] >= pivot)
				high--;
			arr[low] = arr[high];
			// 由左向右，找到大于pivot的元素，交换到high的位置
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
			for (size_t i = 0; i < gap; i++)	//分组
			{
				for (size_t j = i; j < length; j += gap)	//对每组进行插入排序
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
		归并排序
		由上到下分割直到只有两个元素 -> 把这两个元素排序 -> 由下到上开始merge
		复杂度
			时间：O(nlogn):使用了二分法把数组分割
			空间：O(n)
		稳定排序
		缺点：
			需要占用额外的空间
			递归方法，如果输入比较长，递归的层数太多，造成栈溢出
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
	//todo. 下面的写法好像不是最优的...有3层for循环
	// 因为是从0开始到index，而下面是从index反着来的
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

	// 从index=1开始，把index位置的元素插入到前面去，从index位置开始向左移动以插入
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
