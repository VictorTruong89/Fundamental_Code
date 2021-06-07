/**
 * MY COLLECTIVE ANSWERS FOR THE PROBLEM AS POSTED ON LEETCODE/PROBLEMS \n
 * LINK: https://leetcode.com/problemset/all/ \n
 * 
*/

#include "leetcode_practice.hpp"
using namespace std;

/* Swap 2 integer */
void Swap (int* a, int* b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}

/** @brief Quick sort >> Return an sorted array of integers, in ascending order.
 * 
 * In this QuickSort implementation, the pivot is chosen at the rightmost element.
 * 
 * Time complexity (best case)	O( n * log n )
 * Time complexity (worst case)	O( n^2 )
 * Time complexity (average)	O( n * log n )
 *  
 * @param[in] array Pointer to the 1st element of the array to be sorted
 * @param[in] low Starting index ( low = 0 )
 * @param[in] high Ending index (high = array_size - 1)
 * @return	Nothing (void)
*/
int QuickSort_Partition(int* array, int low, int high)
{
	// Choose the last element as pivotal point
	int pivot = *(array + high);
	int i = low - 1;	// Index of smaller element n indicates the right position of pivot found so far

	for(int j = low; j <= high - 1; j++)
	{
		// If current elements is smaller than the pivot
		if( *(array + j) < pivot )
		{
			i++; // Increase the index of the smaller element
			Swap((array+i), (array+j));
		}
	}

	// Finally place the pivot_element to the correct position
	Swap((array+i+1), (array+high));

	return (i+1); // Return the index of the pivot_element
}
void QuickSort(int* array, int low, int high)
{
	if(low < high)	// Terminate function if array has only 0 or 1 element
	{
		int pivot = QuickSort_Partition(array, low, high);

		QuickSort(array, low, pivot - 1);
		QuickSort(array, pivot + 1, high);
	}
}


/** @brief Two Sum
 * @date 22 / May / 2021
 * 
 * First, sort the array in ascending order  >>  Time-complexity O( n * log n )
 * Second, sum up pairwise input elements  >>  Time-complexity worst case O( (n-1)! )
 * 
 * @param[in] array Pointer to the 1st element of input array
 * @param[in] array_size Number of elements in the input array
 * @param[in] target Integer "target" that equals the sum of 2 elements
 * 
 * @return 0 if found the pair. -1 if not found.
*/
int TwoSum(int* array, int array_size, int target, int* index_1, int* index_2)
{
	// First sort the array in the ascending order
	QuickSort(array, 0, array_size - 1);

	//
	int sum = 0;
	for(int i = 0; i < array_size - 1; i++)
	{
		for(int j = i + 1; j < array_size; j++)
		{
			sum = *(array + i) + *(array + j);

			// As array is increasing, if sum > target, no need to try further
			if( sum > target )	return -1;

			// 
			if(sum == target)
			{
				*index_1 = i;
				*index_2 = j;
				return 0;
			}
		}
	}
	return -1;
}


/* ============================== */
/** @brief Add 2 Numbers using Linked List
 * @date 22/May/2021
 * 
 * First, 	create temporary pointers so not to mess up the input Linked Lists. \n
 * Second, 	use 2 temporary variable x, y to handle the case in which 2 Linked Lists are different size. \n
 * Third, 	if sum of 2 Nodes > 10, "carry" 1 to the next sum-Node. \n
 * Fourth, 	after while-loop, remember to add the last Node to "result" Linked List. \n
*/
NodeList* Add2LinkedList::Solution(NodeList* input_1, NodeList* input_2)
{
	// Create a new Node for "result" Linked List
	NodeList* result = new NodeList;
	int carry = 0;
	int sum = 0;

	// Create temporary pointers so that not to mess up the input Linked Lists
	NodeList* temp = result;
	NodeList* temp_1 = input_1;
	NodeList* temp_2 = input_2;

	// Assign Node->key to x,y in case the current Node is NULL
	int x = (temp_1 != NULL) ? temp_1->key : 0;
	int y = (temp_2 != NULL) ? temp_2->key : 0;

	while( temp_1->next != NULL || temp_2->next != NULL )
	{
		// Assign the sum_value to "result" Linked List
		sum = x + y + carry;
		temp->key = sum % 10;
		carry = sum / 10;	// If sum >= 10, "carry" 1 to the next sum
		
		// Add the next NodeList to "result"
		temp->next = new NodeList;
		temp = temp->next;

		// Traverse to the next NodeList of 2 inputs
		if(temp_1->next != NULL)	
		{
			temp_1 = temp_1->next;
			x = temp_1->key;
		}
		else	x = 0;

		if(temp_2->next != NULL)	
		{
			temp_2 = temp_2->next; 
			y = temp_2->key;
		}
		else	y = 0;
	}

	// Sum the last Node that is left out from the while-loop earlier
	sum = x + y + carry;
	temp->key = sum % 10;
	if( (carry = sum / 10) > 0 )	// Add 1 more Node if last sum > 10
	{
		temp->next = new NodeList;
		temp = temp->next;
		temp->key = 1;
		temp->next = NULL;
	}

	return result;
}

/** @brief Convert an integer to Linked List, in reverse order
 * 
 * @param[in] number The given integer to be converted into Linked List
 * 
 * @return Pointer to the head of Linekd List that contains the digits of input integer
*/
NodeList* Add2LinkedList::Int2LinkedList(int number)
{
	NodeList* result = new NodeList;
	NodeList* temp = result;

	while(number > 0)
	{
		temp->key = number % 10;
		number /= 10;
		
		// Add new Node to the Linked List
		if(number > 0)	// Early check so not to create extra "zero" Node
		{
			temp->next = new NodeList;
			temp = temp->next;
		}
		
	}

	return result;
}

/** @brief Convert a Linked List back to Integer, in reverse order
 * 
 * EXAMPLE: Linked List [1][2][3] >> Integer: 321
 * 
 * @param[in] head Pointer to the 1st Node of Linked List
 * 
 * @return The equivalent integer
*/
int Add2LinkedList::LinkedList2Int(NodeList* head)
{
	int result = 0;

	// If Linked List is empty, return 0
	if(head == NULL)	return 0;

	//
	int power = 0;
	NodeList* temp = head;	// Not to mess up with the value inside "head"
	while(temp != NULL)
	{
		// Calculate the "result" based on the order of Linked List
		result += temp->key * std::pow(10, power);
		power++;

		// Traverse to the next Node
		temp = temp->next;
	}

	return result;
}

/** @brief Display the value of Nodes inside Linked List
 * 
 * @param[in] head Pointer to the 1st Node of Linked List
 * 
 * @return Nothing
*/
void Add2LinkedList::Display(NodeList* head)
{
	NodeList* temp = head;

	printf("Linked List display:\t");
	while(temp != NULL)
	{
		printf(" %d ", temp->key);
		temp = temp->next;
	}
	printf("\n");
}

/** @brief Test Case for question "Add 2 Numbers using Linked List"
 * 
 * @return Number of failed test-case.
*/
int Add2LinkedList::TestCase()
{
	// Given integers to test the Solution( )
	int number_1[] = {123, 12345, 0, 0};
	int number_2[] = {4567, 678, 12345, 0};
	int size = sizeof(number_1) / sizeof(number_1[0]);

	// The expected sum of 2 integers should be
	int* answer = new int[size];
	for(int i = 0; i < size; i++)
	{
		answer[i] = number_1[i] + number_2[i];
	}
	int fail_num = 0;	// Number of the failed test-case
	int pass_num = 0;	// Number of the passed test-case

	
	Add2LinkedList test;
	NodeList* list_1;
	NodeList* list_2;
	NodeList* result;
	for(int i = 0; i < size; i++)
	{
		// Convert the input integers into Linked List respectively
		list_1 = test.Int2LinkedList(number_1[i]);
		list_2 = test.Int2LinkedList(number_2[i]);

		// Calculate the sum of 2 Linked List
		result = test.Solution(list_1, list_2);
		int sum = test.LinkedList2Int(result);

		// Count the number of passed / failed test-case
		if(sum - answer[i] != 0)	
		{
			fail_num++;
			printf("Fail : \t");
			test.Display(result);
			printf("\n");
		}
		else	
		{
			pass_num++;
			printf("Pass : \t");
			test.Display(result);
			printf("\n");
		}
	}

	printf("Number of passed test: %d (out of %d tests)\n", pass_num, size);
	printf("Number of failed test: %d (out of %d tests)\n", fail_num, size);

	return fail_num;
}



/* ============================== */
/** @brief Find the longest sub-string by using sliding-window method
 * @date 23/May/2021
 * 
 * The sliding-window uses 2 indices [i, j], that indicates the start and end of the sub-string respectively.
 * Whenever the "length = j - i" > "previous_length", update the new length and indices.
 * 
 * @param[in] text The given C++ string to find longest sub_string.
 * 
 * @return The number of characters inside the longest sub-string.
*/
int LongestSubString::Solution_1(std::string text)
{
	cout << text << endl;
	int size = text.length();
	int sub_length = 0; // Number of characters inside sub_string

	// Assume ASCII table with 128 characters
	bool visited[128] = {0};

	for(int i = 0; i < size; i++)
	{
		for(int j = i; j < size; j++)
		{
			if(visited[text[j]] == true)	break;
			else
			{
				if(sub_length < j - i + 1)
				{
					sub_length = j - i + 1;	// Update the number of characters of sub_string
					LongestSubString::index_start = i;
					LongestSubString::index_end = j;
				}
				visited[text[j]] = true;
			}
		}
		// Reset the character [i] as unseen
		visited[text[i]] = false;
	}

	return sub_length;
}

/** @brief Display the longest sub_string that has no repeated character.
 * 
 * This uses the indices that are obtained after running Solution( ).
 * 
 * @param[in] text Given string to find the longest sub_string.
 * 
 * @return Nothing
*/
void LongestSubString::DisplayLongestSubString(std::string text)
{
	for(int i = LongestSubString::index_start; i <= LongestSubString::index_end; i++)
	{
		printf("%c", text[i]);
	}
}

/** @brief Test Case
 * 
*/
int TestCase()
{
	int case_num = 3;
	string test_case[] = {
		"geeksforgeeks", 
		" abcdefgah",
		""};
	return 0;
}



/* ============================== */
/** @brief Input the given array into class's vector
 * 
 * Assumption: The input arrays are already sorted in ascending order.
 * 
 * @param[in] num_1 Pointer to the array 1
 * @param[in] num_2 Pointer to the array 2
 * @param[in] size_1 Number of elements in array_1
 * @param[in] size_2 Number of elements in array_2
 * 
 * @return Nothing
*/
void Median2Array::inputArray(int num_1[], int num_2[], int size_1, int size_2)
{
	for(int i = 0; i < size_1; i++)
	{
		Median2Array::arr_1.push_back(num_1[i]);
	}
	for(int i = 0; i < size_2; i++)
	{
		Median2Array::arr_2.push_back(num_2[i]);
	}
	std::cout << "Copy Done\n";
}

/** @brief Merge and sort 2 arrays in the ascending order
 * 
 * Assumption: 2 input vectors are already sorted in ascending order.
*/
void Median2Array::MergeSort()
{
	// Declare 3 counter as indices of 2 input-vectors and merge-vector
	int id1, id2, id3;
	id1 = id2 = id3 = 0;

	//
	int size_1 = Median2Array::arr_1.size();
	int size_2 = Median2Array::arr_2.size();
	cout << "2 vector sizes : " << size_1 << "\t" << size_2 << endl;

	// Traverse 2 input vectors with id1 & id2 
	// Compare the elements between 2 vector to copy into merge-vector
	while( id1 < size_1 || id2 < size_2 )
	{
		// Copy the smaller element into merge-vector
		if(Median2Array::arr_1[id1] < Median2Array::arr_2[id2])
		{
			Median2Array::merge.push_back(Median2Array::arr_1[id1]);
			cout << Median2Array::arr_1[id1] << " ";
			id1++;	// Increase vector_1 index
		}
		else if(Median2Array::arr_1[id1] > Median2Array::arr_2[id2])
		{
			Median2Array::merge.push_back(Median2Array::arr_2[id2]);
			cout << Median2Array::arr_2[id2] << " ";
			id2++;	// Increase vector_2 index
		}
		else	// Both array equal
		{
			Median2Array::merge.push_back(Median2Array::arr_2[id2]);
			cout << Median2Array::arr_2[id2] << " ";

			id1++;
			id2++;
		}

		//
		if(id1 == size_1)	// When vector_1 ends, copy the rest of vector_2
		{
			while(id2 < size_2)
			{
				Median2Array::merge.push_back(Median2Array::arr_1[id2]);
				cout << Median2Array::arr_2[id2] << " ";
				id2++;
			}
		}
		if(id2 == size_2)	// When vector_2 ends, copy the rest of vector_1
		{
			while(id1 < size_1)
			{
				Median2Array::merge.push_back(Median2Array::arr_1[id1]);
				cout << Median2Array::arr_1[id1] << " ";
				id1++;
			}
		}
	} 
	cout << "\nmerge size : " << Median2Array::merge.size() << endl;
}


/** @brief Method 1: Merge & Sort into 3rd vector then simply take the Median of merge-vector
 * 
*/
double Median2Array::Method_1()
{
	// Merge 2 vectors into 1 sorted vector
	Median2Array::MergeSort();
	int size = Median2Array::merge.size();

	// If merge-size is an odd number
	if(size % 2 == 1)
	{
		return Median2Array::merge[size / 2]; // Beware vector-index starts from zero
	}
	else	// If merge-size is an even number
	{
		return (Median2Array::merge[size / 2] + Median2Array::merge[size / 2 - 1]) / 2;
	}
}




