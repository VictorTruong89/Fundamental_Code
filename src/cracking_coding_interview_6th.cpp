#include "cracking_coding_interview_6th.hpp"

using namespace std;

/*
QUESTION 2.1:
	Write codes to remove duplicates from an unsorted linked list
	Implement 2nd algorithm, in which no temporary buffer is allowed
	e.g. "FOLLOWUP" --> "FOLWUP"
*/
#include <unordered_map>
int C02_LinkedList::Solution_2_1()
{
	std::string sample = "follow up ASCW FOL fol";
	int size = sizeof(sample) / sizeof(sample[0]);

	/*=====METHOD 1=====*/
	// Hash_Map that stores the elements that has appeared previously
	unordered_map<char, bool> map_sample;

	for(int i = 0; i < size; i++)
	{
		// Print out the elements if it is not there in the Hash_Map
		if (map_sample.find(sample[i]) == map_sample.end())
			std::cout << sample[i] << " ";

		// Insert this elements in the Hash Map
		map_sample[sample[i]] = true;
	}

	/*=====METHOD 2=====*/


	std::cout << "\nEND\n";
	return 0;
}


/*
QUESTION 2.3
	Delete a node in the middle of a singly linked list, given only access to that node.
	e.g. Given a list a->b->c->d->e->f ; Delete node "c"
*/
int C02_LinkedList::Solution_2_3()
{
	int sample[] = { 1,2,3,4,5,6,7,8,9 };
	const int location = 5;

	Node* head;
	Node* tail;
	Node *next = head;
	next = new Node;

	return 0;
}


