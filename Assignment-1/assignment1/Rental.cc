
#include "Rental.h"
#include <stdexcept> // Approved by professor to use library (email proof)
#include <iostream>

// CONSTRUCTORS
Rental::Rental() {
    this->num_of_reservations = 0;
}

Rental::Rental(int rental_id, Category category, const string& description, int maxPeople, double price_per_day) {
    this->rental_id = rental_id;
    this->category = category;
    this->description = description;
    if (maxPeople <= 0)  throw invalid_argument("Max people must be atleast 1");
    this->maxPeople = maxPeople;

    if (price_per_day <= 0)  throw invalid_argument("Price must be greater than or equal to 1");
    this->price_per_day = price_per_day;
    this->num_of_reservations = 0;
}

bool Rental::addReservation(const string& name, int num_of_people, Date& checkin, Date& checkout) {

    if (num_of_people > maxPeople) {
        cout << "Max people is: " << maxPeople << " - cannot have " << num_of_people << endl; 
        return false;
    }

    // Checks every exisisting reservation for any collisions with the one we are adding
    for (int i = 0; i < num_of_reservations; i ++) { 
        
        if (!((reservations_list[i].getCheckOutDate()).lessThan(checkin)) && (reservations_list[i].getCheckInDate()).lessThan(checkin)){ // Prevent Creation of a reservation during an already reserved timespace
            cout << "Failure to Add Reservation - under: '" << name << "'" << ".\nThe following reservation has already been reserved for this time: " << endl;
            reservations_list[i].print();
            return false;
        }      
    }

    // Add reservations sorted by their checkin date
    for (int i = 0; i < num_of_reservations; i ++) { 

        // If true, insert new reservation where the new reservations checkout date is less than or equals to an existing checkin date
        if (!(reservations_list[i].getCheckInDate()).lessThan(checkout) || (reservations_list[i].getCheckInDate()).equals(checkout) ) { // || (reservations_list[i].getCheckInDate()).equals(checkout)
            // cout << "Insert Before" << endl;
            for (int j = num_of_reservations - 1; j >= i; j--) {
                reservations_list[j + 1] = reservations_list[j]; // Shift items to the right to make room for new reso
            }
            reservations_list[i] = Reservation(name, num_of_people, checkin, checkout);
            num_of_reservations++;
            cout << "Successfully added Reservation to Rental - 'under: " << name << "'" << endl;
            return true;
        } 
    }
    reservations_list[num_of_reservations] = Reservation(name, num_of_people, checkin, checkout);
    num_of_reservations++;
    cout << "Successfully added Reservation to Rental - 'under: " << name << "'" << endl;
    return true;
}

void Rental::removeReservation(const string& name, Date& checkin) {
    for (int i = 0; i < num_of_reservations; i++) {
        if (reservations_list[i].getName() == name && reservations_list[i].getCheckInDate().equals(checkin) ) { 
            for (int j = i; j < num_of_reservations; j++) {
                reservations_list[j] = reservations_list[j + 1]; // Shift all the objects in the array to the left, effectively replacing the one we are removing
            }
            num_of_reservations--;
            return;
        }
    }
}

// GETTERS
int Rental::getId() {return rental_id;}
int Rental::getReservationsSize() {return num_of_reservations;}
cat::Category Rental::getCategory() {return category;}


// PRINT FUNCTIONS
void Rental::print() {
    cout << "\nRental Id: " << rental_id 
         << "\nCategory: " << categoryToString(category)
         << "\nDescription: " << description
         << "\nMax People: " << maxPeople
         << "\nPrice Per Day: $" << price_per_day << ".00"
         << endl;
}

void Rental::printReservations() {
    if (num_of_reservations == 0) {
        cout << "\n---- No Reservations! ---\n" << endl;
    }

    for (int i = 0; i < num_of_reservations; i++) {
        reservations_list[i].print();
    }

    cout << "\nTotal (" << num_of_reservations << ")" << endl;
}

void Rental::printReservation(Date& date) {

    if (num_of_reservations == 0) {
        cout << "\n----No Reservations!---\n" << endl;
    }
    int count = 0;
    for (int i = 0; i < num_of_reservations; i++) {
        if (!((reservations_list[i].getCheckOutDate()).lessThan(date)) && (reservations_list[i].getCheckInDate()).lessThan(date)) { 
            reservations_list[i].print();
            count++;
        }
    }
    if (count == 0) {
        cout << "--- No Reservations found in that date range! ---" << endl;
    } else {
        cout << "--- Found " << "( " << count << " ) " << "reservation in that range! ---"  << endl;
    }
}