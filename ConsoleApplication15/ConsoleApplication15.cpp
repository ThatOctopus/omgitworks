// ConsoleApplication15.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "DogControl.h"
#include "Search.h"
#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <cstdint>
#include <vector>
using namespace std;

int main()
{
	int i = 1;
	int iColoumn = 0;
	int iRow = 0;
	int iRowCounter = 0;
	int iCSV = 0;
	string sLine;
	string sCell;
	vector<DogControl> v2d;
	do {
		ifstream myfile("dog-control-orders.csv");
		if (myfile.is_open())
		{
			cout << "file is open";
			system("pause");
			while (getline(myfile, sLine, '\n'))
			{
				istringstream ss(sLine);

				while (getline(ss, sCell, ','))
				{
					if (iColoumn == 0)
					{
						DogControl DC;
						v2d.push_back(DC);
					}

					if (iColoumn == 0)
					{
						v2d[iRow].sLabel = sCell;
					}
					if (iColoumn == 1)
					{
						v2d[iRow].sURI = sCell;
					}
					if (iColoumn == 2)
					{
						v2d[iRow].sLocation = sCell;
					}
					if (iColoumn == 3)
					{
						v2d[iRow].sType = sCell;
					}
					if (iColoumn == 4)
					{
						v2d[iRow].sYear = sCell;
					}

					if (iColoumn == 4)
					{
						iColoumn = 0;
						++iRow;
					}
					else {
						++iColoumn;
					}
					cout << sLine << "\n";
				}
			}
			cout << "Ended" << endl;
			search(v2d);
		}
		else
		{
			cout << "File did not open";
			system("pause");
		}
			} while (i = !0);
	return 0;
}

