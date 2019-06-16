// Customer.cpp
#include <sstream>
#include <vector>
#include "Customer.h"

using std::ostringstream;
using std::vector;

using namespace std;

string Customer::statement() {
    double totalAmount = 0;
    int frequentRenterPoints = 0;

    auto iter = _rentals.begin();
    auto iter_end = _rentals.end();

    ostringstream result;

    result << "AbstractRental Record for " << getName() << "\n";
    for (; iter != iter_end; ++iter) {

        double thisAmount = 0;
        AbstractRental *rental = (*iter).get();

        // determine amounts for each line
        thisAmount += rental->getMovie()->getPrice(rental->getDaysRented());

        // add frequent renter points
        frequentRenterPoints += rental->getMovie()->getPoints(rental->getDaysRented());

        // show figures for this rental
        result << "\t" << rental->getMovie()->getTitle() << "\t" << thisAmount << "\n";

        totalAmount += thisAmount;
    }

    // add footer lines
    result << "Amount owed is " << totalAmount << "\n";
    result << "You earned " << frequentRenterPoints << " frequent renter points";

    return result.str();
}


Customer::Customer() {}

Customer::Customer(const std::string &name) : _name(name) {}

void Customer::addRental(std::shared_ptr<AbstractRental> arg) {
    _rentals.push_back(move(arg));
}

std::string Customer::getName() const {
    return _name;
}