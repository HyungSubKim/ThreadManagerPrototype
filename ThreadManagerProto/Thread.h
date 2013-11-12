/*
 * Thread.h
 *
 *  Created on: Nov 7, 2013
 *      Author: hyungsubkim
 */

#ifndef THREAD_H_
#define THREAD_H_

#include <iostream>
#include <pthread.h>
#include <string>
#include <stdexcept>
#include <sys/time.h>
#include <signal.h>
#include <stdlib.h>

using namespace std;

class Thread {

private:
	pthread_t pthread;
	static int tid;
	int state;
	static pthread_attr_t attr;

	struct HeapAddrSpace {
		long startAddr;
		long endAddr;
	};
	HeapAddrSpace heapAddrSpace;

	bool interrupted;

	static void* threadHandler(void* arg);
	static void interruptHandler(int sigInt);
	//virtual void run() = 0;
	bool joinning;
	pthread_mutex_t mutex;
    pthread_cond_t cond;

public:
	Thread(int tid);
	virtual ~Thread();
	void create(int tid);
	void terminate();
	void join();
	void join(unsigned long time);
	void interrupt();
	bool isInterrupted();
	bool isAlive();
	long getTid();
	void setHeapAddrSpace(long startAddr, long endAddr);
	void getHeapAddrSpace();
	void showAllInfo();

};

class InterruptedException: public exception {
public:
	explicit InterruptedException(const string& message) :
			_message(message) {
	}

	virtual ~InterruptedException() throw () {
	}

	virtual const char* what() const throw () {
		return _message.c_str();
	}

private:
	string _message;

};

class IllegalThreadStateException: public exception {
public:
	explicit IllegalThreadStateException(const string& message) :
			_message(message) {
	}

	virtual ~IllegalThreadStateException() throw () {
	}

	virtual const char* what() const throw () {
		return _message.c_str();
	}

private:
	string _message;

};

#endif /*THREAD_H_*/
