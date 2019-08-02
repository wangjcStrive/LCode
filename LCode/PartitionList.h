#pragma once
/*
	86. Partition List. ������С�ڸ���ֵ�Ľڵ㶼�Ƶ�ǰ�棬���ڸ�ֵ�Ľڵ�˳�򲻱�
	Given 1->4->3->2->5->2 and x = 3,
	return 1->2->2->4->3->5.

	�߽�����
	1. 4 4 4 3 1 2 2 =>1�ڵ�Ҫ���ͷ�ڵ���..
	2. �ǵ��޸���Ӧ�ڵ��nextָ�룬��Ȼ�����γɻ�
	3. list���ֵȫ�����ڻ�С�� x

	Solution
	1. �ҵ�3֮ǰ��һ������3�Ľڵ㣬Ȼ�󽫺���ÿ������3�Ľڵ�ŵ�4֮ǰ�ͺ��ˡ�
	2. ����С��3�Ľڵ�ȡ��Ϊһ���������ٽ�ԭ��������������֮�󼴿ɡ�
*/
#include "solutions.h"
class PartitionList
{
public:
	//��򵥵����½��ڵ㣬Ȼ�������list�ϲ�������ķ��������½��ڵ㣬������΢����һЩ
	ListNode* partition(ListNode* head, int x)
	{
		if (head == nullptr || head->next == nullptr)
			return head;
		ListNode* newListHead=nullptr;
		ListNode* newListEnd = nullptr;
		ListNode* right = head;
		ListNode* left = head;

		while ( right != NULL)
		{
			ListNode* cur;
			cur = right;
			right = right->next;
			if (cur->val < x)
			{
				//delete node that less than x.
				if (cur == head)		// 1-2-3-5-1 -> old list should be 3-5, head point to 3.
					head = right;
				else
					left->next = right;
				// add it to new list.
				if (newListHead == nullptr)
				{
					newListHead = cur;
					newListEnd = cur;
				}
				else
				{
					newListEnd->next = cur;
					newListEnd = cur;
				}
				newListEnd->next = nullptr;
			}
			else
			{
				//left����ָ�����һ����Լx��node��ֻ��ȷ����cur node�Ǵ�Լx��ʱ�򣬲Ż�ǰ��.
				left = cur;
			}
		}

		//!!�߽�
		if (newListHead != nullptr)
			newListEnd->next = head;
		else
			newListHead = head;
		return newListHead;
	}
};
