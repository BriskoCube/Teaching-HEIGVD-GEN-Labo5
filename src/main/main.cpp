#include <iostream>

#include "Customer.h"

int main() {

    Customer customer("Olivier");
    customer.addRental( Rental( Movie("Karate Kid"), 7));
    customer.addRental( Rental( AbstractMovie( "Avengers: Endgame", AbstractMovie::NEW_RELEASE ), 5));
    customer.addRental( Rental( AbstractMovie("Snow White", AbstractMovie::CHILDRENS), 3 ));

    std::cout << customer.statement() << std::endl;

    return 0;
}