#include"ClassLibrary.h"

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
type Library<type>::Begin()
{
	return this->begin;
}

template<typename type>
type Library<type>::End()
{
	return this->end;
}

template<typename type>
int Library<type>::GetSize()
{
	int counter = 0;
	Book* field = begin;
	while (field != nullptr)
	{
		field = field->next;
		counter++;
	}
	return counter;
}

template<typename type>
type Library<type>::operator[](const int index)
{
	int counter = 0;
	Book* field = this->begin;
	while (field != nullptr)
	{
		if (counter == index)return field->GetInfo();

		field = field->next;
		counter++;
	}
}