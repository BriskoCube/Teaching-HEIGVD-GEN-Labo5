#include "../main/Customer.h"
#include "gtest/gtest.h"

using namespace std;


namespace {
    TEST(StatementTest, NO_RENTAL) {
        Customer customer("Olivier");
        string statement = customer.statement();

        EXPECT_EQ(statement, "Rental Record for Olivier\n"
                "Amount owed is 0\n"
                "You earned 0 frequent renter points");
    }
}

