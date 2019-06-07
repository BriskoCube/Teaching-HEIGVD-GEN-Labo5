//
// Created by julien on 07.06.19.
//

#include "gtest/gtest.h"
#include "gmock/gmock.h"
#include "../main/Rental.h"

class RentalMock : public Rental{

public:
    MOCK_CONST_METHOD0(getDaysRented, int());
    MOCK_CONST_METHOD0(getMovie, Movie*());

    ~RentalMock(){
        delete getMovie();
    }
};