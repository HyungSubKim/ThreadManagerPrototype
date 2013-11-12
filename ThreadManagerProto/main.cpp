/*
 * main.cpp
 *
 *  Created on: Nov 7, 2013
 *      Author: hyungsubkim
 */

#include <iostream>
#include <sstream>
#include <typeinfo>

using namespace std;

void printMenu() {
	cout << "Thread Manger Simulator Help" << endl;
	cout << "1. " << endl;
	cout << "2. " << endl;
	cout << "3. " << endl;
	cout << "4. " << endl;
	cout << "5. " << endl;
	cout << "6. " << endl;
	cout << "7. " << endl;
	cout << "8. " << endl;
	cout << "9. Show Thread Manager Help" << endl;
}

int main() {
	int input;
	printMenu();

	while (true) {
		switch (input) {
		case '1':
			break;
		case '2':
			break;
		case '3':
			break;
		case '4':
			break;
		case '5':
			break;
		case '6':
			break;
		case '7':
			break;
		case '8':
			break;
		case '9':	// Show Thread Manager Help
			printMenu();
			break;
		}
	}

	sleep(1);
	cout << "Main thread ending" << endl;

	return 0;
}
