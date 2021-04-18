#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

#include "C01_arrays_string.hpp"
#include "C02_linked_list.hpp"


using namespace std;

void DisplayLinkedList(LinkedList::Node* node)
{
	while(node->next != NULL)
	{
		cout << node->key << " ";
		node = node->next;
	}
	cout << endl;
}


int main()
{
	LinkedList list;

	LinkedList::Node *one, *two, *three, *four, *five, *six;
	one = new LinkedList::Node();
	two = new LinkedList::Node();
	three = new LinkedList::Node();
	four = new LinkedList::Node();
	five = new LinkedList::Node();
	six = new LinkedList::Node();
	//
	one->key = 10;
	two->key = 2;
	three->key = 12;
	four->key = 4;
	five->key = 1;
	six->key = 22;
	//
	one->next = two;
	two->next = three;
	three->next = four;
	four->next = five;
	five->next = six;

	// Display original Linked List
	DisplayLinkedList(one);

	// list.RemoveDuplicate(one);
	LinkedList::Node* test = list.Partition(one, 11);

	// Display final Linked List
	// DisplayLinkedList(test);
	DisplayLinkedList(test);

	return 0;
}

