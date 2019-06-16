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

    static std::shared_ptr<AbstractRental> newRental(std::shared_ptr<AbstractMovie> movie, int daysRented);


private:
    std::shared_ptr<AbstractMovie> _movie;
    int _daysRented;
};



#endif //GEN_LABO5_RENTAL_H
