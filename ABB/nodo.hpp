#pragma once
#include <iostream>


using namespace std;


template <class T>
class nodoBB{
    
    private:
        T dato_;
        nodoBB<T> *izdo_;
        nodoBB<T> *dcho_;
    
    public:
        
        nodoBB(T dat, nodoBB *izq=NULL, nodoBB *der=NULL):
            dato_(dat),
            izdo_(izq),
            dcho_(der)
            {}
            
        nodoBB(void):
            izdo_(NULL),
            dcho_(NULL)
            {}
            
        ~nodoBB (void){
            
            if (izdo_ != NULL){
                delete izdo_;
                izdo_ = NULL;
            }
            if (dcho_ != NULL){
                delete dcho_;
                dcho_ = NULL;
            }
        }

    /* Devuelve el dato del nodo */
        T get_dato (void){
            return dato_;
        }
    
        /* Asigna un valor al dato del nodo */
        void set_dato (T dato){
            dato_ = dato;
        }
    
        /* Devuelve el nodo raíz del sub-árbol izquierdo */
        nodoBB<T>*& get_izdo(void){
            return izdo_;
        }
    
        /* Devuelve el nodo raíz del sub-árbol derecho */
        nodoBB<T>*& get_dcho(void){
            return dcho_;
        }
    
        /* Imprime el nodo formateado */
        ostream& write (ostream& os) const
        {
            // Si el nodo está vacío...
            if (this == NULL){
                os << "[.]";
            }
            // Si el nodo NO está vacío...
            else{
                os << "[";
                dato_.write(os);
                cout << "]";
            }
            return os;
        }
};
