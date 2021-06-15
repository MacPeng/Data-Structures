/*
 * Queue.cpp
 *
 *  Created on: Oct 28, 2019
 *      Author: mikepeng
 */

#include "Queue.h"
#include <iostream>
#include <chrono>
using namespace std;



    void Queue::initializeQueue()
    {
    	queueFront = 0;
    	queueRear = maxQueueSize - 1;
    	count = 0;
    }



	void Queue::addQueue (int n)
	{

		if(! isFull())
		{
			queueRear = (queueRear + 1) % maxQueueSize;
			arrayPtr[queueRear] = n;
			count++;
		}else
		{
			throw "error, the queue is full..";
		}
	}
	void Queue::deleteQueue()
	{

		if(! isEmpty())
		{
			queueFront = (queueFront + 1) % maxQueueSize;
			count--;
		}else
		{
			throw "error, the queue is empty..";
		}
	}
	bool Queue::isEmpty()
	{
		if(count == 0)
			return true;
		else
		{
			return false;
		}
	}
	bool Queue::isFull()
	{
		if(count == maxQueueSize)
		{
			return true;
		}else
		{
			return false;
		}
	}
	int Queue::front()
	{

		if(!isEmpty())
		{
			return arrayPtr[queueFront];
		}else
		{
			throw "error, the queue is empty..";
		}
	}
	int Queue::back()
	{

		if(!isEmpty())
		{
			return arrayPtr[queueRear];

		}else
		{
			throw "error, the queue is empty..";
		}
	}

	Queue::Queue(int size)
	{
		int * arr = new int[size];
		arrayPtr = arr;
		maxQueueSize = size;
		initializeQueue();


	}

	Queue::~Queue()
	{
		delete arrayPtr;
	}

