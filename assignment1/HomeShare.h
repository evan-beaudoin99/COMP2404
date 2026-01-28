
#ifndef HOMESHARE_H
#define HOMESHARE_H

#include <string>

#include "Date.h"
#include "Rental.h"
#include "Category.h"
#include "defs.h"

using namespace std;
using namespace cat;

/*
    The HomeShare class maintains an array of Rentals, as well as functions related to adding, removing, and
    displaying Rentals and Reservations.
*/
class HomeShare {

    private: 
        int num_of_rentals;
        Rental rental_list[MAX_ARRAY];

    public: 
        // CONSTRUCTORS
        HomeShare(); 

        // GETTERS
        Rental getRental(int rental_id);
        
        // ADD / REMOVE FUNCTIONS
        void addRental(int rental_id, Category category, const string& description, int maxPeople, double price_per_day); 
        void removeRental(int rental_id); 

        void addReservation(int rental_id, const string& name, int num_of_people, Date& checkin, Date& checkout);
        void removeReservation(int rental_id, const string& name, Date& checkin);

        // PRINT FUNCTIONS
        void printRentals();
        void printReservations(int rental_id);
        void printReservations(Date& date);
        void printRentalsByCategory(Category category);
};

#endif