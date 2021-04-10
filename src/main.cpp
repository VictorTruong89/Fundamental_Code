#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

#include "data_structures.hpp"
#include "cracking_coding_interview_6th.hpp"
#include "C01_arrays_string.hpp"


using namespace std;


int main()
{
	ArraysString chapter01;
	// chapter01.isUniqueChars();

	string input_1 = "def sasd fed wer";
	cout << input_1 << endl;
	
	// bool vic = chapter01.isPalindrome(input_1);
	// cout << vic << endl;
	char* output = chapter01.ReverseSentence(input_1);
	for(int i = 0; i < 100; i++)
		cout << output[i];
	cout << endl;

	// cout << output << endl;

	return 0;
}

