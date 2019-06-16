// AbstractMovie.h
#ifndef MOVIE_H
#define MOVIE_H

#include <string>

class AbstractMovie {
public:
    virtual std::string getTitle() const = 0;

    virtual double getPrice(int duration) const = 0;

    virtual int getPoints(int duration) const = 0;

    virtual ~AbstractMovie() {}

};

#endif // MOVIE_H