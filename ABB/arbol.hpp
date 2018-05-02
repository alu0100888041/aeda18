#pragma once
#include <iostream>
#include <stddef.h>
#include "nodo.hpp"
#include "dni.hpp"
#include "cola.hpp"

using namespace std;


template <class T>
class arbolBB{
    private:
        nodoBB<T> *raiz_;
        
    public:
        
        arbolBB(void):
            raiz_(NULL)
            {}
            
        arbolBB(nodoBB<T>* raiz):
            raiz_(raiz)
            {}
            
        ~arbolBB (void){
            
            podar(raiz_);
        }
    
        /* Elimina la rama cuya raíz se pasa como parámetro */
        void podar (nodoBB<T>* &nodo){
            
            if (nodo != NULL){  // Si el nodo no está vacío...
                podar(nodo->get_izdo());  // Elimina el sub-árbol izquierdo
                podar(nodo->get_dcho());  // Elimina el sub-árbol derecho
                delete nodo;  // Elimina el nodo
                nodo = NULL;
            }
        }
        
        nodoBB<T>* buscar(T clave_dada){
            return buscarRama(raiz_, clave_dada);
        }
        
        nodoBB<T>* buscarRama(nodoBB<T>* nodo, T clave_dada){
            contador ++;
            
            if(nodo == NULL)
                return NULL;
            if(clave_dada == nodo->get_dato())
                return nodo;
            if(clave_dada < nodo->get_dato())
                return buscarRama(nodo->get_izdo(), clave_dada);
            return buscarRama(nodo->get_dcho(), clave_dada);
        }
        
        void insertar(T clave_dada){
            insertarRama(raiz_, clave_dada);
        }
        
        void insertarRama(nodoBB<T>* &nodo, T clave_dada){
            if(nodo == NULL){
                nodo = new nodoBB<T>(clave_dada);
            }
            else if(clave_dada < nodo->get_dato()){
                insertarRama(nodo->get_izdo(), clave_dada);
                
            }
            else{
                insertarRama(nodo->get_dcho(), clave_dada);
                
            }
        }
        
        void eliminar(T clave_dada){
            eliminarRama(raiz_, clave_dada);
        }
        
        void eliminarRama(nodoBB<T>* &nodo, T clave_dada){
            if(nodo == NULL){
                cerr << "Ese nodo no se encuentra en el arbol" << endl;
            }
            
            else{
                if(clave_dada < nodo->get_dato()){
                    eliminarRama(nodo->get_izdo(), clave_dada);
                }
                else if (clave_dada > nodo->get_dato()){
                    eliminarRama(nodo->get_dcho(), clave_dada);
                }
                else{
                    
                    if(nodo->get_dcho() == NULL){
                        nodo = nodo->get_izdo();
                    }
                    else if(nodo->get_izdo() == NULL){
                        nodo = nodo->get_dcho();
                    }
                    else{
                        nodoBB<T>* eliminado = nodo;
                        sustituye(eliminado, nodo->get_izdo());
                    }
                    //delete(eliminado);
                }
            }
        }
        
        void sustituye(nodoBB<T>* &eliminado, nodoBB<T>* &sust){
            if(sust->get_dcho() != NULL){
                sustituye(eliminado, sust->get_dcho());
            }
            else{
                eliminado->set_dato(sust->get_dato());
                eliminado = sust;
                sust = sust->get_izdo();
            }
        }
        
        
        const bool balanceado(void){
            return balanceRama(raiz_);
        }
        
        ostream& write (ostream& os) const{
            
            COLA<T> cola;  // Cola para guardar los nodos por niveles
            nodoBB<T>* nodo;  // Nodo auxiliar
            int nivel = 0;  // Nivel auxiliar
            int nivel_actual = 0;  // Nivel actual
            cola.insertar(raiz_, nivel);// Se inserta el primer nodo y nivel (nodo raíz y nivel 0)
            cout << "\t";
            os << "Nivel 0: ";
            // Mientras la cola no esté vacía...
            while (!cola.vacia()){
                cola.extraer(nodo, nivel);  // Se extrae un nodo y nivel
                // Si el nivel extraído es mayor que el nivel actual, se aumenta el nivel actual
                if (nivel > nivel_actual){
                    nivel_actual = nivel;
                    os << "\n\tNivel " << nivel_actual << ": ";
                }
                nodo->write(os);
                // Si el nodo extraído no está vacío, se insertan sus dos hijos en la cola
                if (nodo != NULL){
                    cola.insertar(nodo->get_izdo(), nivel+1);
                    cola.insertar(nodo->get_dcho(), nivel+1);
                }
            }
        }
        
        const bool balanceRama(nodoBB<T>* nodo){
            if(nodo == NULL){
                return true;
            }
            
            int balance = altura(nodo->get_izdo()) - altura(nodo->get_dcho());
            
            switch(balance){
                case -1:
                case 0:
                case 1:
                return balanceRama(nodo->get_izdo()) && balanceRama(nodo->get_dcho());
                default: return false;
            }
        }
        
        
        
};