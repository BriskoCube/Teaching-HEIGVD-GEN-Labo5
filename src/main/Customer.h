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

inline Customer::
Customer() {}

inline Customer::
Customer( const std::string& name )
        : _name( name ) {}

inline void Customer::
addRental( std::shared_ptr<AbstractRental> arg) { _rentals.push_back( move(arg) ); }

inline std::string Customer::
getName() const { return _name; }

#endif // CUSTOMER_H