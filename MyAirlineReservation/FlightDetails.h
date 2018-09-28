#pragma once
#include <iostream>
#include <list>
#include "Helper.h"
using namespace std;

namespace MyAirlineReservationApp {
	
	class FlightDetails {
		private:
		
			int mFlightNo;
		
			//string mFlightName;
			//int mPrice;
			Time mDeparting_Time;
			/*
			Time mArrival_time;
			string mSourceAirportName;
			string mDestinationAirportName;
			int mNoOfStops;
			*/
			int mNooFSeatsAvailableToReserve;
			int mTotalNoofSeats;
		
		public:
			//constructors:
			FlightDetails() = default;
		
			//member functions
			int getFlightNo() const;
			void setFlightNo(int flightNo);
			
			Time getDepartingTime() const;
			void setDepartingTime(Time departingTime);
		/*
			Time getArrivalTime() const;
			void SetArrivalTime(string& arrivalTiime);
		
			const string& getSourceAirportName() const;
			void setSourceAirportName(string& sourceAirportName);
			const string& getDestiantionAirportName() const;
			void setDestiantionAirportName(string& destinationAirportName);
		
			int getFlightCost() const;
			void setFlightCost(int flightPrice);
			const string& getFlightName() const;
			void setFlightName(string& flightName);

		
			int getNoOfStops() const;
			int setNoOfStops(int noOfStops);
			*/
			int getNoOfReservableSeatsAvailable() const;
			void setNoOfReservableSeatsAvailable(int nooFSeatsAvailable);
			int getTotalNoofSeats() const;
			void setTotalNoofSeats(int totalNoofSeats);
			//static bool CheckforSeatsAvailble(int NoofSeatsToBeBooked);

		
			void display() const;

			/*

			void AddFlightInformation();
			static void displayFlightInformation(int FlightNo);
			static void displayFlightSchedule();
			static void reserveSeat(int FlightNo, int NoOfSeatsToBeBooked);
			static bool ValidateFlightNumber(int FlightNo);
			static bool CheckforSeatsAvailble(int NoofSeatsToBeBooked);
			*/
	};
}