/*=====================================================
 *
 *	Author: Moses
 *	Filename: Keyboard.h
 *	Description: Keyboard Input Functions
 *	Created:14 June 2017
 *
 *======================================================*/

#include <iostream>
#include <sstream>
#include <string.h>
#include <stdio.h>
#include <cstdlib>
#include <ctime>
#include <ctype.h>
#include <string>

using namespace std;

int readInt(string);
double readDouble(string);
float readFloat(string);
char readChar(string);
bool readBoolean(string);
tm readDate(string);

int main() {
	readDate("Please enter an Integer: ");
}

int readInt(string prompt) {
	cout << prompt;
	char enter[32];
	int i = 0;
	bool numOnly = false;
	while (numOnly == false) {
		cin >> enter;
		while (enter[i] != '\0') {
			if (isdigit(enter[i]) == false)
				break;
			else
				i++;
		}
		if (isdigit(enter[i]) == false && enter[i] != '\0') {
			cout << "Please Enter a Valid Integer: ";
		} else
			numOnly = true;
	}
	int value;
	value = atoi(enter);
//	cout << value;
	return value;
}

double readDouble(string prompt) {
	cout << prompt;
	char enter[32];
	double value = 0;
	bool numOnly = false;
	int i = 0;
	while (numOnly == false) {
		cin >> enter;
		while (enter[i] != '\0') {
			if (isdigit(enter[i]) == true || enter[i] == '.')
				i++;
			else
				break;
		}
		if (isdigit(enter[i]) == false && enter[i] != '\0') {
			cout << "Please Enter a Valid Number: ";
		} else
			numOnly = true;
	}
	value = atof(enter);
//	cout << value;
	return value;
}

float readFloat(string prompt) {
	cout << prompt;
	char enter[32];
	char* pEnd;
	float value = 0;
	bool numOnly = false;
	int i = 0;
	while (numOnly == false) {
		cin >> enter;
		while (enter[i] != '\0') {
			if (isdigit(enter[i]) == true || enter[i] == '.')
				i++;
			else
				break;
		}
		if (isdigit(enter[i]) == false && enter[i] != '\0') {
			cout << "Please Enter a Valid Number: ";
		} else
			numOnly = true;
	}
	value = strtof(enter, &pEnd);
//	cout << value;
	return value;
}

char readChar(string prompt) {
	cout << prompt;
	char enter[32];
	bool charOnly = false;
	while (charOnly == false) {
		cin >> enter;
		if (enter[1] != '\0') {
			charOnly = false;
			cout << "Please Enter a Valid Character: ";
		} else
			charOnly = true;
	}
	char value;
	value = enter[0];
//	cout << value;
	return value;
}

bool readBoolean(string prompt) {
	cout << prompt;
	char enter[32];
	bool value;
	bool boolOnly = false;
	while (boolOnly == false) {
		cin >> enter;
		if (strcasecmp(enter, "yes") == 0 || strcasecmp(enter, "y") == 0) {
			value = true;
			boolOnly = true;
		} else if (strcasecmp(enter, "no") == 0
				|| strcasecmp(enter, "n") == 0) {
			value = false;
			boolOnly = true;
		} else
			cout << "Please Enter a Valid Option(Y/N): ";
	}
//	cout << value;
	return value;
}

tm readDate(string prompt) {
	cout << prompt;
	string month[12] = { "Jan", "Feb", "Mar", "Apr", "May", "Jun", "Jul", "Aug",
			"Sep", "Oct", "Nov", "Dec" };
	char enter[32];
	int day;
	int mon;
	int year;
	struct tm value = { 0 };
	time_t timer;
	time(&timer);
	double seconds;

	// to get the years since 2000
	value.tm_hour = 0;
	value.tm_min = 0;
	value.tm_sec = 0;
	value.tm_year = 100;
	value.tm_mon = 0;
	value.tm_mday = 1;
	seconds = difftime(timer, mktime(&value));
	value.tm_year = (seconds / 60 / 60 / 24 / 365);
	//
	bool dateOnly = false;
	while (dateOnly == false) {
		cin >> enter;
		char * pch;
		pch = strtok(enter, "/-");
			day = atoi(pch);
		value.tm_mday = day;
		pch = strtok(NULL, "/-");
			mon = atoi(pch);
		value.tm_mon = mon - 1;
		pch = strtok(NULL, "/-");
			year = atoi(pch);
		value.tm_year = year;
		pch = strtok(NULL, "/-");
		if (day > 31 || mon > 12 || year > (2000 + value.tm_year)) {
			dateOnly = false;
			cout << "Please Enter A Valid Date (DD/MM/YYYY): ";
		} else
			dateOnly = true;
	}
	cout << day;
	cout << " ";
	cout << month[mon - 1];
	cout << " ";
	cout << year;

	return value;
}

