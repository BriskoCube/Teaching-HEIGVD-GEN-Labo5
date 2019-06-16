//
// Created by julien on 07.06.19.
//

#ifndef GEN_LABO5_CHILDRENMOVIE_H
#define GEN_LABO5_CHILDRENMOVIE_H

#include "Movie.h"

class RegularMovie : public Movie{
    override double getPrice(int duration) const{
        double amount = 2;

        if (duration > 2)
            thisAmount += (duration - 2) * 1.5;

        return amount;
    }

    int getPoints(int duration) const{
        return 1;
    }
};

#endif //GEN_LABO5_CHILDRENMOVIE_H
