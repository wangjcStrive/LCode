#pragma once
#include "solutions.h"

/*
	206. Reverse Linked List
	implete it both interatively and recursively
*/

class ReverseLinkedList {
public:
	ListNode* reverseList(ListNode* head)
	{
		if (head == NULL || head->next == NULL)
			return head;

		ListNode* slow, * mid, * fast;
		slow = head;
		mid = head->next;
		fast = head->next->next;
		head->next = NULL;
		while (mid != NULL)
		{
			mid->next = slow;
			slow = mid;
			mid = fast;
			if(fast != NULL)
				fast = fast->next;
		}

		return slow;
	}

	ListNode* reverseList_recursive(ListNode* head)
	{
				
		if (head == NULL || head->next == NULL)
			return head;
		ListNode* oldHead = head->next;
		ListNode* newHead = head;
		newHead->next = NULL;
		reverseRecursive(oldHead, &newHead);
		return newHead;
	}

	void reverseRecursive(ListNode* oldHead, ListNode** newHead)
	{
		if (oldHead == NULL)
			return;

		ListNode* tempHead = oldHead->next;
		oldHead->next = *newHead;
		*newHead = oldHead;
		oldHead = tempHead;
		reverseRecursive(oldHead, newHead);
		
	}
};
