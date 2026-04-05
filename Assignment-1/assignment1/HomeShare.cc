
#include "HomeShare.h"

#include <iostream>

HomeShare::HomeShare() {
    this->num_of_rentals = 0;
}

// ADD / REMOVE FUNCTIONS
void HomeShare::addRental(int rental_id, Category category, const string& description, int maxPeople, double price_per_day) {
   
    // SIZE GUARD: Ensure # of rentals does not exceed limit 
    if (num_of_rentals > MAX_ARRAY) {
        cout << "Error - HomeShare: Rental limit reached!" << endl;
        return;
    }

    // DUPLICATE GUARD: Ensure no duplicate entries by id
    for (int i = 0; i < num_of_rentals; i ++) {
        if (rental_list[i].getId() == rental_id) {
            cout << "Rental with id: " << rental_id << " already exists" << endl;
            return;
        }
    }

    // If all else is good add rental...
    rental_list[num_of_rentals] = Rental(rental_id, category, description, maxPeople, price_per_day);
    num_of_rentals++;
    cout << "Successfully added Rental to HomeShare!" << endl;
}

void HomeShare::removeRental(int rental_id) {
    for (int i = 0; i < num_of_rentals; i++) {
        if (rental_list[i].getId() == rental_id) { // Implement is equals Date Function
            for (int j = i; j < num_of_rentals; j++) {
                rental_list[j] = rental_list[j + 1];
            }
            num_of_rentals--;
            cout << "Successfully removed Rental from HomeShare!" << endl;
            return;
        }
    }
    cout << "Rental does not exist!" << endl;
}


void HomeShare::addReservation(int rental_id, const string& name, int num_of_people, Date& checkin, Date& checkout) {
    // SIZE GUARD: Ensure # of rentals does not exceed limit 
    if (rental_list[rental_id].getReservationsSize() > MAX_ARRAY) {
        cout << "Error - Rental - (" << name  <<" ) limit reached!" << endl;
        return;
    }

    for (int i = 0; i < num_of_rentals; i ++) {
        if (rental_list[i].getId() == rental_id) {
            if (rental_list[i].addReservation(name, num_of_people, checkin, checkout)) {
                continue;
            }
            else {
                return;
            }
        }
    }    
}

// Implement Remove Function

void HomeShare::removeReservation(int rental_id, const string& name, Date& checkin) {
    // Find rental by id
    // Remove reservation by name and date
    for (int i = 0; i < num_of_rentals; i ++) {
        if (rental_list[i].getId() == rental_id) {
            rental_list[i].removeReservation(name, checkin); 
        }
    }
}

// GETTERS
Rental HomeShare::getRental(int rental_id) {
    return rental_list[rental_id];
}

// PRINT FUNCTIONS
void HomeShare::printRentals() {
    if (num_of_rentals == 0) {
        cout << "\n---- No Rentals! ---\n" << endl;
    }

    cout << "\nAll Rentals: " << endl;
    cout << "-------------" << endl;
    for (int i = 0; i < num_of_rentals; i++) {
        rental_list[i].print();
    }

    cout << "\nTotal: (" << num_of_rentals << ")" << endl;

}

void HomeShare::printReservations(int rental_id) {

    cout << "\nAll Reservations: " << endl;
    cout << "-------------" << endl;

    for (int i = 0; i < num_of_rentals; i ++) {
        if (rental_list[i].getId() == rental_id) {
            rental_list[i].printReservations();
            return;
        }
    }

    cout << "No rentals by that Id!" << endl;
     
}

void HomeShare::printReservations(Date& date) {

    if (num_of_rentals == 0) {
        cout << "\n----No Reservations!---\n" << endl;
    }
    for (int i = 0; i < num_of_rentals; i++) {
        rental_list[i].printReservation(date);
    }
   
}

void HomeShare::printRentalsByCategory(Category category){

    cout << "\nAll Rentals in '" << categoryToString(category) << "' category: " << endl;
    cout << "---------------------" << endl;
    for (int i = 0; i < num_of_rentals; i ++) {
        if (rental_list[i].getCategory() == category) {
            rental_list[i].print();
        }
    }

}
