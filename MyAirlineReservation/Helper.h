#pragma once
#include "pch.h"
#include<string>
#include <sstream>
#include<iostream>
#include<vector>
#include <string.h>
#include <ctime>
#include <iostream>

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
		//static Member functions
		static bool checkValidTime(string time)
		{ // check the validity of the time (must be xx:xx, where x = Natural number)
			// enter ONLY if string is NOT empty
			if (!time.empty()) {
				for (int i = 0; i < time.length(); i++) {
					if (i == 2) {
						if (time.at(i) != ':') {
							cout << "1";
							return false;
						}

					}
					else if (!(time.at(i) >= '0' && time.at(i) <= '9')) {
						cout << "2";
						return false;
					}
				}
				//cout << "3";
				return true;
			}
			else {
				cout << "4";
				return false;
			}
	    }
			
		    static bool checkTime(string inputstring)
		    {
				vector<string> time;
				char hour1[3], min1[3];
				string hourstring,minutestring;
				int hour, minute;
				for (int i = 0; i <=inputstring.size(); i++) {
					if (i < 2) {
						hour1[i] = inputstring[i];
					}
					else if (i ==3) {
						min1[0] = inputstring[i];
					}
					else if (i == 4) {
						min1[1] = inputstring[i];
					}
				}
				hour1[2] = '\0';
				min1[2] = '\0';
			//	cout << "Hourchar"<<hour1<< endl;
			//	cout << "minchar" << min1 << endl;

				hourstring = hour1;
				minutestring = min1;
			//	cout << "Hourstring" << hourstring << endl;
			//	cout << "minstring" << minutestring << endl;
				time.push_back(hourstring);
				time.push_back(minutestring);
				hour = atoi(time[0].c_str());
				minute= atoi(time[1].c_str());
			//	cout << "Hourint" << hour << endl;
			//	cout << "minstint" << minute << endl;
				
				if ((hour >= 0 && hour <= 23) && (minute >= 0 && minute <= 59)) {
					return true;
				}
				return false;
			}
			static string appendAMandPM(string inputstring) {
				string appendstring;
				vector<string> time;
				char hour1[3], min1[3];
				string hourstring, minutestring;
				int hour, minute;
				for (int i = 0; i <= inputstring.size(); i++) {
					if (i < 2) {
						hour1[i] = inputstring[i];
					}
					else if (i == 3) {
						min1[0] = inputstring[i];
					}
					else if (i == 4) {
						min1[1] = inputstring[i];
					}
				}
				hour1[2] = '\0';
				min1[2] = '\0';
				//	cout << "Hourchar"<<hour1<< endl;
				//	cout << "minchar" << min1 << endl;

				hourstring = hour1;
				minutestring = min1;
				//	cout << "Hourstring" << hourstring << endl;
				//	cout << "minstring" << minutestring << endl;
				time.push_back(hourstring);
				time.push_back(minutestring);
				hour = atoi(time[0].c_str());
				minute = atoi(time[1].c_str());
				//	cout << "Hourint" << hour << endl;
				//	cout << "minstint" << minute << endl;
			
				if ((hour >=0 && hour < 12) && (minute >=0 && minute <= 59)) {
					appendstring = " am";
				}
				else if ((hour >= 12 && hour < 24) && (minute >=0 && minute <= 59)){
					appendstring = " pm";
				}
				
				if ((hour == 0) && (minute == 0)) {
					appendstring = " midnight";
				}
				else if ((hour == 12) and (minute == 0)) {
					appendstring = " noon";
				}
				return appendstring;
			}
			static int getIntegerInput() {
				int number;
				// get user's input
			    cin >> number;
				/*if (!isdigit(number)) {
					cout << "Please insert a valid number!" << endl;
					goto IntegerLoop;
				}*/
				return number;
			}
			static string getString() {
				string inputString,returnstring;
				// get user's input
				cin.clear();
				cin.ignore(INT_MAX, '\n');
				//getline(cin, inputString);
				cin >> inputString;
				/*
				for (auto& mychar : inputString)
					if (!isalpha((unsigned char)mychar)) {
						cout << "Please insert a valid string!" << endl;
						goto stringloop;
					}*/
				returnstring = inputString;
				return returnstring;
			}
			static string getTime() {
				string TimeString,appendstring,returnstring;
				//cin.clear();
				cin.ignore(INT_MAX, '\n');
				//LoopTime:getline(cin, TimeString);
			LoopTime:   cin >> TimeString;
				if (TimeString.length() != 5 || !checkValidTime(TimeString)) {
					cout << "Please insert a valid boarding time (e.g. 07:30)! "<<endl;
					goto LoopTime;
				}
				if (!checkTime(TimeString)) {
					cout << "Please insert a valid boarding time (e.g. 07:30)! " << endl;
					goto LoopTime;
				}
				//InputTime = convertStringToTime(TimeString);
				appendstring = appendAMandPM(TimeString);
				cout << "Appendstring" << appendstring << endl;
				returnstring = TimeString + appendstring;
				return returnstring;
			}
			static string getDate() {
				string dateString;
				//string date;
				//string month;
				//string year;
				//std::cin >> date; // read the day
				//if (std::cin.get() != '/') // make sure there is a slash between DD and MM
				//{
				//	std::cout << "expected /\n";
				//	return 1;
				//}
				//std::cin >> month; // read the month
				//if (std::cin.get() != '/') // make sure there is a slash between MM and YYYY
				//{
				//	std::cout << "expected /\n";
				//	return 1;
				//}
				//std::cin >> year; // read the year
				//dateString = date + "/" + month + "/" + year;
				//std::cout << "input date: " << date << "/" << month << "/" << year << ":" << dateString << endl;
				cin.clear();
				cin.ignore(INT_MAX, '\n');
				getline(cin, dateString);
				return dateString;
			}

			//Keeping below code to remember my learnings
			//static Time convertStringToTime(string timestring) 
			//{

			//	/* --Check for arrival, departure time validity (USED ONLY IN BOARDING & ARRIVING TIME)-- */
			//	vector<string> TimeArray; // stores, splitted,  user input to be checked
			//	char* splitstring;// stores result of function strtok() 
			//	Time T;

			//	//char* t_temp = new char[timestring.length()];

			//	//strcpy(t_temp,timestring.c_str());

			//	////split string
			//	//splitstring = strtok(t_temp, ":");

			//	//delete[] t_temp;

			//	//while (splitstring != NULL) {
			//	//	TimeArray.push_back(splitstring);
			//	//	splitstring = strtok(NULL, ":");
			//	//}


			//	//// declaring character array 
			//	char *str= new char[timestring.length() + 1];;

			//	// copying the contents of the  
			//	// string to char array 
			//	strcpy(str, timestring.c_str());
			//	
			//	const char *delim = ":";
			//	char *next_token, *token;
			//	printf("Parsing the input string '%s'\n", str);
			//	token = strtok_s(str, delim, &next_token);
			//	while (token) {
			//		puts(token);
			//		TimeArray.push_back(token);
			//		token = strtok_s(NULL, delim, &next_token);
			//	}

			//	T.hour = atoi(TimeArray[0].c_str()); // stores hour
			//	T.min = atoi(TimeArray[1].c_str()); // store minutes
			//	return T;
			//}


			//static Time getTime() {
			//	string TimeString;
			//	//const char *time_details = "16:35:12";
			//	//struct tm tm;
			//	//strptime(time_details, "%H:%M:%S", &tm);
			//	//time_t t = mktime(&tm);  // t is now your desired time_t
			//	getline(cin, TimeString);
			//}

		
	};

}