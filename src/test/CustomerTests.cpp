#include <gmock/gmock-spec-builders.h>
#include "../main/Customer.h"
#include "gtest/gtest.h"
#include "MovieMock.h"
#include "RentalMock.h"

using namespace std;
using namespace testing;


namespace {
    TEST(StatementTest, NO_RENTAL) {
        Customer customer("Olivier");
        string statement = customer.statement();

        EXPECT_EQ(statement, "Rental Record for Olivier\n"
                "Amount owed is 0\n"
                "You earned 0 frequent renter points");
    }

    shared_ptr<Rental> createMockRental(string movieTitle, int movieType, int rentDuration){
        MovieMock* movie = new MovieMock();
        RentalMock* rental = new RentalMock();

        EXPECT_CALL(*movie, getPriceCode()).WillRepeatedly(Return(movieType));
        EXPECT_CALL(*movie, getTitle()).WillRepeatedly(Return(movieTitle));

        EXPECT_CALL(*rental, getDaysRented()).WillRepeatedly(Return(rentDuration));
        EXPECT_CALL(*rental, getMovie()).WillRepeatedly(Return(movie));

        return shared_ptr<Rental>(rental);
    }


    TEST(StatementTest, ONE_SIMPLE_RENTAL) {
        Customer customer("Nat");

        shared_ptr<Rental> rental = createMockRental("Le jour ou Nathan a tout foire.", Movie::REGULAR, 10);

        customer.addRental(shared_ptr<Rental>(rental));

        string statement = customer.statement();

        EXPECT_EQ(statement, "Rental Record for Nat\n"
                             "\tLe jour ou Nathan a tout foire.\t14\n"
                             "Amount owed is 14\n"
                             "You earned 1 frequent renter points");
    }

    TEST(StatementTest, ONE_REGULAR_RENTAL) {
        Customer customer("Nat");

        shared_ptr<Rental> rental = createMockRental("Un beau matin", Movie::REGULAR, 1);

        customer.addRental(rental);

        string statement = customer.statement();

        EXPECT_EQ(statement, "Rental Record for Nat\n"
                             "\tUn beau matin\t2\n"
                             "Amount owed is 2\n"
                             "You earned 1 frequent renter points");
    }

    TEST(StatementTest, ONE_REGULAR_RENTAL_MORE_THAN_THREE_DAYS) {
        Customer customer("Nat");

        shared_ptr<Rental> rental = createMockRental("Nathanael le dernier samourai", Movie::REGULAR, 3);

        customer.addRental(rental);

        string statement = customer.statement();

        EXPECT_EQ(statement, "Rental Record for Nat\n"
                             "\tNathanael le dernier samourai\t3.5\n"
                             "Amount owed is 3.5\n"
                             "You earned 1 frequent renter points");
    }

    TEST(StatementTest, ONE_NEW_RELEASE_RENTAL) {
        Customer customer("Nat");

        shared_ptr<Rental> rental = createMockRental("End Game", Movie::NEW_RELEASE, 1);

        customer.addRental(rental);

        string statement = customer.statement();

        EXPECT_EQ(statement, "Rental Record for Nat\n"
                             "\tEnd Game\t3\n"
                             "Amount owed is 3\n"
                             "You earned 1 frequent renter points");
    }

    TEST(StatementTest, ONE_NEW_RELEASE_RENTAL_MORE_THAN_ONE_DAY) {
        Customer customer("Nat");

        shared_ptr<Rental> rental = createMockRental("End Game", Movie::NEW_RELEASE, 2);

        customer.addRental(rental);

        string statement = customer.statement();

        EXPECT_EQ(statement, "Rental Record for Nat\n"
                             "\tEnd Game\t6\n"
                             "Amount owed is 6\n"
                             "You earned 2 frequent renter points");
    }


    TEST(StatementTest, ONE_CHILDRENS_RENTAL) {
        Customer customer("Nat");

        shared_ptr<Rental> rental = createMockRental("Cars", Movie::CHILDRENS, 3);

        customer.addRental(rental);

        string statement = customer.statement();

        EXPECT_EQ(statement, "Rental Record for Nat\n"
                             "\tCars\t1.5\n"
                             "Amount owed is 1.5\n"
                             "You earned 1 frequent renter points");
    }


    TEST(StatementTest, ONE_CHILDRENS_RENTAL_MORE_THAN_THREE_DAYS) {
        Customer customer("Robert");

        shared_ptr<Rental> rental = createMockRental("Nathan et la girafe", Movie::CHILDRENS, 4);

        customer.addRental(rental);

        string statement = customer.statement();

        EXPECT_EQ(statement, "Rental Record for Robert\n"
                             "\tNathan et la girafe\t3\n"
                             "Amount owed is 3\n"
                             "You earned 1 frequent renter points");
    }

    TEST(StatementTest, TWO_SPECIAL_RENTAL) {
        Customer customer("Customer");

        shared_ptr<Rental> rental = createMockRental("Juju au zoo", Movie::CHILDRENS, 4);
        shared_ptr<Rental> rental2 = createMockRental("Juju en vacance", Movie::NEW_RELEASE, 4);

        customer.addRental(rental);
        customer.addRental(rental2);

        string statement = customer.statement();

        EXPECT_EQ(statement, "Rental Record for Customer\n"
                             "\tJuju au zoo\t3\n"
                             "\tJuju en vacance\t12\n"
                             "Amount owed is 15\n"
                             "You earned 3 frequent renter points");
    }
}

