// Customer.cpp
#include <sstream>
#include <vector>
#include "Customer.h"

using std::ostringstream;
using std::vector;

using namespace std;

Customer::Customer() {}

Customer::Customer(const std::string &name) : _name(name) {}

string Customer::statement() {
    double totalAmount = 0;
    int frequentRenterPoints = 0;

    auto iter = _rentals.begin();
    auto iter_end = _rentals.end();

    ostringstream result;

    result << "AbstractRental Record for " << getName() << "\n";
    for (; iter != iter_end; ++iter) {
        AbstractRental *rental = (*iter).get();
        result << movieDetail(rental, totalAmount, frequentRenterPoints);
    }

    // add footer lines
    result << "Amount owed is " << totalAmount << "\n";
    result << "You earned " << frequentRenterPoints << " frequent renter points";

    return result.str();
}

string Customer::movieDetail(AbstractRental *rental, double &totalAmount, int &frequentRenterPoints) const {

    ostringstream movieLine;

    double thisAmount = rental->getMovie()->getPrice(rental->getDaysRented());
    frequentRenterPoints += rental->getMovie()->getPoints(rental->getDaysRented());

    totalAmount += thisAmount;

    movieLine << "\t" << rental->getMovie()->getTitle() << "\t" << thisAmount << "\n";

    return movieLine.str();
}

void Customer::addRental(std::shared_ptr<AbstractRental> arg) {
    _rentals.push_back(move(arg));
}

std::string Customer::getName() const {
    return _name;
}