/*
 * Program: numbers.cpp
 * Author: Aren Kyle
 * Date: 1/14/2017
 * Description: Prints values of various macros from <climts> library, as well as numbers regarding 1 byte of data
 * Input: No input from user
 * Output: Value of <climits> macros and 1 byte of data. Macro values dependent on user hardware
 */


#include <iostream>
#include <climits>
#include <cmath>


int main() {

	/*Lists values of users specific hardware*/
	std::cout << "The minimum value for a short is " << SHRT_MIN;

	std::cout << ", the maximum value for a short is " << SHRT_MAX;

	std::cout << ", and the maximum value for an unsigned short is " << USHRT_MAX << std::endl;

	std::cout << "The minimum value for an int is " << INT_MIN;

	std::cout << ", the maximum value for an int is " << INT_MAX; 

	std::cout << ", and the maximum for an unsigned int is " << UINT_MAX << std::endl; 

	std::cout << "The minimum value for a long is " << LONG_MIN;

	std::cout << ", the maximum value for a long is " << LONG_MAX;

	std::cout << ", and the maximum value for an unsigned long is " << ULONG_MAX << std::endl; 

	/*Calculates 1 byte values*/
	std::cout << "The maximum and minimum signed number that can be stored in one byte are " << pow(-2,7) + 1;

	std::cout << " and " << pow(2,7) - 1 << ", respectively." << std::endl; 

	std::cout << "The maximum unsigned number in one byte is: " << pow(2,8) - 1 << std::endl; 

	return 0; 

}
