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

    TEST(StatementTest, TWO_SPECIAL_RENTAL) {
        Customer customer("Customer");
        customer.addRental(Rental(Movie("Juju au zoo", 2), 4));
        customer.addRental(Rental(Movie("Juju en vacance", 1), 4));
        string statement = customer.statement();

        EXPECT_EQ(statement, "Rental Record for Customer\n"
                             "\tJuju au zoo\t3\n"
                             "\tJuju en vacance\t12\n"
                             "Amount owed is 15\n"
                             "You earned 3 frequent renter points");
    }
}

