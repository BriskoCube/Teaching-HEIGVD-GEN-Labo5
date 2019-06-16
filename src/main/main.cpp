#include <iostream>

#include "Customer.h"
#include "movies/RegularMovie.h"
#include "movies/NewReleaseMovie.h"
#include "movies/ChildrenMovie.h"
#include "RentalImpl.h"

int main() {

    Customer customer("Olivier");
    customer.addRental( RentalImpl::newRental(RegularMovie::newMovie("Karate Kid"), 7));
    customer.addRental( RentalImpl::newRental(NewReleaseMovie::newMovie( "Avengers: Endgame"), 5));
    customer.addRental( RentalImpl::newRental(ChildrenMovie::newMovie("Snow White"), 3 ));

    std::cout << customer.statement() << std::endl;

    return 0;
}