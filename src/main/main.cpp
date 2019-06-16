#include <iostream>

#include "Customer.h"
#include "movies/RegularMovie.h"
#include "movies/NewReleaseMovie.h"
#include "movies/ChildrenMovie.h"
#include "Rental.h"

int main() {

    Customer customer("Olivier");
    customer.addRental( Rental::newRental(RegularMovie::newMovie("Karate Kid"), 7));
    customer.addRental( Rental::newRental(NewReleaseMovie::newMovie( "Avengers: Endgame"), 5));
    customer.addRental( Rental::newRental(ChildrenMovie::newMovie("Snow White"), 3 ));

    std::cout << customer.statement() << std::endl;

    return 0;
}