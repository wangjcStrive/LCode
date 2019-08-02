#pragma once
/*
	86. Partition List. 把所有小于给定值的节点都移到前面，大于该值的节点顺序不变
	Given 1->4->3->2->5->2 and x = 3,
	return 1->2->2->4->3->5.

	边界条件
	1. 4 4 4 3 1 2 2 =>1节点要变成头节点了..
	2. 记得修改相应节点的next指针，不然容易形成环
	3. list里的值全部大于或小于 x

	Solution
	1. 找到3之前第一个大于3的节点，然后将后面每个大于3的节点放到4之前就好了。
	2. 所有小于3的节点取出为一个新链表，再将原链表置于新链表之后即可。
*/
#include "solutions.h"
class PartitionList
{
public:
	//最简单的是新建节点，然后把两个list合并。下面的方法不会新建节点，但是稍微复杂一些
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
				//left总是指向最后一个大约x的node，只有确认了cur node是大约x的时候，才会前移.
				left = cur;
			}
		}

		//!!边界
		if (newListHead != nullptr)
			newListEnd->next = head;
		else
			newListHead = head;
		return newListHead;
	}
};
