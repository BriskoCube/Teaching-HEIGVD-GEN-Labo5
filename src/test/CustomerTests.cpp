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

        EXPECT_EQ(statement, "AbstractRental Record for Olivier\n"
                "Amount owed is 0\n"
                "You earned 0 frequent renter points");
    }

    shared_ptr<AbstractRental> createMockRental(string movieTitle, int rentDuration, double price, int points){
        MovieMock* movie = new MovieMock();
        RentalMock* rental = new RentalMock();

        EXPECT_CALL(*movie, getTitle()).WillRepeatedly(Return(movieTitle));
        EXPECT_CALL(*movie, getPoints(rentDuration)).WillRepeatedly(Return(points));
        EXPECT_CALL(*movie, getPrice(rentDuration)).WillRepeatedly(Return(price));

        EXPECT_CALL(*rental, getDaysRented()).WillRepeatedly(Return(rentDuration));
        EXPECT_CALL(*rental, getMovie()).WillRepeatedly(Return(movie));

        return shared_ptr<AbstractRental>(rental);
    }


    TEST(StatementTest, ONE_SIMPLE_RENTAL) {
        Customer customer("Nat");

        shared_ptr<AbstractRental> rental = createMockRental("Le jour ou Nathan a tout foire.", 10, 14, 1);

        customer.addRental(shared_ptr<AbstractRental>(rental));

        string statement = customer.statement();

        EXPECT_EQ(statement, "AbstractRental Record for Nat\n"
                             "\tLe jour ou Nathan a tout foire.\t14\n"
                             "Amount owed is 14\n"
                             "You earned 1 frequent renter points");
    }

    TEST(StatementTest, ONE_REGULAR_RENTAL) {
        Customer customer("Nat");

        shared_ptr<AbstractRental> rental = createMockRental("Un beau matin", 1, 2, 1);

        customer.addRental(rental);

        string statement = customer.statement();

        EXPECT_EQ(statement, "AbstractRental Record for Nat\n"
                             "\tUn beau matin\t2\n"
                             "Amount owed is 2\n"
                             "You earned 1 frequent renter points");
    }

    TEST(StatementTest, ONE_REGULAR_RENTAL_MORE_THAN_THREE_DAYS) {
        Customer customer("Nat");

        shared_ptr<AbstractRental> rental = createMockRental("Nathanael le dernier samourai", 3, 3.5, 1);

        customer.addRental(rental);

        string statement = customer.statement();

        EXPECT_EQ(statement, "AbstractRental Record for Nat\n"
                             "\tNathanael le dernier samourai\t3.5\n"
                             "Amount owed is 3.5\n"
                             "You earned 1 frequent renter points");
    }

    TEST(StatementTest, ONE_NEW_RELEASE_RENTAL) {
        Customer customer("Nat");

        shared_ptr<AbstractRental> rental = createMockRental("End Game", 1, 3, 1);

        customer.addRental(rental);

        string statement = customer.statement();

        EXPECT_EQ(statement, "AbstractRental Record for Nat\n"
                             "\tEnd Game\t3\n"
                             "Amount owed is 3\n"
                             "You earned 1 frequent renter points");
    }

    TEST(StatementTest, ONE_NEW_RELEASE_RENTAL_MORE_THAN_ONE_DAY) {
        Customer customer("Nat");

        shared_ptr<AbstractRental> rental = createMockRental("End Game", 2, 6, 2);

        customer.addRental(rental);

        string statement = customer.statement();

        EXPECT_EQ(statement, "AbstractRental Record for Nat\n"
                             "\tEnd Game\t6\n"
                             "Amount owed is 6\n"
                             "You earned 2 frequent renter points");
    }


    TEST(StatementTest, ONE_CHILDRENS_RENTAL) {
        Customer customer("Nat");

        shared_ptr<AbstractRental> rental = createMockRental("Cars", 3, 1.5, 1);

        customer.addRental(rental);

        string statement = customer.statement();

        EXPECT_EQ(statement, "AbstractRental Record for Nat\n"
                             "\tCars\t1.5\n"
                             "Amount owed is 1.5\n"
                             "You earned 1 frequent renter points");
    }


    TEST(StatementTest, ONE_CHILDRENS_RENTAL_MORE_THAN_THREE_DAYS) {
        Customer customer("Robert");

        shared_ptr<AbstractRental> rental = createMockRental("Nathan et la girafe", 4, 3, 1);

        customer.addRental(rental);

        string statement = customer.statement();

        EXPECT_EQ(statement, "AbstractRental Record for Robert\n"
                             "\tNathan et la girafe\t3\n"
                             "Amount owed is 3\n"
                             "You earned 1 frequent renter points");
    }

    TEST(StatementTest, TWO_SPECIAL_RENTAL) {
        Customer customer("Customer");

        shared_ptr<AbstractRental> rental = createMockRental("Juju au zoo", 4, 3, 1);
        shared_ptr<AbstractRental> rental2 = createMockRental("Juju en vacance", 4, 12, 2);

        customer.addRental(rental);
        customer.addRental(rental2);

        string statement = customer.statement();

        EXPECT_EQ(statement, "AbstractRental Record for Customer\n"
                             "\tJuju au zoo\t3\n"
                             "\tJuju en vacance\t12\n"
                             "Amount owed is 15\n"
                             "You earned 3 frequent renter points");
    }
}

