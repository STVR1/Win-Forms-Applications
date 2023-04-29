#pragma once

#include<iostream>

template<typename type>
class Library
{

private:
	
	struct Book
	{

	private:
		
	    type info;

	public:

		Book* next = nullptr;

		Book* prev = nullptr;

		type GetInfo()
		{
			return this->info;
		}

		type& GetLinkInfo()
		{
			return this->info;
		}

		void SetInfo(type info)
		{
			this->info = info;
		}

	};

	Book* begin = nullptr, * end = nullptr;

public:

	void push_back(type info);

	void push_front(type info);

	void pop_back();

	void pop_front();

	auto Begin();

	auto End();

	int GetSize();

	type& operator[](const int index);

};

template<typename type>
void Library<type>::push_back(type info)
{
	Book* field = new Book;
	field->SetInfo(info);
	if (begin == nullptr)begin = end = field;
	else
	{
		field->prev = end;
		end->next = field;
		end = field;
	}
}

template<typename type>
void Library<type>::push_front(type info)
{
	Book* field = new Book;
	field->SetInfo(info);
	if (begin == nullptr)begin = end = field;
	else
	{
		field->next = begin;
		begin->prev = field;
		begin = field;
	}
}

template<typename type>
void Library<type>::pop_back()
{
	Book* field = end->prev;
	delete end;
	end = field;
}

template<typename type>
void Library<type>::pop_front()
{
	Book* field = begin->next;
	delete begin;
	begin = field;
}

template<typename type>
auto Library<type>::Begin()
{
	return this->begin;
}

template<typename type>
auto Library<type>::End()
{
	return this->end;
}

template<typename type>
int Library<type>::GetSize()
{
	int counter = 0;
	Book* field = begin;
	while (field != end)
	{
		field = field->next;
		counter++;
	}
	return ++counter;
}

template<typename type>
type& Library<type>::operator[](const int index)
{
	int counter = 0;
	Book* field = this->begin;
	while (field != nullptr)
	{
		if (counter == index)return field->GetLinkInfo();

		field = field->next;
		counter++;
	}
}