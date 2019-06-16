// AbstractRental.h
#ifndef RENTAL_H
#define RENTAL_H

#include <memory>
#include "movies/AbstractMovie.h"

class AbstractRental {
public:
    virtual int getDaysRented() const = 0;
    virtual AbstractMovie* getMovie() const = 0;

    virtual ~AbstractRental(){};
};

#endif // RENTAL_H