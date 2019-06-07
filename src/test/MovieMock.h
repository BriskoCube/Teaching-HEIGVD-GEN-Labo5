//
// Created by julien on 07.06.19.
//

#include "gtest/gtest.h"
#include "gmock/gmock.h"
#include "../main/Movie.h"

class MovieMock : public Movie{

public:
    MOCK_CONST_METHOD0(getPriceCode, int());
    MOCK_CONST_METHOD0(getTitle, std::string());
};