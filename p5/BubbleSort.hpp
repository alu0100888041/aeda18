

#ifndef Burbuja_hpp
#define Burbuja_hpp

#include <stdio.h>

#endif /* BubbleSort_hpp */

template <class T>
class BubbleSort: public Sort<T> {
public:
    BubbleSort(){};
    virtual ~BubbleSort(){};
    void MethodSort(T* ,int, int&, int);
};


template <class T>
void BubbleSort<T>::MethodSort(T* v, int sz, int& cnt, int modo_) {
    for (int i = 1; i < sz; i++) {
        for (int j = sz-1; j >= i; j--) {
            
            if(modo_==1){
            cout<<"Comparando elemento: "<<v[j]<<" ";
            cout<<"con elemento: "<<v[j-1]<<" ";
            }
            
            if (v[j] < v[j-1]) {
                T x = v[j-1];
                v[j-1] = v[j];
                v[j] = x;
            }
            cnt++;
            
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
}