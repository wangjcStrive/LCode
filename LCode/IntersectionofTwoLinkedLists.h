#pragma once
#include "solutions.h"


/*
	160. Intersection of Two Linked Lists
	分别计算两端链表长度n1, n2
	长链表从头向后移动（n1 - n2）的长度，然后一起向后移动，如果相交即可。
*/

class IntersectionofTwoLinkedLists {
public:
	ListNode* getIntersectionNode(ListNode* headA, ListNode* headB)
	{
		ListNode* longList, * shortList;
		int lenA = calculateLinkListLength(headA);
		int lenB = calculateLinkListLength(headB);
		
		if (lenA - lenB >0)
		{
			longList = headA;
			shortList = headB;
		}
		else
		{
			longList = headB;
			shortList = headA;
		}
		for (int i = abs(lenA - lenB); i > 0; i--)
			longList = longList->next;
		while (longList!=NULL)
		{
			if (longList == shortList)
				return longList;
			longList = longList->next;
			shortList = shortList->next;
		}
		return NULL;
	}

	int calculateLinkListLength(ListNode* head)
	{
		int len = 0;
		for (; head != NULL; head = head->next)
			len++;
		return len;
	}
};
