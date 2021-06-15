//============================================================================
// Name        : PengA02PA1.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;

struct LLnode
{
	LLnode * fwdptr;
	string theData;
};
void push_front (LLnode * & llh, string s);
void push_back (LLnode * & llh, string s);
int list_length (LLnode * llh);
string retrieve_front (LLnode * llh);
string retrieve_back (LLnode * llh);
void display_nodes (LLnode * llh);

int main() {

	LLnode * theLLHeader1 = nullptr;

	cout << "Main:  number of nodes in empty list " << list_length(theLLHeader1) << endl;
	display_nodes(theLLHeader1);
	push_front (theLLHeader1, "aaaaa");
	push_back (theLLHeader1, "bbbbb");
	push_front (theLLHeader1, "before aaaaa");
	push_back (theLLHeader1, "after bbbbb");
	cout << "Main:  number of nodes after 4 pushes - " << list_length(theLLHeader1) << endl;
	display_nodes (theLLHeader1);
	cout << "Main:  retrieve front: " << retrieve_front (theLLHeader1) << endl;
	cout << "Main:  retrieve back: " << retrieve_back (theLLHeader1) << endl;
	cout << endl;

	LLnode * theLLHeader2 = nullptr;

	push_front (theLLHeader2, "33333");
	push_front (theLLHeader2, "22222");
	push_front (theLLHeader2, "11111");
	push_back (theLLHeader2, "44444");
	push_back (theLLHeader2, "55555");
	push_back (theLLHeader2, "66666");
	display_nodes (theLLHeader2);

	cout <<list_length(theLLHeader2)<<endl;
	display_nodes(theLLHeader2);

	return 0;
}
void push_front (LLnode * &llh, string s)
{
	if (llh == nullptr)
	{
		LLnode * LLptr = new LLnode;
		LLptr -> theData = s;
		LLptr -> fwdptr = nullptr;
		llh = LLptr;
	}
	else
	{

        LLnode * LLptr = new LLnode;
		LLptr->theData = s;
		LLnode* temp = llh;
		llh = LLptr;
		LLptr->fwdptr = temp;



	}



}
void push_back (LLnode * &llh, string s)
{

	if (llh == nullptr)
		{
			LLnode * LLptr = new LLnode;
			LLptr -> fwdptr = nullptr;
			LLptr -> theData = s;
			llh = LLptr;
		}
	else
	{
		LLnode * LLptr = new LLnode;
		LLptr -> theData = s;
		LLnode * temp = llh;
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
int list_length (LLnode * llh)
{

	int counter = 0;
    LLnode * curr = llh;

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
string retrieve_front (LLnode * llh)
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



string retrieve_back (LLnode * llh)
{
	LLnode * curr = llh;
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

void display_nodes (LLnode * llh)
{
	LLnode * curr = llh;
	int counter = 0;

	if (llh == nullptr)
	{
		cout << " Sorry, this linked list is empty. ";

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

