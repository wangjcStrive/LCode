#include "solutions.h"
#include <Windows.h>
#include <mutex>

/*
    1114. Print in Order
    『三个不同的线程将会共用一个 Foo 实例!!』
    Runtime: 128 ms, faster than 59.53% of C++ online submissions for Print in Order.
    Memory Usage: 7.1 MB, less than 89.26% of C++ online submissions for Print in Order.
*/

class PrintInOrder_1114 {
public:
    PrintInOrder_1114() {

    }

    void first(function<void()> printFirst) {
        std::unique_lock<std::mutex> lk(m_mutex);
        
        printFirst();

        counter++;
        cv1.notify_one();
    }

    void second(function<void()> printSecond) {
        std::unique_lock<std::mutex> lk(m_mutex);
        cv1.wait(lk, [this]() {return counter == 2; });

        printSecond();

        counter++;
        cv2.notify_one();
    }

    void third(function<void()> printThird) {
        std::unique_lock<std::mutex> lk(m_mutex);
        cv2.wait(lk, [this]() {return counter == 3; });

        printThird();
    }

private:
    int counter = 1;
    std::condition_variable cv1;
    std::condition_variable cv2;
    std::mutex m_mutex;
};


/*
    没有使用条件wait
*/
class ThreadDemo {
public:
    void first() {
        std::unique_lock<std::mutex> lk(m_mutex);
        cout << "print: " << 1 << endl;

        cv1.notify_one();
        m_counter++;
    }

    void second() {
        std::unique_lock<std::mutex> lk(m_mutex);
        while (m_counter != 2)
        {
            cv1.wait(lk);
        }

        cout << "print: " << 2 << endl;
        m_counter++;
        cv2.notify_one();
    }

    void third() {
        std::unique_lock<std::mutex> lk(m_mutex);
        while (m_counter != 3)
            cv2.wait(lk);

        cout << "print: " << 3 << endl;

    }
private:
    std::mutex m_mutex;
    std::condition_variable cv1;
    std::condition_variable cv2;
    int m_counter = 1;
};