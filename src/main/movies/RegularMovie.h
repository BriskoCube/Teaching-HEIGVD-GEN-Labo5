//
// Created by julien on 07.06.19.
//

#ifndef GEN_LABO5_REGULARMOVIE_H
#define GEN_LABO5_REGULARMOVIE_H

#include "Movie.h"

class RegularMovie : public Movie{

public:

    RegularMovie(const std::string &title): Movie(title){ }

    double getPrice(int duration) const{
        double amount = 2;

        if (duration > 2)
            amount += (duration - 2) * 1.5;

        return amount;
    }

    int getPoints(int duration) const{
        return 1;
    }

    static std::shared_ptr<AbstractMovie> newMovie(const std::string &title){
        AbstractMovie* movie = new RegularMovie(title);
        return std::shared_ptr<AbstractMovie>(movie);
    }
};

#endif //GEN_LABO5_REGULARMOVIE_H
