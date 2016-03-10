#include "stdafx.h"
#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <cstdint>
#include <vector>
using namespace std;

int search(vector<DogControl> DCHere)
{
	vector<DogControl> SearchResults;
	int i = 0;
	string iYear;
	cout << "Please insert year" << endl << "Year : ";
	cin >> iYear;
	cout << DCHere.size();
	for (int i = 0; i < DCHere.size(); i++)
	{
		if (DCHere[i].sYear == iYear)
		{
			SearchResults.push_back(DCHere[i]);
			cout << DCHere[i].sLocation << " " <<  DCHere[i].sURI << endl;
		}

	}
	return 0;
};