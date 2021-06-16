//============================================================================
// Name        : pengA02pa7.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <fstream>
#include <vector>
#include <ctime>
using namespace std;

struct EmpData{
	int ssn;
	string firstName, lastName;
	vector <EmpData*> chain;
};


int HashFunc(EmpData data);
int readWrite(string filename);
void displayChain(vector<EmpData*> sd);
int SSNKey(int data);
int generateHash(int ssn);
void printHashTable(EmpData table[]);
bool readData (string FileName, vector <string> & names, vector <string> & ids);
EmpData createEmployee(string name, int id );
const int SIZE = 101;

//main starts
int main() {
	EmpData arr[SIZE];

	for(int i = 0; i < SIZE; i++) {
		arr[i].ssn = 0;
	}
	EmpData EmpTemp;
	int key;
	bool readFlag;
	string fileName = "./src/x";
	vector <string> ids ,names;
	int error = readWrite(fileName);

	if (error == -1)
	{
		cout << "Error.Couldn't open or create a file.\n";
		return 0;
	}

	readFlag = readData(fileName, names, ids);
	if (readFlag == false)
	{
		cout << "Error.Couldn't read what is in the file.\n";
		return 0;
	}

	EmpData* p;

	for (unsigned int i = 0; i < names.size(); i++)
	{
		EmpTemp = createEmployee(names[i], stoi(ids[i]));
		key = HashFunc(EmpTemp);
		if (arr[key].ssn != 0)
		{
			p = new EmpData;
			*p = EmpTemp;
			(arr[key].chain).push_back(p);
		}
		else
			arr[key]= EmpTemp;

		}

	delete p;

	int findSSN = -1;

	ifstream file("x");
	string ssn, firstName, lastname;




			printHashTable(arr);
////		cout << ssn <<endl;
////		stoi(ssn);
////		cout << firstName + lastname<<ssn<<endl;
//	}



	do{
		cout << "Enter employee SSN\n";
		cin >> findSSN;
		while(findSSN < 0) // 1st case
		{
			cout << "Error please enter a value equal to or greater than 0. "<< endl;
			cin >> findSSN;
		}
		if (findSSN == 0) // second case
		{
			cout << "Thank you, have a nice day.";
			break;
		}
		key = SSNKey(findSSN);
		if (arr[key].ssn == findSSN)
			cout << "This is "<< arr[key].firstName << " " << arr[key].lastName << endl;
		else if(!arr[key].chain.empty())
			for (unsigned int j= 0; j < arr[key].chain.size() ; j++)
			{
				if (arr[key].chain[j]->ssn == findSSN)
				{
					cout << "Name: "<< arr[key].chain[j]->firstName << " "<< arr[key].chain[j]->lastName << endl;
					break;
				}
			}
		else
			cout << "Sorry. This SSN is not in the data base\n";
		    //break;

	  }
	while (findSSN != 0);
	return 0;
}
//main ends

int SSNKey(int data)
{
	string s = to_string(data);
	int ascii = 0;
	for(unsigned int i = 0; i < s.length(); i++)
	{
		ascii += s[i];
	}
	ascii = ascii*(data % 23);
	return ascii % SIZE;
}
int HashFunc( EmpData data)
{
	return SSNKey(data.ssn);
}


EmpData createEmployee(string name, int id)
{
	EmpData ed;
	int spot = name.find(" ");
	ed.firstName = name.substr(0, spot);
	ed.lastName = name.substr(spot+1, name.size());
	ed.ssn = id;
	return ed;
}

void displayChain(vector <EmpData*> sb)
{
	cout << "There is " << sb.size() << " chains.";
	for (unsigned int i= 0; i < sb.size() ; i++)
	{
		cout << "\nChained Name: "<< sb[i]->firstName << " "<< sb[i]->lastName << "\tChained SSN: "<<sb[i]->ssn ;
	}
	cout << endl;
}

bool readData (string FileName, vector <string> & names, vector <string> & ids)
{
	fstream f;
	string name, id;
	f.open(FileName);
	if(!f)
	{
		cout << "Sorry. Can't open file! \n";
		return false;
	}
	while (getline(f,name) and getline(f,id))
	{
		names.push_back(name);
		ids.push_back(id);
	}
	f.close();
	return true;
}

void printHashTable(EmpData table[])
{
	for (int i = 0; i < SIZE; i++)
		{
			cout << "The " << i << "th Employee: \n";
			cout << "Name " << table[i].firstName << " " << table[i].lastName << endl;
			cout << "Social " << table[i].ssn << endl;
			cout << "Is it chained? ";
			if(table[i].chain.empty())
				cout << "No. \n";
			else
			{
				cout << "Yes: ";
				displayChain(table[i].chain);
			}
			cout << "*********************************\n\n";
		}
}


int readWrite(string filename)
{
    fstream f;
    int random;
    string names = "vauivbcuibviqrvbbvchrvuqivqovqvvqcrbvcbqvybqbfuoeiabi";
    const int amount = 100, word = 10, ssnLength = 9;
    srand(time(0));
    f.open(filename);
    if (!f.is_open())
    {
        cout << filename << " not found." << endl;
        f.open(filename, ios::out|ios::in|ios::trunc);
        if (!f.is_open())
        {
           cout << "Error creating file " << filename << "!!!" << endl;

            return -1;
        }
    	for (int i = 0; i < amount; i++ )
    	{
    		for (int j = 0; j < word; j++)
    		{
    			random = rand() % names.size() + 1;
    			f<< names[random];
    			if (j == word/2)
    				f << " ";
    		}
    		f << endl;
    		for (int k = 0; k < ssnLength; k++)
    		{
    			f << to_string(rand() % 9 + 1);
    		}
    		f << endl;
    	}

    }
    else //File already exists
    {
    	for (int i = 0; i < amount; i++ )
    	{
    		for (int j = 0; j < word; j++)
    		{
    			if (j == word/2)
    				f << " ";
    			random = rand() % names.size() + 1;
    			f<< names[random];
    		}
    		f << endl;
    		for (int k = 0; k < ssnLength; k++)
    		{
    			f << to_string(rand() % 9 +1);
    		}
    		f << endl;
    	}

    }
    f.close();
    return 0;
}

inline int generateHash(int ssn) {
	return(ssn%100);
}
