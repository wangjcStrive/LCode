#pragma once
#include "solutions.h"

/*
	142. Linked List Cycle II
	如果链表中存在环，那么fp和sp一定会相遇，当两个指针相遇的时候，我们设相遇点为c，此时fp和sp都指向了c，
	接下来令fp继续指向c结点，sp指向链表头结点head，
	此时最大的不同是fp的步数变成为每次走一步，令fp和sp同时走，每次一步，那么它们再次相遇的时候即为环的入口结点

	conditions:
		确保fast.nexe.nexe不是NULL
*/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class LinkedListCycleII {
public:
	ListNode* detectCycle(ListNode* head)
	{
		ListNode* fast = head;
		ListNode* slow = head;

		if (head == NULL)
			return NULL;
		fast = head;
		slow = head;
		while (fast!=NULL && fast->next!=NULL)
		{
			fast = fast->next->next;
			slow = slow->next;
			if (fast == slow)
				break;
		}

		if (fast!=NULL && fast->next != NULL)
		{
			for (slow = head; ; slow = slow->next, fast = fast->next)
			{
				if (slow == fast)
					break;
			}
			return fast;
		}
		else
			return NULL;
	}
};
