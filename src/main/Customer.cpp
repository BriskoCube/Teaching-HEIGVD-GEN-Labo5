// Customer.cpp
#include <sstream>
#include <vector>
#include <regex>
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
        result << movieDetail(rental, totalAmount, frequentRenterPoints,
                              "\t{title}\t{price}\n");
    }

    // add footer lines
    result << "Amount owed is " << totalAmount << "\n";
    result << "You earned " << frequentRenterPoints << " frequent renter points";

    return result.str();
}

string Customer::movieDetail(AbstractRental *rental, double &totalAmount,
        int &frequentRenterPoints, const string &format) const {

    ostringstream movieLine;

    double thisAmount = rental->getMovie()->getPrice(rental->getDaysRented());
    frequentRenterPoints += rental->getMovie()->getPoints(rental->getDaysRented());

    totalAmount += thisAmount;

    return formatMovie(format, rental->getMovie()->getTitle(), thisAmount);
}

/**
 * Format a movie, {title} will be replaced by the film title and {price} by the price
 */
string Customer::formatMovie(const string &format, const string& title, double price) const{
    string formatted = std::regex_replace(format, std::regex("\\{title}"), title);
    formatted = std::regex_replace(formatted, std::regex("\\{price}"), to_string(price));
    return formatted;
}

void Customer::addRental(std::shared_ptr<AbstractRental> arg) {
    _rentals.push_back(move(arg));
}

std::string Customer::getName() const {
    return _name;
}