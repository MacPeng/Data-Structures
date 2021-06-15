//============================================================================
// Name        : PengA02PA3.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;

int fact(int n);

int fib(int n);

bool isPrime (int n, int d);
void prime(int n);

int mult(int n1, int n2);

string reverseString(string s);

int countOccurrences(string s1, string s2);
int counterHelper(string s1, string s2, int counter);

int main() {
	// factorial
		int count;
		int f=5;
		cout << "factorial of " << f << " is " << fact(f) << endl << endl;
	// Fibonocci
		for (count=0;count < 10;count++)
		{
			cout << "Fibonocci sequence number " << count+1 << " is " << fib(count+1) << endl;
		}
	// primes
    	prime (10);
	// multiplication
		int a=6, b=5;
		cout << endl << "product of " << a << " and " << b << " is " << mult(a,b) << endl << endl;
	// string reversal
		string s = "abcde";
		cout << "original string " << s << " reversed string " << reverseString(s) << endl << endl;
	// character counting
		string t="a";
		cout << "number of occurrences of " << t[0] << " in " << s << " is " << countOccurrences(s,t) << endl;

	    return 0;
}


int fact(int n)
{
	if(n == 0 || n == 1)
	{
		return 1;
	}
	else
	{
		return fact(n-1)*n;
	}
}
int fib(int n)
{
	if(n == 1)
	{
		return 0;
	}
	else if(n == 2)
	{
		return 1;
	}
	else
	{
		return fib(n-2) + fib(n-1);
	}
}


//make a helper for prime

void prime(int n)
{
  int i = 0;
  int counter = 0;
  while(counter != n)
  {
	  if(isPrime(i,2))
	  {
		  cout << i << endl;
		  counter++;
	  }
	  i++;
  }

}
bool isPrime (int n, int d)
{
	if(n == 0 || n == 1)
	{
		return false;
	}
	if(d == n)
	{
		return true;
	}
	if(n % d == 0)
	{
		return false;
	}
	return isPrime(n, d+1);
}

//use for loop to check if the number is prime and then increment the counter
int mult(int n1, int n2)
{
	if(n2 == 0)
	{
		return 0;
	}
	else
	{
		return mult(n1, n2-1) + n1;
	}
}
string reverseString(string s)
{
	if(s.length() <= 1)
	{
		return s;
	}
	else
	{
		int len = s.length();
		return s.back() + reverseString(s.substr(0, len-1));
	}
}


//helper function
int countOccurrences(string s1, string s2)
{
	return counterHelper(s1,s2,0);
}

int counterHelper(string s1, string s2, int counter)
{
	if(s1.length() == 0)
	{
		return counter;
	}
	if(s1.substr(0,1) == s2)
	{
		counter++;
	}
	return counterHelper(s1.substr(1), s2, counter);
}


