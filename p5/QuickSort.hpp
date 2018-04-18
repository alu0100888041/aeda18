

#ifndef QuickSort_hpp
#define QuickSort_hpp

#include <stdio.h>

#endif /* QuickSort_hpp */

template <class T>
class QuickSort: public Sort<T> {
public:
    QuickSort(){};
    virtual ~QuickSort(){};
    void MethodSort(T* ,int, int&, int);
    void Qsort(T* v,int ini, int fin, int&, int);
    
};


template <class T>
void QuickSort<T>::MethodSort(T* v, int sz, int& cnt, int modo_) {
    Qsort(v,0,sz-1,cnt, modo_);
}


template <class T>
void QuickSort<T>::Qsort(T* v,int ini, int fin, int& cnt, int modo_){
    int i = ini;
    int f = fin ;
    T p = v[(i+f)/2] ;
    
    while (i <= f) {
        if(modo_==1){
        cout<<"Pivote: "<<p<<endl;
        }
        while (v[i] < p) {
            if(modo_==1){
            cout<<"Recorrido Ascendente -------------- "<<endl;
            cout<<"Comparando Elemento: "<<v[i]<<endl;
            }
            i++;

            cnt++;
        }
        while (v[f] > p) {
            if(modo_==1){
            cout<<"Recorrido Descendente ------------- "<<endl;
            cout<<"Comparando Elemento: "<<v[f]<<endl;
            }
            f--;

            cnt++;
        }
        if (i <= f) {
            T x = v[i];
            v[i] = v[f];
            v[f] = x;
            i++;
            f--;
        }
        
        if(modo_==1){
        cout<<endl<<endl;
        cout<< "VECTOR REORDENADO: ";
        for(int y=0;y<=fin;y++){
            cout<<v[y]<<" ";
        }
        cout<<endl;
        }
    }
    
    if (ini < f) {
        Qsort(v, ini, f, cnt, modo_);
    }
    if (i < fin) {
        Qsort(v, i, fin, cnt, modo_);
    }
    
}


