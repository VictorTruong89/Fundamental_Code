#include "data_structures.hpp"


using namespace std;


/*==================== HASH TABLE ====================*/
void HashTable::InsertItem(int key, int data)
{
	int index = HashFunction(key);
	table[index].push_back(data);
}

void HashTable::DeleteItem(int key)
{
	int index = HashFunction(key);

	list<int>::iterator i;
	for (i = table[index].begin(); i != table[index].end(); i++)
	{
		if (*i == key) break;
	}

	if (i != table[index].end())
		table[index].erase(i);
}

int HashTable::CheckPrime(int n)
{
	if (n == 1 || n == 0)
		return 0;

	for (int i = 2; i < n / 2; i++)
	{
		if (n % i == 0) return 0;
	}

	return 1;
}

int HashTable::GetPrime(int n)
{
	if (n % 2 == 0)	n++;

	while (HashTable::CheckPrime(n) == false)
	{
		n += 2;
	}

	return n;
}

void HashTable::DisplayHash()
{
	for (int i = 0; i < capacity; i++)
	{
		std::cout << "Table [" << i << "]";
		for (auto x : table[i])
			std::cout << "-->" << x;
		std::cout << endl;
	}
}

int HashTable::Example()
{
	std::cout << "\nThis example demonstrated how HashTable solves the collision of the HashFunction \n by using Linked-List.\n";

	int key[] = { 231, 321, 212, 321, 433, 262 };
	int data[] = { 123, 432, 523, 43, 423, 111 };
	int size = sizeof(data) / sizeof(data[0]);

	HashTable hash_table(size);

	for (int i = 0; i < size; i++)
		hash_table.InsertItem(key[i], data[i]);

	hash_table.DeleteItem(12);
	hash_table.DisplayHash();

	return 0;
}



/*==================== LINKED LIST ====================*/
bool LinkedList::InsertAtHead(Node** ref, int data)
{
	// Allocate memory to a Node
	Node* new_node = new Node;

	// Insert the item
	new_node->item = data;
	new_node->next = (*ref);

	// Move head to the new node
	(*ref) = new_node;

	return true;
}

bool LinkedList::InsertAtMid(Node* prev_node, int data)
{
	if (prev_node == NULL)
	{
		std::cout << "The given prev_node cannot be NULL.\n";
		return false;
	}
	Node* new_node = new Node;
	new_node->item = data;
	new_node->next = prev_node->next;
	prev_node->next = new_node;
	return true;
}

bool LinkedList::InsertAtTail(Node** ref, int data)
{
	Node* new_node = new Node;
	Node* last_node = (*ref);

	new_node->item = data;
	new_node->next = NULL;
	
	if (*ref == NULL)
	{
		*ref = new_node->next;
		return true;
	}

	while (last_node->next != NULL)
	{
		last_node = last_node->next;
	}

	last_node->next = new_node;
	return true;
}

bool LinkedList::DeleteNode(Node** ref, int key)
{
	Node* temp = (*ref);
	Node* prev;

	if (temp != NULL && temp->item == key)
	{
		*ref = temp->next;
		delete(temp);
		return false;
	}

	// Find the key to be deleted
	while (temp != NULL && temp->item != key)
	{
		prev = temp;
		temp = temp->next;
	}

	// If the key is not present
	if (temp == NULL) return false;

	// Remove the Node
	prev->next = temp->next;
	delete(temp);
	return true;
}


/*==================== TREE ====================*/
void Tree::PreorderTraversal(Node* node)
{
	if (node == NULL)	return;

	std::cout << node->data << " -> ";
	PreorderTraversal(node->left);
	PreorderTraversal(node->right);
}

void Tree::PostorderTraversal(Node* node)
{
	if (node == NULL)	return;

	PostorderTraversal(node->left);
	PostorderTraversal(node->right);
	std::cout << node->data << " -> ";
}

void Tree::InorderTraversal(Node* node)
{
	if (node == NULL)	return;

	InorderTraversal(node->left);
	std::cout << node->data << " -> ";
	InorderTraversal(node->right);
}

Tree::Node* Tree::NewNode(int data)
{
	Tree::Node* node = new Tree::Node(1);

	node->data = data;
	node->left = NULL;
	node->right = NULL;

	return node;
}

bool Tree::isFullBinaryTree(Tree::Node* root)
{
	// If tree is empty
	if (root == NULL)	return true;

	// If there is no children branch
	if (root->left == NULL && root->right == NULL)	return true;

	// 
	if ((root->left) && (root->right))
		return (isFullBinaryTree(root->left) && isFullBinaryTree(root->right));
	
	return false;
}



