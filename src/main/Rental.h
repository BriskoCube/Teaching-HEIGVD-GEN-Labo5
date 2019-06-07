// Rental.h
#ifndef RENTAL_H
#define RENTAL_H

#include <memory>
#include "movies/Movie.h"

class Rental {
public:
    virtual int getDaysRented() const = 0;
    virtual Movie* getMovie() const = 0;

    virtual ~Rental(){};
};

#endif // RENTAL_H