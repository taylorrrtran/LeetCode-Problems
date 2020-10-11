// LeetCode Problems.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>

int specialArray(std::vector<int>& nums);
bool containsPattern(std::vector<int>& arr, int m, int k);

int main()
{
	std::vector<int> arr = {1, 2, 4, 4, 4, 4};
	std::cout << containsPattern(arr, 1, 3);
}

/* You are given an array nums of non-negative integers. nums is considered special if there exists a number x such that there are exactly x numbers in nums that are greater than or equal to x.
   Notice that x does not have to be an element in nums. Return x if the array is special, otherwise, return -1. It can be proven that if nums is special, the value for x is unique
   LeetCode: EASY, PROBLEM 1608 */
int specialArray(std::vector<int>& nums) {
	//Start wtih size of vector then decrement
	for (int i = nums.size(); i >= 1; i--) {
		int counter = 0;

		//Compare and increment counter for each elementer greater than current i
		for (int j = 0; j < nums.size(); j++)
		{
			if (nums[j] >= i)
				counter++;
		}
		
		//Return special number if there exists a number such that there are exactly x numbers in vector >= x
		if (counter == i)
			return counter;
	}

	//If didnt find vector to be special, return a -1
	return -1;
}

/* Given an array of positive integers arr,  find a pattern of length m that is repeated k or more times.
   A pattern is a subarray (consecutive sub-sequence) that consists of one or more values, repeated multiple times consecutively without overlapping. A pattern is defined by its length and the number of repetitions.
   Return true if there exists a pattern of length m that is repeated k or more times, otherwise return false.
   LeetCode: EASY, PROBLEM 1566
*/
bool containsPattern(std::vector<int>& arr, int m, int k) {

	//Traverse thru vector to find pattern
	int repeat = 0;

	for (int i = 0; i < arr.size(); i++) {
		int plen = 0;
		for (int j = 0; j < arr.size(); j++) {
			//Finding a pattern for m = 1
			if (arr[i] == arr[j])
				repeat++;
		}
	}

	if (repeat == k)
		return true;
	else
		return false;
}

