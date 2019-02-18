#pragma once
#include <iostream>
#include <vector>

using namespace std;

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};


class Solution {
public:
	//136.Given a non-empty array of integers, every element appears twice except for one. Find that single one.
	// a linear runtime complexity + without using extra memory?
	// 1. sort
	// 2. 
	int singleNumber(vector<int>& nums) {
		int result = 0;
		vector<int>::iterator it = nums.begin();
		while (it != nums.end())
		{
			result ^= *it;
		}
		return result;
	}

	// 19. Remove Nth Node From End of List
	// boundary conditions
	// 1. input [1] 1 -> output should be [1]
	// 2. n > link list length
	// 可以再head前面加一个dummy的头!!
	ListNode* removeNthFromEnd(ListNode* head, int n) {
		if (head == nullptr)
			return head;
		ListNode* pFast = head;
		ListNode* pSlow = head;
		ListNode* pPre = head;
		while (n > 1 && head != nullptr)
		{
			pFast = pFast->next;
			--n;
		}
		if (pFast == nullptr)
			return head;
		while (pFast->next != nullptr)
		{
			pFast = pFast->next;
			pPre = pSlow;
			pSlow = pSlow->next;
		}
		pPre->next = pSlow->next;
		return head;
	}


	// 141. Linked List Cycle
	bool hasCycle(ListNode *head) {
		if (head == NULL)
			return false;

		ListNode* fast = head->next;
		ListNode* slow = head;
		
		//这种写法不好看
/*
		while (fast!=NULL && fast->next != NULL)
		{
			if (fast == slow)
				return true;
			fast = fast->next->next;
			slow = slow->next;
		}
		return false;
*/

		while (fast != slow)
		{
			if (fast == NULL || fast->next == NULL)
				return false;
			fast = fast->next->next;
			slow = slow->next;
		}
		return true;
	}

	// 148. Sort List
	ListNode* sortList(ListNode& head)
	{

	}
};

