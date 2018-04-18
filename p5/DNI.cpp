
#include "DNI.hpp"


DNI::DNI() {
    value_=0;
}


DNI::DNI(unsigned long int value) {
    value_=value;
}


DNI::DNI(DNI& n) {
    value_=n.value_;
}


DNI::~DNI() {
    value_=0;
}


int DNI::get_value() {
    return value_;
}


int DNI::operator %(int n) {
    return value_%n;
}


bool DNI::operator==(DNI& n) const {
    return value_==n.value_;
}


bool DNI::operator==(int n) const {
    return value_==n;
}


bool DNI::operator <(DNI& n) const {
    if(value_ < n.value_)
        return true;
    else
        return false;
}


bool DNI::operator >(DNI& n) const {
    if(value_ > n.value_)
        return true;
    else
        return false;
}


DNI& DNI::operator = (DNI& n) {
    value_ = n.value_;
    return *this;
}


DNI& DNI::operator = (int i) {
    value_=i;
    return *this;
}


ostream& DNI::imprimir(ostream& os) const {
    os << value_;
    return os;
}


ostream& operator <<(ostream& os, DNI& n) {
    os << n.value_;
    return os;
}