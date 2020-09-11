#pragma once
#include "solutions.h"
#include <mutex>
#include <atomic>

/*
	1115. Print FooBar Alternately
	先是bar等foo，然后foo又等bar
	Runtime: 376 ms, faster than 24.82% of C++ online submissions for Print FooBar Alternately.
	Memory Usage: 8.1 MB, less than 82.90% of C++ online submissions for Print FooBar Alternately.
*/

class PrintFooBarAlternately_1115 {
private:
	int n;

public:
	PrintFooBarAlternately_1115(int n)
	{
		this->n = n;
	}

	void foo()
	{
		std::unique_lock<mutex> lk(m_mutex);
		for (int i = 0; i < n; i++)
		{
			m_cv.wait(lk, [this]() {return m_counterFoo == m_counterBar; });
			cout << "foo";
			m_counterFoo++;
			m_cv.notify_one();
		}
	}

	void bar()
	{
		std::unique_lock<mutex> lk(m_mutex);
		for (int i = 0; i < n; i++)
		{
			m_cv.wait(lk, [this]() {return m_counterBar == m_counterFoo-1; });
			cout << "bar" << endl;
			m_counterBar++;
			m_cv.notify_one();
		}
	}
private:
	unsigned int m_counterFoo = 0;
	unsigned int m_counterBar = 0;
	std::condition_variable m_cv;
	std::mutex m_mutex;
};


// 使用std::acomic
class FooBar {
private:
	int n;
	atomic<bool> flag = true;

public:
	FooBar(int n) {
		this->n = n;
	}

	void foo(function<void()> printFoo) {

		for (int i = 0; i < n; i++) {
			while (!flag) {
				this_thread::yield();
			}
			// printFoo() outputs "foo". Do not change or remove this line.
			printFoo();
			flag = false;
		}
	}

	void bar(function<void()> printBar) {

		for (int i = 0; i < n; i++) {
			while (flag) {
				this_thread::yield();
			}
			// printBar() outputs "bar". Do not change or remove this line.
			printBar();
			flag = true;
		}
	}
};