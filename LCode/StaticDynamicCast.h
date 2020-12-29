#pragma once

namespace StaticDynamicCast
{
	class A
	{
	public:
		A() {};
		int m_Num;
		virtual void foo() {};
	};

	class B : public A
	{
	public:
		B() {};
		char* m_Name[100];
	};

	void castFunc(A* pA)
	{
		B* pB1 = static_cast<B*>(pA);
		B* pB2 = dynamic_cast<B*>(pA);
	}
}

