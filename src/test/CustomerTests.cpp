#include <gmock/gmock-spec-builders.h>
#include "../main/Customer.h"
#include "gtest/gtest.h"
#include "MovieMock.h"
#include "RentalMock.h"

using namespace std;
using namespace testing;


namespace {
    const string OUT_FORMAT = "\t{title}\t{price}\n";

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

    TEST(MovieDetailTest, BASIC) {
        Customer customer("Customer");

        shared_ptr<AbstractRental> rental = createMockRental("Juju au zoo", 4, 3, 1);

        double totalAmount = 0;
        int frequentRenterPoints = 0;

        string detail = customer.movieDetail(rental.get(), totalAmount, frequentRenterPoints, OUT_FORMAT);

        string statement = customer.statement();

        EXPECT_EQ(detail, "\tJuju au zoo\t3\n");
        EXPECT_EQ(totalAmount, 3);
        EXPECT_EQ(frequentRenterPoints, 1);
    }

    TEST(MovieDetailTest, START_VALUE) {
        Customer customer("Customer");

        shared_ptr<AbstractRental> rental = createMockRental("Le jour ou Nathan a tout foire.", 10, 14, 1);

        double totalAmount = 30.8;
        int frequentRenterPoints = 12;

        string detail = customer.movieDetail(rental.get(), totalAmount, frequentRenterPoints, OUT_FORMAT);

        string statement = customer.statement();

        EXPECT_EQ(detail, "\tLe jour ou Nathan a tout foire.\t14\n");
        EXPECT_EQ(totalAmount, 44.8);
        EXPECT_EQ(frequentRenterPoints, 13);
    }

    TEST(MovieDetailTest, DOUBLE_POINTS) {
        Customer customer("Customer");

        shared_ptr<AbstractRental> rental = createMockRental("Le jour ou Nathan a tout foire.", 10, 14, 2);

        double totalAmount = 30.8;
        int frequentRenterPoints = 12;

        string detail = customer.movieDetail(rental.get(), totalAmount, frequentRenterPoints, OUT_FORMAT);

        string statement = customer.statement();

        EXPECT_EQ(detail, "\tLe jour ou Nathan a tout foire.\t14\n");
        EXPECT_EQ(totalAmount, 44.8);
        EXPECT_EQ(frequentRenterPoints, 14);
    }

    TEST(FormatMovie, SIMPLE_FORMAT) {
        Customer customer("Customer");

        string detail = customer.formatMovie("\t{title}\t{price}\n", "Super film", 12.2);

        string statement = customer.statement();

        EXPECT_EQ(detail, "\tSuper film\t12.2\n");
    }

    TEST(FormatMovie, MISSING_TITLE) {
        Customer customer("Customer");

        string detail = customer.formatMovie("heheh{}{}}{{price}blabla", "Super film", 12.2);

        string statement = customer.statement();

        EXPECT_EQ(detail, "heheh{}{}}{12.2blabla");
    }

    TEST(FormatMovie, MISSING_PRICE) {
        Customer customer("Customer");

        string detail = customer.formatMovie("21323321{title}}}}}}}swqw{}{àe$}", "{film}", 12.2);

        string statement = customer.statement();

        EXPECT_EQ(detail, "21323321{film}}}}}}}swqw{}{àe$}");
    }

    TEST(FormatMovie, MISSING_ALL) {
        Customer customer("Customer");

        string detail = customer.formatMovie("pas de film", "Super film", 12.2);

        string statement = customer.statement();

        EXPECT_EQ(detail, "pas de film");
    }
}

