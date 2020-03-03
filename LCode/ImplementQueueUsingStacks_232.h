#pragma once
#include "solutions.h"

/*
	232. Implement Queue using Stacks
*/

class MyQueue {
public:
	/** Initialize your data structure here. */
	MyQueue() {
	}

	/** Push element x to the back of queue. */
	void push(int x) {
		m_s1.push(x);
		updateStack2();
	}

	/** Removes the element from in front of queue and returns that element. */
	int pop() {
		m_s2.pop();
		updateStack1();
	}

	/** Get the front element. */
	int peek() {
		return m_s2.top();
	}

	/** Returns whether the queue is empty. */
	bool empty() {

	}
private:
	stack<int> m_s1;
	stack<int> m_s2;
	void updateStack2(int x)
	{
		while (!m_s2.empty())
			m_s2.pop();
		stack<int> tempStack(m_s1);
		while (!tempStack.empty())
		{
			m_s2.push(tempStack.top());
			tempStack.pop();
		}
	}
	void updateStack1()
	{
		while (!m_s1.empty())
			m_s1.pop();

		stack<int> tempStack(m_s2);
		while (!tempStack.empty())
		{
			m_s1.push(tempStack.top());
			tempStack.pop();
		}
	}
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */
