//
// Created by julien on 07.06.19.
//

#ifndef GEN_LABO5_RENTALIMPL_H
#define GEN_LABO5_RENTALIMPL_H

#include "Rental.h"

class RentalImpl : Rental {
public:
    RentalImpl(std::unique_ptr<AbstractMovie> movie, int daysRented);

    int getDaysRented() const;

    AbstractMovie* getMovie() const;

private:
    std::unique_ptr<AbstractMovie> _movie;
    int _daysRented;
};

inline RentalImpl::
RentalImpl(std::unique_ptr<AbstractMovie> movie, int daysRented)
        : _movie(move(movie)), _daysRented(daysRented) {}

inline int RentalImpl::
getDaysRented() const { return _daysRented; }

inline AbstractMovie* RentalImpl::
getMovie() const { return _movie.get(); }

#endif //GEN_LABO5_RENTALIMPL_H
