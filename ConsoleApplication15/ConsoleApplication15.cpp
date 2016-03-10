// ConsoleApplication15.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
//#include "CsvCpp.hpp"
#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <cstdint>
using namespace std;

class DogControl
{
public:
	string sLabel;
	string sURI;
	string sLocation;
	string sType;
	string sYear;

};

int main()
{
	int i = 1;
	string sLine;
	DogControl DC;
	do {
		ifstream myfile("dog-control-orders.csv");
		if (myfile.is_open())
		{
			cout << "file is open";
			system("pause");
			//	
			//myfile >> a >> b >> c >> d >> e;
			//	{
			//	cout << a << b << c << d << e;
			//}
			while (getline(myfile, sLine, ','))
			{
				//cout << "in the while loop";
				cout << sLine;
				istringstream iss(sLine);
				string a;
				if (!(iss >> a))
				{
					cout << "Broken";
					break; 
				}
				cout << a << "\n";
			}
		}
		else
		{
			cout << "File did not open";
			system("pause");
		}
			} while (i = !0);
	return 0;
}

