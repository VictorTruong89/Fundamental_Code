/**
 * MY COLLECTIVE ANSWERS FOR THE PROBLEM AS POSTED ON LEETCODE/PROBLEMS \n
 * LINK: https://leetcode.com/problemset/all/ \n
 * 
*/

#ifndef _LEETCODE_PRACTICE_HPP_
#define _LEETCODE_PRACTICE_HPP_

#include <iostream>
#include <cmath>

#include "helper.hpp"


/* ============================== */
/** @brief Two Sum
 * @date 22 / May / 2021
 * 
 * Given an array of integers & an integer "target", 
 * return the indices of the integers that add up to the "target".
 * 
 * @param[in] array Pointer to the input array
 * @param[in] array_size Number of elements inside the input array
 * @param[in] target "target" value equal to the sum of 2 required_integers
 * @param[in] index_1 Position of the 1st required_integer in input_array
 * @param[in] index_2 Position of the 2nd required_integer in input_array
 * 
 * @return 0 if found. -1 if not found
*/
int TwoSum(int* array, int array_size, int target, int* index_1, int* index_2);
int TwoSum_Test();



/* ============================== */
/** @brief Add 2 Numbers using Linked List
 * @date 22/May/2021
 * 
 * QUESTION:
 * Given 2 Linked List that store the digits of 2 numbers, in reverse order.
 * Return the sum of 2 numbers in the similar Linekd List format.
 * 
 * EXAMPLE: 
 * Given: [1][2][3] + [4][5][6][7] means "321 + 6547 = 6868"
 * Return:[8][6][8][6] 
*/
struct NodeList
{
	int key = 0;
	NodeList* next = NULL;

	NodeList() {}
	NodeList(int x)
	{
		key = x;
		next = NULL;
	}
	NodeList(int x, NodeList* n)
	{
		key = x;
		next = n;
	}
};
class Add2LinkedList
{
public:
	/* Convert an integer to Linked List, each Node represent 1 digit, in reverse order */
	NodeList* Int2LinkedList(int number);

	/* Convert back a Linked List to integer correspondingly */
	int LinkedList2Int(NodeList* head);

	/* Display values of Nodes inside Linked List */
	void Display(NodeList* head);

	/* Main function to add 2 numbers that are represented by 2 Linked List */
	NodeList* Solution(NodeList* input_1, NodeList* input_2);

	/* Test case for the Solution( ) */
	int TestCase();
};



/* ============================== */
/** @brief Longest sub-string
 * @date 23/May/2021
 * 
 * QUESTION:
 * Given a string s, find the longest sub-string that has no repeated characters.
 * 
 * EXAMPLE:
 * Input: s = "abccdefggh" 
 * Output: 5 &&  Print the logest sub-string "cdefg"
 * 
 * SOLUTION:
 * There are 2 methods implemented here.
 * 1st method: Sliding window >> Time complexity O(n^2) ; with small memory buffer.
 * 2nd method: Use buffer-space to store the last index of visited characters >> Time complexity O(n)
 * 
*/
class LongestSubString
{
public:
	/**/
	int Solution_1(std::string text);

	/**/
	int Solution_2(std::string text);

	/**/
	void DisplayLongestSubString(std::string text);

	/**/
	inline int getStartingIndex() {return index_start;}

	/**/
	inline int getEndingIndex()	{return index_end;}

	/**/
	int TestCase();


private:
	int index_start;
	int index_end;
};









#endif // _LEETCODE_PRACTICE_HPP_