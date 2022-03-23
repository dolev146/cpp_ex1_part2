/**
 * Demo program for mat exercise.
 * 
 * Author: Dolev Dublon
 * Since : 2022-03
 */

#include "mat.hpp"

#include <iostream>
#include <stdexcept>
using namespace std;

int main() {
	cout << ariel::mat(1, 9, '@', '-') << endl;

	cout << ariel::mat(15, 9, '@', '-') << endl; 

	try {
		cout << ariel::mat(12, 5, '$', '%') << endl; // Exception - not a valid code
	} catch (exception& ex) {
	 	cout << "   caught exception: " << ex.what() << endl;  // should print "Mat size is always odd"
	}
}