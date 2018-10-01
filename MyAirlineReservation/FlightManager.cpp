#include "pch.h"
#include<iostream>
#include <stdexcept>
#include<iomanip> //setw function
#include "FlightManager.h"
#include "Helper.h"
#include <list>
#include <algorithm>
#include <iterator>
#include <iostream>

#define _CRT_SECURE_NO_WARNINGS 1 
#define _WINSOCK_DEPRECATED_NO_WARNINGS 1 

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

	bool FlightManager::ValidateIfPassengerExists(int passportNo)
	{
		for (auto& thePassenger : mPassengers) {
			if (thePassenger.getmPassportNo() == passportNo)
			{
				return true;
			}
		}
		return false;
	}
	
	FlightDetails& FlightManager::addFlightDetails(int FlightNumber) {
		FlightDetails theFlight;//constructor called and Flightnumber set
		theFlight.setFlightNo(FlightNumber);
			
		cout << "Enter Source : " << endl;
		string sourceAirport = Helper::getString();
		theFlight.setSourceAirportName(sourceAirport);
				
		cout << "Enter Destination: " << endl;
		string destinationAirport = Helper::getDate();
		theFlight.setDestiantionAirportName(destinationAirport);

		cout << "Enter the No of Stops in this Flight:" << endl;
		int noOfStops = Helper::getIntegerInput();
		theFlight.setNoOfStops(noOfStops);
			
		/*cout << "Enter Date Flight is running:(e.g 01/06/2018)" << endl;
		string travelDate = Helper::getDate();
		theFlight.setTravelDate(travelDate);
*/
		
		cout << "Enter the Total No of seats: " << endl;
		int totalNoOfSeats = Helper::getIntegerInput();
		theFlight.setTotalNoofSeats(totalNoOfSeats);

	loop:	cout << "Enter the No of Seats Available for booking: " << endl; 
		int ReservableSeats = Helper::getIntegerInput();
		if (ReservableSeats >= totalNoOfSeats) {
			cout << "Reservable seats cant be more than or equal to total no of seats.Check your data! " << endl;
			goto loop;
		}
		theFlight.setNoOfReservableSeatsAvailable(ReservableSeats);
		cout << "Enter The Departing Time:" << endl;
		
		/* --DEPARTURE TIME-- */
		cout << "Departing time (e.g. 19:40): "; //ask from user for the boarding time
		string departingTime = Helper::getTime();
		theFlight.setDepartingTime(departingTime);
		
		/* --ARRIVAL TIME-- */
		cout << "Arrival time (e.g. 19:40): "; //ask from user for the boarding time
		string arrivalTime = Helper::getTime();
		theFlight.SetArrivalTime(arrivalTime);

		cout << "Enter ticket Price : " << endl;
		int ticketPrice = Helper::getIntegerInput();
		theFlight.setFlightCost(ticketPrice);

		cout << "Enter the Flight Name: " << endl;
		string flightName = Helper::getString();
		theFlight.setFlightName(flightName);
		
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
		//cout << left << setw(10) << "FLIGHT" << left << setw(10) << "SEATS" << left << setw(10) << "BOOKED" << left << setw(10) << "DEPARTURE TIME"<<endl;
		//cout << left << setw(10) << "FLIGHT" << left << setw(10) << "NAME" << left << setw(10) << "SOURCE" << left << setw(10) << "DESTINATION" << left << setw(10) << "DEPARTURE" << left << setw(10) << "ARRIVAL" << left << setw(10) << "DATE" << left << setw(14) << "STOPS" << left << setw(10) << "TOTAL" << left << setw(10) << "SEATS" << left << setw(10) << "PRICE" << endl;
		cout << left << setw(10) << "FLIGHT" << left << setw(10) << "NAME" << left << setw(10) << "SOURCE" << left << setw(10) << "DESTINATION" << left << setw(10) << "DEPARTURE" << left << setw(10) << "ARRIVAL" << left << setw(10) << "STOPS" << left << setw(10) << "TOTAL" << left << setw(10) << "SEATS" << left << setw(10) << "PRICE" << endl;

		for (const auto& flight : mFlights) {
			flight.displayFlightInformation();
		}
	}

	bool FlightManager::ValidateIfSeatsAvailable(int FlightNumber, int noOfSeats)
	{
		for (auto& Flight : mFlights) {
			if ((Flight.getFlightNo() == FlightNumber)&& (noOfSeats <=Flight.getNoOfReservableSeatsAvailable()))
			{
				return true;
			}
		}
		return false;
	}


	Passenger & FlightManager::addPassengerDetails(int FlightNumber,int noOfSeats)
	{
		bool booked_result;
		// TODO: insert return statement here
		Passenger thePassenger;//constructor called and Flightnumber set
		thePassenger.setmNoOfSeatstoBeReserved(noOfSeats);
		cout << "Enter your Passport Number : " << endl;
		int passportNo = Helper::getIntegerInput();
		thePassenger.setmPassportNo(passportNo);
		thePassenger.setmFlightNo(FlightNumber);
		cout << "Enter your Full name : " << endl;
		string passengerName = Helper::getString();
		thePassenger.setmFullName(passengerName);
		booked_result = BookPassengerFlight(FlightNumber, noOfSeats);
		if (booked_result) {
			mPassengers.push_back(thePassenger);
		}
		return mPassengers[mPassengers.size() - 1];
	}
	
	void FlightManager::displayPassengerInformation(int Passportnumber) 
	{
		for (auto& thePassenger : mPassengers) {
			if (thePassenger.getmPassportNo() == Passportnumber) {

				cout << "\n\t\t\t\t PASSENGER INFO" << endl << endl;
				cout << left << setw(10) << "NAME" << left << setw(10) << "PASSPORT_No" << left << setw(10) << endl;
				cout << left << setw(10) << thePassenger.getmFullName() << left << setw(10) << thePassenger.getmPassportNo() << endl;
				//cout << left << setw(15) << "NAME" << left << setw(15) << "SURNAME" << left << setw(15) << "PASSPORT_No" << left << setw(15) << "NATIONALLITY" << left << setw(15) << "ADDRESS" << left << setw(15) << "TELEPHONE" << endl;

				//cout << left << setw(15) << i->name << left << setw(15) << i->surname << left << setw(15) << i->passportNo << left << setw(15) << i->nationallity << left << setw(15) << i->address << left << setw(15) << i->tel << endl << endl;
				cout << "Your flight(s): ";


				for (auto& flights : thePassenger.getmFlightNo()) {

					cout << flights;
				}
				//// std::copy copies items using iterators.
				////     The first two define the source iterators [begin,end). In this case from the list.
				////     The last iterator defines the destination where the data will be copied too
				//std::copy(std::begin(thePassenger.getmFlightNo()), std::end(thePassenger.getmFlightNo()),

				//	// In this case the destination iterator is a fancy output iterator
				//	// It treats a stream (in this case std::cout) as a place it can put values
				//	// So you effectively copy stuff to the output stream.
				//	std::ostream_iterator<int>(std::cout, " "));

				////for (std::list<int>::iterator i2 = (thePassenger.getmFlightNo()).begin(); i2 != (thePassenger.getmFlightNo()).end(); ++i2) {

				////	cout << *i2 << "  ";
				////}

				cout << endl;
			}
		}


	}

	void FlightManager::displayPassengerTicketInformation(int Passportnumber){
		for (auto& thePassenger : mPassengers) {
			if (thePassenger.getmPassportNo() == Passportnumber) {
				for (auto& pflights : thePassenger.getmFlightNo()) { //list
					for (auto& Flight : mFlights) {
						if ((Flight.getFlightNo() == pflights)) {
							cout << "\n\t\t\t\t PASSENGER TICKET INFO" << endl << endl;
							cout << left << setw(10) << "NAME" << left << setw(10) << "PASSPORT_No" << left << setw(10) << "PRICE"<<endl;
							cout << left << setw(10) << thePassenger.getmFullName() << left << setw(10) << thePassenger.getmPassportNo() <<left << setw(10)<< Flight.getFlightCost()<< endl;
							//cout << left << setw(15) << "NAME" << left << setw(15) << "SURNAME" << left << setw(15) << "PASSPORT_No" << left << setw(15) << "NATIONALLITY" << left << setw(15) << "ADDRESS" << left << setw(15) << "TELEPHONE" << endl;

							//cout << left << setw(15) << i->name << left << setw(15) << i->surname << left << setw(15) << i->passportNo << left << setw(15) << i->nationallity << left << setw(15) << i->address << left << setw(15) << i->tel << endl << endl;
						  
						}

					}
				}
			}
		}


	}

	void FlightManager::displayFlightInformation(int FlightNo)
	{
		for (auto& Flight : mFlights) {
			if ((Flight.getFlightNo() == FlightNo)) {
				cout << "\n\t\t\t\t FLIGHT SCHEDULE" << endl << endl;
				cout << left << setw(10) << "FLIGHT" << left << setw(10) << "NAME" << left << setw(10) << "SOURCE" << left << setw(10) << "DESTINATION" << left << setw(10) << "DEPARTURE" << left << setw(10) << "ARRIVAL" << left << setw(10) << "STOPS" << left << setw(10) << "TOTAL" << left << setw(10) << "SEATS" << left << setw(10) << "PRICE" << endl;

			//	cout << left << setw(10) << "FLIGHT NO" << left << setw(10) << "FLIGHT NAME" << left << setw(10) << "SOURCE" << left << setw(10) << "DESTINATION" << left << setw(10) << "DEPARTURE"<< left << setw(10) << "ARRIVAL" << left << setw(10) << "DATE" << left << setw(10) << "NO-OF-STOPS" << left << setw(10) << "TOTAL SEATS" << left << setw(10) << "SEATS LEFT" << left << setw(10) << "TICKET PRICE" << endl;

				//cout << left << setw(10) << "FLIGHT" << left << setw(10) << "SEATS" << left << setw(10) << "BOOKED" << left << setw(10) << "DEPARTURE TIME" << endl;
				Flight.displayFlightInformation();
			}
		}
	}

	bool FlightManager::BookPassengerFlight(int FlightNumber, int noOfSeats)
	{
		for (auto& Flight : mFlights) {
			if ((Flight.getFlightNo() == FlightNumber))
			{
				int reduced_noOfSeats = (Flight.getNoOfReservableSeatsAvailable()) - noOfSeats;
				Flight.setNoOfReservableSeatsAvailable(reduced_noOfSeats);
				return true;
			}
		
		}
		return false;
	}
		

}