#ifndef _C02_LINKED_LIST_HPP_
#define _C02_LINKED_LIST_HPP_

#include <iostream>
#include <string>
#include <unordered_set>    // for using Hash Table



class LinkedList
{
public: 
    struct Node
    {
        Node* next = NULL;
        int key;
    };
    

    /** @brief QUESTION 2.1
     * 
     * Remove duplicates from an unsorted linked list. 
     * What if no temporary buffer is allowed.
    */
    bool RemoveDuplicate(Node* node);


    /** @brief QUESTION 2.2
     * 
     * Find from k-th to the last Node of a Linked List
     * e.g. k=1 >> last Node ; k=2 >> 2nd-last Node ; k=3 >> 3rd-last Node
    */
    LinkedList::Node* kNode2Last(LinkedList::Node* head, int k);


    /** @brief QUESTION 2.3
     * 
     * Delete a Node at somewhere middle of a Linked List
     * Please refer to private function below DeleteNode(Node* ref, int data);
    */


    /** @brief QUESTION 2.4
     * 
     * Given a value (Node->key)
     * Re-arrange Nodes such that smaller Node->key go in front, larger Node->key go behind
     * Just re-arrange into 2 groups. Not require to sort in ascending / descending order.
    */
    LinkedList::Node* Partition(LinkedList::Node* head, int value);


    /** @brief QUESETION 2.5
     * 
     * Given 2 numbers that are represented by Linked List in reversed order,
     * such that the last digit is stored at head of Linked List.
     * Add them up & store the result in another Linked List
    */
    LinkedList::Node* SumLists(LinkedList::Node* one, LinkedList::Node* two, bool& carry);


    /** @brief QUESTION 2.7
     * Given 2 Linked Lists, determine if they intersect each other.
     * Return the Node at Intersection
    */
    LinkedList::Node* checkIntersectList(LinkedList::Node* one, LinkedList::Node* two);




private:
    // Create a new Node
    Node* CreateNode (int data);

    // Insert new Node to the beginning of Linked List
    bool InsertHead (Node* ref, int data);

    // Insert new Node to the end of Linked List
    bool InsertTail (Node* ref, int data);

    // Insert new Node to somewhere in the middle of Linked List
    bool InsertMid (Node* prev_node, int data);

    // Delete a particular Node
    bool DeleteNode(Node* ref, int data);

};





#endif //_C02_LINKED_LIST_HPP_