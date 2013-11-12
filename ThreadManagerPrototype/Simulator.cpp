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


int main() {
	/*try {

		while (1) {

			}
		}
	} catch (IllegalThreadStateException& e) {
		cerr << typeid(e).name() << ": " << e.what() << endl;
	}*/

	sleep(1);
	cout << "Main thread ending" << endl;

	return 0;
}
