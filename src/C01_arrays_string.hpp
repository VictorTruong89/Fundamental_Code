#ifndef _C01_ARRAYS_STRING_HPP_
#define _C01_ARRAYS_STRING_HPP_

#include <iostream>
#include <string>
#include <cstring>
#include <algorithm>
#include <vector>

using namespace std;

/** This Class is the 1st chapter of the book 
 * "CRACKING THE CODING INTERVIEWS - 6TH EDITION"
*/
class ArraysString
{
public:
    /** @brief QUESTION 1.1
     * 
     * 1/ Implement an algorithm to determine if a string has all unique (appear once only) characters. \n
     * 2/ What if you cannot use additional data structures. \n
     * 
     * Assumptions: String follows ASCII standard with 128 characters.
    */
    bool isUniqueChars();


    /** @brief QUESTION 1.2
     * 
     * Given 2 strings, determine if they are permutation of each other.
     * 
     * Assumptions: ASCII standard with 128 characters.
     * Assumptions: Lower / Upper case sensitive.
     */
    bool isPermutationString(std::string input_1, std::string input_2);


    /** @brief QUESTION 1.3
     * 
     * Replace all white-space inside a string with %20 character.
     * 
     * Assumptions: The string has enough empty space at the end to accommodate the increase in character.
     * Assumptions: The length of string is given.
    */
    char* URLify(string input, int num_char);



    /** @brief QUESTION 1.4
     * 
     * Check if a string is a permutation of a palindrome.
    */
    bool isPalindrome(string input);


    /** @brief QUESTION 1.5
     * 
     * Check if 2 string is different by only 1 Insert / Removal / Edit
    */
    bool isEditOnce(string input_1, string input_2);


    /** @brief QUESTION 1.6
     * 
     * Compress a string so that every character only appears once.
    */
    char* StringCompress(string input);


    /** @brief QUESTION 1.7
     * 
     * Create a transposed matrix (rotate 90-deg clockwise)
    */
    int* RotateMatrix(int* matrix, int m_size);


    /** @brief QUESTION 1.8
     * 
     * If any cell of a matrix is 0 >> set Zeros to the entire respective row & column
    */
    int* ZeroRowCol(int* matrix, int row, int col);


    /** @brief QUESTION 1.9
     * 
     * Reverse words inside a string.
     * Example: "Hello World" >> "World Hello"
    */
    char* ReverseSentence(string input);


  


private:
    /** @brief EXTRA 1.1
     * 
     * Remove all white space inside a string.
    */
    inline::string RemoveEmptySpace(std::string input)
    {
        input.erase( std::remove_if(input.begin(), input.end(), ::isspace) );
        return input;
    }


    /** @brief EXTRA 1.2
     * 
     * Read multiple lines into multiple entries.
    */
    string ReplaceSpace(string input);


    /** @brief EXTRA 1.3
     * 
     * Turn a string into array of characters,
     * easier to perform other manipulation and display output.
    */
    char* String2Char(string input);


    /** @brief EXTRA 1.4
     * 
     * Count the number of types of character inside a string.
    */
    int* CharacterCount(string input);
};




#endif // _C01_ARRAYS_STRING_HPP_