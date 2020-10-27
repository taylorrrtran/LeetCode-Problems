// LeetCode Problems.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
#include <string>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <bitset>

//LeetCode: MEDIUM, PROBLEM 1171 (NOT COMPLETE)
//Structure for linked-list;
struct ListNode {
	int val;
	ListNode* next;
	ListNode() : val(0), next(nullptr) {}
	ListNode(int x) : val(x), next(nullptr) {}
	ListNode(int x, ListNode* next) : val(x), next(next) {}
};

class Solution {
public:
	ListNode* removeZeroSumSublists(ListNode* head) {

		//create vector to store linked list values
		std::vector<int> num;

		//Begin at the head of linked list
		ListNode* nodePtr = head;
		
		//Load vector with values from linked list
		while (nodePtr) {
			num.push_back(nodePtr->val);
			nodePtr = nodePtr->next;
		}

		//Find values
		for (int i = 0; i < num.size(); i++) {
		}
	}
};

int specialArray(std::vector<int>& nums);
bool containsPattern(std::vector<int>& arr, int m, int k);
int sumOddLengthSubarrays(std::vector<int>& arr);
std::vector<int> finalPrices(std::vector<int>& prices);
std::vector<int> twoSum(std::vector<int>& nums, int target);
int reverse(int x);
int dayOfYear(std::string date);
int maximum69Number(int num);
std::vector<int> arrayRankTransform(std::vector<int>& arr);
std::vector<int> replaceElements(std::vector<int>& arr);
int romanToInt(std::string s);
std::vector<std::vector<int>> generate(int numRows);
std::vector<int> getRow(int rowIndex);
int mySqrt(int x);
bool isPowerOfTwo(int n);
int hammingWeight(uint32_t n);
int addDigits(int num);
bool isPowerOfFour(int num);
bool isPowerOfThree(int n);

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


//USED TO CALL FUNCTIONS OR PROBLEMS*
int main()
{ 
	int n = 38;
	int sol = addDigits(n);
	std::cout << sol;
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
   LeetCode: EASY, PROBLEM 7 (COMPLETE - ASSISTED)
*/
int reverse(int x) {

	//initialize variables
	int sol = 0;
	int n;

	
	while (x != 0) {

		//Grab remainder of modulo for the last digit place
		n = x % 10;

		//Focus on remaining numbers after getting the last digit place for reversal
		x = x / 10;

		//Account for overflow for the positive and negative values of int range. CANNOT DO ANS * 10 > INT_MAX/MIN
		if (sol > INT_MAX / 10 || (sol == INT_MAX / 10 && n > 7))
			return 0;
		if (sol < INT_MIN / 10 || (sol == INT_MIN / 10 && n < -8))
			return 0;
		sol = sol * 10 + n;

	}

	//Return answer
	return sol;
}

/* Given a string date representing a Gregorian calendar date formatted as YYYY-MM-DD, return the day number of the year.
   LeetCode: EASY, PROBLEM 1154 (COMPLETED)
*/
int dayOfYear(std::string date) {

	//Variable for solution
	int solution = 0;

	//Instantiate max number of days in each month
	std::vector<int> mdays = { 31,28,31,30,31,30,31,31,30,31,30,31 };

	//Convert strings to integers for year, month, day
	int year = stoi(date.substr(0, 4));
	int month = stoi(date.substr(5, 2));
	int day = stoi(date.substr(8, 2));

	//Solution beings with the day value since answer is returned in number of days for the year
	solution = day;

	//Add total number of days
	for (int i = 0; i < month - 1; i++) {
		solution += mdays[i];
	}

	//Check for leap year condition
	if ((((year % 4 == 0) && (year % 100 != 0)) || (year % 400 == 0)) && month > 2)
		solution++;
	
	//Return solution
	return solution;
}

/* Given a positive integer num consisting only of digits 6 and 9.
   Return the maximum number you can get by changing at most one digit (6 becomes 9, and 9 becomes 6).
   LeetCode: EASY, PROBLEM 1323 (COMPLETED)
*/
int maximum69Number(int num) {

	//Convert num to string then store in char array to evaluate each character
	std::string number = std::to_string(num);
	
	//Just find the first 6 to replace to a 9 starting from left most value place.
	for (int i = 0; i < number.size(); i++) {
		if (number[i] == '6')
		{
			number[i] = '9';
			break;
		}
	}

	//Return integer after conversion from string
	return stoi(number);
}

/* Given an array of integers arr, replace each element with its rank.
   The rank represents how large the element is. The rank has the following rules:
   Rank is an integer starting from 1.
   The larger the element, the larger the rank. If two elements are equal, their rank must be the same.
   Rank should be as small as possible.
   EASY, PROBLEM 1331 (NOT COMPLETE)
*/
std::vector<int> arrayRankTransform(std::vector<int>& arr) {
	return arr;
}

/*
   EASY, PROBLEM 1299 (COMPLETED)
*/
std::vector<int> replaceElements(std::vector<int>& arr) {

	//Begin from end of array. Maxi holds highest value seen so far
	int maxi = -1;
	int n = arr.size() - 1;

	//Keep track of highest number from the right or end of array, then replace current index with the highest number so far
	while (n >= 0) {
		int current = arr[n];
		arr[n] = maxi;

		//Return largest number between current index and current highest
		maxi = std::max(current, maxi);

		//Decrement index
		n--;
	}

	//Return new array
	return arr;
}

/*
	EASY. NOT COMPLETE
*/
int romanToInt(std::string s) {

	//Initiate variable for total
	int total = 0;

	for (int i = 0; i < s.length(); i++)
	{
		std::cout << total << std::endl;
		//Check for IV, IX, else it's I
		if (s[i] == 'I')
		{
			if (s[i + 1] == 'V')
			{
				total += 4;
				i += 2;
			}
			else if (s[i + 1] == 'X')
			{
				total += 9;
				i += 2;
			}
			else
				total += 1;
		}

		//V Roman Numeral
		else if (s[i] == 'V')
			total += 5;

		//Check for XL, XC, else it's X
		else if (s[i] == 'X') 
		{
			if (s[i + 1] == 'L')
			{
				total += 40;
				i += 2;
			}
			else if (s[i + 1] == 'C')
			{
				total += 90;
				i += 2;
			}
			else
				total += 10;
		}

		else if (s[i] == 'L')
			total += 50;

		//Check for CD, CM, else it;s C
		else if (s[i] == 'C')
		{
			if (s[i + 1] == 'D')
			{
				total += 400;
				i += 2;
			}
			else if (s[i + 1] == 'M')
			{
				total += 900;
				i += 2;
			}
			else
				total += 100;
		}

		//D Roman Numeral
		else if (s[i] == 'D')
			total += 500;

		//M Roman Numeral
		else if (s[i] == 'M')
			total += 1000;
	}

	//return total
	return total;
}

/*  Given a non-negative integer numRows, generate the first numRows of Pascal's triangle.
	EASY, PROBLEM 118 (COMPLETED)
*/

std::vector<std::vector<int>> generate(int numRows) {

	//Initialize variable for result
	std::vector<std::vector<int>> result;
	result.resize(numRows);
	for (int k = 0; k < numRows; k++)
	{
		result[k].resize(k + 1);
	}

	for (int i = 0; i < numRows; i++) {
		for (int j = 0; j <= i; j++) {

			//Fill in the first and last elements of the rows with 1s
			if (j == 0 || j == i)
				result[i][j] = 1;

			//Fill in the rest of the cells
			else
			{
				result[i][j] = result[i - 1][j - 1] + result[i - 1][j];
			}
		}
	}

	//return pascal triangle in the form of a 2D vector
	return result;
}

/*  Given an integer rowIndex, return the rowIndexth row of the Pascal's triangle.
	EASY, PROBLEM 119 (COMPLETED) CAN BE OPTIMIZED.
*/

std::vector<int> getRow(int rowIndex) {
	//Initialize variable for result
	std::vector<std::vector<int>> result;
	std::vector<int> solution(rowIndex + 1);
	result.resize(rowIndex + 1);
	for (int k = 0; k < rowIndex + 1; k++)
	{
		result[k].resize(k + 1);
	}

	for (int i = 0; i < rowIndex + 1; i++) {
		for (int j = 0; j <= i; j++) {

			//Fill in the first and last elements of the rows with 1s
			if (j == 0 || j == i)
				result[i][j] = 1;

			//Fill in the rest of the cells
			else
			{
				result[i][j] = result[i - 1][j - 1] + result[i - 1][j];
			}

			//Store values to return elements of the rowIndexth
			if (i + 1 == rowIndex + 1) {
				solution[j] = result[i][j];
			}
		}
	}
	
	//Return only the rowIndexth
	return solution;
}
/* Compute and return the square root of x, where x is guaranteed to be a non-negative integer.
	Since the return type is an integer, the decimal digits are truncated and only the integer part of the result is returned.
	EASY, PROBLEM 67 (COMPLETED)
*/
int mySqrt(int x) {
	int sol = trunc(sqrt(x));
	return sol;
}

/* Given an integer n, write a function to determine if it is a power of two.
   EASY, PROBLEM 231 (COMPLETED)
*/
bool isPowerOfTwo(int n) {
	//Use Log base 2 function to check for power of two. Must check ceiling and floor because numbers will be same regardless it if it a power of two (no remainders).
	if (ceil(log2(n)) == floor(log2(n)) && !(n <= 0))
		return true;
	else
		return false;
}

/* Write a function that takes an unsigned integer and returns the number of '1' bits it has (also known as the Hamming weight).
   EASY, PROBLEM 191 (COMPLETE)
*/
int hammingWeight(uint32_t n) {

	//Convert 32 bits from octal literal in C++ to binary literal. Use the count member function to find all values of 1 and return value.
	std::bitset<32> b(n);
	return b.count();
}

/* Given a non-negative integer num, repeatedly add all its digits until the result has only one digit.
   EASY, PROBLEM 258 (NOT COMPLETE)
*/
int addDigits(int num) {
	
	//Only add digits for non-negative values
	if (num <= 0)
		return 0;

	//Highest value single digit is 9. So use modulo 9
	return num % 9 == 0 ? 9 : num % 9;
}

/* Given an integer (signed 32 bits), write a function to check whether it is a power of 4.
   EASY, PROBLEM 342 (COMPLETED)
*/
bool isPowerOfFour(int num) {
	
	//Cannot take logarithmic of 0 or negative numbers;
	if (num <= 0)
		return false;

	//Return if input is a power of 4 using logarithmic expressions: log(a) / log(b) = log base b of (a)
	return ((log(num) / log(4)) == trunc((log(num) / log(4))));
}

/* Given an integer, write a function to determine if it is a power of three.
   EASY, PROBLEM 326 (COMPLETED)
*/
bool isPowerOfThree(int n) {

	//Cannot take logarithmic of 0 or negative numbers; 3^19 is highest power of 3 within a 32-bit signed integer
	return (n > 0 && 1162261467 % n == 0);
}