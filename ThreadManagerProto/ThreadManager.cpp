/*
 * ThreaedManager.cpp
 *
 *  Created on: Nov 11, 2013
 *      Author: beumjincho
 */

#include "ThreadManager.h"

int ThreadManager::threadCount = 0;
list<Thread*> ThreadManager::threadList;

ThreadManager::ThreadManager() {
	// TODO Auto-generated constructor stub
	init();
}

ThreadManager::~ThreadManager() {
	// TODO Auto-generated destructor stub
}

void ThreadManager::init() {
	isInitiated = true;
}

/*
 *
 */
void ThreadManager::generateThread() {
	Thread* newThreadPointer;

	if (isInitiated) {
		newThreadPointer = new Thread(threadCount++);
		threadList.push_back(newThreadPointer);
	}

}

/*
 * Find a thread whose tid is the same as the given tid
 * and, delete it from the thread list.
 */
void ThreadManager::terminateThread(int tid) {

	for (threadListIterator = threadList.begin(); threadListIterator != threadList.end(); ) {
		if ((*threadListIterator)->getTid() == tid) {
			list<Thread*>::iterator tempIterator = threadListIterator++;

			delete(*tempIterator);

			if(threadListIterator == threadList.end()) {
				break;
			}
		}
		else {
			++threadListIterator;
		}
	}

}

void ThreadManager::showAllThreads() {
	for (threadListIterator = threadList.begin();
			threadListIterator != threadList.end(); threadListIterator++) {
		(*threadListIterator)->showAllInfo();
	}
}
