

#ifndef Selection_hpp
#define Selection_hpp

#pragma once
#include <stdio.h>
#endif /* SelectionSort_hpp */

template <class T>
class SelectionSort: public Sort<T> {
public:
    SelectionSort(){};
    virtual ~SelectionSort(){};
    void MethodSort(T* ,int, int&, int);
};


template <class T>
void SelectionSort<T>::MethodSort(T* v, int sz, int& cnt, int modo_) {
for (int i=0; i < sz; i++) {
        int min = i;
            for (int j = i+1; j < sz; j++){
        		if(modo_==1){
                cout<<"Comparando elemento: "<< v[min] << " ";
                cout << "con elemento: " << v[j] << endl;
                }
        		if (v[j] < v[min])
        			min = j;
            }

        cnt++;
        
        T x = v[min];
        v[min] = v[i];
        v[i] = x;
        
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