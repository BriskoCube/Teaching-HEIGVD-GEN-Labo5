// Customer.h
#ifndef CUSTOMER_H
#define CUSTOMER_H
#include <string>
#include <vector>
#include "AbstractRental.h"

class Customer {
public:
    Customer();
    explicit Customer( const std::string& name );

    void addRental( std::shared_ptr<AbstractRental> arg );
    std::string getName() const;
    std::string statement();

private:
    std::string _name;
    std::vector<std::shared_ptr<AbstractRental>> _rentals;
};

#endif // CUSTOMER_H