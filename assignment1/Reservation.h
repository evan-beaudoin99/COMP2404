
#ifndef RESERVATION_H
#define RESERVATION_H

#include <string>

#include "Date.h"
#include "Reservation.h"
#include "defs.h"

using namespace std;

class Reservation {

    private: 
        string name;
        int num_people;
        Date checkin;
        Date checkout;

    public: 
        // CONSTRUCTORS
        Reservation(const string& name, int num_people, Date& checkin, Date& checkout);
        Reservation();

        // GETTERS
        string getName();
        Date getCheckInDate();
        Date getCheckOutDate();
        
        // PRINT FUNCTIONS
        void print();

};


#endif