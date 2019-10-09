#pragma once
#include "solutions.h"

/*
	142. Linked List Cycle II
	��������д��ڻ�����ôfp��spһ����������������ָ��������ʱ��������������Ϊc����ʱfp��sp��ָ����c��
	��������fp����ָ��c��㣬spָ������ͷ���head��
	��ʱ���Ĳ�ͬ��fp�Ĳ������Ϊÿ����һ������fp��spͬʱ�ߣ�ÿ��һ������ô�����ٴ�������ʱ��Ϊ������ڽ��

	conditions:
		ȷ��fast.nexe.nexe����NULL
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
