#pragma once

#include <iostream>

using namespace std;

namespace inputslib
{
	int readnumber(string ask)
	{
		int number = 0;
		cout << ask << endl;
		cin >> number;
		
		
		
		while (cin.fail())
		{
			cin.clear();
			cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			cout << "Wrong Index, Enter A valid One\n";
			cin >> number;


		}
		
		


		

		return number;

	}
	int read_PositiveNumber(string ask)
	{
		int number;
		do {
			cout << ask << endl;
			cin >> number;
			
			while (cin.fail())
			{
				cin.clear();
				cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
				cout << "Wrong Index, Enter A valid One\n";
				cin >> number;


			}
			
			
			
			


			
		} while (number <= 0);
		return number;
	}
	string readstring(string ask)
	{
		string word = "";


		cout << ask;
		cin >> word;
		return word;
	}
	float readfloat(string ask)
	{
		float number;
		do {
			cout << ask << endl;
			cin >> number;
			while (cin.fail())
			{
				cin.clear();
				cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
				cout << "Wrong Index, Enter A valid One\n";
				cin >> number;


			}
		} while (number <= 0);
		return number;
	}
	void addelement(int array[100], int &arraylength , int number)
	{
		arraylength++;
		array[arraylength - 1] = number;

	}

	int readumber_FromTO(int from, int to)
	{
		int number = 0;
		do
		{
			cout << "Enter A Number From " << from << " To " << to << endl;
			cin >> number;
			while (cin.fail())
			{
				cin.clear();
				cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
				cout << "Wrong Index, Enter A valid One\n";
				cin >> number;


			}
		} while (number < from || number >to);

return number;
	}

	
}
