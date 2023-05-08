#pragma once

#include<iostream>

#include"PairClass.h"

template<typename type1, typename type2>
class Node
{

private:

	Pair<type1, type2> pair;

public:

	Node<type1, type2>* left, * right;

	Node(Pair<type1, type2> pair) : pair(pair), left(nullptr), right(nullptr) {
	}

	Node() : left(nullptr), right(nullptr) {
	}

	Pair<type1, type2>* GetPair()
	{
		return &this->pair;
	}

};

template<typename type1, typename type2>
class Tree
{

	typedef Node<type1, type2> TNode;

	typedef Pair<type1, type2> NPair;

private:

	TNode* root;

	NPair* searched = nullptr;

	int nodescount;

	void Add(TNode*& node, NPair pair)
	{
		if (!node)node = new Node<type1, type2>(pair), nodescount++;
		else
		{
			if (node->GetPair()->first > pair.first) Add(node->left, pair);
			else if (node->GetPair()->first < pair.first)Add(node->right, pair);
		}
	}

	void Delete(type1 key, TNode*& parent, TNode*& child)
	{
		if (!child)return;

		if (parent == child && child->GetPair()->first == key)
		{
			TNode* field1 = child->right;
			TNode* field2 = child;

			NPair min = (*field1->GetPair());

			while (true)
			{
				if (min.first > field1->GetPair()->first)min = (*field1->GetPair());
				if (field1->left == nullptr)break;
				field2 = field1;
				field1 = field1->left;
			}

			(*child->GetPair()) = min;

			if (field2 == child)
			{
				field2->right = field2->right->right;
				delete field1;
				field1 = nullptr;
			}
			else
			{
				field2->left = nullptr;
				delete field1;
				field1 = nullptr;
			}

			nodescount--;

			return;
		}

		if (child->GetPair()->first == key)
		{

			if (child->left == nullptr && child->right == nullptr)
			{

				if (parent->GetPair()->first > child->GetPair()->first)parent->left = nullptr;
				else parent->right = nullptr;

				delete child;
				child = nullptr;
			}
			else if (child->left == nullptr)
			{
				if (parent->GetPair()->first > child->GetPair()->first)
				{
					auto field = child->right;
					delete child;
					child = nullptr;
					parent->left = field;
				}
				else
				{

					auto field = child->right;
					delete child;
					child = nullptr;
					parent->right = field;
				}

			}
			else if (child->right == nullptr)
			{

				if (parent->GetPair()->first > child->GetPair()->first)
				{
					auto field = child->left;
					delete child;
					child = nullptr;
					parent->left = field;
				}
				else
				{
					auto field = child->left;
					delete child;
					child = nullptr;
					parent->right = field;
				}

			}
			else
			{
				TNode* field1 = child->right;
				TNode* field2 = child;

				NPair min = (*field1->GetPair());

				while (true)
				{
					if (min.first > field1->GetPair()->first)min = (*field1->GetPair());
					if (field1->left == nullptr)break;
					if (field1->left == nullptr)break;
					field2 = field1;
					field1 = field1->left;
				}

				(*child->GetPair()) = min;

				if (field2 == child)field2->right = nullptr;
				else field2->left = nullptr;
				delete field1;
				field1 = nullptr;

			}

			nodescount--;

			return;
		}

		if (child)Delete(key, child, child->left);
		if (child)Delete(key, child, child->right);

	}

	void Clear(TNode*& node)
	{
		if (!node)return;
		Clear(node->left);
		Clear(node->right);
		delete node;
		node = nullptr;
	}

	NPair* Preorder(TNode* node, NPair* array, int& index)
	{
		if (!node)return array;
		array[index++]=(*node->GetPair());
		Preorder(node->left, array, index);
		Preorder(node->right, array, index);
		return array;
	}

	NPair* Postorder(TNode* node, NPair* array, int& index)
	{
		if (!node)return array;
		Postorder(node->left, array, index);
		Postorder(node->right, array, index);
		array[index++] = (*node->GetPair());
		return array;
	}

	NPair* Inorder(TNode* node, NPair* array, int& index)
	{
		if (!node)return array;
		Inorder(node->left, array, index);
		array[index++] = (*node->GetPair());
		Inorder(node->right, array, index);
		return array;
	}

	void MakeBalanced(TNode** node, int n, int k, TNode* arr)
	{
		if (n == k)
		{
			*node = nullptr;
			return;
		}
		else
		{
			int middle = (n + k) / 2;
			*node = new Node<type1, type2>(arr[middle]);
			MakeBalanced(&(*node)->left, n, middle, arr);
			MakeBalanced(&(*node)->right, middle + 1, k, arr);
		}
	}

	NPair* Max(TNode* node)
	{
		if (node->right != nullptr) {
			return Max(node->right);
		}
		else {
			return node->GetPair();
		}
	}

	NPair* Min(TNode* node)
	{
		if (node->left != nullptr) {
			return Min(node->left);
		}
		else {
			return node->GetPair();
		}

	}

	void Find(type1 key, TNode* node)
	{
		if (!node)return;

		if (node->GetPair()->first == key)
		{
			searched = node->GetPair();
			return;
		}

		Find(key, node->left);

		Find(key, node->right);

	}

	void QuickSort(TNode* arr, int start, int end)
	{
		if (start < end)
		{
			int left = start;
			int right = end;
			auto middle = arr[(start + end) / 2].GetPair()->first;
			do
			{
				while (arr[left].GetPair()->first < middle)left++;
				while (arr[right].GetPair()->first > middle)right--;
				if (left <= right)
				{
					Node<type1, type2> temp = arr[right];
					arr[right] = temp;
					left++;
					right--;
				}
			} while (left < right);
			QuickSort(arr, start, right);
			QuickSort(arr, left, end);
		}
	}

	void MakeArray(TNode* arr, TNode* node, int& index)
	{

		if (!node)return;

		MakeArray(arr, node->left, index);

		arr[index].GetPair()->first = node->GetPair()->first;
		arr[index++].GetPair()->second = node->GetPair()->second;

		MakeArray(arr, node->right, index);

	}

public:

	Tree() : root(nullptr), nodescount(0) {
	}

	// Method to push node

	void Add(NPair pair)
	{
		Add(root, pair);
	}

	// Method to delete node

	void Delete(type1 key)
	{
		Delete(key, root, root);
	}

	// Method to print a tree (preorder traversal)

	NPair* Preorder()
	{
		NPair* array = nullptr;
		int index = 0;

		if (nodescount == 0)return nullptr;
		else array = new NPair[nodescount];
		
		return Preorder(root, array, index);
	}

	// Method to print a tree (inorder traversal)

	NPair* Inorder()
	{
		NPair* array = nullptr;
		int index = 0;

		if (nodescount == 0)return nullptr;
		else array = new NPair[nodescount];

		return Inorder(root, array, index);
	}

	// Method to print a tree (postorder traversal)

	NPair* Postorder()
	{
		NPair* array = nullptr;
		int index = 0;

		if (nodescount == 0)return nullptr;
		else array = new NPair[nodescount];

		return Postorder(root, array, index);
	}

	// Method to clear a tree

	void Clear()
	{
		Clear(root);
		nodescount = 0;
	}

	// Method to balance a tree

	void MakeBalanced()
	{
		if (!root)return;

		int index = 0;
		Node<type1, type2>* arr = new Node<type1, type2>[nodescount];

		MakeArray(arr, root, index);
		QuickSort(arr, 0, nodescount - 1);

		Clear(root);
		MakeBalanced(&root, 0, nodescount, arr);

		delete[] arr;
	}

	// Method to create a tree using array with nodes

	void Emplace(NPair* array, int size)
	{
		if (array==nullptr)return;
		for (int i = 0; i < size; i++)Add(array[i]);
	}

	// Method to find a node using a key

	auto Find(type1 key)
	{
		searched = nullptr;
		Find(key, root);
		return searched;
	}

	// Method to check, if a tree is empty

	bool IsEmpty()
	{
		if (!root)return true;
		return false;
	}

	// Method to get a node with max key

	NPair* Max()
	{
		if (!root)return nullptr;
		return Max(root);
	}

	// Method to get a node with min key

	NPair* Min()
	{
		if (!root)return nullptr;
		return Min(root);
	}

	// Method to get a size of tree

	int Size()
	{
		return this->nodescount;
	}

	// Method to get the root

	auto Begin()
	{
		return root;
	}

	// Destructor with function Clear()

	~Tree()
	{
		if (root != nullptr)Clear(root);
	}

};

template<typename type1, typename type2>
class MyTask : protected Node<type1, type2>
{

private:

	Node<type1, type2>* root;

	int* searchedarray;

	void OneBranch(Node<type1, type2>* node, int& counter)
	{
		if (!node)return;
		if ((node->left == nullptr && node->right != nullptr) || (node->left != nullptr && node->right == nullptr)) counter++;
		OneBranch(node->left, counter);
		OneBranch(node->right, counter);
	}

	void GetSearched(Node<type1, type2>* node, int& counter, int* array)
	{
		if (!node)return;
		if ((node->left == nullptr && node->right != nullptr) || (node->left != nullptr && node->right == nullptr)) array[counter++]=node->GetPair()->first;
		GetSearched(node->left, counter, array);
		GetSearched(node->right, counter, array);
	}

public:

	int OneBranchNodes()
	{
		int counter = 0;
		OneBranch(root, counter);
		return counter;
	}

	int* GetSearched()
	{
		int counter = 0;
		if (searchedarray != nullptr)delete[] searchedarray, searchedarray = nullptr;
		searchedarray = new int[OneBranchNodes()];
		GetSearched(root, counter, searchedarray);
		return searchedarray;
	}

	MyTask(Node<type1, type2>* root) : root(root), searchedarray(nullptr) {
	}

	MyTask() :root(nullptr), searchedarray(nullptr) {
	}
	
	~MyTask()
	{
		if (searchedarray != nullptr)delete[] searchedarray, searchedarray = nullptr;
	}

};