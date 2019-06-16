//
// Created by julien on 07.06.19.
//

#ifndef GEN_LABO5_MOVIEIMPL_H
#define GEN_LABO5_MOVIEIMPL_H

#include <string>
#include "AbstractMovie.h"

class Movie : public AbstractMovie {
public:

    Movie(const std::string &title);

    std::string getTitle() const;

private:
    std::string _title;
};


#endif //GEN_LABO5_MOVIEIMPL_H
