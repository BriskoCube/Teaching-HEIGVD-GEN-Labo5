// Movie.h
#ifndef MOVIE_H
#define MOVIE_H

#include <string>

class Movie {
public:
    static const int CHILDRENS = 2;
    static const int REGULAR = 0;
    static const int NEW_RELEASE = 1;

    virtual int getPriceCode() const = 0;

    virtual std::string getTitle() const = 0;

    virtual ~Movie() {}

};

#endif // MOVIE_H