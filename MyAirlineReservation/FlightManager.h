#pragma once
#include "pch.h"
#include <iostream>
#include<vector>
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
		//No destructor needed as we instructed compiler to create default constructor
		//FlightManager();
	private:
		vector<FlightDetails> mFlights;
	};
}