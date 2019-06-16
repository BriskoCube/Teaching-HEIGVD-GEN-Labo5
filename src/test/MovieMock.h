//
// Created by julien on 07.06.19.
//

#include "gtest/gtest.h"
#include "gmock/gmock.h"
#include "../main/movies/AbstractMovie.h"

class MovieMock : public AbstractMovie{

public:
    MOCK_CONST_METHOD0(getTitle, std::string());
    MOCK_CONST_METHOD1(getPrice, double(int));
    MOCK_CONST_METHOD1(getPoints, int(int));
};