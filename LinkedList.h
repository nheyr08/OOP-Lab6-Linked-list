#pragma once
#pragma once
#include<iostream>
using namespace std;

struct ListNode
{
	int data;
	ListNode* next;

	ListNode() : data(0), next(NULL) {};
	ListNode(int x) : data(x), next(NULL) {};
};

class LinkedList
{

public:
	LinkedList();
	void Push_back(int x);
	void Push_front(int x);
	void Insert(int data, int n);
	void Delete(int index);
	void Reverse();
	void Print();
	~LinkedList();

private:
	ListNode* Head;
};