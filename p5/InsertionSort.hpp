

#ifndef Insercion_hpp
#define Insercion_hpp

#pragma once
#include <stdio.h>

#endif /* InsertionSort_hpp */

template <class T>
class InsertionSort: public Sort<T> {
public:
    InsertionSort(){};
    virtual ~InsertionSort(){};
    void MethodSort(T* ,int, int&, int);
};


template <class T>
void InsertionSort<T>::MethodSort(T* v, int sz, int& cnt, int modo_) {
    for (int i=0; i<sz; i++) {
        int j=i;
        T x=v[i];
        v[-1]=x;

        if(modo_==1){
        cout<<"Comparando elemento: "<<v[i]<<" ";
        }
        
        v[j]=v[j-1];
        
        if(modo_==1){
        cout<<"con elemento: "<<v[j]<<" ";
        }

        cnt++;
        
        while(x < v[j-1]) {
            v[j]=v[j-1];

            if(modo_==1){
            cout<<"con elemento: "<<v[j-2]<<" ";
            }
            
            j--;
            cnt++;
        }
        v[j]=x;
        
        if(modo_==1){
        cout<<endl<<endl;
        cout<< "VECTOR REORDENADO: ";
        for(int i=0;i<sz;i++){
            cout<<v[i]<<" ";
        }
        cout<<endl;
        }
        
    }
}