

#ifndef DNI_hpp
#define DNI_hpp

#pragma once
#include <stdio.h>
#include <iostream>
#include <iomanip>

#endif /* DNI_hpp */

using namespace std;

class DNI {
private:
    unsigned long int value_;
    
public:
    DNI();
    DNI(unsigned long int);
    DNI(DNI&);
    ~DNI();
    
    int get_value();
    
    int operator %(int);
    bool operator==(DNI&) const;
    bool operator==(int) const;
    bool operator<(DNI&) const;
    bool operator>(DNI&) const;
    DNI& operator=(DNI&);
    DNI& operator=(int);
    
    
    
    ostream& imprimir(ostream&) const;
    friend ostream& operator <<(ostream&, DNI&);
};

