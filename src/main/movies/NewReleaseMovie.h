//
// Created by julien on 07.06.19.
//

#ifndef GEN_LABO5_NEWRELEASEMOVIE_H
#define GEN_LABO5_NEWRELEASEMOVIE_H

#include "Movie.h"

class NewReleaseMovie : public Movie {

public:
    NewReleaseMovie(const std::string &title): Movie(title){ }

    double getPrice(int duration) const {
        return duration * 3;
    }

    int getPoints(int duration) const {
        return duration > 1 ? 2 : 1;
    }

    static std::shared_ptr<AbstractMovie> newMovie(const std::string &title){
        AbstractMovie* movie = new NewReleaseMovie(title);
        return std::shared_ptr<AbstractMovie>(movie);
    }
};

#endif //GEN_LABO5_NEWRELEASEMOVIE_H
