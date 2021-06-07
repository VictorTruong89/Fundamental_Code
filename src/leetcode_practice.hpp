/**
 * MY COLLECTIVE ANSWERS FOR THE PROBLEM AS POSTED ON LEETCODE/PROBLEMS \n
 * LINK: https://leetcode.com/problemset/all/ \n
 * 
*/

#ifndef _LEETCODE_PRACTICE_HPP_
#define _LEETCODE_PRACTICE_HPP_

#include <iostream>
#include <cmath>
#include <vector>

#include "helper.hpp"


/* ============================== */
/** @brief 1. Two Sum
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
/** @brief 2. Add 2 Numbers using Linked List
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
/** @brief 3. Longest sub-string
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



/* ============================== */
/** @brief 4. Median of 2 Sorted Arrays
 * @date 02/Jun/2021
 * 
 * QUESTION:
 * Given 2 sorted arrays arr_1 & arr_2 of size m, n respectively. Return the median of them.
 * The overall runtime should be O( log(m+n) )
 * 
 * EXAMPLE:
 * Given arr_1 = {1, 12} ; arr_2 = {3, 14, 25} >> merge = {1, 3, 12, 14, 25} >> median = 12
 * Given arr_1 = {1, 12, 23} ; arr_2 = {3, 14, 25} >> merge = {1, 3, 12, 14, 23, 25} >> median = (12+14)/2 = 13
 * 
 * SOLUTION:
 * Method 1: Simply merge & sort 2 arrays into 1 array >> Get median
 * 
 * Method 2: Comparing the medians of 2 arrays
 * 1/ Create recursive function that takes in 2 array & sizes of these 2 arrays
 * 2/ Take care of the case in which array has less than 2 elements
 * 3/ Find 2 medians of 2 arrays >> Compare 2 medians
 * 4/ If median_1 < median_2 >> Repeat with 1st-half of arr_1 & 2nd-half of arr_2
 * 5/ If median_1 > median_2 >> Repeat with 2nd-half of arr_1 & 1st-half of arr_2
*/
class Median2Array
{
	std::vector<int> arr_1;
	std::vector<int> arr_2;
	std::vector<int> merge;
public:
	// Input user's array into class's vectors
	void inputArray(int num_1[], int num_2[], int size_1, int size_2);

	// Merge 2 arrays into 1 sorted array
	void MergeSort();

	// Find median of 1 array
	int SimpleMedian();

	// Make sub-vector after finding median

	//
	double Method_1();

	// 
	int Method_2();
};








#endif // _LEETCODE_PRACTICE_HPP_