//
// Created by julien on 16.06.19.
//
#include "Rental.h"

Rental::Rental(std::shared_ptr<AbstractMovie> movie, int daysRented)
        : _movie(movie), _daysRented(daysRented) {}

int Rental::getDaysRented() const {
    return _daysRented;
}

AbstractMovie *Rental::getMovie() const {
    return _movie.get();
}

std::shared_ptr<AbstractRental> Rental::newRental(std::shared_ptr<AbstractMovie> movie, int daysRented) {
    AbstractRental *rental = new Rental(movie, daysRented);
    return std::shared_ptr<AbstractRental>(rental);
}