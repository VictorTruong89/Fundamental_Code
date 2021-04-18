/** LICENCE
 * 
*/

#include "C02_linked_list.hpp"

using namespace std;

/** @brief QUESTION 2.1a - SOLUTION
 * 
 * Remove duplicates from an unsorted Linked List
 * Traverse through LinkedList once, add each element to a Hash Table.
 * When we discover a duplicate elements, we simply delete that Node.
 * 
 * This algorithm requires memory buffer for Hash Table, but run at O(N)
 * @param[in] node  Pointer to the Node at beginning search
 * @return "true" if there are duplicates inside the unsorted Linked List
*/
bool LinkedList::RemoveDuplicate(Node* node)
{
    std::unordered_set<int> hash;

    Node* prev_node;

    while(node->next != NULL)
    {
        // If cannot find node->key inside the Hash Table
        if( hash.find(node->key) == hash.end() )
        {
            hash.insert(node->key);
            prev_node = node;
        }
        else
        {
            // Remove the Node node
            prev_node->next = node->next;
        }

        // Traverse to the next Node of Linked List
        node = node->next;
    }

    return true;
}
/** @brief QUESTION 2.1b - SOLUTION
 * 
 * Remove duplicates from an unsorted Linked List, given that no memory buffer is allowed.
 * Use 2 pointer to run along the Linked List.
 * 1st-pointer to anchor a specific Node that has not been seen before.
 * 2nd-pointer search the rest of Linked List n delete Nodes that duplicate 1st-pointer.
 * 
 * This algorithm run time is O(N^2)
*/

/** @brief QUESTION 2.2a - SOLUTION
 * 
 * Traverse the Linked List >> when hit the end, the method passes back a "counter = 0". \n
 * Each parent call adds 1 to "counter" >> when "counter == k", we reach the k-th element from Last. \n
 * The passing-back is done by C++ reference.
 * 
 * This recursive-method is coded faster, while taking more memory O(n) while same time O(n)
*/
LinkedList::Node* kNode2Last_a(LinkedList::Node* head, int k, int& counter)
{
    // Quick check if the Linekd List has elements inside
    if(head == NULL)
        return NULL;

    // Function kNode2Last_a() recursively calls itself until Last, in which head->next == NULL
    LinkedList::Node* node = kNode2Last_a(head->next, k, counter);
    counter = counter + 1;  // After each recursive-call, add 1 to "counter"
    
    // Stop when counter reaches "k"
    if(counter == k)
    {
        return node;
    }
}
LinkedList::Node* LinkedList::kNode2Last(LinkedList::Node* head, int k)
{
    int counter = 0;
    return kNode2Last_a(head, k, counter);
}


/** @brief QUESTION 2.2b - SOLUTION
 * 
 * Use 2 pointers: p1 -> head & p2 -> k-node-from-head
 * Traverse both pointers at the same pace >> When p2 read the end >> p1 is the Node to return. \n
 * 
 * This 2-pointer-method takes less memory O(1) while same timing O(n).
*/
LinkedList::Node* kNode2Last_b(LinkedList::Node* head, int k)
{
    // Declare 2 pointers
    LinkedList::Node* p1 = head;
    LinkedList::Node* p2 = head;

    // Move pointer p2 by k-elements while p1 remains at "head"
    for(int i = 0; i < k; i++)
    {
        if(p2 == NULL)  return NULL;
        p2 = p2->next;
    }

    // After 2 pointers are k-elements apart, move both pointers at the same speed
    while(p2 != NULL)
    {
        p1 = p1->next;
        p2 = p2->next;
    }

    return p1;
}


/** @brief QUESTION 2.3 - SOLUTION
 * 
 * Different from Array, which is expensive in shifting,
 * For Linked List, we create 2 separate Linked Lists, 1 for Greater & 1 for Smaller than the pivotal value. \n
 * Finally we merge these 2 Linked Lists together.
*/
LinkedList::Node* LinkedList::Partition(LinkedList::Node* node, int value)
{
    //
    LinkedList::Node* greater_head = NULL;
    LinkedList::Node* greater_tail = NULL;
    LinkedList::Node* smaller_head = NULL;
    LinkedList::Node* smaller_tail = NULL;

    // Create 1 running node so that *head is immutable
    while(node != NULL)
    {
        // This is how we traverse the Linked List with "next" instead of "node"
        LinkedList::Node* next = node->next;    // node->next will be set to NULL later

        // To make sure greater_tail & smaller_tail->next is always NULL until the next while-iteration
        // This means that greater_tail & smaller_tail is really a tail (...->next == NULL)
        node->next = NULL;

        if(node->key < value)
        {
            // Insert the node into the smaller_head list
            if(smaller_head == NULL)
            {
                smaller_head = node;            // smaller_head->next = NULL
                smaller_tail = smaller_head;    // smaller_tail->next = NULL
            }
            else
            {
                // Link the Node (key) to the previous smaller_tail
                smaller_tail->next = node;      
                // Shift the smaller_tail to the current Node & smaller_tail->next = NULL
                smaller_tail = node;            
            }
        }
        else
        {
            if(greater_head == NULL)
            {
                greater_head = node;
                greater_tail = greater_head;
            }
            else
            {
                greater_tail->next = node;
                greater_tail = node;
            }
        }

        // Move to the next Node
        node = next;
    }

    // In case the entire Linked List are all greater than "value"
    if(smaller_head == NULL)
    {
        return greater_head;
    }

    // Merge the smaller & greater Linked List
    smaller_tail->next = greater_head;

    return smaller_head;
}


/** @brief QUESTION 2.5 - SOLUTION
 * 
*/
LinkedList::Node* SumPerNode(LinkedList::Node* one, LinkedList::Node* two, bool& carry)
{
    if(one == NULL && two == NULL && carry == 0)
        return NULL;

    // Add the key-values inside Nodes "one" and "two", plus the carry-over value
    int sum_per_node = carry;
    if(one != NULL)
        sum_per_node += one->key;
    if(two != NULL)
        sum_per_node += two->key;

    // Store this sum_per_node into a new Node
    LinkedList::Node* add;
    add->key = sum_per_node % 10;
    add->next = NULL;

    if(sum_per_node >= 10)  carry = true;

    return add;
}
LinkedList::Node* LinkedList::SumLists(LinkedList::Node* one, LinkedList::Node* two, bool& carry)
{
    // Initially "carry" should be zero
    carry = false;

    LinkedList::Node* sum_head;
    LinkedList::Node* sum_node;

    sum_head = SumPerNode(one, two, carry);
    sum_head->next = sum_node;

    while(one != NULL || two != NULL)
    {
        if(one != NULL) one = one->next;
        if(two != NULL) two = two->next;

        sum_node = SumPerNode(one, two, carry);

        // Link the Node* more to the Linked List "sum"
        sum_node->next = sum_node;
        sum_node = sum_node;    // Traverse the Linked List "sum" to the current Node* more;
    }

    return sum_head;
}



/** @brief QUESTION 2.7 - SOLUTION
 * 
 * If 2 Linked Lists intersect, their last Nodes must be identical >> Simply travel to the last Node. \n
 * 
 * To find Intersection, set 2 pointers at similar distance from the end of each Linked List. \n
 * Then traverse at same pace  >>  Compare each Node until found the intersection.
 * 
 * @param[in]   one Head of the 1st Linked List to check
 * @param[out]  two Head of the 2nd Linked List to check
 * @return  Return the Node at intersection. NULL if no intersection
*/
LinkedList::Node* LinkedList::checkIntersectList(LinkedList::Node* one, LinkedList::Node* two)
{
    // Traverse 2 Linked Lists & find their length concurrently
    int one_length = 0;
    int two_length = 0;
    LinkedList::Node* one_tail = one;
    LinkedList::Node* two_tail = two;

    while(one_tail != NULL)
    {
        one_tail = one_tail->next;
        one_length ++;
    }
    while(two_tail != NULL)
    {
        two_tail = two_tail->next;
        two_length ++;
    }

    // Check if 2 Linked Lists intersect each other
    if( (one_tail->key != two_tail->key) || (&one_tail != &two_tail) )
        return NULL;
    
    // Now find the Intersection
    LinkedList::Node* one_node = one;
    LinkedList::Node* two_node = two;
    LinkedList::Node* intersection = NULL;

    // Traverse the Linked List so that both List at same length
    if(one_length > two_length)
    {
        for(int i = 0; i < one_length - two_length; i++)
        {
            one_node = one_node->next;
        }
    }
    else
    {
        for(int i = 0; i < two_length - one_length; i++)
        {
            two_node = two_node->next;
        }
    }

    // Check node-by-node until find the Intersection
    while(one_node != NULL)
    {
        if( (one_node->key == two_node->key) && (&one_node == &two_node) )
        {
            intersection = one_node;
            break;
        }
        
        one_node = one_node->next;
        two_node = two_node->next;    
    }

    return intersection;
}










/*==================== PRIVATE SUPPORTING FUNCTIONS ====================*/
/** @brief Create a stand-alone Node to store "data"
 * 
 * @param[in] data The data inside the Node to be delete.
 * @return  Pointer to the new Node
*/
LinkedList::Node* LinkedList::CreateNode(int data)
{
    LinkedList::Node* node;
    
    node->key = data;
    node->next = NULL;

    return node;
}

/** @brief Delete a Node that contains a specific data
 * 
 * @param[in] ref Pointer to a Node where we start searching.
 * @param[in] data The data inside the Node to be delete.
 * @return  "true" -> Successfully delete || "false" -> Cannot find the Node to delete
*/
bool LinkedList::DeleteNode(Node* ref, int data)
{
    // (*ref) is the starting Node to search for the given data
    Node* temp = ref;
	Node* prev;

    // If (*ref) Node contains the particular data
	if (temp != NULL && temp->key == data)
	{
        // Point (*ref) to the next Pointer
		ref = temp->next;
		delete(temp);   // Free up the temporary Node
		return true;
	}

	// Find the key to be deleted
	while (temp != NULL && temp->key != data)
	{
		prev = temp;
		temp = temp->next;  // Traverse along the Linked List
	}

    // At the end of Linked List, if still cannot find the key
	if (temp == NULL) return false;

	// Remove the Node
	prev->next = temp->next;
	delete(temp);
	return true;
}


/** @brief Insert a new Node to the beginning
 * Node is passed by pointer as parameter in this function.
 * @param[in] ref   Pointer to the new Node->next
 * @param[in] data  Data to be stored in the new Node->key
 * @return  "true" if method created successfully.
*/
bool LinkedList::InsertHead(Node* ref, int data)
{
    // Allocate memory for an arbitrary Node
    Node* new_head = new Node;

    // Assign the next-pointer to the old head
    new_head->next = ref;

    // Store the given data into new_head key
    new_head->key = data;

    return true;
}


/** @brief Insert a new Node to the tail
 * Node is passed by pointer as parameter in this function.
 * @param[in] ref   Pointer to the new Node
 * @param[in] data  Data to be stored in the new Node->key
 * @return  "true" if method created successfully.
*/
bool LinkedList::InsertTail(Node* ref, int data)
{
    // Allocate memory for a new node
    Node* new_node = new Node;
    new_node->key = data;
    new_node->next = NULL;

    Node* last_node = ref;

    // If *ref is already the tail of Linked List
    if( ref == NULL ) 
    {
        ref = new_node;
        return true;
    }

    // Traverse to the end of Linked List
    while( last_node->next != NULL )
    {
        last_node = last_node->next;
    }
    last_node->next = new_node;

    return true;
}


/** @brief Insert a new Node to somewhere in middle of Linked List
 * Node is passed by pointer as parameter in this function.
 * @param[in] prev_node Pointer to the reference Node
 * @param[in] data  Data to be stored in the new Node->key
 * @return  "true" if method created successfully.
*/
bool LinkedList::InsertMid(Node* prev_node, int data)
{
    // If the prev_node is acutally a Tail
    if(prev_node == NULL)
    {
        cout << "The previous Node cannot be NULL. \n";
        return false;
    }

    Node* new_node = new Node;
    new_node->key = data;
    new_node->next = prev_node->next;

    prev_node->next = new_node->next;

    return true;
}



