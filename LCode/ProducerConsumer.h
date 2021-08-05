#pragma once
#include <iostream>
#include <vector>
#include <queue>
#include <mutex>
#include <thread>
#include <chrono>
/*
	��������������ߺ������ߣ����������������ߣ�������ģʽ����ģʽ����Ҫ��һ�����������������ߺ�������֮�䣬��Ϊһ���н顣�����߰����ݷ��뻺�������������ߴӻ�����ȡ�����ݡ�
	����������
		����
		֧�ֲ�����������ţ����ŷŰ��ŷ�������Ϳ���ȥ����������ˣ�������������ɵ�
*/



/*
	could control produce/consume speed.
*/
class ProducerConsumer
{
public:
	static std::queue<int> m_productionBuff;
	static const int m_maxQueueSize = 10;
	static const int m_totalProductCount = 20;
	static std::mutex m_mtx;
	static std::condition_variable m_cvProducer, m_cvConsumer;
	//can't init static member in class
	static int m_productIndex;
	static int m_consumeIndex;
	//static bool m_ready;
	//static bool m_done;

	static void producer(int producerID, int produceSpeed)
	{
		while (true)
		{
			this_thread::sleep_for(chrono::milliseconds(produceSpeed));      // producer is a little faster than consumer  

			unique_lock<mutex> lck(m_mtx);
			m_cvProducer.wait(lck, [] {return m_productionBuff.size() != m_maxQueueSize; });   // will block this thread when m_productionBuff.size() == max. otherwise, will produce continuely

			cout << "->>> producer " << ": ";
			m_productionBuff.push(producerID);
			cout << "procue " << to_string(++m_productIndex) << endl;
			cout << m_productionBuff.size() << '\n';

			m_cvConsumer.notify_all();  // notify(wake up) consumer since we have product now.

		}
	}

	static void consumer(int consumeSpeed)
	{
		while (true)
		{
			this_thread::sleep_for(chrono::milliseconds(consumeSpeed));

			unique_lock<mutex> lck(m_mtx);
			m_cvConsumer.wait(lck, [] {return m_productionBuff.size() != 0; });     // wait(block) consumer if buffer is 0. otherwise, will consume product

			cout << "<<<-consumer " << ": ";
			m_productionBuff.pop();
			cout << "consume " << to_string(++m_consumeIndex) << endl;
			cout << m_productionBuff.size() << '\n';

			m_cvProducer.notify_all();                               // nodity(wake up) producer when q.size() != maxSize is true
		}
	}
};



// ֻ����״̬������ͬ��
class ProducerConsumer_NoSync
{
private:
	bool m_isBuffHasProduct = false;
	int m_productIndex = 0;
	const int m_productCount = 50;
	const int m_bufferSize = 10;
	//std::vector<int> m_buffer;
	std::queue<int> m_buffer;

public:
	void produce()
	{
		while (m_productIndex < m_productCount)
		{
			if (m_buffer.size() < m_bufferSize)
			{
				m_productIndex++;
				m_buffer.push(m_productIndex);
				std::cout << "Producing " << m_productIndex << std::endl;
			}
		}
		std::cout << "Produce done!" << std::endl;
	}

	void consume()
	{
		while (m_productCount < m_productCount)
		{
			if (m_buffer.size() > 0)
			{
				m_buffer.pop();
				std::cout << "Consuming " << m_productIndex << std::endl;

			}
		}
		std::cout << "Consume done!" << std::endl;
	}
};