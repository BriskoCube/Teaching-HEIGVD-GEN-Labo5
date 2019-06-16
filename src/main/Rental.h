//
// Created by julien on 07.06.19.
//

#ifndef GEN_LABO5_RENTAL_H
#define GEN_LABO5_RENTAL_H

#include "AbstractRental.h"

class Rental : public AbstractRental {
public:

    Rental(std::shared_ptr<AbstractMovie> movie, int daysRented);

    int getDaysRented() const;

    AbstractMovie* getMovie() const;

    static std::shared_ptr<AbstractRental> newRental(std::shared_ptr<AbstractMovie> movie, int daysRented){
        AbstractRental* rental = new Rental(movie, daysRented);
        return std::shared_ptr<AbstractRental>(rental);
    }

private:
    std::shared_ptr<AbstractMovie> _movie;
    int _daysRented;
};

inline Rental::
Rental(std::shared_ptr<AbstractMovie> movie, int daysRented)
        : _movie(movie), _daysRented(daysRented) {}

inline int Rental::
getDaysRented() const { return _daysRented; }

inline AbstractMovie* Rental::
getMovie() const { return _movie.get(); }

#endif //GEN_LABO5_RENTAL_H
