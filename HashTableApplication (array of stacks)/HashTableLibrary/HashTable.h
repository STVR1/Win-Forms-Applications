#pragma once

#include<iostream>
#include"Stack.h"
#include"PairClass.h"

class HashTable
{

private:

	class HashItem
	{

	public:

		MyStack<Pair<int, int>> mystack;

		HashItem() : mystack(MyStack<Pair<int, int>>()) {
		}

		~HashItem() {
		}

	};

private:

	HashItem** items;

	int size;
	int count;

	unsigned long HashFunc(int key);

public:

	HashTable(int size);

	HashTable();

	void Insert(int key, int value);

	int Search(int);

	HashItem* ExtendedSearch(int index)
	{
		return items[index];
	}

	bool Delete(int);

	void Clear();

	int Size();

	~HashTable();

};


// Private

unsigned long HashTable::HashFunc(int key) {

	int temp = key, counter = 0, amount=0;

	do
	{
		amount++;
		temp /= 10;
	} while (temp != 0);

	if (key < 0)amount++;
	char* string = new char[++amount];

    temp = key;
	if (key < 0)temp *= -1;
	
	do
	{
		
		switch (temp % 10)
		{
			case 0:
			{
				string[counter++] = '0';
				break;
			}
			case 1:
			{
				string[counter++] = '1';
				break;
			}
			case 2:
			{
				string[counter++] = '2';
				break;
			}
			case 3:
			{
				string[counter++] = '3';
				break;
			}
			case 4:
			{
				string[counter++] = '4';
				break;
			}
			case 5:
			{
				string[counter++] = '5';
				break;
			}
			case 6:
			{
				string[counter++] = '6';
				break;
			}
			case 7:
			{
				string[counter++] = '7';
				break;
			}
			case 8:
			{
				string[counter++] = '8';
				break;
			}
			case 9:
			{
				string[counter++] = '9';
				break;
			}
		}

		temp /= 10;
		
	} while (temp!=0);

	if (key < 0 && counter<amount) string[counter++] = '-';
	string[counter] = '\0';
	
	unsigned long i = 0;
	
	for (int j = 0; j < amount; j++) i += string[j];

	delete[] string, string = nullptr;
	
	return i % size;

}


// Public

HashTable::HashTable() :items(nullptr), size(0), count(0)
{

}

HashTable::HashTable(int size) : size(size), count(0), items(new HashItem* [size]) {
	for (int i = 0; i < size; i++)items[i] = nullptr;
}

int HashTable::Size()
{
	return this->size;
}

void HashTable::Insert(int key, int value)
{
	int index = HashFunc(key);

	Pair<int, int> pair;
	pair.first = key;
	pair.second = value;

	if (items[index] == nullptr)items[index] = new HashItem(), count++;
	
	auto field = items[index]->mystack.top();

	while (field != nullptr)
	{
		if (field->info.first == key)
		{
			field->info.second = value;
			return;
		}
		field = field->next;
	}

	items[index]->mystack.push(pair);

}

int HashTable::Search(int key)
{
	int index = HashFunc(key);
	HashItem* item = items[index];

	if (item != nullptr) {

		if (item->mystack.top()->info.first == key) return item->mystack.top()->info.second;
		else
		{
			auto field = item->mystack.top();
			while (field != nullptr)
			{
				if (field->info.first == key)return field->info.second;
				field = field->next;
			}
		}
	}
	return -100;
}

bool HashTable::Delete(int key)
{
	int index = HashFunc(key);

	if (items[index] == nullptr)return false;

	if (items[index]->mystack.top()->info.first != key)
	{
		auto field = items[index]->mystack.top();

		while (field != nullptr)
		{
			if (field->info.first == key)
			{
				field->info = items[index]->mystack.top()->info;
				items[index]->mystack.pop();
				return true;
			}
			field = field->next;
		}

	}
	else
	{
		items[index]->mystack.pop();

		if (items[index]->mystack.top() == nullptr)
		{
			delete items[index], items[index] = nullptr, count--;
			return true;
		}
	}

	return false;
}

void HashTable::Clear()
{
	if (items == nullptr) return;
	for (int i = 0; i < size; i++)if (items[i] != nullptr)delete items[i], items[i] = nullptr;
	delete[] items, items = nullptr;
}

HashTable::~HashTable()
{
	if (items != nullptr)Clear();
}


class DivideTables : public HashTable
{

public:

	DivideTables() 
	{

	}

	Pair<MyStack<Pair<int, int>>, MyStack<Pair<int, int>>>* Divide(HashTable* table);

};

Pair<MyStack<Pair<int, int>>, MyStack<Pair<int, int>>>* DivideTables::Divide(HashTable* table)
{

	Pair<int, int> pair;
	Pair<MyStack<Pair<int, int>>, MyStack<Pair<int, int>>>* result=new Pair<MyStack<Pair<int, int>>, MyStack<Pair<int, int>>>;

	for (int i = -1; i>-51; i--)
	{
		pair.first = i;
		pair.second = table->Search(i);

		if (pair.second != -100) result->second.push(pair);

	}

	for (int i = 50; i > 0; i--)
	{
		pair.first = i;
		pair.second = table->Search(i);

		if (pair.second != -100) result->first.push(pair);
	}

	return result;

}