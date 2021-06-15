/*
 * LL.h
 *
 *  Created on: Oct 7, 2019
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
	LLnode<T> * backHelper(LLnode<T> * LLptr);
	int list_length ();
	int list_lengthHelper(LLnode<T> * LLptr, int counter);
	string retrieve_front ();
	string retrieve_back ();
	void display_list ();
	void display_listHelper(LLnode<T> * LLptr, int counter);
	void destroy_list();
	void destroy_listHelper(LLnode<T> * LLptr);
	bool search_list(T target);
	bool search_listHelper(T target, LLnode<T> * LLptr);
	bool delete_node(T target);
	bool delete_nodeHelper(T target, LLnode<T> * curr, LLnode<T> * next);
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

	LLnode<T> * curr = backHelper(llh);
	if (curr == nullptr)
		{
			LLnode<T> * LLptr = new LLnode<T>();
			LLptr -> fwdptr = nullptr;
			LLptr -> theData = s;
			llh = LLptr;
		}
	else
	{
		LLnode<T> * LLptr = new LLnode<T>();
		LLptr -> fwdptr = nullptr;
		LLptr -> theData = s;
		curr -> fwdptr = LLptr;
	}


}

template <class T>
LLnode<T> * LL<T>::backHelper(LLnode<T> * LLptr)
{
	if(llh == nullptr)
	{
		return nullptr;
	}
	if(LLptr -> fwdptr != nullptr)
	{
		return backHelper(LLptr -> fwdptr);
	}else
	{
		return LLptr;
	}

}


template <class T>
int LL<T>::list_length ()
{
	return list_lengthHelper(llh, 0);
}

template <class T>
int LL<T>::list_lengthHelper(LLnode<T> * LLptr, int counter)
{
	if(llh == nullptr)
	{
		return 0;

	}
	if(LLptr == nullptr)
	{
		return counter;
	}
	return list_lengthHelper(LLptr -> fwdptr, counter + 1);
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
	LLnode<T> * curr = backHelper(llh);
	if(curr == nullptr)
	{
		throw " Sorry, this linked list is empty. ";
	}else
	{
		return curr -> theData;
	}
}

template <class T>
void LL<T>::display_list ()
{
	return display_listHelper(llh, 0);
}

template <class T>
void LL<T>::display_listHelper(LLnode<T> * LLptr, int counter)
{
	if(llh == nullptr)
	{
		cout << "Sorry, this list is empty." <<endl;
	}else
	{
		if(LLptr != nullptr)
		{
			 cout << "node "<< counter << " data -> "<< LLptr ->theData  << endl;
			 display_listHelper(LLptr -> fwdptr, counter + 1);
		}
	}
}

template <class T>
void LL<T>::destroy_list()
{
	destroy_listHelper(llh);
	llh = nullptr;

}

template <class T>
void LL<T>::destroy_listHelper(LLnode<T> * LLptr)
{
	if(LLptr != nullptr)
	{
		LLnode<T> * curr = LLptr;
		LLptr = LLptr -> fwdptr;
		delete curr;
		destroy_listHelper(LLptr);
	}
}

template <class T>
bool LL<T>::search_list(T target)
{
	return search_listHelper(target, llh);
}

template <class T>
bool LL<T>::search_listHelper(T target, LLnode<T> * LLptr)
{
	if(LLptr == nullptr)
	{
		return false;
	}
	if(LLptr -> theData == target)
	{
		return true;
	}
	return search_listHelper(target, LLptr -> fwdptr);
}

template <class T>
bool LL<T>::delete_node(T target)
{
//	LLnode<T> * curr = llh;
//	LLnode<T> * temp;
//
//
//	if (curr == nullptr)
//			return false;
//
//	if (curr != nullptr && curr -> theData == target)
//	{
//		llh = curr -> fwdptr;
//		delete curr;
//		return true;
//	}
//
//	while (curr != nullptr && curr -> theData != target)
//	{
//		temp = curr;
//		curr = curr -> fwdptr;
//
//	}
//    if(temp == nullptr)
//    return false;
//
//    temp -> fwdptr = curr -> fwdptr;
//	delete curr;
//
//    return true;
	return delete_nodeHelper(target, llh, llh -> fwdptr);
}

template <class T>
bool LL<T>::delete_nodeHelper(T target, LLnode<T> * curr, LLnode<T> * next)
{

	if(next == nullptr)
	{
		return false;
	}
	if(curr == nullptr)
		{
			return false;
		}
	if(curr -> theData == target)
	{
		LLnode<T> * temp = curr -> fwdptr;
		delete curr;
		llh = temp;
		return true;
	}
	if(next -> fwdptr == nullptr && next -> theData == target)
		{
			curr -> fwdptr = nullptr;
			return true;

		}
	if (next -> fwdptr != nullptr && next -> theData == target)
	{
		LLnode<T> * temp = next -> fwdptr;
		delete next;
		curr -> fwdptr = temp;

		return true;
	}

	return delete_nodeHelper(target, curr -> fwdptr, next -> fwdptr);
}

template <class T>
LL<T>::LL()
{
	llh = nullptr;
}


#endif /* LL_H_ */
