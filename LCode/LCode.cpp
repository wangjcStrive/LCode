#include "pch.h"
#include <iostream>
#include <vector>
#include <string>
#include "solutions.h"
#include "LetterCombinationsOfaPhoneNumber.h"
#include "PartitionList.h"
#include "LIS.h"
using namespace std;

//#define LETTER_COMBINATION_PHONE_NUMBER_17;
//#define PARTITION_LIST_86
//#define DYNAMIC_PROGRAM
#define LIS_300


int main()
{
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