/*=====================================================
*
*	Author: Moses
*	Filename: 
*	Description: 
*	Created:17 Feb 2017
*
*======================================================*/

#include <iostream>
#include <sstream>
#include <string.h>
#include <stdio.h>
#include <cstdlib>

#include <ctype.h>

using namespace std;

int readInt(string);
double readDouble(string);
float readFloat(string);
char readChar(string);
bool readBoolean(string);

int main ()
{
	readBoolean("Please enter an Integer: ");
}


int readInt(string prompt)
{
	cout << prompt;
	char enter[32];
	int i = 0;
	bool numOnly = false;
	while (numOnly == false)
	{
		cin >> enter;
		while (enter[i] != '\0')
		{
			if (isdigit(enter[i]) == false)
				break;
			else
				i++;
		}
		if (isdigit(enter[i]) == false && enter[i] != '\0')
		{
			cout << "Please Enter a Valid Integer: ";
		}
		else
			numOnly = true;
	}
	int value;
	value = atoi(enter);
//	cout << value;
	return value;
}

double readDouble(string prompt)
{
	cout << prompt;
	char enter[32];
	double value = 0;
	bool numOnly = false;
	int i =0;
	while (numOnly == false)
	{
		cin >> enter;
		while (enter[i] != '\0')
		{
			if (isdigit(enter[i]) == true || enter[i] == '.')
				i++;
			else
				break;
		}
		if (isdigit(enter[i]) == false && enter[i] != '\0')
		{
			cout << "Please Enter a Valid Number: ";
		}
		else
		numOnly = true;
	}
	value = atof(enter);
//	cout << value;
	return value;
}

float readFloat(string prompt)
{
	cout << prompt;
	char enter[32];
	char* pEnd;
	float value = 0;
	bool numOnly = false;
	int i =0;
	while (numOnly == false)
	{
		cin >> enter;
		while (enter[i] != '\0')
		{
			if (isdigit(enter[i]) == true || enter[i] == '.')
				i++;
			else
				break;
		}
		if (isdigit(enter[i]) == false && enter[i] != '\0')
		{
			cout << "Please Enter a Valid Number: ";
		}
		else
		numOnly = true;
	}
	value = strtof(enter, &pEnd);
//	cout << value;
	return value;
}

char readChar(string prompt)
{
	cout << prompt;
	char enter[32];
	bool charOnly = false;
	while (charOnly == false)
	{
		cin >> enter;
		if (enter[1] != '\0')
		{
			charOnly =false;
			cout << "Please Enter a Valid Character: ";
		}
		else
			charOnly = true;
	}
	char value;
	value = enter [0];
//	cout << value;
	return value;
}

bool readBoolean(string prompt)
{
	cout << prompt;
	char enter[32];
	bool value;
	bool boolOnly = false;
	while (boolOnly == false)
	{
		cin >> enter;
		if (strcasecmp(enter,"yes") == 0 || strcasecmp(enter,"y") == 0)
		{
			value = true;
			boolOnly = true;
		}
		else if (strcasecmp(enter,"no") == 0 || strcasecmp(enter,"n") == 0)
		{
			value = false;
			boolOnly = true;
		}
		else
			cout << "Please Enter a Valid Option(Y/N): ";
	}
//	cout << value;
	return value;

}
