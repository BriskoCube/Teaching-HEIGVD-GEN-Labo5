//
// Created by julien on 07.06.19.
//

#ifndef GEN_LABO5_CHILDRENMOVIE_H
#define GEN_LABO5_CHILDRENMOVIE_H

#include "Movie.h"

class ChildrenMovie : public Movie{
    double getPrice(int duration) const{
        double amount = 1.5;

        if (duration > 3)
            amount += (duration - 3) * 1.5;

        return amount;
    }

    int getPoints(int duration) const{
        return 1;
    }
};

#endif //GEN_LABO5_CHILDRENMOVIE_H
