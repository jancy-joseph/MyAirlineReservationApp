#pragma once
#include <iostream>
#include "FlightDetails.h"
#include "Passenger.h"

namespace MyAirlineReservationApp {
	struct FlightQueueData //structure for managing each flight's queue
	{
		Passenger data;
		FlightQueueData* next;
	};
	class FlightReservationQueue {
	private:
		int mFlightNumber;
		FlightQueueData *front;
		FlightQueueData *rear;
	public:
		FlightReservationQueue() { front = rear = NULL; }

		void insertPassengertoReservationQueue(Passenger& newPassenger);
		void deleteitem();
		void display();
		~FlightReservationQueue();
	};



}
