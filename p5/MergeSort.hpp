

#ifndef MergeSort_hpp
#define MergeSort_hpp

#include <stdio.h>

#endif /* MergeSort_hpp */

template <class T>
class MergeSort: public Sort<T> {
public:
    MergeSort(){};
    virtual ~MergeSort(){};
    void MethodSort(T*,int,int&, int);
    void Msort(T* v, int ini, int fin, int& cnt, int modo_);
    void Mezcla(T* v, int ini, int cen, int fin, int& cnt);
};


template <class T>
void MergeSort<T>::MethodSort(T* v,int sz,int& cnt, int modo_) {
    Msort(v,0,sz-1,cnt, modo_);
}


template <class T>
void MergeSort<T>::Msort(T* v, int ini, int fin,int& cnt, int modo_) {
    if(ini<fin) {
        int cen=(ini+fin)/2;
        if(ini!=fin && modo_==1){
            cout<<"Msort:[";
            for(int h=ini;h<=fin;h++){
                cout<<v[h]<<" ";
            }
            cout<<"]"<<endl;
        }
        Msort(v,ini,cen,cnt,modo_);
        Msort(v,cen+1,fin,cnt,modo_);
        if(modo_==1){
            cout<<"Mezcla:[";
            for(int h=ini;h<=fin;h++){
                cout<<v[h]<<" ";
            }
            cout<<"] ---> [";
        }
        Mezcla(v,ini,cen,fin,cnt);
        if(modo_==1){
            for(int h=ini;h<=fin;h++){
                cout<<v[h]<<" ";
            }
            cout<<"]"<<endl;
        }
    }
}

template <class T>
void MergeSort<T>::Mezcla(T* v, int ini, int cen, int fin, int& cnt) {
    int i = ini; int j = cen + 1 ; int k = ini ;
    T aux[fin+1];
    while ((i <= cen) && (j <= fin)){
        if (v[i] < v[j]){ 
            aux[k] = v[i] ;
            i++ ;
        }
        else{ 
            aux[k] = v[j] ;
            j++ ;
        }
        k++ ;cnt++;
    }
    
    if (i > cen)
        while (j <= fin){ 
            aux[k] = v[j] ;
            j++ ; k++ ;
        }
    else
        while (i <= cen){ 
            aux[k] = v[i] ;
            i++ ; k++ ;
        };
    //cout<<"\nordenado: ";
    for (k = ini; k <= fin; k++){
        v[k] = aux[k] ;
        //cout<<v[k]<<" ";
    }

}


