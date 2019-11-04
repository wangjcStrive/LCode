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
};
