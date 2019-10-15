#pragma once
#include "solutions.h"

/*
	148. Sort List
	Sort a linked list in O(n log n) time using constant space complexity.
*/

class SortList {
public:
	ListNode* sortList(ListNode* head) {
		if (head == NULL || head->next == NULL)
			return head;

		ListNode* dummyRoot = new ListNode(0);
		dummyRoot->next = head;
		head = head->next;
		dummyRoot->next->next = NULL;

		while (head)
		{
			ListNode* currentHead = head;
			ListNode* tempRoot;
			for (tempRoot = dummyRoot; tempRoot->next != NULL; tempRoot = tempRoot->next)
			{
				if (tempRoot->next->val > head->val)
				{
					ListNode* tempP = head->next;
					head->next = tempRoot->next;
					tempRoot->next = head;
					head = tempP;
					break;
				}
			}
			if (currentHead == head)
			{
				tempRoot->next = head;
				head = head->next;
				tempRoot->next->next = NULL;
			}
		}
		return dummyRoot->next;
	}
};
