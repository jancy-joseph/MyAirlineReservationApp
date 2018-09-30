#include <iostream>
#include "pch.h"
#include "Passenger.h"
#include <string>
using namespace std;

namespace MyAirlineReservationApp{
	int Passenger::getmNoOfSeatstoBeReserved()
	{
		return 	mNoOfSeatstoBeReserved;
	}
	void Passenger::setmNoOfSeatstoBeReserved(int NoOfSeats)
	{
		mNoOfSeatstoBeReserved = NoOfSeats;
		
	}
	int Passenger::getmPassportNo()
	{
		return mPassportNo;
	}
	void Passenger::setmPassportNo(int PassportNumber)
	{
		mPassportNo = PassportNumber;
	}
	 void Passenger::setmFlightNo(int FlightNum)
	{
		 FlightsPassengerBooked.push_back(FlightNum);
		 mFlightNo = FlightNum;//this variable not needed just keeping to test will remove later
	}
	list<int> Passenger::getmFlightNo()
	{
		return FlightsPassengerBooked;
	}

	string Passenger::getmFullName()
	{
		return mFullName;
	}

	void Passenger::setmFullName(string FullName)
	{ 
		mFullName = FullName;
	}
	
	//Intialize constructor
	/*Passenger::Passenger(void) 
	{
			cout << "Constructor for Passenger is invoked" << endl;
	}
	const string& Passenger::getFullName() const {
		return;
	}*/
//implement the passenger member functions 
	/*void Passenger::setPassengerDetails(const std::string fullname, float weight, int height) {
		mFullname = fullname;
		mWeight = weight;
		mHeight = height;
	}
	std::string& Passenger::getPassengerFullname(){
		return mFullname;
	}
	float& Passenger::getWeight() {
		return mWeight;
	}
	int& Passenger::getHeight() {
		return mHeight;
	}
	void Passenger::display() {
		cout << "Passenger Weight" << getWeight() << endl;
		cout << "Passenger Height" << getHeight() << endl;
		cout << "Passenger Name" << getPassengerFullname() << endl;
		}
		*/
			
}
