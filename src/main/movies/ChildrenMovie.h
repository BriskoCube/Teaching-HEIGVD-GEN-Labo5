//
// Created by julien on 07.06.19.
//

#ifndef GEN_LABO5_CHILDRENMOVIE_H
#define GEN_LABO5_CHILDRENMOVIE_H

#include "Movie.h"

class ChildrenMovie : public Movie{

public:
    ChildrenMovie(const std::string &title): Movie(title){ }

    double getPrice(int duration) const{
        double amount = 1.5;

        if (duration > 3)
            amount += (duration - 3) * 1.5;

        return amount;
    }

    int getPoints(int duration) const{
        return 1;
    }

    static std::shared_ptr<AbstractMovie> newMovie(const std::string &title){
        AbstractMovie* movie = new ChildrenMovie(title);
        return std::shared_ptr<AbstractMovie>(movie);
    }
};

#endif //GEN_LABO5_CHILDRENMOVIE_H
