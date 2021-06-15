//============================================================================
// Name        : pengA02pa6.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include "Queue.h"
#include <iostream>
#include <chrono>
#include <ctime>
using namespace std;
struct Transaction
{
	int i = 20;

};
int main()
{
	Queue queue(5);
	cout<<"Now pushing 5 elements into queue."<<endl;
	queue.addQueue(111);
	queue.addQueue(222);
	queue.addQueue(333);
	queue.addQueue(444);
	queue.addQueue(555);
	cout<<"The front of the queue is "<<queue.front()<<endl;
	cout<<"The back of the queue is "<<queue.back()<<endl;
	cout<<"Now deleting the front .."<<endl;
	queue.deleteQueue();
	cout<<"Now, the front of the queue is "<<queue.front()<<endl;
	cout<<"Now, the back of the queue is "<<queue.back()<<endl;
	cout<<"Now deleting all the elements .."<<endl;
	queue.deleteQueue();
	queue.deleteQueue();
	queue.deleteQueue();
	queue.deleteQueue();
	cout<<"Checking if the queue is empty after five deletes.."<<endl;
	if(queue.isEmpty())
	{
		cout<<"The queue is empty.."<<endl;

	}else
	{
		cout<<"The queue is not empty.."<<endl;
	}
	cout<<"checking if the queue is full after five pushes.."<<endl;
	cout<<"Pushing five elements into queue.."<<endl;
	queue.addQueue(111);
	queue.addQueue(222);
	queue.addQueue(333);
	queue.addQueue(444);
	queue.addQueue(555);




    cout<<"......Now The Simulation Get Started......"<<endl;


    int clockticks = 0;
    int transaction_Started = 0;
    int numOfClockTicks;
    int transactionGeneratedCount = 0;
    int transactionCompletedCount = 0;
    int GeneratingNewTransactionProb;
    int EndingTransactionProb;
    bool transactionStarted = false;
    int queueSize;
    cout<<"Please enter the queue size: "<<endl;
    cin>>queueSize;
    cout<<"Please enter the probability of generating a new transaction size: "<<endl;
    cin>>GeneratingNewTransactionProb;
    cout<<"Please enter the probability of ending transaction size: "<<endl;
    cin>>EndingTransactionProb;
    cout<<"Please enter the number of clock ticks: "<<endl;
    cin>>numOfClockTicks;
    cout<<".......The simulation Ended........"<<endl;



    srand(time(0));
    Queue q(queueSize);
	while(clockticks < numOfClockTicks)
	{
		if((rand()%100) < GeneratingNewTransactionProb)
		{
			Transaction s;
			q.addQueue(s.i);
			transactionGeneratedCount++;

		}
		if(transactionStarted == false)
		{
			if(q.isEmpty() == false)
			{
				q.deleteQueue();
				transactionStarted = true;
				transaction_Started++;
			}
		}
		if(transactionStarted == true)
		{
			if((rand()%100) < EndingTransactionProb)
			{
				transactionStarted = false;
				transactionCompletedCount++;
			}
		}
		clockticks++;
	}

	cout<<"Number of transactions generated is "<< transactionGeneratedCount  <<endl;
    cout<<"Number of transactions processed is "<< transaction_Started  <<endl;
    cout<<"Number of unprocessed transaction left in the queue is "<<  transactionGeneratedCount - transactionCompletedCount <<endl;
    cout<<"Number of clock ticks is "<< numOfClockTicks<<endl;
    return 0;
}
