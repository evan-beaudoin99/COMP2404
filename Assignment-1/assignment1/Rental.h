
#ifndef RENTAL_H
#define RENTAL_H

#include <string>

#include "Date.h"
#include "Category.h"
#include "Reservation.h"

using namespace std;
using namespace cat;

class Rental {

    private: 
        int rental_id;
        Category category;
        string description;
        int maxPeople;
        double price_per_day;
        
        int num_of_reservations;
        Reservation reservations_list[MAX_ARRAY];
    public:
        Rental();
        Rental(int rental_id, Category category, const string& description, int maxPeople, double price_per_day);
        
        bool addReservation(const string& name, int num_of_people, Date& checkin, Date& checkout); // Adds reservation to reservation_list
        void removeReservation(const string& name, Date& checkin); // Removes reservation from reservation_list if name and checin matches

        // GETTERS
        int getId();
        int getReservationsSize();
        Category getCategory(); 

        // PRINT FUNCTIONS
        void print();
        void printReservations();
        void printReservation(Date& date);
};


#endif