#include "pch.h"
#include <iostream>
#include <vector>
#include <string>
#include <time.h>
#include <Windows.h>
#include <chrono>
#include <thread>
#include "solutions.h"
//#include "PrintInOrder_1114.h"
//#include "LetterCombinationsOfaPhoneNumber.h"
//#include "PartitionList.h"
//#include "LIS.h"
//#include "ThreeSum.h"
//#include "LinkedListCycleII.h"
//#include "RotateImage.h"
//#include "SortList.h"
//#include "AllSortSolutions.h"
//#include "IntersectionofTwoLinkedLists.h"
//#include "ReverseLinkedList.h"
//#include "DailyTemperatures_739.h"
//#include "DecodeString_394.h"
//#include "ImplementQueueUsingStacks_232.h"
//#include "TrappingRainWater_42.h"
//#include "SimplifyPath_71.h"
//#include "LargestRectangleInHistogram_84.h"
//#include "ValidParentheses_20.h"
//#include "CoinChange_322.h"
//#include "LongestIncreasingSubsequence_300.h"
//#include "LongestPalindromicSubstring_5.h"
//#include "MaximumSubarray_53.h"
//#include "MinimumPathSum_64.h"
//#include "ClimbingStairs_70.h"
//#include "BestTimeToBuyAndSellStock_121.h"
////#include "PrintFooBarAlternately_1115.h"
//#include "WordBreak_139.h"
//#include "PalindromicSubstrings_647.h"
//#include "TaskScheduler_621.h"
//#include "TwoSum_1.h"
//#include "LongestSubstringWithoutRepeatingCharacters_3.h"
//#include "SingleNumber_136.h"
//#include "AllSortTemplate.h"
#include "SubarraySumEqualsK_560.h"
//#include "IsValidSudoku_36.h"
//#include "fourSum_18.h"
//#include "PrintInOrder_1114.h"
//#include "PrintFooBarAlternately_1115.h"
//#include "PrintZeroEvenOdd_1116.h"
#include "ProducerConsumer.h"

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
//#define Print_In_Order_1114_TEST
//#define Maximum_Subarray_53
//#define Minimum_Path_Sum_64
//#define Climbing_Stairs_70
//#define Best_Time_To_Buy_And_Sell_Stock_121
//#define Print_FooBar_Alternately_1115
#define Thread_Producer_Consumer
//#define CPP_DEMO
//#define Word_Break_139
//#define Palindromic_Substrings_647
//#define Task_Scheduler_621
//#define Two_Sum_1
//#define Longest_Substring_Without_Repeating_Characters_3
//#define Single_Number_136
//#define ALL_SORT_TEMPLATE
//#define Zero_Even_Odd_1116
//#define Subarray_Sum_Equal_sK_560
//#define Is_Valid_Sudoku
//#define Four_Sum_18

#pragma region PrintFunc
void printVector(vector<int> input)
{
	for (auto x : input)
		std::cout << x << " ";
	std::cout << endl;
}

void printLogWithTime(string log)
{
	char timeStr[30];
	SYSTEMTIME st;
	GetLocalTime(&st);

	sprintf_s(timeStr, 30, "%d/%02d/%02d %02d:%02d:%02d.%d: ", st.wYear, st.wMonth, st.wDay, st.wHour, st.wMinute, st.wSecond, st.wMilliseconds);
	//sprintf(timeStr, "%d/%02d/%02d %02d:%02d:%02d.%d: ", st.wYear, st.wMonth, st.wDay, st.wHour, st.wMinute, st.wSecond, st.wMilliseconds);
	std::string time(timeStr);

	std::cout << time << log << std::endl;
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
#pragma endregion

#pragma region ThreadStudy
/*
void threadRun(PrintInOrder_1114_Test& ins, int id)
{
	cout << "thread: " << id << endl;
	if (id == 1)
	{
		ins.first();
	}
	else if (id == 2)
	{
		ins.second();
	}
	else if (id == 3)
	{
		ins.third();
	}
}

void PrintFooBarAlternately_runThread(PrintFooBarAlternately_1115& ins, int threadID)
{
	if (threadID == 1)
		ins.foo();
	else
		ins.bar();
}
std::atomic_flag atomicFlag = ATOMIC_FLAG_INIT;
std::stringstream stream;
void append_number(int x)
{
	while (atomicFlag.test_and_set())
	{
	}
	cout << "thread #" << x << '\n';
	atomicFlag.clear();
}
*/
#pragma endregion

// LCode 1116
//void funcZero(ZeroEvenOdd_1116& ins)
//{
//	ins.zero();
//	//cout << "zero done!" << endl;
//}
//void funcEven(ZeroEvenOdd_1116& ins)
//{
//	ins.even();
//	//cout << "Even done!" << endl;
//}
//void funcOdd(ZeroEvenOdd_1116& ins)
//{
//	ins.odd();
//	//cout << "Odd done!" << endl;
//}
// LCode 1116 end

#ifdef Thread_Producer_Consumer
// can't move below code to main. compile error.
int ProducerConsumer::m_productIndex = 0;
int ProducerConsumer::m_consumeIndex = 0;
std::queue<int> ProducerConsumer::m_productionBuff;
std::mutex ProducerConsumer::m_mtx;
std::condition_variable ProducerConsumer::m_cvProducer, ProducerConsumer::m_cvConsumer;
#endif // Thread_Producer_Consumer



int main()
{
	vector<int> input = { 5,4,6,3,7,2,8,1 };
	vector<int> input1 = { 1, 0, -1, 0, -2, 2 };
	vector<int> input2 = { 1,-1,0 };
	vector<int> input3 = { 0,0,0,0 };
	vector<int> input4 = { -2,-1,-1,1,1,2,2 };
	vector<int> input5 = { -1,0,1,2,-1,-4 };
	vector<int> input6 = { 1,0,-1,0,-2,2 };
	vector<int> input7 = { 3,1,4,2,5,-4,2,4,-5 };
	vector < vector<char>> twoDInput = { {'5','3','.','.','7','.','.','.','.'},{'6','.','.','1','9','5','.','.','.'},{'.','9','8','.','.','.','.','6','.'},{'8','.','.','.','6','.','.','.','3'},{'4','.','.','8','.','3','.','.','1'},{'7','.','.','.','2','.','.','.','6'},{'.','6','.','.','.','.','2','8','.'},{'.','.','.','4','1','9','.','.','5'},{'.','.','.','.','8','.','.','7','9'} };
	auto startTime = std::chrono::steady_clock::now();
	try
	{
#ifdef  Four_Sum_18
		FourSum_18 ins;
		vector<vector<int>> result;
		//result = ins.fourSum(input1, 0);
		//for (auto x : result)
		//{
		//	for (auto y : x)
		//		cout << y << " ";
		//	cout << endl;
		//}
		result = ins.fourSum(input7, -12);
		cout << endl;
		for (auto x : result)
		{
			for (auto y : x)
				cout << y << " ";
			cout << endl;
		}
#endif // Four_Sum_18



#ifdef Is_Valid_Sudoku
		IsValidSudoku_36 ins;
		cout << ins.isValidSudoku(twoDInput) << endl;
#endif // Is_Valid_Sudoku

#ifdef Subarray_Sum_Equal_sK_560
		SubarraySumEqualsK_560 ins;
		vector<int> vecLong;
		Solution::readLongVecFromFile(vecLong);
		cout << ins.subarraySum_prefixSum(vecLong, 12450) << endl;
		//cout << ins.subarraySum_prefixSum(input, 9) << endl;
		//cout << ins.subarraySum_prefixSum(input, 10) << endl;
		//cout << ins.subarraySum_prefixSum(input1, 1) << endl;
		//cout << ins.subarraySum_prefixSum(input1, 2) << endl;
		//cout << ins.subarraySum_prefixSum(input1, 3) << endl;
		//cout << ins.subarraySum_prefixSum(input2, 0) << endl;
#endif // Subarray_Sum_Equal_sK_560

#ifdef Zero_Even_Odd_1116
		const int count = 5;
		ZeroEvenOdd_1116 ins(count);
		std::thread tZero(funcZero, std::ref(ins));
		std::thread tOdd(funcOdd, std::ref(ins));
		std::thread tEven(funcEven, std::ref(ins));
		tZero.join();
		tEven.join();
		tOdd.join();
#endif // Zero_Even_Odd_1116


#ifdef ALL_SORT_TEMPLATE
		// todo. 生成比较大的随机数序列，进行性能测试. 堆排序，读取文件，然后排序后写回到新文件
		AllSort<int> ins;
		vector<int> input = { 5,4,6,3,7,2,8,1 };
		//vector<int> input = { 5,4,3, 2,1 };
		//ins.insertSort(input);
		//ins.selectionSort(input);
		//ins.bubbleSort(input);
		//ins.mergeSort(input);
		//ins.shellSort(input);
		//ins.quickSort(input, 0, input.size()-1);
		ins.heapSort(input);
		for (auto x : input)
		{
			cout << x << endl;
		}
#endif // ALL_SORT_TEMPLATE



#ifdef Single_Number_136
		SingleNumber_136 ins;
		vector<int> input1 = { 1, 2, 2 };
		//cout << ins.singleNumber(input1) << endl;
		cout << ins.singleNumber_LCode(input1) << endl;
#endif // Single_Number_136


#ifdef Longest_Substring_Without_Repeating_Characters_3
		LongestSubstringWithoutRepeatingCharacters_3 ins;
		cout << ins.lengthOfLongestSubstring("dvdf") << endl;
		cout << ins.lengthOfLongestSubstring("abcabcbb") << endl;
		cout << ins.lengthOfLongestSubstring("bbbbb") << endl;
		cout << ins.lengthOfLongestSubstring("pwwkew") << endl;
		cout << ins.lengthOfLongestSubstring(" ") << endl;
#endif // Longest_Substring_Without_Repeating_Characters_3



#ifdef Two_Sum_1
		TwoSum_1 ins;
		vector<int> input1 = { 2,5,5,11 };
		vector<int> input2 = { 3,3 };
		vector<int> input3 = { 3,1,2 };
		auto result = ins.twoSum(input1, 10);
		for (auto x : result)
		{
			cout << x << "  ";
		}
		cout << endl;
		result = ins.twoSum(input2, 6);
		for (auto x : result)
		{
			cout << x << "  ";
		}
		cout << endl;

		result = ins.twoSum(input3, 3);
		for (auto x : result)
		{
			cout << x << "  ";
		}
		cout << endl;
#endif // Two_Sum_1




#ifdef Task_Scheduler_621
		TaskScheduler_621 ins;
		vector<char> input1 = { 'A', 'A','B','B','B','C','C','C','C' };
		vector<char> input2 = { 'A', 'A', 'A','B','B','B','C','C','C' };
		vector<char> input3 = { 'A', 'A','B','B','B','C','C','C','C' };
		vector<char> input4 = { 'A', 'A','B','B','B','C','C','C','C' };
		cout << ins.leastInterval(input1, 3) << endl;
		cout << ins.leastInterval(input2, 2) << endl;
		cout << ins.leastInterval(input3, 3) << endl;
#endif // Task_Scheduler_621



#ifdef Palindromic_Substrings_647
		PalindromicSubstrings_647 ins;
		//cout << "aaa: " << ins.countSubstrings_1D_DP("aaa") << endl;
		//cout << "abc: " << ins.countSubstrings_1D_DP("abc") << endl;
		//cout << "aba: " << ins.countSubstrings_1D_DP("aba") << endl;
		//cout << "a: " << ins.countSubstrings_1D_DP("a") << endl;
		cout << "fdsklf: " << ins.countSubstrings_1D_DP("fdsklf") << endl;

#endif // Palindromic_Substrings_647


#ifdef Word_Break_139
		WordBreak_139 ins;
		vector<string> wordDict1 = { "leet", "code" };
		vector<string> wordDict2 = { "apple", "pen" };
		vector<string> wordDict3 = { "aaaa", "aaa" };
		cout << ins.wordBreak_DP_set("leetcode", wordDict1) << endl;
		cout << ins.wordBreak_DP_set("applepenapple", wordDict2) << endl;
		cout << ins.wordBreak_DP_set("applepenapple11", wordDict2) << endl;
		cout << ins.wordBreak_DP_set("aaaaaaa", wordDict3) << endl;
		//cout << ins.wordBreak_DFS("leetcode", wordDict1) << endl;

#endif // Word_Break_139




#ifdef CPP_DEMO
#endif // CPP_DEMO


#ifdef Thread_Producer_Consumer
		const int threadQuantity = 1;
		thread producer[threadQuantity], consumer[threadQuantity];

		for (size_t i = 0; i < 8; i++)
		{
			ProducerConsumer::m_productionBuff.push(i);
		}

		for (size_t i = 0; i < threadQuantity; i++)
		{
			producer[i] = thread(ProducerConsumer::producer, i, 1000);
			consumer[i] = thread(ProducerConsumer::consumer, 500);
		}
		for (size_t i = 0; i < threadQuantity; i++)
		{
			producer[i].join();
			consumer[i].join();
		}
#endif // Thread_Producer_Consumer




#ifdef Print_FooBar_Alternately_1115
		PrintFooBarAlternately_1115 ins(30);
		std::thread t1(PrintFooBarAlternately_runThread, std::ref(ins), 1);
		std::this_thread::sleep_for(std::chrono::milliseconds(2000));
		std::thread t2(PrintFooBarAlternately_runThread, std::ref(ins), 2);
		t1.join();
		t2.join();
#endif // Print_FooBar_Alternately_1115




#ifdef Best_Time_To_Buy_And_Sell_Stock_121
		vector<int> input{ 7,1,5,3,6,4 };
		vector<int> input1{ 7,6,5,3,1 };
		BestTimeToBuyAndSellStock_121 ins;
		cout << ins.maxProfit(input) << endl;
		cout << ins.maxProfit(input1) << endl;
#endif // Best_Time_To_Buy_And_Sell_Stock_121


#ifdef Climbing_Stairs_70
		ClimbingStairs_70 ins;
		cout << ins.climbStairs(4) << endl;
#endif // Climbing_Stairs_70



#ifdef Minimum_Path_Sum_64
		vector<vector<int>> input = { {1,3,1} ,{1,5,1},{4,2,1} };
		vector<vector<int>> input_long = { {5,0,1,1,2,1,0,1,3,6,3,0,7,3,3,3,1},{1,4,1,8,5,5,5,6,8,7,0,4,3,9,9,6,0},{2,8,3,3,1,6,1,4,9,0,9,2,3,3,3,8,4},{3,5,1,9,3,0,8,3,4,3,4,6,9,6,8,9,9},{3,0,7,4,6,6,4,6,8,8,9,3,8,3,9,3,4},{8,8,6,8,3,3,1,7,9,3,3,9,2,4,3,5,1},{7,1,0,4,7,8,4,6,4,2,1,3,7,8,3,5,4},{3,0,9,6,7,8,9,2,0,4,6,3,9,7,2,0,7},{8,0,8,2,6,4,4,0,9,3,8,4,0,4,7,0,4},{3,7,4,5,9,4,9,7,9,8,7,4,0,4,2,0,4},{5,9,0,1,9,1,5,9,5,5,3,4,6,9,8,5,6},{5,7,2,4,4,4,2,1,8,4,8,0,5,4,7,4,7},{9,5,8,6,4,4,3,9,8,1,1,8,7,7,3,6,9},{7,2,3,1,6,3,6,6,6,3,2,3,9,9,4,4,8} };
		MinimumPathSum_64 ins;
		cout << ins.minPathSum(input_long) << endl;
		//cout << ins.minPathSum_recursive(input) << endl;
		//cout << ins.minPathSum_recursive(input_long) << endl;
#endif // Minimum_Path_Sum_64


#ifdef Maximum_Subarray_53
		vector<int> input1 = { -2,1,-3,4,-1,2,1,-5,4 };
		vector<int> input2 = { 1 };
		vector<int> input3 = { -1, -2, -3, -4 };
		vector<int> input4 = { 1,2,3,4 };
		MaximumSubarray_53 ins;
		cout << ins.maxSubArray(input1) << endl;
		cout << ins.maxSubArray(input2) << endl;
		cout << ins.maxSubArray(input3) << endl;
		cout << ins.maxSubArray(input4) << endl;
#endif // Maximum_Subarray_53

#ifdef Print_In_Order_1114
		ThreadDemo ins;
		// 1 -> 2 -> 3
		/*
			std::thread t1(threadRun, std::ref(ins), 1);
			t1.join();
			std::thread t2(threadRun, std::ref(ins), 2);
			t2.join();
			std::thread t3(threadRun, std::ref(ins), 3);
			t3.join();
		*/

		// 3 -> 2 -> 1
		std::thread t3(threadRun, std::ref(ins), 3);

		std::this_thread::sleep_for(std::chrono::milliseconds(2000));
		std::thread t2(threadRun, std::ref(ins), 2);

		std::this_thread::sleep_for(std::chrono::milliseconds(2000));
		std::thread t1(threadRun, std::ref(ins), 1);
		t3.join();
		t2.join();
		t1.join();


#endif // Print_In_Order_1114
#ifdef Print_In_Order_1114_TEST
		PrintInOrder_1114_Test ins;
		std::thread t1(threadRun, std::ref(ins), 3);
		std::this_thread::sleep_for(std::chrono::milliseconds(4000));
		std::thread t2(threadRun, std::ref(ins), 2);
		std::this_thread::sleep_for(std::chrono::milliseconds(4000));
		std::thread t3(threadRun, std::ref(ins), 1);
		t1.join();
		t2.join();
		t3.join();
#endif // Print_In_Order_1114_TEST



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