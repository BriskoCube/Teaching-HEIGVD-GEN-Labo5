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

    TEST(StatementTest, ONE_SIMPLE_RENTAL) {
        Customer customer("Nat");
        customer.addRental(Rental(Movie("Le jour ou Nathan a tout foire."), 10));
        string statement = customer.statement();

        EXPECT_EQ(statement, "Rental Record for Nat\n"
                             "\tLe jour ou Nathan a tout foire.\t14\n"
                             "Amount owed is 14\n"
                             "You earned 1 frequent renter points");
    }
}

