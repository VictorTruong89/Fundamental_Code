#include <list>
#include <mutex>
#include <algorithm>

#include <iostream>
#include <vector>

#include "leetcode_practice.hpp"

using namespace std;

double SimpleMedian(int* data, int& size);

int num_1[] = {1, 12, 23, 44, 55};
int num_2[] = {4, 15, 26, 37};
double med_1 = 0;
double med_2 = 0;

int main()
{
	// Get the size of the original arrays
	int size_1 = sizeof(num_1) / sizeof(num_1[0]);
	int size_2 = sizeof(num_2) / sizeof(num_2[0]);

	Median2Array test;
	// Input the arrays into class's vectors
	test.inputArray(num_1, num_2, size_1, size_2);
	double median = -1;

	// Apply method 1
	median = test.Method_1();
	cout << median << endl;

	return 0;
}



