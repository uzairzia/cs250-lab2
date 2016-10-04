//Name	: Uzair Zia 
//Class	: BESE-6A
//Reg No: 127997
//Date	: 30 / 09 / 2016
//Lab	: 2
//Task	: 2

#include<iostream>
#include<stdlib.h>
#include<time.h>
#include<vector>
#include<algorithm>
using namespace std;

void printVector(vector<int> vectPrint)
{
	for (int i = 0; i < vectPrint.size(); i++)
	{
		cout << vectPrint[i] << " ";
	}
	cout << endl;
}

bool updateTopScores(vector<int> &in, vector<int> &out)
{
	int temp;

	for (int i = in.size() - 1; i > 0; i--)
	{
		for (int j = in.size() - 1; j >= i; j--)
		{
			if (in[j-1] < in[j])
			{
				temp = in[j-1];
				in[j-1] = in[j];
				in[j] = temp;
			}
		}
	}

	for (int k = 0; k < in.size(); k++)
	{
		out.push_back(in[k]);
	}

	return true;
}


bool testUpdateTopScores()
{
	int myArray[10];

	for (int i = 0; i < 10; i++)
	{
		myArray[i] = (rand() % 100) + 1;
	}

	vector<int> myTestVector1(myArray, myArray + sizeof(myArray) / sizeof(myArray[0]));

	cout << endl << endl;

	sort(myTestVector1.begin(), myTestVector1.end());
	reverse(myTestVector1.begin(), myTestVector1.end());
	
	myTestVector1.push_back((rand() % 100) + 1);

	vector<int> myTestVector2(myTestVector1);

	vector<int> mySortedTestVector2;

	sort(myTestVector1.begin(), myTestVector1.end());
	reverse(myTestVector1.begin(), myTestVector1.end());

	updateTopScores(myTestVector2, mySortedTestVector2);
	
	cout << "Sort done by STL sort alogrithm:\t";
	printVector(myTestVector1);

	cout << "Sort done by my own sort function:\t";
	printVector(mySortedTestVector2);

	for (int i = 0; i < mySortedTestVector2.size(); i++)
	{
		if (myTestVector1[i] != mySortedTestVector2[i])
		{
			return false;
		}
	}

	return true;
}

int main()
{
	srand(time(NULL));
	vector<int> topScores = {443,439,438,438,434,418,418,417,413,411};

	cout << "topScores: ";
	printVector(topScores);

	topScores.push_back(444);

	cout << "Unsorted topScores: ";
	printVector(topScores);

	vector<int> sortedTopScores;

	cout << "Sorted topScores: ";
	updateTopScores(topScores, sortedTopScores);
	printVector(topScores);

	if (testUpdateTopScores())
	{
		cout << "Function is working properly.\n";
	}
	else
	{
		cout << "Function is not working properly.\n";
	}
}