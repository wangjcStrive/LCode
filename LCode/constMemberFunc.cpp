#include "constMemberFunc.h"

void constMemberFunc::funcToBeCallByConstMember()
{
	m_sMember = "funcToBeCallByConstMember";
}

void constMemberFunc::constFunc() const
{
	// 不能修改类的成员变量
	//m_sMember = "constFunc";
	// 不能调用非const成员函数
	//printMember();
}

void constMemberFunc::printMember()
{
	cout << m_sMember << endl;
}
