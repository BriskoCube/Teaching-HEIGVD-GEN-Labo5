//
// Created by julien on 07.06.19.
//

#ifndef GEN_LABO5_MOVIEIMPL_H
#define GEN_LABO5_MOVIEIMPL_H

#include <string>
#include "Movie.h"

class MovieImpl : Movie {
public:

    MovieImpl(const std::string &title, int priceCode = REGULAR);

    int getPriceCode() const;

    void setPriceCode(int arg);

    std::string getTitle() const;

    virtual int getPrice(int duration) const = 0;

private:
    std::string _title;
    int _priceCode;
};


#endif //GEN_LABO5_MOVIEIMPL_H
