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

private:
    std::string _title;
    int _priceCode;
};

inline MovieImpl::
MovieImpl(const std::string &title, int priceCode)
        : _title(title), _priceCode(priceCode) {}

inline int MovieImpl::
getPriceCode() const { return _priceCode; }

inline void MovieImpl::
setPriceCode(int arg) { _priceCode = arg; }

inline std::string MovieImpl::
getTitle() const { return _title; }


#endif //GEN_LABO5_MOVIEIMPL_H
