/*
 * Thread.cpp
 *
 * Created on: Nov 7, 2013
 * Author: hyungsubkim
 */

#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>
#include <signal.h>
#include "Thread.h"

using namespace std;

void* Thread::threadHandler(void* arg) {

	signal(SIGUSR1, interruptHandler);
	Thread* thread = (Thread*) arg;

	try {
//		thread->run();
	} catch (InterruptedException& e) {
		thread->isInterrupted = true;
	} catch (...) {

	}

	thread->state = -1;

	return NULL;
}

void Thread::interruptHandler(int sigInt) {
	throw InterruptedException("Thread interrupted");
}

Thread::Thread(int tid) {
	this->tid = tid;

	joinning = false;
	interrupted = false;

	pthread_mutex_init(&mutex, NULL);
	pthread_cond_init(&cond, NULL);
	state = 0;
	pthread_mutex_lock(&mutex);

	if(tid == 0) {
		pthread_attr_init(&attr);
		pthread_attr_setdetachstate(&attr, PTHREAD_CREATE_DETACHED);
	}

	pthread_mutex_unlock(&mutex);

	create(tid); // static
}

Thread::~Thread() {
	pthread_attr_destroy(&attr);
	pthread_mutex_destroy(&mutex);
	pthread_cond_destroy(&cond);
}

int Thread::create(int tid) { // thread

	if (state == 1) {
		throw IllegalThreadStateException("Thread already started");
	} else if (state == 0) {
		state = 1;
		pthread_create(&pthread, &attr, threadHandler, this);
	} else if (state == -1) {
		throw IllegalThreadStateException("Thread had been started.");
	}

}

int Thread::terminate() {
	~Thread();
}

void Thread::join()
{
	if (state == 1)
	{
		pthread_mutex_lock(&mutex);
		joinning = true;
		pthread_cond_wait(&cond, &mutex);
		joinning = false;
		pthread_mutex_unlock(&mutex);
	}
}

void Thread::join(unsigned long time)
{
	if (state == 1)
	{
		struct timeval now;
		struct timespec timeout;
		gettimeofday(&now, NULL);
		ldiv_t t = ldiv(time * 1000000, 1000000000);
		timeout.tv_sec = now.tv_sec + t.quot;
		timeout.tv_nsec = now.tv_usec * 1000 + t.rem;
		pthread_mutex_lock(&mutex);
		joinning = true;
		pthread_cond_timedwait(&cond, &mutex, &timeout);
		joinning = false;
		pthread_mutex_unlock(&mutex);
	}
}

void Thread::interrupt()
{
	pthread_kill(pthread, SIGUSR1);
}

bool Thread::isInterrupted()
{
	return interrupted;
}

bool Thread::isAlive()
{
	return state == 1;
}

long Thread::getTid() {
	return tid;
}

void Thread::setHeapAddrSpace(long startAddr, long endAddr) {
	this->heapAddrSpace.startAddr = startAddr;
	this->heapAddrSpace.endAddr = endAddr;
}

void Thread::getHeapAddrSpace() {
	cout << "(" << this->heapAddrSpace.startAddr << ", "
			<< this->heapAddrSpace.endAddr << ")" << endl;
}

void Thread::showAllInfo() {
	cout << "----------------------------------" << endl;
	cout << "TID : " << getTid() << endl;
	cout << "HeapArea : " << getHeapAddrSpace() << endl;
	cout << "----------------------------------" << endl;
}
