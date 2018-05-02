#include "dni.hpp"
#include "arbol.hpp"


#include <iostream>
#include <vector>
#include <cstdlib>
#include <limits>


using namespace std;

bool demo = false;
int contador;

void funcion(int opcion, arbolBB<DNI> arbolito){
    
    demo = true;
    
    long int numero;
    
    cout << "\n\tIntroduzca valor de clave: ";
    cin >> numero;
    cout << endl;
    
    DNI clave(numero);
    
    char letrasDNI[24]="TRWAGMYFPDXBNJZSQVHLCKE"; 
    clave.set_Letra(letrasDNI[numero % 23]);
    
    clave.write(cout);
    cout << endl;
    
    arbolito.write(cout);
    cout << endl;
    
    if(opcion == 1){
        arbolito.insertar(clave);
        arbolito.write(cout);
        cout << endl;
    }
    else if(opcion == 2){
        arbolito.eliminar(clave);
        arbolito.write(cout);
        cout << endl;
    }
    
    
}



void menu (void){
        
        unsigned int opmenu;
        unsigned int opalg;
        
        do{
        
            
            cout << "\n\tMENU:";
            cout << "\n\t0 - Salir del programa";
            cout << "\n\t1 - MODO DEMOSTRACION";
            cout << "\n\t2 - MODO ESTADISTICA";
             
            cout << "\n\n\tIntroduzca la opción: ";
            cin >> opmenu;
            cin.get();
            
            if(opmenu == 1){
                
                demo = true;
                
                arbolBB<DNI> arbolito;
                cout << "\tArbol vacio:"<<endl;
                arbolito.write(cout);
                cout << endl;
                
                do{
                
                    
                    arbolito.write(cout);
                    cout << endl;
                    cout << "\n\t\t1 - Insertar Clave";
                    cout << "\n\t\t2 - Eliminar Clave";
                    cout << "\n\t\t0 - Salir del programa";
                 
                    cout << "\n\n\tIntroduzca la opción: ";
                    cin >> opalg;
                    cin.get();
                
                    switch (opalg){
                    
                        case 1: {       
                            long int numero;
    
                            cout << "\n\tIntroduzca valor de clave: ";
                            cin >> numero;
                            cout << endl;
                            
                            DNI clave(numero);
                            
                            char letrasDNI[24]="TRWAGMYFPDXBNJZSQVHLCKE"; 
                            clave.set_Letra(letrasDNI[numero % 23]);
                            
                            
                            arbolito.insertar(clave);
                            /*cout << endl;
                            //arbolito.write(cout);
                            cout << endl;*/
                            
                            break;                              
                            
                        }
                    
                        case 2: { 
                            long int numero;
    
                            cout << "\n\tIntroduzca valor de clave: ";
                            cin >> numero;
                            cout << endl;
                            
                            DNI clave(numero);
                            
                            char letrasDNI[24]="TRWAGMYFPDXBNJZSQVHLCKE"; 
                            clave.set_Letra(letrasDNI[numero % 23]);
                            
                            clave.write(cout);
                            cout << endl;
                            
                            arbolito.eliminar(clave);
                            //arbolito.write(cout);
                            cout << endl;
                            
                            break;
                        }
                    
                        default: {      break;                              }
                    
                    }
                
                }while(opalg != 0);
            }
            
            else if (opmenu == 2){
                demo = false;
    
                cout << "\tMODO ESTADISTICO" << endl;
                int max_sz;
                
                cout << "\n\tIntroduzca tamaño del arbol: ";
                cin >> max_sz;
                cout << endl;
                
                int tam = 2 * max_sz;
                
                arbolBB<DNI> arbolito;
                vector<DNI> bancoPruebas(tam);
                vector<int> posiciones;
                
                bancoPruebas.clear();
                bancoPruebas.resize(tam);
                
                srand(time(NULL));
                
                long int num;
                char letrasDNI[24]="TRWAGMYFPDXBNJZSQVHLCKE";
                
                for(int j = 0; j<tam;j++){
                    num = rand()%50000000+30000001;
                    bancoPruebas[j] = num;
                    
                    bancoPruebas[j].set_Letra(letrasDNI[bancoPruebas[j] % 23]);
            
                }
                
                for(int i = 0; i <tam; i++){
                    bancoPruebas[i].write(cout);
                    cout << endl;
                }
                
                
                for(int i = 0; i < max_sz; i++){
                    arbolito.insertar(bancoPruebas[i]);
                }
                
                
                int npruebas;
                int min, max;
                int media = 0;
                int suma = 0;
                
                cout << "\n\tIntroduzca el número de pruebas: ";
                cin >> npruebas;
                cout << endl;
                
                
                
                posiciones.clear();
                posiciones.resize(npruebas);
                
                suma = 0;
                min = std::numeric_limits<int>::max();
                max = std::numeric_limits<int>::min();
                
                for(int i = 0; i < npruebas; i++){
                    contador = 0;
                    arbolito.buscar(bancoPruebas[posiciones[i]]);
                    
                    if(contador < min){
                        min = contador;
                    }
                    
                    if(contador > max){
                        max = contador;
                    }
                    
                    suma += contador;
                    
                }
                
                media = suma/npruebas;
                
                const char * alg[] = {"BÚSQUEDA", "INSERCIÓN"};
    
                cout << "\t----------TABLA ESTADÍSTICA----------"<<endl;
                cout << setw(30) << "N" << setw(10) << "PRUEBAS" << setw(10) << "MINIMO" << setw(10) << "MEDIA" << setw(10) << "MAXIMO"<< endl;
                cout << setw(15) << alg[0]<< setw(15)<<max_sz<<setw(10)<<npruebas<<setw(10) << min << setw(10) << media << setw(10) << max <<endl;
                cout << setw(15) << alg[1]<< setw(15)<<max_sz<<setw(10)<<npruebas<<setw(10) << min << setw(10) << media << setw(10) << max <<endl;
            }
            
        }while (opmenu != 0);
    
        
}

int main (void){
    
    menu();
    
    return 0;
}