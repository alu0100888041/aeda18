#ifndef Heap_hpp
#define Heap_hpp

#include <stdio.h>

#endif /* HeapSort_hpp */

template <class T>
class HeapSort: public Sort<T> {
public:
    HeapSort(){};
    virtual ~HeapSort(){};
    void MethodSort(T* ,int, int&, int);
    void baja(T* v, int i, int n, int&);
    void makeheap(T* v, int n, int&);
};



template <class T>
void HeapSort<T>::baja(T* v, int i, int sz, int& cnt){
    
    int l=i;
    int j=2*l+1;
    T x=v[i];
    
    while(j<sz){
        if(j<sz-1)
            if(v[j]<v[j+1])
            j++;
        if((x>v[j])||(x==v[j]))
            break;
        v[i]=v[j];
        i=j;
        j=2+i+1;
    }
    v[i]=x;
    
}


template <class T>
void HeapSort<T>::makeheap(T* v, int sz, int&cnt){
    
    int l=sz/2;
    while(l){
        l--;
        cnt++;
        baja(v,l,sz,cnt);
    }
}


template <class T>
void HeapSort<T>::MethodSort(T* v, int sz, int& cnt, int modo_) {

    makeheap(v,sz,cnt);

    while(sz>1){
        T x=v[0];
        sz--;
        v[0]=v[sz];
        v[sz]=x;
        baja(v,0,sz,cnt);
        cnt++;
    }

    
}