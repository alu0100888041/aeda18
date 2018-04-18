
#ifndef Test_hpp
#define Test_hpp

#include <stdio.h>
#include <time.h>
#include <cstdlib>
#include <iostream>
#include <cmath>
#include "Sort.hpp"
#include "ShakeSort.hpp"
#include "SelectionSort.hpp"
#include "InsertionSort.hpp"
#include "BubbleSort.hpp"
#include "MergeSort.hpp"
#include "QuickSort.hpp"
#include "ShellSort.hpp"
#include "HeapSort.hpp"
#include "DNI.hpp"

#endif /* Test_hpp */
using namespace std;

template <class T>
class Test {
    private:
        Sort<T>* method;
        unsigned Npruebas;
        char option;
        T** vectorpruebas;
        int sz_;
        int comp_;
        int compmax_;
        long compmin_;
    
    public:
        Test();
        ~Test();
        void RunTest(int modo_);
};


template <class T>
Test<T>::Test() {
    method=NULL;
    Npruebas=0;
    vectorpruebas=NULL;
    sz_=0;
    comp_=0;
    compmax_=0;
    compmin_=100000000000000;
}


template <class T>
Test<T>::~Test() {}


template <class T>
void Test<T>::RunTest(int modo_) {
    cout<<"Introduzca el tamaño del vector de elementos que desea ordenar: ";
    cin>>sz_;
    
if(modo_==1){
    while (sz_>25) {
        cout<<"El tamaño maximo es de 25, introduzca nuevo valor: ";
        cin>>sz_;
    }
    
    cout<<endl<<"INTRODUZCA EL NUMERO DEL ALGORITMO QUE DESEA EJECUTAR."<<endl;
    cout<<endl<<"1-> Insertionsort.";
    cout<<endl<<"2-> Bubblesort.";
    cout<<endl<<"3-> ShellSort.";
    cout<<endl<<"4-> Quicksort.";
    cout<<endl<<"5-> MergeSort.";
    cout<<endl<<"6-> SelectionSort.";
    cout<<endl<<"7-> ShakeSort.";
    cout<<endl<<"8-> HeapSort.";
    cout<<endl<<"NUMERO ALGORITMO: ";
    cin>>option;
    cout<<endl;
    Npruebas=1;
}else if(modo_==2){
    cout<<"Numero de pruebas: ";
    cin>> Npruebas;
}
    
    char num_letra[9];
    unsigned long int suma_letras=0;
    
    vectorpruebas=new T*[Npruebas];
    srand(time(NULL));
    
    for (int n=0;n<Npruebas;n++){
        vectorpruebas[n]=new T[sz_];
        for(int h=0;h<sz_;h++){
            char letra;
            for (int j=0;j<9;j++){
                if(j<8){
                    
                    letra = (rand()%10)+48;
                    num_letra[j] = letra;
                }
                else{
                    
                    letra = (rand()%26)+65;
                    num_letra[j] = letra;
                }
                //cout<<letra;
            }
            cout<<num_letra<<endl;
            
            //CONVERSION DE LETRAS A NUMEROS
            suma_letras=0;
            for(int j=0;j<=8;j++){
            suma_letras+=num_letra[j];
            }
            vectorpruebas[n][h]=suma_letras;
            
        }
        
    }

if(modo_==1){
    switch(option) {
        case '1':
            method=new InsertionSort<T>;
            cout<< "VECTOR DE "<< sz_ << " ELEMENTOS: ";
            for(int i=0;i<sz_;i++) {
                cout<<vectorpruebas[0][i]<<" ";
            }
            cout<<endl;
            method->MethodSort(vectorpruebas[0], sz_, comp_, modo_);
            cout<<endl;
            break;
            
        case '2':
            method=new BubbleSort<T>;
            cout<< "VECTOR DE "<< sz_ << " ELEMENTOS: ";
            for(int i=0;i<sz_;i++) {
                cout<<vectorpruebas[0][i]<<" ";
            }
            cout<<endl;
            method->MethodSort(vectorpruebas[0], sz_, comp_, modo_);
            cout<<endl;
            break;
        
        case '3':
            method=new ShellSort<T>;
            cout<< "VECTOR DE "<< sz_ << " ELEMENTOS: ";
            for(int i=0;i<sz_;i++) {
                cout<<vectorpruebas[0][i]<<" ";
            }
            cout<<endl;
            method->MethodSort(vectorpruebas[0], sz_, comp_, modo_);
            cout<<endl;
            break;
        
        case '4':
            method=new QuickSort<T>;
            cout<< "VECTOR DE "<< sz_ << " ELEMENTOS: ";
            for(int i=0;i<sz_;i++) {
                cout<<vectorpruebas[0][i]<<" ";
            }
            cout<<endl;
            method->MethodSort(vectorpruebas[0], sz_, comp_, modo_);
            cout<<endl;
            break;
        
        case '5':
            method=new MergeSort<T>;
            cout<< "VECTOR DE "<< sz_ << " ELEMENTOS: ";
            for(int i=0;i<sz_;i++) {
                cout<<vectorpruebas[0][i]<<" ";
            }
            cout<<endl;
            method->MethodSort(vectorpruebas[0], sz_, comp_, modo_);
            cout<<endl;
            break;
        
        case '6':
            method=new SelectionSort<T>;
            cout<< "VECTOR DE "<< sz_ << " ELEMENTOS: ";
            for(int i=0;i<sz_;i++) {
                cout<<vectorpruebas[0][i]<<" ";
            }
            cout<<endl;
            method->MethodSort(vectorpruebas[0], sz_, comp_, modo_);
            cout<<endl;
            break;
            
        case '7':
            method=new ShakeSort<T>;
            cout<< "VECTOR DE "<< sz_ << " ELEMENTOS: ";
            for(int i=0;i<sz_;i++) {
                cout<<vectorpruebas[0][i]<<" ";
            }
            cout<<endl;
            method->MethodSort(vectorpruebas[0], sz_, comp_, modo_);
            cout<<endl;
            break;
            
        case '8':
            method=new HeapSort<T>;
            cout<< "VECTOR DE "<< sz_ << " ELEMENTOS: ";
            for(int i=0;i<sz_;i++) {
                cout<<vectorpruebas[0][i]<<" ";
            }
            cout<<endl;
            method->MethodSort(vectorpruebas[0], sz_, comp_, modo_);
            cout<<endl;
            break;
            
        default: break;
        
    }
    
    cout <<"---------------------------------------------------------------------------"<< endl;
    cout<< "VECTOR FINAL ORDENADO: ";
    if(modo_==1){
    for(int y=0;y<sz_;y++){
        cout<<vectorpruebas[0][y]<<" ";
    }
    cout<<endl;
    cout <<"---------------------------------------------------------------------------"<<endl<<endl;
    }
    
    
}else if(modo_==2){
    
    cout<<"COMPARACIONES-------------------------------- "<<endl;
    cout<<setw(26)<<"Mínimo"<<setw(10)<<"Medio"<<setw(12)<<"Máximo"<<endl;

    
    method=new InsertionSort<T>;
    for(int i=0;i<Npruebas;i++) {
        comp_=0;
        method->MethodSort(vectorpruebas[i], sz_, comp_, modo_);
        if (comp_<compmin_)
            compmin_=comp_;
        if(comp_>compmax_)
            compmax_=comp_;
    }
    cout<<"Inserción:"<< setw(13)<<compmin_<<setw(10)<<(compmin_+compmax_)/2<<setw(10)<<compmax_<<endl;
    delete method;
    comp_=0;
    compmax_=0;
    compmin_=100000000000000;
    
    
    method=new BubbleSort<T>;
    for(int i=0;i<Npruebas;i++) {
        comp_=0;
        method->MethodSort(vectorpruebas[i], sz_, comp_, modo_);
        if (comp_<compmin_)
            compmin_=comp_;
        if(comp_>compmax_)
            compmax_=comp_;
    }
    cout<<"Burbuja:"<< setw(15)<<compmin_<<setw(10)<<(compmin_+compmax_)/2<<setw(10)<<compmax_<<endl;
    delete method;
    comp_=0;
    compmax_=0;
    compmin_=100000000000000;
    
    
    method=new ShellSort<T>;
    for(int i=0;i<Npruebas;i++) {
        comp_=0;
        method->MethodSort(vectorpruebas[i], sz_, comp_, modo_);
        if (comp_<compmin_)
            compmin_=comp_;
        if(comp_>compmax_)
            compmax_=comp_;
    }
    cout<<"ShellSort:"<< setw(13)<<compmin_<<setw(10)<<(compmin_+compmax_)/2<<setw(10)<<compmax_<<endl;
    delete method;
    comp_=0;
    compmax_=0;
    compmin_=100000000000000;
    
    
    method=new QuickSort<T>;
    for(int i=0;i<Npruebas;i++) {
        comp_=0;
        method->MethodSort(vectorpruebas[i], sz_, comp_, modo_);
        if (comp_<compmin_)
            compmin_=comp_;
        if(comp_>compmax_)
            compmax_=comp_;
    }
    cout<<"QuickSort:"<< setw(13)<<compmin_<<setw(10)<<(compmin_+compmax_)/2<<setw(10)<<compmax_<<endl;
    delete method;
    comp_=0;
    compmax_=0;
    compmin_=100000000000000;
    
    
    method=new MergeSort<T>;
    for(int i=0;i<Npruebas;i++) {
        comp_=0;
        method->MethodSort(vectorpruebas[i], sz_, comp_, modo_);
        if (comp_<compmin_)
            compmin_=comp_;
        if(comp_>compmax_)
            compmax_=comp_;
    }
    cout<<"MergeSort:"<< setw(13)<<compmin_<<setw(10)<<(compmin_+compmax_)/2<<setw(10)<<compmax_<<endl;
    delete method;
    comp_=0;
    compmax_=0;
    compmin_=100000000000000;
 
    method=new SelectionSort<T>;
    for(int i=0;i<Npruebas;i++) {
        comp_=0;
        method->MethodSort(vectorpruebas[i], sz_, comp_, modo_);
        if (comp_<compmin_)
            compmin_=comp_;
        if(comp_>compmax_)
            compmax_=comp_;
    }
    cout<<"SelectionSort:"<< setw(9)<<compmin_<<setw(10)<<(compmin_+compmax_)/2<<setw(10)<<compmax_<<endl;
    delete method;
    comp_=0;
    compmax_=0;
    compmin_=100000000000000;
    
    method=new ShakeSort<T>;
    for(int i=0;i<Npruebas;i++) {
        comp_=0;
        method->MethodSort(vectorpruebas[i], sz_, comp_, modo_);
        if (comp_<compmin_)
            compmin_=comp_;
        if(comp_>compmax_)
            compmax_=comp_;
    }
    cout<<"ShakeSort:"<< setw(13)<<compmin_<<setw(10)<<(compmin_+compmax_)/2<<setw(10)<<compmax_<<endl;
    delete method;
    comp_=0;
    compmax_=0;
    compmin_=100000000000000;
    
    
    method=new HeapSort<T>;
    for(int i=0;i<Npruebas;i++) {
        comp_=0;
        method->MethodSort(vectorpruebas[i], sz_, comp_, modo_);
        if (comp_<compmin_)
            compmin_=comp_;
        if(comp_>compmax_)
            compmax_=comp_;
    }
    cout<<"HeapSort:"<< setw(14)<<compmin_<<setw(10)<<(compmin_+compmax_)/2<<setw(10)<<compmax_<<endl;
    delete method;
    comp_=0;
    compmax_=0;
    compmin_=100000000000000;
    
}

}


