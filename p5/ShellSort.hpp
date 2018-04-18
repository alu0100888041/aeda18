

#ifndef ShellSort_hpp
#define ShellSort_hpp

#include <stdio.h>
#endif /* ShellSort_hpp */

template <class T>
class ShellSort: public Sort<T> {
public:
    ShellSort(){};
    virtual ~ShellSort(){};
    void MethodSort(T* ,int, int&, int);
    void DeltaSort(int d,T* v, int sz,int& cnt, int modo_);
    
};

template <class T>
void ShellSort<T>::MethodSort(T* v, int sz, int& cnt, int modo_) {
    int del=sz;
    double alfa=0.7;
    /*cout<<"Introduce valor 0 < alfa < 1 : "; cin>>alfa;*/
    while(del>1) {
        del=del*alfa;
        if(modo_==1){
        cout << endl <<"------------------------------------------------------------------DESCOMPOSICION DELTA="<<del<<endl;
        }
        DeltaSort(del,v,sz,cnt, modo_);
        if (del==1) {
            del=0;
        }
    }
    
    if(modo_==1){
    cout<<endl;
    cout<< "VECTOR REORDENADO: ";
    for(int i=0;i<sz;i++){
    cout<<v[i]<<" ";
    }
    cout<<endl;
    }
     
}


template <class T>
void ShellSort<T>::DeltaSort(int d,T* v, int sz,int& cnt, int modo_) {
    for(int i=d;i<sz;i++) {
        T x=v[i];
        int j=i;
        if(modo_==1){
        cout<<"Comparando elemento: "<<v[j-d]<<" ";
        cout<<"con elemento: "<<v[i]<<" ";
        cout << endl << endl;
        }
        while((j>d)&&(x<v[j-d])) {
            v[j]=v[j-d];
            j=j-d;
        }
        cnt++;
        v[j]=x;
        
        if(modo_==1){
        cout<<endl;
        cout<< "VECTOR REORDENADO: ";
        for(int i=0;i<sz;i++){
            cout<<v[i]<<" ";
        }
        cout<<endl;
        }
        
    }
}