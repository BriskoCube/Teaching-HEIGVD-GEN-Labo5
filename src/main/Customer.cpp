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

    result << "Rental Record for " << getName() << "\n";
    for (; iter != iter_end; ++iter) {

        double thisAmount = 0;
        Rental *each = (*iter).get();

        // determine amounts for each line
        thisAmount += each->getMovie()->getPrice(each->getDaysRented());

        // add frequent renter points
        frequentRenterPoints += each->getMovie()->getPoints(each->getDaysRented());

        // show figures for this rental
        result << "\t" << each->getMovie()->getTitle() << "\t" << thisAmount << "\n";

        totalAmount += thisAmount;
    }

    // add footer lines
    result << "Amount owed is " << totalAmount << "\n";
    result << "You earned " << frequentRenterPoints << " frequent renter points";

    return result.str();
}