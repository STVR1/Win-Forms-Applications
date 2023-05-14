#pragma once

#include<iostream>

template<class type>
class MyStack
{

private:

	struct Node
	{
		type info;

		Node* next;

		Node(type info): info(info), next(nullptr){
		}

	};

	Node* Top;

public:

	MyStack() :Top(nullptr) {
	}

	void push(type info)
	{
		Node* field = new Node(info);
		
		if (Top == nullptr)Top = field;
		else
		{
			field->next = Top;
			Top = field;
		}
	}

	void pop()
	{
		Node* field = Top->next;
		delete Top;
		Top = field;
	}

	Node* top()
	{
		return Top;
	}

	int size()
	{
		Node* field = Top;
		int counter = 0;

		while (field != nullptr)
		{
			field = field->next;
			counter++;
		}

		return counter;
	}

	void clear()
	{
		while (Top != nullptr)pop();
	}

	~MyStack()
	{
		clear();
	}

};