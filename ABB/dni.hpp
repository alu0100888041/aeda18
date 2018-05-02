#pragma once
#include <iostream>
#include <cstdio>
#include <stdlib.h>     /* srand, rand */
#include <time.h>       /* time */
#include <iomanip>
#include <stdint.h>
#include <string>
#include <stdio.h>
#include <cstdlib>  // Para generación de números pseudoaleatorios
#include <chrono>// Recursos para medir tiempos
#include <random>

extern int contador;

using namespace std;

class DNI{

  private:
    unsigned long int numero_;
    char letra_;
  public:
  
    // CONSTRUCTOR
    DNI(void){
      numero_ = 0;
      letra_ = '&';
    }
    DNI(long int num){
      numero_ = num;
    }

    // METODOS
    void set_Dni(int num){
      this->numero_ = num;
    }
    long int get_Dni(){
      return numero_;
    }
    char get_Letra(){
      return letra_;
    }
    void set_Letra(char letrilla){
      this->letra_ = letrilla;
    }

    long int operator% (const int& num){
      long int resultado = numero_ % num;
      return resultado;
    }
    
    long int operator% (DNI& aux){
      long int resultado = numero_ % aux.numero_;
      return resultado;
    }
    
    void operator= (const int& num){
       this->numero_ = num;
    
    }
    
    void operator= (const DNI& aux){
       this->numero_ = aux.numero_;
       this->letra_ = aux.letra_;
    
    }
    
    
    /**********************************************************/
    bool operator== (const DNI& aux) const{
      contador++;
      if(this->numero_ == aux.numero_)
        return true;
      else if ((this->numero_ == aux.numero_) && (this->letra_ == aux.letra_))
        return true;
      else
        return false;
    }
    bool operator== (const int& num) const{
      contador++;
      if (this->numero_ == num)
        return true;
      else
        return false;
    }
    
    /******************************************************************/
    bool operator!= (const DNI& aux)const{
      contador++;
      if(this->numero_ == aux.numero_)
        return false;
      else if ((this->numero_ == aux.numero_) && (this->letra_ == aux.letra_))
            return false;
        else
            return true;
    }
    
    bool operator!= (const int& num) const{
      contador++;
      if (this->numero_ == num)
        return false;
      else
        return true;
    }
    
    
    /***********************************************************************/
    bool operator> (const DNI& aux) const{
        contador++;
        if(this->numero_ > aux.numero_)
          return true;
        
        else if ((this->numero_ > aux.numero_) && (this->letra_ > aux.letra_))
            return true;
        else
            return false;
    }
    bool operator> (const int& num) const{
        contador++;
        if (this->numero_ > num)
            return true;
        else
            return false;
    }
    
    
    /***************************************************************************/
    
    bool operator< (const DNI& aux)const{
        contador++;
        if(this->numero_ < aux.numero_)
          return true;
        else if ((this->numero_ < aux.numero_) && (this->letra_ < aux.letra_))
            return true;
        else
            return false;
    }
    bool operator< (const int& num) const{
        contador++;
        if (this->numero_ < num)
            return true;
        else
            return false;
    }
    
  /******************************************************************************/
    bool operator>= (const DNI& aux)const{
        contador++;
        if(this->numero_ >= aux.numero_)
          return true;
        else if (this->numero_ >= aux.numero_ && this->letra_ >= aux.letra_)
            return true;
        else
            return false;
    }
    bool operator>= (const int& num) const{
        contador++;
        if (this->numero_ >= num)
            return true;
        else
            return false;
    }
    
    
    bool operator<= (const DNI& aux)const{
        contador++;
        if(this->numero_ <= aux.numero_)
          return true;
        else if (this->numero_ <= aux.numero_ && this->letra_ <= aux.letra_)
            return true;
        else
            return false;
    }
    bool operator<= (const int& num) const{
        contador++;
        if (this->numero_ <= num)
            return true;
        else
            return false;
    }
    
    operator long int () const{
        return numero_;
    }
    
    ostream& write (ostream& os) const{
      os << numero_ << letra_;
      return os;
    }

};
