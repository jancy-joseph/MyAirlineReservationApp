#include "pch.h"
#include<iostream>
#include <stdexcept>
#include<iomanip> //setw function
#include "FlightManager.h"
#include "Helper.h"
using namespace std;


namespace MyAirlineReservationApp {
	//Intialize constructor
	/*FlightManager::FlightManager(void)
	{
		cout << "Constructor for FlightManager is invoked" << endl;
	}*/
	
	bool FlightManager::ValidateIfFlightExists(int FlightNumber) {
		for (auto& Flight : mFlights) {
			if (Flight.getFlightNo() == FlightNumber) {
				return true;
			}
		}
		return false;
	}
	
	FlightDetails& FlightManager::addFlightDetails(int FlightNumber) {
		FlightDetails theFlight;//constructor called and Flightnumber set
		theFlight.setFlightNo(FlightNumber);
		cout << "Enter the Total No of seats: " << endl;
		int totalNoOfSeats = Helper::getIntegerInput();
		theFlight.setTotalNoofSeats(totalNoOfSeats);
		cout << "Enter the No of Seats Available for booking: " << endl; 
		int ReservableSeats = Helper::getIntegerInput();
		theFlight.setNoOfReservableSeatsAvailable(ReservableSeats);
		cout << "Enter the No of Seats Available for booking: " << endl;
		/* --DEPARTURE TIME-- */
		//cout << "Departing time (e.g. 19:40): "; //ask from user for the boarding time
		//Time departingTime = Helper::getTime();
		//theFlight.setDepartingTime(departingTime);
		mFlights.push_back(theFlight);
	    return mFlights[mFlights.size() - 1];
	}
	FlightDetails& FlightManager::getFlightDetails(int FlightNumber){
		for (auto& Flight:mFlights) {
			if (Flight.getFlightNo() == FlightNumber) {
				return Flight;
			}
		}
		throw logic_error("No flight found");
	}
	void FlightManager::DisplayFlightsSchedule()const {
		cout << "\n\t\t\t\t FLIGHT SCHEDULE" << endl << endl;
		cout << left << setw(10) << "FLIGHT" << left << setw(10) << "SEATS" << left << setw(10) << "BOOKED" << endl;
		for (const auto& flight : mFlights) {
			flight.display();
		}
	}
}