#pragma once
#include "solutions.h"
#include <mutex>

/*
	1116. Print Zero Even Odd
    三个线程一直处于阻塞状态，只有flag满足的时候(return true)

    Runtime: 44 ms, faster than 76.94% of C++ online submissions for Print Zero Even Odd.
    Memory Usage: 7.5 MB, less than 6.33% of C++ online submissions for Print Zero Even Odd.
*/
class ZeroEvenOdd_1116 {
private:
    int n;
    std::mutex m;
    std::condition_variable cond;
    bool zero_flag = true;  //只要打印了数字就置true -> print 0
    bool odd_flag = true;   //是否可以打印奇数
public:
    ZeroEvenOdd_1116(int n) {
        this->n = n;
    }
    // printNumber(x) outputs "x", where x is an integer.
    //void zero(function<void(int)> printNumber) {
    void zero() {
        for (int ind = 0; ind < n; ++ind)
        {
            std::unique_lock<std::mutex> lk(m);
            cond.wait(lk, [this] {return zero_flag; });
            printNumber(0);
            zero_flag = false;
            cond.notify_all();
        }
    }

    //void odd(function<void(int)> printNumber) {
    void odd() {
        for (int ind = 1; ind <= n; ind += 2)
        {
            std::unique_lock<std::mutex> lk(m);
            cond.wait(lk, [this] {return !zero_flag && odd_flag; });
            printNumber(ind);
            zero_flag = true;
            odd_flag = false;
            cond.notify_all();
        }
    }

    //void even(function<void(int)> printNumber) {
    void even() {
        for (int ind = 2; ind <= n; ind += 2)
        {
            std::unique_lock<std::mutex> lk(m);
            cond.wait(lk, [this] {return !zero_flag && !odd_flag; });
            printNumber(ind);
            zero_flag = true;
            odd_flag = true;
            cond.notify_all();
        }

    }
private:
    void printNumber(int num)
    {
        std::cout << num << std::endl;
    }
};
