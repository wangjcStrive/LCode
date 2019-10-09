#pragma once
#include "solutions.h"
#include <limits>

/*
	155. Min Stack
	getMin, pop之后的最小值
*/



class MinStack {
private:
	vector<int> m_vec;
	vector<int>::iterator m_top;
	int m_min = INT_MAX;
public:
	/** initialize your data structure here. */
	MinStack() {
		m_top = m_vec.begin();
	}

	void push(int x) {
		m_min = m_min > x ? x : m_min;
		m_vec.push_back(x);
	}

	void pop() {
		if (m_top != m_vec.end())
			++m_top;
	}

	int top() {
		if (m_top != m_vec.end())
			return *m_top;
		return *m_top;
	}

	int getMin() {
		return m_min;
	}
};


/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(x);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */
