//
// Created by julien on 07.06.19.
//

#ifndef GEN_LABO5_RENTALIMPL_H
#define GEN_LABO5_RENTALIMPL_H

#include "Rental.h"

class RentalImpl : Rental {
public:

    RentalImpl(std::shared_ptr<AbstractMovie> movie, int daysRented);

    int getDaysRented() const;

    AbstractMovie* getMovie() const;

    static std::shared_ptr<Rental> newRental(std::shared_ptr<AbstractMovie> movie, int daysRented){
        Rental* rental = new RentalImpl(movie, daysRented);
        return std::shared_ptr<Rental>(rental);
    }

private:
    std::shared_ptr<AbstractMovie> _movie;
    int _daysRented;
};

inline RentalImpl::
RentalImpl(std::shared_ptr<AbstractMovie> movie, int daysRented)
        : _movie(movie), _daysRented(daysRented) {}

inline int RentalImpl::
getDaysRented() const { return _daysRented; }

inline AbstractMovie* RentalImpl::
getMovie() const { return _movie.get(); }

#endif //GEN_LABO5_RENTALIMPL_H
