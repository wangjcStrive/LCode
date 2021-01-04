#pragma once
#pragma warning( disable : 4018 )
#include <iostream>
#include <vector>
#include <set>
#include <string>
#include <stack>
#include <algorithm>
#include <limits>
#include <iostream>
#include <fstream>
#include <sstream>

/*
	tag list: Sort. DP. Hash. Stack. DataStruct(Tree, LinkList). Thread. TwoPointer
*/

using namespace std;

class ListNode {
public:
	int val;
	ListNode* next;
	ListNode(int x) : val(x), next(NULL) {}
	static void printListNode(ListNode* head)
	{
		for (ListNode* cur = head; cur != nullptr; cur = cur->next)
			cout << cur->val << endl;
	}
};


class Solution {
public:
	Solution()
	{

	}
	static void readLongVecFromFile(vector<int>& vec)
	{
		//ifstream fileStream("C:\\Users\\jicwang\\Documents\\Study\\Code\\LCodeCPP\\LCode\\LCode\\andomData20000.txt");
		//ifstream myfile("G:\\C++ project\\Read\\hello.txt");
		ifstream fileStream;
		string tempLineStr;
		std::stringstream strStream;
		fileStream.open(".\\RandomData20000.txt");
		if (!fileStream.is_open())
			cout << "can't open random data file" << endl;
		while (!fileStream.eof())
		{
			fileStream >> tempLineStr;
			strStream << tempLineStr;
			int tempInt;
			strStream >> tempInt;
			strStream.clear();
			vec.push_back(tempInt);
		}
	}
#pragma region PrintFunc
	template<class T>
	static void printVec(const vector<T>& input)
	{
		for (auto x : input)
		{
			cout << x << " ";
		}
		cout << ":" << endl;
	}
	template<class T>
	static void printVec(const vector<T>& input, T input2)
	{
		for (auto x : input)
		{
			cout << x << " ";
		}
		cout << ": " << input2 << endl;
	}
	static void printVector(vector<int> input)
	{
		for (auto x : input)
			std::cout << x << " ";
		std::cout << endl;
	}

	static void printLinkList(ListNode* head)
	{
		while (head != NULL)
		{
			std::cout << head->val << " ";
			head = head->next;
		}
		std::cout << endl;
	}
	template<typename T>
	static void printResult(T except, T output)
	{
		try
		{
			std::cout << "except: " << except << ".  result: " << output << std::endl;
		}
		catch (const std::exception& e)
		{
			std::cout << e.what() << endl;
		}
	}
#pragma endregion

};

