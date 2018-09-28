#pragma once
#include "pch.h"
#include<string>
#include <sstream>
#include<iostream>
using namespace std;

namespace MyAirlineReservationApp {
	struct Time // structure for managing the Arrival and Departing times
	{
		int min;
		int hour;
	};
	
	class Helper {
	public:

		Helper() = default;
		//static Member functions:
		//static bool checkValidTime(string time) 
		//{ // check the validity of the time (must be xx:xx, where x = Natural number)
		//	// enter ONLY if string is NOT empty
		//	if (!time.empty()) {
		//		for (int i = 0; i < time.length(); i++) {
		//			if (i == 2) {
		//				if (time.at(i) != ':') {
		//					return false;
		//				}

		//			}
		//			else if (!(time.at(i) >= '0' && time.at(i) <= '9')) {
		//				return false;
		//			}
		//		}
		//		return true;
		//	}
		//	else {
		//		return false;
		//	}

		//}
		//static Time convertStringToTime(string timestring) {

		//	/* --Check for arrival, departure time validity (USED ONLY IN BOARDING & ARRIVING TIME)-- */
		//	vector<string> TimeArray; // stores, splitted,  user input to be checked
		//	char* splitstring;// stores result of function strtok() 
		//	Time T;
		//	char* t_temp = new char[timestring.length()];

		//	strcpy(t_temp, timestring.c_str());

		//	//split string
		//	splitstring = strtok(t_temp, ":");

		//	delete[] t_temp;

		//	while (splitstring != NULL) {
		//		TimeArray.push_back(splitstring);
		//		splitstring = strtok(NULL, ":");
		//	}

		//	T.hour = atoi(TimeArray[0].c_str()); // stores hour
		//	T.min = atoi(TimeArray[1].c_str()); // store minutes
		//	return T;
		//}
		static int getIntegerInput() {
			int number;
			// get user's input
			IntegerLoop:cin >> number;
			if (!isdigit(number)) {
				cout << "Please insert a valid number!" << endl;
				goto IntegerLoop;
			}
			return number;
		}
		static string getString() {
			string inputString;
			// get user's input
		stringloop:getline(cin, inputString);
		for(auto& mychar: inputString)
			if (!isalpha(mychar)) {
				cout << "Please insert a valid string!" << endl;
				goto stringloop;
			}
			return inputString;
		}
		//static Time getTime() {
		//	Time InputTime;
		//	string TimeString;
		//	// get user's input
		//	LoopTime:getline(cin, TimeString);
		//	if (TimeString.length() != 5 || !checkValidTime(TimeString)) {
		//		cout << "Please insert a valid boarding time (e.g. 07:30)! "<<endl;
		//		goto LoopTime;
		//	}

		//	InputTime = convertStringToTime(TimeString);
		//	return InputTime;
		//}
	};

	};
	

