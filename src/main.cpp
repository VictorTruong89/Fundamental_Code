#include <iostream>
#include <string>
#include <vector>

#include "data_structures.hpp"
#include "cracking_coding_interview_6th.hpp"


using namespace std;

bool StringPermutation(string s, string t)
{
	if (s.length() != t.length())
		return false;

	//int* letter = new int[128];
	int letter[128] = { 0 };
	int j;

	for (int i = 0; i < s.length(); i++)
	{
		j = (int)s[i];
		letter[j] ++;
	}
	for (int i = 0; i < t.length(); i++)
	{
		j = (int)t[i];
		letter[j] --;
		if (letter[j] < 0)
			return false;
	}
	return true;
}

bool RotateMatrix(vector< vector<int> > &matrix_2d)
{
	int size_row = matrix_2d.size();
	int size_col = matrix_2d[0].size();
	std::cout << "row = " << size_row << "\tcolumn = " << size_col << endl;
	return true;
}



int main()
{
	Tree tree;
	Tree::Node* root = new Tree::Node(1);

	root->left = new Tree::Node(12);
	root->right = new Tree::Node(9);

	root->left->left = new Tree::Node(5);
	root->left->right = new Tree::Node(6);

	root->right->left = tree.NewNode(100);
	root->right->right = tree.NewNode(50);

	//tree.root->NewNode(100);
	if (tree.isFullBinaryTree(root))
		std::cout << "\nfull bin tree\n";
	else cout << "not full tree\n";

	cout << "\nInorder traversal : ";
	tree.InorderTraversal(root);
	
	cout << "\nPreorder traversal : ";
	tree.PreorderTraversal(root);

	cout << "\nPostorder traversal : ";
	tree.PostorderTraversal(root);

	return 0;
}