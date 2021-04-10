/** LICENCE:
 * 
*/

#include "C01_arrays_string.hpp"

using namespace std;


/** @brief QUESTION 1.1 - SOLUTION
 * 
 * Run 2 loops:
 * 1st loop slides from beginning till the end.
 * 2nd loop >> @ every character, check if that character appears again.
*/
bool ArraysString::isUniqueChars()
{
    // Ask the user to input the string
    string input;
    cout << "Please input the string to check for unique characters: " << endl;
    cin >> input;

    // ASCII standard has only 128 characters. 
    // The given string cannot have more than 128 characters
    if(input.length() > 128)
    {
        cout << "This string has more than 128 characters. \n";
        return false;
    }

    // Slide through every character, from beginning till the 2nd-last
    for(int i = 0; i < input.length() - 1; i++)
    {
        // From the current character, compare it with the rest of the string
        for(int j = i + 1; j < input.length(); j++)
        {
            if(input[i] == input[j])
            {
                cout << "Character " << input[i] << " has re-appeared.";
                return false;
            }
        }
    }

    // Finally 
    cout << "This string contains all unique characters." << endl;
    return true;
}


/** @brief QUESTION 1.2 - SOLUTION
 * 
 * Count the number of each characters of both strings.
 * Then compare the 2 quantities together.
 * 
 * Assumptions: ASCII standard 128 characters only.
 * Assumptions: No case sensitive.
*/
bool ArraysString::isPermutationString(std::string input_1, std::string input_2)
{
    // Quick-check if 2 strings have the same number of characters
    if(input_1.length() != input_2.length())
        return false;

    // One-hot code to count for the number of characters
    int letter[128] = {0};
    int index;
    int string_len = input_1.length();
    cout << string_len << endl;

    // Get the index of each character in 1st string input_1
    // And count the number of each character by using 2-loop method as per QUESTION 1.1
    for(int i = 0; i < string_len; i++)
    {
        index = (int)(input_1[i]);
        
        // If the index has not been counted before, (letter[index] == 0)
        if( letter[index] != 0 )
            break;
        else
        {
            int count = 1;
            for (int j = i + 1; j < string_len; j++)
            {
                if(input_1[i] == input_1[j])
                    count ++;
            }
            letter[index] = count;
        }   
    }

    // Loop through the 2nd string, back-count the quantity stored in letter[index]
    for(int i = 0; i < string_len; i++)
    {
        index = (int)(input_2[i]);
        
        // Subtract 1 for letter[index] 
        letter[index] --;
        
        // In case 2nd-string has more of a specific characters than 1st-string
        if(letter[index] < 0)
            return false;
        // No need to check if 2nd-string has fewer of a specific character,
        // because that is equivalent to the extra of another character.
    }

    return true;
}


/** @brief EXTRA 1.2 - SOLUTION
 * 
 * Method: Use 2 for-loop runners to copy the original string to new string without empty-space
*/
string ArraysString::ReplaceSpace(string input)
{
    // Runer for the empty-space
    int space_count = 0;

    // New string
    string new_string;
    // input = input.c_str();

    for(int i = 0; i < input.length(); i++)
    {
        if(input[i] == ' ')
        {
            space_count ++;
            new_string[i] = input[i + space_count];
        }
        else
            new_string[i] = input[i + space_count];
        
        if(i + space_count == input.length() - 1)
            break;
    }

    return new_string;
}


/** @brief EXTRA 1.3 - SOLUTION
 * 
*/
char* ArraysString::String2Char(string input)
{
    // Length of the given string
    int length = input.length();

    // Declare the character array
    char* array = new char [length + 1]; // +1 includes the termination character

    // Copy the content of the string into the array of char
    std::strcpy( array, input.c_str() );

    return array;
}


/** @brief EXTRA 1.4 - SOLUTION
 * 
*/
int* ArraysString::CharacterCount(string input)
{
    // One-hot search
    int* letter = new int [128]; // ASCII standard has 128 characters

    int string_len = input.length();

    for(int i = 0; i < string_len; i++)
    {
        int index = input[i];
        int count = 0;

        // Ignore white-space
        if(input[i] == ' ')
            continue;

        // Check if the letter input[i] not been counted eariler
        if(letter[index] != 0)
            continue;
        else // Count the rest of the string for the specific character input[i]
        {
            count ++;
            for(int j = i + 1; j < string_len; j++)
            {
                if(input[i] == input[j])
                    count ++;
            }
            letter[index] = count;
            // cout << "character [" << index << "] " << count << endl;
        }
    }

    return letter;
}


/** @brief QUESTION 1.3 - SOLUTION
 * 
*/
char* ArraysString::URLify(string input, int num_char)
{
    // Count the number of white-space to calculate the length of output string
    int space_count = 0;
    for(int i = 0; i < input.length(); i++)
    {
        if(input[i] == ' ')
            space_count ++ ;
    }

    // Create an array of character with specified length to store the new string
    static int index = input.length() + space_count * 3;
    char* output = new char [index];

    // Copy the input string to the new character-array
    space_count = 0;
    for(int i = 0; i < input.length(); i++)
    {
        //
        if(input[i] != ' ')
        {
            output[i + space_count * 3] = input[i];
        }
        else
        {
            output[i + 0 + space_count * 3] = '%';
            output[i + 1 + space_count * 3] = '2';
            output[i + 2 + space_count * 3] = '0';
            //
            space_count ++;
        }
    }

    return output;
}


/** @brief QUESTION 1.4 - SOLUTION
 *  
 * A palindrome is a string that has 0-1 character with odd-quantity
 * and all other characters must have even-quantity.
*/
bool ArraysString::isPalindrome(string input)
{
    // Declare all counting-variables
    int char_total = 0;
    int char_odd = 0;
    int char_even = 0;

    // Count the number of characters
    int* letter = CharacterCount(input);

    // Return false if more than 1 character that has odd-quantity
    bool has_odd = false;
    for(int i = 0; i < 128; i++)
    {
        if( (letter[i] % 2 == 1) && (has_odd == false) ) // First letter that has odd-quantity
        {
            has_odd = true;
            continue;
        }
        else if( (letter[i] % 2 == 1) && (has_odd == true) )
        {
            cout << "Not a PALINDROME \n";
            return false;
        }
    }

    std::cout << "PALINDROME. \n";
    return true;
}


/** @brief QUESTION 1.5 - SOLUTION
 * 
*/
bool isEdit_Replace(string input_1, string input_2)
{
    bool found_diff = false;

    for(int i = 0; i < input_1.length(); i++)
    {
        // Tolerance for the 1st difference between 2 strings
        if( input_1[i] != input_2[i] && found_diff == false )
        {
            found_diff = true;
            continue;
        }
            
        // Return false if found_diffeence for the 2nd time
        if( input_1[i] != input_2[i] && found_diff == true )
            return false;
    }

    return true;
}
bool isEdit_Insert(string input_1, string input_2)
{
    // Assumption: input_1 is shorter than input_2 by 1 character
    int insert = 0;

    for(int i = 0; i < input_1.length(); i++)
    {
        if( input_1[i] != input_2[i + insert] )
        {
            insert ++;  // Tolerance the 1st difference
            if(insert == 2) // Terminate if 2nd difference found
                return false;
        }
    }
    return true;
}
bool ArraysString::isEditOnce(string input_1, string input_2)
{
    if(input_1.length() == input_2.length())
        return isEdit_Replace(input_1, input_2);
    else if( input_1.length() == input_2.length() + 1 )
        return isEdit_Insert(input_2, input_1);
    else if( input_1.length() == input_2.length() - 1 )
        return isEdit_Insert(input_1, input_2);
    
    return false;
}


/** @brief QUESTION 1.7 - SOLUTION
 * 
 * Matrix is created as an 1D-array for efficient operation.
 * Original  >> cell[x, y] = array[ (x-1) * m_width + (y-1) ]
 * Transpose >> cell[y, x] = cell[xT, yT] >> xT = 
 * x*w + y = y*w + x >> w*(x - y) = x - y >> 
*/
int* ArraysString::RotateMatrix(int* matrix, int m_size)
{
    // Uncomment this if you want to create original & transposed matrices separately
    int* output = new int [m_size * m_size];

    int temp; // to swap the value between 2 related cells

    // Perform O(N^2) steps to swab values
    for(int i = 0; i < m_size; i++)
    {
        for(int j = 0; j < m_size; j++)
        {
            // Uncomment this to create 2 separate matrices
            // output[];

            temp = matrix[i * m_size + j];
            matrix[i * m_size + j] = matrix[i * m_size + i];
            matrix[j * m_size + i] = temp;
        }
    }

    // return output    // Same speed, waste memory >> Have 2 separate matrices to work with
    return matrix;      // The original matrix has gone, be transformed >> save memory
}


/** @brief QUESTION 1.8 - SOLUTION
 * Matrix[M x N] >> Matrix[x, y] = Array[x * N + y]
 * 1st step: Check if 1st row & 1st column has Zero
 * 2nd step: Screen through matrix (N^2 times) >> If has Zero, set the 1st cell of that column / row to Zero
 * 3rd step: Return to Zero indicators in 2nd-step >> Set entire row / column to Zeros
 * 
 * Not improve speed, but save memory, because not required 2nd matrix
*/
int* ArraysString::ZeroRowCol(int* matrix, int row, int col)
{
    // As matrix is actually a 1D-array, 1st row is equivalent to 0 <= i <= N
    // 1st column is equivalent to ( i % N == 0 )
    // Belnding the 1st step while screen the matrix by using flag_row & flag_col
    bool flag_row = false;
    bool flag_col = false;

    // First screen through the entire matrix to check for Zeros
    int max_index = row * col - 1;
    for(int i = 0; i < max_index; i++)
    {
        // 1st step - check 1st row has Zeros or not
        if(i <= col)
        {
            if(matrix[i] == 0)
                flag_row = true;
        }
        // 1st step - check 1st column has Zeros or not
        if( i % col == 0 )
        {
            if(matrix[i] == 0)
                flag_col = true;
        }

        // If inside cell has Zero, set Zero to respective cells at 1st row & column
        if( matrix[i] == 0 )
        {
            matrix[i % col] = 0;    // respective cell at 1st row
            matrix[i % row] = 0;    // respective cell at 1st col
        }
    }

    // Slide through 1st row to set Zeros to entire columns
    for(int i = 0; i < col; i++)
    {
        if(matrix[i] == 0)
        {
            for(int j = 1; j < col; j++)
            {
                matrix[j * col + i] = 0;
            }
        }
    }

    // Slide through 1st column to set Zeros to entire columns
    for(int j = 0; j < row; j++)
    {
        if(matrix[j * col] == 0)
        {
            for(int i = 0; i < col; i++)
            {
                matrix[j * col + i] = 0;
            }
        }
    }

    // Lastly, if either flag_row or flag_col == true, set Zeros accordingly
    if(flag_row)
    {
        for(int i = 0; i < col; i++)
            matrix[i] = 0;  // Set 1st row to Zeros
    }
    if(flag_col)
    {
        for(int j = 0; j < row; j++)
            matrix[j * col] = 0;    // Set 1st column to Zeros
    }

    return matrix;
}


/** @brief QUESTION 1.9 - SOLUTION
 * 
*/
char* ArraysString::ReverseSentence(string input)
{
    char* output;

    // Detect the index of white-space inside the string
    std::vector<int> space_idx;
    int space_count = 0;
    for(int i = 0; i < input.length(); i++)
    {
        if(input[i] == ' ')
        {
            space_idx.push_back(i);
            space_count ++;
        }
    }
    space_count--; // Back track by 1 to match the index inside vector "space_idx"

    // Word[i].begin = space_idx[i - 1] + 1
    // Word[i].end   = string.end - space_idx[i]

    // Copy the last word to the beginning
    int new_idx = 0;
    for(int j = space_idx[space_count] + 1; j < input.length(); j++)
    {
        output[new_idx] = input[j];
        new_idx++;
    }
    // Add 1 more white-space
    output[new_idx] = ' ';
    new_idx++;
    cout << "last word \n";

    // Copy the middle words in reversed sequence
    for(int i = space_count - 1; i > 0; i--)
    {
        // Copy 1 word
        for(int j = space_idx[i] + 1; j < (input.length() - space_idx[i + 1]); j++ )
        {
            output[new_idx] = input[j];
            new_idx ++;
        }
        // Add 1 more space after each words
        output[new_idx] = ' ';
        new_idx ++;
        cout << "between \n";
    }

    // Copy the first word to the end
    for(int j = 0; j < space_idx[0]; j++)
    {
        output[new_idx] = input[j];
        new_idx ++;
    }
    // Do not add any more white-space
    cout << "first word \n";

    return output;
}






