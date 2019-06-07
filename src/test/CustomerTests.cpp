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

        Movie movie("Le jour ou Nathan a tout foire.");
        Rental rental(movie, 10);

        customer.addRental(rental);
        string statement = customer.statement();

        EXPECT_EQ(statement, "Rental Record for Nat\n"
                             "\tLe jour ou Nathan a tout foire.\t14\n"
                             "Amount owed is 14\n"
                             "You earned 1 frequent renter points");
    }

    TEST(StatementTest, ONE_REGULAR_RENTAL) {
        Customer customer("Nat");

        Movie movie("Un beau matin", Movie::REGULAR);
        Rental rental(movie, 1);

        customer.addRental(rental);

        string statement = customer.statement();

        EXPECT_EQ(statement, "Rental Record for Nat\n"
                             "\tUn beau matin\t2\n"
                             "Amount owed is 2\n"
                             "You earned 1 frequent renter points");
    }

    TEST(StatementTest, ONE_REGULAR_RENTAL_MORE_THAN_THREE_DAYS) {
        Customer customer("Nat");

        Movie movie("Nathanael le dernier samourai", Movie::REGULAR);
        Rental rental(movie, 3);

        customer.addRental(rental);

        string statement = customer.statement();

        EXPECT_EQ(statement, "Rental Record for Nat\n"
                             "\tNathanael le dernier samourai\t3.5\n"
                             "Amount owed is 3.5\n"
                             "You earned 1 frequent renter points");
    }

    TEST(StatementTest, ONE_NEW_RELEASE_RENTAL) {
        Customer customer("Nat");

        Movie movie("End Game", Movie::NEW_RELEASE);
        Rental rental(movie, 1);

        customer.addRental(rental);

        string statement = customer.statement();

        EXPECT_EQ(statement, "Rental Record for Nat\n"
                             "\tEnd Game\t3\n"
                             "Amount owed is 3\n"
                             "You earned 1 frequent renter points");
    }

    TEST(StatementTest, ONE_NEW_RELEASE_RENTAL_MORE_THAN_ONE_DAY) {
        Customer customer("Nat");

        Movie movie("End Game", Movie::NEW_RELEASE);
        Rental rental(movie, 2);

        customer.addRental(rental);

        string statement = customer.statement();

        EXPECT_EQ(statement, "Rental Record for Nat\n"
                             "\tEnd Game\t6\n"
                             "Amount owed is 6\n"
                             "You earned 2 frequent renter points");
    }


    TEST(StatementTest, ONE_CHILDRENS_RENTAL) {
        Customer customer("Nat");

        Movie movie("Cars", Movie::CHILDRENS);
        Rental rental(movie, 3);

        customer.addRental(rental);

        string statement = customer.statement();

        EXPECT_EQ(statement, "Rental Record for Nat\n"
                             "\tCars\t1.5\n"
                             "Amount owed is 1.5\n"
                             "You earned 1 frequent renter points");
    }


    TEST(StatementTest, ONE_CHILDRENS_RENTAL_MORE_THAN_THREE_DAYS) {
        Customer customer("Robert");

        Movie movie("Nathan et la girafe", Movie::CHILDRENS);
        Rental rental(movie, 4);

        customer.addRental(rental);

        string statement = customer.statement();

        EXPECT_EQ(statement, "Rental Record for Robert\n"
                             "\tNathan et la girafe\t3\n"
                             "Amount owed is 3\n"
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

