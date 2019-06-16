//
// Created by julien on 07.06.19.
//

#ifndef GEN_LABO5_CHILDRENMOVIE_H
#define GEN_LABO5_CHILDRENMOVIE_H

#include "Movie.h"

class NewReleaseMovie : public Movie{
    double getPrice(int duration) const{
        return duration * 3;
    }

    int getPoints(int duration) const{
        return duration > 1 ? 2 : 1;
    }
};

#endif //GEN_LABO5_CHILDRENMOVIE_H
