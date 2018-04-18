
#ifndef ShakeSort_hpp
#define ShakeSort_hpp

#include <stdio.h>

#endif /* ShakeSort_hpp */

template <class T>
class ShakeSort: public Sort<T> {
public:
    ShakeSort(){};
    virtual ~ShakeSort(){};
    void MethodSort(T*,int,int&, int);
};


template <class T>
void ShakeSort<T>::MethodSort(T* v,int sz,int& cnt, int modo_) {
 
    int ini = 1;
    int fin = sz-1;
    int cam = sz;
    while (ini < fin){ 
        for (int j=fin; j>=ini; j--){
            cnt++;
            if (v[j] < v[j-1]){ 
                T x = v[j-1] ;
                v[j-1] = v[j] ;
                v[j] = x ;
                cam = j ;
            }
        }
        if(modo_==1){
        cout<<"\nizq <-- der : [ ";
        for(int h=0;h<sz;h++){
            cout<<v[h]<<" ";
        }
        cout<<"]";//<<cnt;
        }
        ini = cam + 1 ;
        for (int j = ini; j <= fin; j++){
            cnt++;
            if (v[j] < v[j-1]){ 
                T x = v[j-1] ;
                v[j-1] = v[j] ;
                v[j] = x ;
                cam = j;
            }
        }
        if(modo_==1){
        cout<<"\nizq --> der : [ ";
        for(int h=0;h<sz;h++){
            cout<<v[h]<<" ";
        }
        cout<<"]";
        }
        fin = cam - 1;
    }
}




