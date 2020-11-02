#pragma once
#include "solutions.h"
#include <mutex>

/*
	1116. Print Zero Even Odd
*/

class ZeroEvenOdd_1116 {
public:
	ZeroEvenOdd_1116(int n) {
		this->n = n;
	}

	// printNumber(x) outputs "x", where x is an integer.
	//void zero(function<void(int)> printNumber) {
	void zero() {
		if (m_counter <= n)
		{
			std::unique_lock<std::mutex> ulk(m_mutex);
			m_cvZero.wait(ulk, [this]() {return m_counter == 0; });
			printNumber(0);
			m_counter++;
			if (m_counter % 2 == 1)
				m_cvOdd.notify_one();
			else
				m_cvEven.notify_one();
		}
	}

	//void even(function<void(int)> printNumber) {
	void even() {
		std::unique_lock<std::mutex> ulk(m_mutex);
		m_cvEven.wait(ulk, [this]() {return m_counter % 2 == 1; });
		printNumber(m_counter);
		m_cvZero.notify_one();
	}

	//void odd(function<void(int)> printNumber) {
	void odd() {
		std::unique_lock<std::mutex> ulk(m_mutex);
		m_cvOdd.wait(ulk, [this]() {return m_counter>0 && m_counter % 2 == 0; });
		printNumber(m_counter);
		m_cvZero.notify_one();
	}
private:
	int n;
	size_t m_counter = 0;
	std::condition_variable m_cvEven;
	std::condition_variable m_cvOdd;
	std::condition_variable m_cvZero;
	std::mutex m_mutex;


	void printNumber(int num)
	{
		cout << num << endl;
	}
};
