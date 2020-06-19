#include <iostream>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

using std::cout;
using std::cin;
using std::endl;

int main(int argc, char** argv) {
	
	bool loop = true;
	while(loop) {
	
		cout<<"********MENU********" << endl
			<<"1) " << endl
			<<"2) " << endl
			<<"3) " << endl
			<<"4)Salida " << endl
			<<"Su eleccion: ";
	
		int opcion;
		cin >> opcion;
	
		while (!cin || (opcion < 1 || opcion > 4)) {
			cin.clear ();    // Restore input stream to working state
    		cin.ignore ( 100 , '\n' );    // Get rid of any garbage that user might have entered
   		 	cout << "Por favor, ingrese una opcion valida: ";
    		cin >> opcion; 
		}
		
		switch(opcion) {
			case 1: {
				
				break;
			}
			case 2: {
				
				break;
			}
			case 3: {
				
				break;
			}
			case 4: {
				cout << "Saliendo ...";
				loop = false;
				break;
			}
		}
	}
	return 0;
	
}
