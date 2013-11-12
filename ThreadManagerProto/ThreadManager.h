/*
 * ThreaedManager.h
 *
 *  Created on: Nov 11, 2013
 *      Author: beumjincho
 */


#include <iostream>
#include <list>
#include "Thread.h"

#ifndef THREAEDMANAGER_H_
#define THREAEDMANAGER_H_

class ThreadManager {

private:
	static list<Thread*> threadList;
	list<Thread*>::iterator threadListIterator;
	static int threadCount;
	bool isInitiated;

public:
	ThreadManager();
	virtual ~ThreadManager();
	void init();
	void generateThread();
	void terminateThread(int tid);
	void showAllThreads();
};

#endif /* THREAEDMANAGER_H_ */
