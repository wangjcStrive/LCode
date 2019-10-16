#include "pch.h"
#include <iostream>
#include <vector>
#include <string>
#include "solutions.h"
#include "LetterCombinationsOfaPhoneNumber.h"
#include "PartitionList.h"
#include "LIS.h"
#include "ThreeSum.h"
#include "LinkedListCycleII.h"
#include "RotateImage.h"
#include "SortList.h"
#include "AllSortSolutions.h"
using namespace std;

//#define LETTER_COMBINATION_PHONE_NUMBER_17;
//#define PARTITION_LIST_86
//#define DYNAMIC_PROGRAM
//#define LIS_300
//#define ThreeSum_15
//#define LinkedListCycleII_142
//#define Rotate_Image_48
//#define SortList_148
#define Sort_All

void printVector(vector<int> input)
{
	for (auto x : input)
		cout << x << endl;
	cout << endl;
}


int main()
{
	vector<int> arr = { 6,7,5,2,1,9 };
	
#ifdef Sort_All
	Sort ins;
	printVector(arr);
	//ins.bubbleSort(arr);
	//ins.SelectionSort(arr);
	ins.insertSort(arr);
	printVector(arr);
#endif // SortAll

#ifdef SortList_148
	ListNode* head = new ListNode(0);
	SortList ins;
	ListNode* tempLast = head;
	ListNode* cycle = nullptr;
	for (int i = 5; i >0 ; i--)
	{
		tempLast->next = new ListNode(i);
		tempLast = tempLast->next;
		if (i == 1)
			cycle = tempLast;

	}
	for (ListNode* p = head; p != NULL; p = p->next)
		cout << p->val << endl;

	cout << endl;
	ins.sortList(head);

	for (ListNode* p = head; p != NULL; p = p->next)
		cout << p->val << endl;

#endif // SortList_148



#ifdef Rotate_Image_48
	RotateImage ins;
	//vector<vector<int>> input = { {1, 2, 3},{4, 5, 6},{7, 8,9} };
	vector<vector<int>> input = { {1, 2},{4, 5} };
	int n = input[0].size();
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cout << to_string(input[i][j]) << endl;
		}
	}
	cout << endl;
	ins.rotate(input);

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cout << to_string(input[i][j]) << endl;
		}
	}
#endif // Rotate_Image_48


#ifdef LinkedListCycleII_142
	ListNode* head = new ListNode(0);
	LinkedListCycleII ins;
	ListNode* tempLast = head;
	ListNode* cycle=nullptr;
	for ( int i = 1; i < 5; i++)
	{
		tempLast->next = new ListNode(i);
		tempLast = tempLast->next;
		if (i == 1)
			cycle = tempLast;

	}
	tempLast->next = cycle;
	ins.detectCycle(head);

#endif // LinkedListCycleII_142



#ifdef ThreeSum_15
	ThreeSum ins;
	//vector<int> input = { -1, 0, 1, 2, -1, -4 };
	vector<int> input = { 0,0,0,0 };
	vector<vector<int>> result = ins.threeSum(input);
	for (auto x : result)
	{
		for (auto y : x)
		{
			cout << y << endl;
		}
	}
#endif // ThreeSum_15



#ifdef LIS_300
	LIS lis;
	vector<int> input = { 10,9,2,5,3,7,101,18 };
	cout << lis.lengthOfLIS(input) << endl;
#endif // LIS_300



#ifdef DYNAMIC_PROGRAM
	DP dp;
	vector<int> coinList = {1, 2, 5};
	vector<int> resultList;
	cout << dp.coinsChange(coinList, 33) << endl;
#endif // DYNAMIC_PROGRAM


#ifdef LETTER_COMBINATION_PHONE_NUMBER_17
	LetterCombinationsOfPhoneNumber lcpn;
	vector<string> result = lcpn.letterCombinations("2345");
	for (auto c : result)
	{
		cout << c << endl;
	}
#endif // LETTER_COMBINATION_PHONE_NUMBER_17

#ifdef PARTITION_LIST_86
	int input[] = { 1, 1 };
	//int input[] = { 2, 3, 4, 1, 2, 6, 7 };
	ListNode* head = new ListNode(input[0]);
	ListNode* cur = head;
	for (size_t i = 1; i < sizeof(input)/sizeof(int); i++)
	{
		cur->next = new ListNode(input[i]);
		cur = cur->next;
	}
	cur->next = nullptr;
	
	ListNode::printListNode(head);
	cout << endl;

	PartitionList ins;
	ListNode* result = ins.partition(head, 0);
	ListNode::printListNode(result);
	
#endif // PARTITION_LIST_86


}