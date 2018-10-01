#pragma once
#include <iostream>
#include <list>
#include "Helper.h"
#include "FlightResQueue.h"
using namespace std;

namespace MyAirlineReservationApp {
	
	class FlightDetails {
		private:
		
			int mFlightNo;
		
			string mFlightName;
			int mPrice;
			string mTraveldate;
			string mDeparting_Time;
			
			string mArrival_time;
			string mSourceAirportName;
			string mDestinationAirportName;
			int mNoOfStops;
			
			int mNooFSeatsAvailableToReserve;
			int mTotalNoofSeats;
			
		public:
			//constructors:
			FlightDetails() = default;
		
			//member functions

			const int getFlightNo() const;
			void setFlightNo(int flightNo);
			


		    const string getDepartingTime() const;
			void setDepartingTime(string departingTime);
		
			const string getArrivalTime() const ;
			void SetArrivalTime(string arrivalTiime);
		
			const string getSourceAirportName() const;
			void setSourceAirportName(string sourceAirportName);

			const string getDestiantionAirportName() const;
			void setDestiantionAirportName(string destinationAirportName);
		
			const int getFlightCost() const;
			void setFlightCost(int flightPrice);

			const string getFlightName() const;
			void setFlightName(string flightName);

			const string getTraveldate() const;
			void setTravelDate(string Traveldate);


		
			const int getNoOfStops() const;
			void setNoOfStops(int noOfStops);
			
			const int getNoOfReservableSeatsAvailable() const;
			void setNoOfReservableSeatsAvailable(int nooFSeatsAvailable);
			const int getTotalNoofSeats() const;
			void setTotalNoofSeats(int totalNoofSeats);
			//static bool CheckforSeatsAvailble(int NoofSeatsToBeBooked);

		
			void displayFlightInformation() const;

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