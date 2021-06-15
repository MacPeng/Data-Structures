/*
 * LL.cpp
 *
 *  Created on: Sep 24, 2019
 *      Author: mikepeng
 */

//#include "LL.h"
//#include <iostream>
//using namespace std;
//
//template <class T>
//void LL<T>::push_front (T s)
//{
//	if (llh == nullptr)
//	{
//		LLnode<T> * LLptr = new LLnode<T>();
//		LLptr -> theData = s;
//		LLptr -> fwdptr = nullptr;
//		llh = LLptr;
//	}
//	else
//	{
//
//        LLnode<T> * LLptr = new LLnode<T>();
//		LLptr->theData = s;
//		LLnode<T> * temp = llh;
//		llh = LLptr;
//		LLptr->fwdptr = temp;
//
//
//	}
//
//
//
//}
//
//template <class T>
//void LL<T>::push_back (T s)
//{
//
//	if (llh == nullptr)
//		{
//			LLnode<T> * LLptr = new LLnode<T>();
//			LLptr -> fwdptr = nullptr;
//			LLptr -> theData = s;
//			llh = LLptr;
//		}
//	else
//	{
//		LLnode<T> * LLptr = new LLnode<T>();
//		LLptr -> theData = s;
//		LLnode<T> * temp = llh;
//		if (temp != nullptr)
//		{
//			while (temp -> fwdptr != nullptr)
//			{
//				temp = temp -> fwdptr;
//			}
//		}
////		else
////		{
////			llh = LLptr;
////		}
//		LLptr -> fwdptr = nullptr;
//		temp -> fwdptr = LLptr;
//	}
//
//
//}
//
//template <class T>
//int LL<T>::list_length ()
//{
//
//	int counter = 0;
//    LLnode<T> * curr = llh;
//
//	if(curr == nullptr)
//	{
//		return 0;
//	}
//
//	while (curr  != nullptr)
//	{
//		counter++;
//		curr = curr -> fwdptr;
//	}
//	return counter;
//
//}
//template <class T>
//string LL<T>::retrieve_front ()
//{
//	if (llh == nullptr)
//	{
//		throw " Sorry, this linked list is empty. ";
//
//	}
//	else
//	{
//		return llh -> theData;
//	}
//}
//
//
//template <class T>
//string LL<T>::retrieve_back ()
//{
//	LLnode<T> * curr = llh;
//	if (llh == nullptr)
//		{
//			throw " Sorry, this linked list is empty. ";
//		}
//		else
//		{
//			while (curr -> fwdptr != nullptr)
//			{
//				curr = curr -> fwdptr;
//			}
//			return curr -> theData;
//		}
//}
//
//template <class T>
//void LL<T>::display_list ()
//{
//	LLnode<T> * curr = llh;
//	int counter = 0;
//
//	if (llh == nullptr)
//	{
//		cout << " Sorry, this linked list is empty. " << endl;
//
//	}
//	else
//	{
//		while (curr != nullptr)
//
//		{
//			cout << "node "<< counter << " data -> "<< curr -> theData<<endl;
//			curr = curr->fwdptr;
//			counter++;
//		}
//	}
//
//}
//
//template <class T>
//LL<T>::LL()
//{
//	llh = nullptr;
//}
//
