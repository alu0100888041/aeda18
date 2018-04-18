
#include "Test.hpp"
#include <iostream>
#include <cstdlib>

using namespace std;

int main() {
	int modo;
	
	cout << "1-> Demostración"<< endl;
	cout << "2-> Estadística." << endl;
	cout << "Indique el modo que desea usar: ";
	cin >> modo;
	
	Test<DNI> PRUEBAS;
	PRUEBAS.RunTest(modo);
}
