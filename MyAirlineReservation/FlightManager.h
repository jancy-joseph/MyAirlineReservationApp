#pragma once
#include "pch.h"
#include <iostream>
#include <vector>
#include "FlightDetails.h"
using namespace std;

using std::vector;



namespace MyAirlineReservationApp {
	class FlightManager {
	public:
		//constructor
		FlightManager() = default;
		FlightDetails& addFlightDetails(int FlightNumber);
		FlightDetails& getFlightDetails(int FlightNumber);
		void DisplayFlightsSchedule()const;
		//void DisplayCurrent() const;	
		//void DisplayFormer() const;
		bool ValidateIfFlightExists(int FlightNumber);
		bool ValidateIfPassengerExists(int passportNo);

		bool ValidateIfSeatsAvailable(int FlightNumber,int noOfSeats);
		Passenger& addPassengerDetails(int FlightNumber,int noOfseats);
		void displayPassengerInformation(int Passportnumber);
		void displayFlightInformation(int FlightNo);
		bool BookPassengerFlight(int  FlightNumber, int noOfSeats);

		//No destructor needed as we instructed compiler to create default constructor
		//FlightManager();
	private:
		vector<FlightDetails> mFlights;
		vector<FlightReservationQueue> mReservationQueues;
		vector<Passenger> mPassengers;
		
	};
}