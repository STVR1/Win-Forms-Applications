#pragma once

#include<iostream>

template<class type>
class ATS
{

private:

	struct User
	{

	private:

		type info;

	public:

		void SetInfo(type info)
		{
			this->info = info;
		}

		type GetInfo()
		{
			return this->info;
		}

		type& GetLinkInfo()
		{
			return this->info;
		}

	};

	int capacity;
	int size;
	const int DEFAULT_CAPACITY = 10;
	User* array = nullptr;

public:

	ATS();

	void push_back(type info);

	void pop_back();

	int Size();

	void clear();

	type& operator[](const int index);

};

template<typename type>
ATS<type>::ATS()
{
	array = new User[DEFAULT_CAPACITY];
	capacity = DEFAULT_CAPACITY;
	size = 0;
}

template<typename type>
void ATS<type>::push_back(type info)
{
	if (array == nullptr)
	{
		array = new User[DEFAULT_CAPACITY];
		array[size].SetInfo(info);
	}
	else if (size == capacity)
	{
		capacity = 3 * capacity / 2 + 1;
		User* newarray = new User[capacity];

		for (int i = 0; i < size; i++)newarray[i] = array[i];
		newarray[size].SetInfo(info);

		delete[] array;
		array = newarray;
	}
	else array[size].SetInfo(info);

	size++;
}

template<typename type>
void ATS<type>::pop_back()
{
	if (size > 1)
	{
		User* newarray = new User[--size];
		for (int i = 0; i < size; i++) newarray[i] = array[i];
		delete[]array;
		array = newarray;
	}
	else if (size == 1)
	{
		delete[] array;
		array = nullptr;
		capacity = DEFAULT_CAPACITY;
		size = 0;
	}

}

template<typename type>
int ATS<type>::Size()
{
	return this->size;
}

template<typename type>
type& ATS<type>::operator[](const int index)
{
	if (size > 0 && index<size && index>-1)
	{
		for (int i = 0; i < size; i++)if (index == i)return array[i].GetLinkInfo();
	}
}

template<typename type>
void ATS<type>::clear()
{
	if(array!=nullptr)delete[] array;
	array = nullptr;
	size = 0;
	capacity = DEFAULT_CAPACITY;
}