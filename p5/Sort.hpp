
#ifndef Sort_hpp
#define Sort_hpp

#include <stdio.h>

#endif /* Sort_hpp */


using namespace std;

template <class T>
class Sort {

    public:
        Sort(){};
        virtual ~Sort(){};
        virtual void MethodSort(T*, int, int&, int)=0;
};