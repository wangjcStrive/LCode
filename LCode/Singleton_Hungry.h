#pragma once
#include "solutions.h"

class SingletonHungry
{
private:
	SingletonHungry();
	static SingletonHungry m_instance;
public:
	static SingletonHungry* getSingletonInstance();
};

SingletonHungry* SingletonHungry::getSingletonInstance()
{
	return &m_instance;
}
