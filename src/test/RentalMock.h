//
// Created by julien on 07.06.19.
//

#include "gtest/gtest.h"
#include "gmock/gmock.h"
#include "../main/AbstractRental.h"

class RentalMock : public AbstractRental{

public:
    MOCK_CONST_METHOD0(getDaysRented, int());
    MOCK_CONST_METHOD0(getMovie, AbstractMovie*());

    ~RentalMock(){
        delete getMovie();
    }
};