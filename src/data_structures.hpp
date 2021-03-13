#ifndef _DATA_STRUCTURES_HPP_
#define _DATA_STRUCTURES_HPP_


#include <iostream>
#include <stdlib.h>
#include <list>

using namespace std;

struct Node
{
	int item;
	struct Node* next;
};

class HashTable
{
	int capacity;
	list<int>* table;

public:
	HashTable(int V)
	{
		int size = GetPrime(V);
		this->capacity = size;
		table = new list<int>[capacity];
	}

	inline int HashFunction(int key) { return key % capacity; }

	void InsertItem(int key, int data);

	void DeleteItem(int key);

	int CheckPrime(int n);

	int GetPrime(int n);

	void DisplayHash();

	int Example();
};


class LinkedList
{
public:
	bool InsertAtHead(Node** ref, int data);

	bool InsertAtTail(Node** ref, int data);

	bool InsertAtMid(Node* prev_node, int data);

	bool DeleteNode(Node** ref, int key);

	bool DisplayLinkedList(Node *node);
};


class Tree
{
public:
	struct Node
	{
		int data;
		struct Node *left, *right;
		Node(int data)
		{
			this->data = data;
			left = right = NULL;
		}
	};

	// Preorder traversal
	void PreorderTraversal(Node* node);

	// Postorder traversal
	void PostorderTraversal(Node* node);

	// InorderTraversal
	void InorderTraversal(Node* node);

	// New Node Creation
	Node* NewNode(int data);

	//
	bool isFullBinaryTree(Node* root);
};

#endif // !_DATA_STRUCTURES_HPP_


