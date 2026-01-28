
#include "Reservation.h"
#include <iostream>
#include <stdexcept>

// CONSTRUCTORS
Reservation::Reservation(const string& name, int num_people, Date& checkin, Date& checkout) {
    this->name = name;
    if (num_people <= 0)  throw invalid_argument("# of people must be atleast 1");
    this->num_people = num_people;
    if (checkout.lessThan(checkin)) throw invalid_argument("Checkout cannot be before or equal to check in");
    this->checkin = checkin;
    this->checkout = checkout;
}

Reservation::Reservation() {
    this->name = "(Unknown)";
    this->num_people = 0;

    Date default_date;
    this->checkin = default_date;
    this->checkout = default_date;
}

// GETTERS
string Reservation::getName() {return name;}
Date Reservation::getCheckInDate() {return checkin;}
Date Reservation::getCheckOutDate() {return checkout;}

// PRINT FUNCTIONS
void Reservation::print() {
    cout << "\n---Reservation Details---\n" 
         << "For: " 
         << name 
         << "\n# of people: " 
         << num_people << endl;
        cout << "\n-Check In- " << endl;
        checkin.print();
        cout << "\n-Check Out- " << endl;
        checkout.print();
}