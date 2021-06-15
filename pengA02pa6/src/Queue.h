/*
 * Queue.h
 *
 *  Created on: Oct 28, 2019
 *      Author: mikepeng
 */

#ifndef QUEUE_H_
#define QUEUE_H_
#include <iostream>
#include <chrono>
using namespace std;


//struct Transaction
//{
//  int i = 20;
//
//};
class Queue {
private:
	int queueFront;
	int queueRear;
	int count;
	int maxQueueSize;
	int * arrayPtr;
public:
	void initializeQueue();
	void addQueue(int n);
	void deleteQueue();
	bool isEmpty();
	bool isFull();
	int front();
	int back();
	Queue(int size);
	 ~Queue();
};

#endif /* QUEUE_H_ */
