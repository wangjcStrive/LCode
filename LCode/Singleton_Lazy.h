#pragma once
#include "solutions.h"

class SingletonLazy
{
public:
	static SingletonLazy* getInstance()
	{
		if (m_pSingletonLazy == NULL)
		{
			m_pSingletonLazy = new SingletonLazy();
		}
		return m_pSingletonLazy;
	}
private:
	static SingletonLazy* m_pSingletonLazy;
	SingletonLazy();
};
