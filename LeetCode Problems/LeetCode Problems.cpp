// LeetCode Problems.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
#include <string>
#include <cstring>

int specialArray(std::vector<int>& nums);
bool containsPattern(std::vector<int>& arr, int m, int k);
int sumOddLengthSubarrays(std::vector<int>& arr);
std::vector<int> finalPrices(std::vector<int>& prices);
std::vector<int> twoSum(std::vector<int>& nums, int target);
int reverse(int x);

/* Design a parking system for a parking lot. The parking lot has three kinds of parking spaces: big, medium, and small, with a fixed number of slots for each size.
   Implement the ParkingSystem class:
   ParkingSystem(int big, int medium, int small) Initializes object of the ParkingSystem class. The number of slots for each parking space are given as part of the constructor.
   bool addCar(int carType) Checks whether there is a parking space of carType for the car that wants to get into the parking lot. carType can be of three kinds: big, medium, or small, which are represented by 1, 2, and 3 respectively. A car can only park in a parking space of its carType. 
   If there is no space available, return false, else park the car in that size space and return true.
   LeetCode: EASY, PROBLEM 1603 (COMPLETED)
*/
class ParkingSystem {
private:
	//variables to keep track of car size spaces
	int bigSlots, medSlots, smaSlots;

public:

	//constructor to initalize parking spots according to car size
	ParkingSystem(int big, int medium, int small) {
		bigSlots = big;
		medSlots = medium;
		smaSlots = small;
	}

	bool addCar(int carType) {

		//if there is a car spot available to corresponding size, deduct 1 spot then return true
		if (carType == 1 && bigSlots != 0)
		{
			bigSlots -= 1;
			return true;
		}
		else if (carType == 2 && medSlots != 0)
		{
			medSlots -= 1;
			return true;
		}
		else if (carType == 3 && smaSlots != 0)
		{
			smaSlots -= 1;
			return true;
		}

		//Otherwise, return false
		return false;
	}
};

/* Design a HashSet without using any built-in hash table libraries.
   LeetCode: EASY, PROBLEM 705 (NOT COMPLETE)
*/
class MyHashSet {
private:
	std::vector<double> set;
public:
	/** Initialize your data structure here. */
	MyHashSet() {
		std::vector<double> set(1000000);
	}

	void add(int key) {
		set.push_back(key);
	}

	void remove(int key) {

	}

	/** Returns true if this set contains the specified element */
	bool contains(int key) {

	}
};

int main()
{
	std::vector<int> solution;
	std::vector<int> nums = {3, 3};
	solution = twoSum(nums, 6);

	std::cout << solution[0] << " " << solution[1] << std::endl;
}

/* You are given an array nums of non-negative integers. nums is considered special if there exists a number x such that there are exactly x numbers in nums that are greater than or equal to x.
   Notice that x does not have to be an element in nums. Return x if the array is special, otherwise, return -1. It can be proven that if nums is special, the value for x is unique
   LeetCode: EASY, PROBLEM 1608 (COMPLETE)*/
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
   LeetCode: EASY, PROBLEM 1566 (NOT COMPLETE)
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

/* Given an array of positive integers arr, calculate the sum of all possible odd-length subarrays.
   A subarray is a contiguous subsequence of the array.
   Return the sum of all odd-length subarrays of arr.
   LeetCode: EASY, PROBLEM 1588 (COMPLETE - ASSISTED)
*/
int sumOddLengthSubarrays(std::vector<int>& arr) {

	//total amount from adding
	int total = 0;

	for (int i = 0; i < arr.size(); i++)
	{
		//Add elements between odd-length subarrays
		for (int j = i; j < arr.size(); j += 2) {
			for (int k = i; k <= j; k++)
				total += arr[k];
		}
	}

	//return total amount
	return total;
}

/* Given the array prices where prices[i] is the price of the ith item in a shop. There is a special discount for items in the shop, if you buy the ith item, then you will receive a discount equivalent to prices[j] where j is the minimum index such that j > i and prices[j] <= prices[i], otherwise, you will not receive any discount at all.
   LeetCode: EASY, PROBLEM 1475 (COMPLETE)
*/
std::vector<int> finalPrices(std::vector<int>& prices) {

	//Begin 2nd loop at i + 1 since that's the minimum criteria to check
	for (int i = 0; i < prices.size(); i++) {
		for (int j = (i + 1); j < prices.size(); j++) {
			if (prices[j] <= prices[i]) {
				prices[i] -= prices[j];
				break;
			}
		}
	}

	//Return new vector
	return prices;
}

/* Given an array of integers nums and an integer target, return indices of the two numbers such that they add up to target.
   You may assume that each input would have exactly one solution, and you may not use the same element twice.
   You can return the answer in any order.
   LeetCode: EASY, PROBLEM 1 (COMPLETE)
*/
std::vector<int> twoSum(std::vector<int>& nums, int target) {

	//Array to hold the two indicies for target value
	std::vector<int> solution(2);

	//Loop to find two indicies
	for (int i = 0; i < nums.size(); i++)
	{
		for (int j = i + 1; j < nums.size(); j++)
		{
			if (nums[i] + nums[j] == target)
			{
				solution[0] = i;
				solution[1] = j;
			}
		}
	}

	//Return the solution array
	return solution;
}

/* Given a 32-bit signed integer, reverse digits of an integer.
   LeetCode: EASY, PROBLEM 7 (NOT COMPLETE)
*/
int reverse(int x) {
	
	//dynamically allocate array to store argument as a character array
	char* stringStore = new char[];

	//Convert input into string and store
	std::string convert;
	convert = std::to_string(x);
	
	


	//Delete and free memory from array
	delete[] stringStore;
}