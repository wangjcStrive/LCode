#include "pch.h"
#include <iostream>
#include <vector>
#include <string>
#include <time.h>
#include <Windows.h>
#include <chrono>
#include "solutions.h"
#include "LetterCombinationsOfaPhoneNumber.h"
#include "PartitionList.h"
#include "LIS.h"
#include "ThreeSum.h"
#include "LinkedListCycleII.h"
#include "RotateImage.h"
#include "SortList.h"
#include "AllSortSolutions.h"
#include "IntersectionofTwoLinkedLists.h"
#include "ReverseLinkedList.h"
#include "DailyTemperatures_739.h"
#include "DecodeString_394.h"
#include "ImplementQueueUsingStacks_232.h"
#include "TrappingRainWater_42.h"
#include "SimplifyPath_71.h"
#include "LargestRectangleInHistogram_84.h"
#include "ValidParentheses_20.h"
#include "CoinChange_322.h"
#include "LongestIncreasingSubsequence_300.h"
#include "LongestPalindromicSubstring_5.h"
#include "MaximumSubarray_53.h"
//#include "PrintInOrder_1114.h"
using namespace std;

//#define LETTER_COMBINATION_PHONE_NUMBER_17;
//#define PARTITION_LIST_86
//#define DYNAMIC_PROGRAM
//#define LIS_300
//#define ThreeSum_15
//#define LinkedListCycleII_142
//#define Rotate_Image_48
//#define SortList_148
//#define Sort_All
//#define Intersection_of_Two_LinkedLists_160
//#define Reverse_LinkList_206
//#define Shell_Sort
//#define Daily_Temperatures_739
//#define Decode_String_394
//#define ImplementQueueUsingStack_232
//#define TrappingRainWater_42
//#define SimplifyPath_71
//#define LargestRectangleInHistogram_84
//#define ValidParentheses_20
//#define CoinChange_322
//#define LongestPalindromicSubstring
//#define Print_In_Order_1114
#define Maximum_Subarray_53

void printVector(vector<int> input)
{
	for (auto x : input)
		std::cout << x << " ";
	std::cout << endl;
}

void printLinkList(ListNode* head)
{
	while (head != NULL)
	{
		std::cout << head->val << " ";
		head = head->next;
	}
	std::cout << endl;
}

ListNode* createListNode(int len)
{
	ListNode* head = (ListNode*)malloc(sizeof(ListNode));
	head->val = 0;
	ListNode* tempHead = head;
	for (int i = 1; i < len; i++)
	{
		tempHead->next = (ListNode*)malloc(sizeof(ListNode));
		tempHead->next->val = i;
		tempHead = tempHead->next;
	}
	tempHead->next = NULL;
	return head;
}

int main()
{
	auto startTime = std::chrono::steady_clock::now();
	try
	{
#ifdef Maximum_Subarray_53
		vector<int> input1 = { -2,1,-3,4,-1,2,1,-5,4 };
		vector<int> input2 = { 1 };
		vector<int> input3 = { -1, -2, -3, -4};
		vector<int> input4 = { 1,2,3,4};
		MaximumSubarray_53 ins;
		cout << ins.maxSubArray(input1) << endl;
		cout << ins.maxSubArray(input2) << endl;
		cout << ins.maxSubArray(input3) << endl;
		cout << ins.maxSubArray(input4) << endl;
#endif // Maximum_Subarray_53

#ifdef Print_In_Order_1114
		//std::thread t1(threadTest1);
		//Sleep(2000);
		//std::thread t2(threadTest2);
		//Sleep(2000);
		//std::thread t3(threadTest3);
#endif // Print_In_Order_1114


#ifdef LongestPalindromicSubstring
		LongestPalindromicSubstring_5 ins;
		cout << ins.longestPalindrome_DP("abcba") << endl;
		cout << ins.longestPalindrome_DP("abba") << endl;
		cout << ins.longestPalindrome_DP("babad") << endl;
		cout << ins.longestPalindrome_DP("aaaaa") << endl;
		cout << ins.longestPalindrome_DP("aaaa") << endl;
		cout << ins.longestPalindrome_DP("bb") << endl;
		cout << ins.longestPalindrome_DP("ac") << endl;
#endif // LongestPalindromicSubstring

#ifdef ValidParentheses_20
		ValidParentheses ins;
		string input0 = "";
		string input1 = "()[]{}";
		string input2 = "(]";
		string input3 = "([)]";
		std::cout << input1 + "	" << ins.isValid(input1) << endl;
		std::cout << input2 + "	" << ins.isValid(input2) << endl;
		std::cout << input3 + "	" << ins.isValid(input3) << endl;
#endif // ValidParentheses_20


#ifdef LargestRectangleInHistogram_84
		vector<int> input = { 2, 1, 5, 6, 2, 3 };
		LargestRectangleInHistogram ins;
		//std::cout << ins.LargestRectangleinHistogram(input) << endl;
		std::cout << ins.LargestRectangleinHistogram_DivideConquer(input) << endl;
#endif // LargestRec


#ifdef SimplifyPath_71
		vector<string> input_SP =
		{
			//"/home/",
			//"a/a/a",
			//"/a/.aa.../",
			"/..",
			"/a//b////c/d//././/..",
			"/home/.../abc/xyz",
			"/a/.",
			"/../",
			"/home/",
			"/../",
			"/home//foo/",
			"/a/./b/../../c/",
			"/a/../../b/../c//.//",
			"/a//b////c/d//././/.."
		};
		SimplifyPath ins;
		for (size_t i = 0; i < input_SP.size(); i++)
		{
			std::cout << ins.simplifyPath(input_SP[i]) << endl;
		}
#endif // SimplifyPath_71



#ifdef TrappingRainWater_42
		TrappingRainWater ins;
		std::cout << ins.trap2_DP(arr) << endl;
#endif // TrappingRainWater_42



#ifdef ImplementQueueUsingStack_232
		MyQueue queue;
		queue.push(1);
		queue.push(2);
		std::cout << queue.peek() << endl;  // returns 1
		std::cout << queue.pop() << endl;   // returns 1
		bool result = queue.empty() ? true : false;
		if (result)
			std::cout << "yes" << endl;
		else
			std::cout << "No" << endl;
#endif

#ifdef Decode_String_394
		DecodeString ins;
		std::cout << ins.decodeString("2[a3[c]b]") << endl;
#endif // Decode_String_394


#ifdef Daily_Temperatures_739
		DailyTemperatures ins;
		vector<int> result;
		result = ins.dailyTemperatures(arr);
		printVector(result);

#endif // Daily_Temperatures_739




#ifdef Shell_Sort
		Sort ins;
		ins.shellSort(arr, arr.size());
		printVector(arr);
#endif // Shell_Sort

#ifdef Reverse_LinkList_206
		ListNode* root = createListNode(5);
		printLinkList(root);
		ReverseLinkedList ins;
		//ListNode *newRoot = ins.reverseList(root);
		ListNode* newRoot = ins.reverseList_recursive(root);
		printLinkList(newRoot);
#endif // Reverse_LinkList_206


#ifdef Intersection_of_Two_LinkedLists_160
		IntersectionofTwoLinkedLists ins;
		ListNode* intersectionTemp;
		ListNode* headA = new ListNode(4);
		headA->next = new ListNode(1);
		ListNode* temp = headA->next;
		temp->next = new ListNode(8);
		temp = temp->next;
		intersectionTemp = temp;
		temp->next = new ListNode(4);
		temp = temp->next;
		temp->next = new ListNode(5);
		temp->next->next = NULL;
		printLinkList(headA);
		ListNode* headB = new ListNode(5);
		headB->next = new ListNode(0);
		temp = headB->next;
		temp->next = new ListNode(1);
		temp = temp->next;
		temp->next = intersectionTemp;
		printLinkList(headB);

		ListNode* result = ins.getIntersectionNode(headA, headB);
		std::cout << result->val << endl;
		//ins.getIntersectionNode();
#endif // Intersection_of_Two_LinkedLists_160



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
		for (int i = 5; i > 0; i--)
		{
			tempLast->next = new ListNode(i);
			tempLast = tempLast->next;
			if (i == 1)
				cycle = tempLast;

		}
		for (ListNode* p = head; p != NULL; p = p->next)
			std::cout << p->val << endl;

		std::cout << endl;
		ins.sortList(head);

		for (ListNode* p = head; p != NULL; p = p->next)
			std::cout << p->val << endl;

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
				std::cout << to_string(input[i][j]) << endl;
			}
		}
		std::cout << endl;
		ins.rotate(input);

		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < n; j++)
			{
				std::cout << to_string(input[i][j]) << endl;
			}
		}
#endif // Rotate_Image_48


#ifdef LinkedListCycleII_142
		ListNode* head = new ListNode(0);
		LinkedListCycleII ins;
		ListNode* tempLast = head;
		ListNode* cycle = nullptr;
		for (int i = 1; i < 5; i++)
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
				std::cout << y << endl;
			}
		}
#endif // ThreeSum_15



#ifdef LIS_300
		vector<int> input = { 10,9,2,5,3,7,101,18 };
		vector<int> input1 = { 1, 2, 3,4,5,6 };
		vector<int> input2 = { 6,5,4,3,2,1 };
		/*
			//old version:
			LIS lis;
			std::cout << lis.lengthOfLIS(input) << endl;
		*/
		LongestIncreasingSubsequence_300 ins;
		//cout << ins.lengthOfLIS(input) << endl;
		//cout << ins.lengthOfLIS(input1) << endl;		
		//cout << ins.lengthOfLIS(input2) << endl;

		cout << ins.lengthOfLIS_vectorMinMax(input) << endl;		
		cout << ins.lengthOfLIS_vectorMinMax(input1) << endl;
		cout << ins.lengthOfLIS_vectorMinMax(input2) << endl;

#endif // LIS_300



#ifdef DYNAMIC_PROGRAM
		DP dp;
		vector<int> coinList = { 1, 2, 5 };
		vector<int> resultList;
		std::cout << dp.coinsChange(coinList, 33) << endl;
#endif // DYNAMIC_PROGRAM

#ifdef CoinChange_322
		CoinChangeDP ins;
		vector<int> input1 = { 1,2,5 };
		//vector<int> input2 = { 2 };
		std::cout << ins.coinChange(input1, 11) << endl;
		//std::cout << ins.coinChange(input2, 3) << endl;
#endif // CoinChange_322



#ifdef LETTER_COMBINATION_PHONE_NUMBER_17
		LetterCombinationsOfPhoneNumber lcpn;
		vector<string> result = lcpn.letterCombinations("2345");
		for (auto c : result)
		{
			std::cout << c << endl;
		}
#endif // LETTER_COMBINATION_PHONE_NUMBER_17

#ifdef PARTITION_LIST_86
		int input[] = { 1, 1 };
		//int input[] = { 2, 3, 4, 1, 2, 6, 7 };
		ListNode* head = new ListNode(input[0]);
		ListNode* cur = head;
		for (size_t i = 1; i < sizeof(input) / sizeof(int); i++)
		{
			cur->next = new ListNode(input[i]);
			cur = cur->next;
		}
		cur->next = nullptr;

		ListNode::printListNode(head);
		std::cout << endl;

		PartitionList ins;
		ListNode* result = ins.partition(head, 0);
		ListNode::printListNode(result);

#endif // PARTITION_LIST_86
	}
	catch (const std::exception& e)
	{
		auto endTime = chrono::steady_clock::now();
		cout << chrono::duration <double, milli>(endTime - startTime).count() << " ms" << endl;
		std::cout << e.what() << endl;
	}
	auto endTime = chrono::steady_clock::now();
	cout << chrono::duration <double, milli>(endTime - startTime).count() << " ms" << endl;
}