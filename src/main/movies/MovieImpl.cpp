#include <string>
#include "MovieImpl.h"

using namespace std;

MovieImpl::MovieImpl(const string &title, int priceCode)
        : _title(title), _priceCode(priceCode) {}

int MovieImpl::getPriceCode() const {
    return _priceCode;
}

void MovieImpl::setPriceCode(int arg) {
    _priceCode = arg;
}

string MovieImpl::getTitle() const {
    return _title;
}