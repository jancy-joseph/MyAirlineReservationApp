#pragma once
#include <iostream>
#include <list>


using namespace std;

namespace MyAirlineReservationApp {

	class Passenger
	{
		public:
		//constructor
		Passenger() = default;
		int getmNoOfSeatstoBeReserved();
		void setmNoOfSeatstoBeReserved(int NoOfSeats);
		int getmPassportNo();
		void setmPassportNo(int PassportNumber);
		void setmFlightNo(int FlightNum);
		list<int> getmFlightNo();
		string getmFullName();
		void setmFullName(string FullName);

	   // Member Functions() 
		/*
		static bool validatePassport(int PassportNo);
		static bool displayPassengerInformation(int PassportNo);
		int getPassport();
		string getFirstName();
		string getLastName();
		
		const string& getFullName() const;
		*/
		// Access specifier 
		
	private:
		/*std::string mFirstName;
		std::string mLastName;*/
		string mFullName;
		int mNoOfSeatstoBeReserved;
		int mPassportNo;
		int mFlightNo;
		/*std::string mNationality;
		std::string mAddress;

		int mTelephoneNumber;*/
		list<int> FlightsPassengerBooked;		
	};
}

