#include <iostream>
#include "pch.h"
#include "FlightDetails.h"
#include <iomanip>      // std::setw
using namespace std;

namespace MyAirlineReservationApp {
	int FlightDetails::getFlightNo() const {
		//cout << "getFlightNo " << mFlightNo;

		return mFlightNo;
	}
	void FlightDetails::setFlightNo(int flightNo) {

		mFlightNo = flightNo;
		//cout << "setFlightNo " << mFlightNo << endl;;

	}

	Time FlightDetails::getDepartingTime() const {
		return mDeparting_Time;
	};
	void FlightDetails::setDepartingTime(Time departingTime) {
		mDeparting_Time = departingTime;
	};
/*
	Time FlightDetails::getArrivalTime() const {
		return mArrival_time;
	};
	void FlightDetails::SetArrivalTime(string& arrivalTiime) {
		mArrival_time = arrivalTiime;
	};

	const string& FlightDetails::getSourceAirportName() const {
		return mSourceAirportName;
	};
	void FlightDetails::setSourceAirportName(std::string& sourceAirportName) {
		mSourceAirportName = sourceAirportName;
	};
	const string& FlightDetails::getDestiantionAirportName() const {
		return mDestinationAirportName;
	};

	void FlightDetails::setDestiantionAirportName(string& destinationAirportName) {
		mDestinationAirportName = destinationAirportName;
	};


	int FlightDetails::getFlightCost() const {
		return mPrice;
	};
	void FlightDetails::setFlightCost(int flightPrice) {
		mPrice = flightPrice;
	};
	const string& FlightDetails::getFlightName() const {
		return mFlightName;
	};
	void FlightDetails::setFlightName(std::string& flightName) {
		mFlightName = flightName;
	};
	
	int FlightDetails::getNoOfStops() const {
		return mNoOfStops;

	};
	int FlightDetails::setNoOfStops(int noOfStops) {
		mNoOfStops = noOfStops;
	};
	*/
	int FlightDetails::getNoOfReservableSeatsAvailable() const {
		//cout << "mNooFSeatsAvailableToReserve " << mNooFSeatsAvailableToReserve << endl;;

		return mNooFSeatsAvailableToReserve;
	};
	void FlightDetails::setNoOfReservableSeatsAvailable(int SeatsAvailable) {
			mNooFSeatsAvailableToReserve = SeatsAvailable;
			//cout << "setNoOfReservableSeatsAvailable " << mNooFSeatsAvailableToReserve << endl;

	};


	int FlightDetails::getTotalNoofSeats() const {
		//cout <<" getTotalNoofSeats"<< mTotalNoofSeats;
		return mTotalNoofSeats;
	};
	void FlightDetails::setTotalNoofSeats(int NoofSeats) {
		mTotalNoofSeats = NoofSeats;
		//cout << "setTotalNoofSeats" << mTotalNoofSeats << endl;;

	};
	void FlightDetails::display() const {
		
		cout << left << setw(10) << getFlightNo() << left << setw(10) << getTotalNoofSeats()<< left << setw(10)<< getNoOfReservableSeatsAvailable()<< endl;

		//cout << left << setw(10) << "FLIGHT" << left << setw(10) << "FROM" << left << setw(10) << "TO" << left << setw(10) << "LEAVE" << left << setw(10) << "ARRIVE" << left << setw(10) << "COST" << left << setw(10) << "TYPE" << left << setw(10) << "SEATS" << left << setw(10) << "BOOKED" << endl;
		//cout << left << setw(10) << i->flightNo << left << setw(10) << i->from << left << setw(10) << i->to << left << setw(10) << l_time << left << setw(10) << a_time << left << setw(10) << i->cost << left << setw(10) << i->plane_type << left << setw(10) << i->seats << left << setw(10) << i->booked_seats << endl;
	};
}
