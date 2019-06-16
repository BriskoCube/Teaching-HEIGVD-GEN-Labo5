#include <string>
#include "Movie.h"

using namespace std;

Movie::Movie(const string &title)
        : _title(title) {}

string Movie::getTitle() const {
    return _title;
}