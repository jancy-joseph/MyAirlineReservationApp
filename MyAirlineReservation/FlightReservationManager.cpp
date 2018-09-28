#include "pch.h"
#include<iostream>
#include "FlightReservationManager.h"
using namespace std;

namespace MyAirlineReservationApp{

	void FlightReservationQueue::insertPassengertoReservationQueue(Passenger& passengerObj) {
		FlightQueueData *temp = new FlightQueueData;
		if (temp == NULL) {
			cout << "Overflow" << endl;
			return;
		}
		
		temp->data = passengerObj;
		temp->next = NULL;

		//for first node
		if (front == NULL) {
			front = rear = temp;
		}
		else {
			rear->next = temp;
			rear = temp;
		}

		//std::cout<< passengerObj.getFullName()<< " has been inserted successfully to Queue." << endl;
	}


	void FlightReservationQueue::display() {
		if (front == NULL) {
			cout << "Underflow." << endl;
			return;
		}
		FlightQueueData *temp = front;
		//will check until NULL is not found
		while (temp) {
			//cout<< temp->data << " ";
			temp = temp->next;
		}
		cout << endl;
	}

	void FlightReservationQueue::deleteitem()
	{
		if (front == NULL) {
			cout << "underflow" << endl;
			return;
		}

		//cout << front->data << " is being deleted " << endl;
		if (front == rear)//if only one node is there
			front = rear = NULL;
		else
			front = front->next;
	}

	FlightReservationQueue::~FlightReservationQueue()
	{
		while (front != NULL)
		{
			FlightQueueData *temp = front;
			front = front->next;
			delete temp;
		}
		rear = NULL;
	}

}
