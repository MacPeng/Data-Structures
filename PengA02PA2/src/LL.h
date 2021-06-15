/*
 * LL.h
 *
 *  Created on: Sep 24, 2019
 *      Author: mikepeng
 */

#ifndef LL_H_
#define LL_H_
#include <iostream>
using namespace std;

template <class T>
struct LLnode
{
	LLnode * fwdptr;
	T theData;
};
template <class T>
class LL{
private:
	LLnode<T> * llh;

public:
	void push_front (T s);
	void push_back (T s);
	int list_length ();
	string retrieve_front ();
	string retrieve_back ();
	void display_list ();
	void destroy_list();
	bool search_list(T target);
	bool delete_node(T target);
	LL();
};
template <class T>
void LL<T>::push_front (T s)
{
	if (llh == nullptr)
	{
		LLnode<T> * LLptr = new LLnode<T>();
		LLptr -> theData = s;
		LLptr -> fwdptr = nullptr;
		llh = LLptr;
	}
	else
	{

        LLnode<T> * LLptr = new LLnode<T>();
		LLptr->theData = s;
		LLnode<T> * temp = llh;
		llh = LLptr;
		LLptr->fwdptr = temp;


	}



}

template <class T>
void LL<T>::push_back (T s)
{

	if (llh == nullptr)
		{
			LLnode<T> * LLptr = new LLnode<T>();
			LLptr -> fwdptr = nullptr;
			LLptr -> theData = s;
			llh = LLptr;
		}
	else
	{
		LLnode<T> * LLptr = new LLnode<T>();
		LLptr -> theData = s;
		LLnode<T> * temp = llh;
		if (temp != nullptr)
		{
			while (temp -> fwdptr != nullptr)
			{
				temp = temp -> fwdptr;
			}
		}
//		else
//		{
//			llh = LLptr;
//		}
		LLptr -> fwdptr = nullptr;
		temp -> fwdptr = LLptr;
	}


}

template <class T>
int LL<T>::list_length ()
{

	int counter = 0;
    LLnode<T> * curr = llh;

	if(curr == nullptr)
	{
		return 0;
	}

	while (curr  != nullptr)
	{
		counter++;
		curr = curr -> fwdptr;
	}
	return counter;

}
template <class T>
string LL<T>::retrieve_front ()
{
	if (llh == nullptr)
	{
		throw " Sorry, this linked list is empty. ";

	}
	else
	{
		return llh -> theData;
	}
}


template <class T>
string LL<T>::retrieve_back ()
{
	LLnode<T> * curr = llh;
	if (llh == nullptr)
		{
			throw " Sorry, this linked list is empty. ";
		}
		else
		{
			while (curr -> fwdptr != nullptr)
			{
				curr = curr -> fwdptr;
			}
			return curr -> theData;
		}
}

template <class T>
void LL<T>::display_list ()
{
	LLnode<T> * curr = llh;
	int counter = 0;

	if (llh == nullptr)
	{
		cout << " Sorry, this linked list is empty. " << endl;

	}
	else
	{
		while (curr != nullptr)

		{
			cout << "node "<< counter << " data -> "<< curr -> theData<<endl;
			curr = curr->fwdptr;
			counter++;
		}
	}

}

template <class T>
void LL<T>::destroy_list()
{
	LLnode<T> * curr = llh;
	LLnode<T> * temp;
	while (curr != nullptr)
	{
		temp = curr;
		curr = curr -> fwdptr;
		delete temp;
	}
	llh = nullptr;

}
template <class T>
bool LL<T>::search_list(T target)
{
	LLnode<T> * curr = llh;
	while (curr != nullptr)
	{
		if (curr -> theData == target)
		{
			return true;

		}
		curr = curr -> fwdptr;
	}
	return false;
}

template <class T>
bool LL<T>::delete_node(T target)
{
	LLnode<T> * curr = llh;
	LLnode<T> * temp;


	if (curr == nullptr)
			return false;

	if (curr != nullptr && curr -> theData == target)
	{
		llh = curr -> fwdptr;
		delete curr;
		return true;
	}

	while (curr != nullptr && curr -> theData != target)
	{
		temp = curr;
		curr = curr -> fwdptr;

	}
    if(temp == nullptr)
    return false;

    temp -> fwdptr = curr -> fwdptr;
	delete curr;

    return true;
}



template <class T>
LL<T>::LL()
{
	llh = nullptr;
}


#endif /* LL_H_ */
