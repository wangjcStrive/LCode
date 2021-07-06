#pragma once
#include "solutions.h"
class constMemberFunc
{
public:
	void funcToBeCallByConstMember();
	void constFunc() const;
	void printMember();

private:
	string m_sMember;
};

