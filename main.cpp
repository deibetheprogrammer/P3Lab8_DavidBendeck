#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <fstream>
#include "Usuario.h"
#include "Post.h"

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

using namespace std;

//Funcion que guarda los usuarios
void guardarUsuarios(vector<Usuario*>&);

//Funcion que lee los usuarios
void leerUsuarios(vector<Usuario*>&);

int main(int argc, char** argv) {
	
	vector<Usuario*> usuarios;
	
	leerUsuarios(usuarios);
	
	bool loop = true;
	while(loop) {
	
		cout<<"********MENU********" << endl
			<<"1) Registrarse" << endl
			<<"2) Ingresar" << endl
			<<"3)Salida " << endl
			<<"Su eleccion: ";
	
		int opcion;
		cin >> opcion;
	
		while (!cin || (opcion < 1 || opcion > 3)) {
			cin.clear ();    // Restore input stream to working state
    		cin.ignore ( 100 , '\n' );    // Get rid of any garbage that user might have entered
   		 	cout << "Por favor, ingrese una opcion valida: ";
    		cin >> opcion; 
		}
		
		switch(opcion) {
			case 1: {
				
				cout << "***REGISTRO***" << "\n\n"
					 << "Ingrese su nombre: ";
				
				string nombre;
				cin >> nombre;
				
				cout << "Ingrese su nombre de usuario: ";
				
				string nomUsuario;
				cin >> nomUsuario;
				
				//Validacion
				bool repetido = false;
				
				for(int i = 0; i < usuarios.size(); i++) {
					if(usuarios[i]->nomUsuario == nomUsuario)
						repetido = true;
						break;
				}
				
				while(repetido) {
					
					repetido = false;
					cout << "El nombre de su usuario ya esta tomado, por favor escoja otro: ";
					cin >> nomUsuario;
					for(int i = 0; i < usuarios.size(); i++) {
						if(usuarios[i]->nomUsuario == nomUsuario) {
							repetido = true;
							break;
						}	
					}
				}
				
				cout << "Ingrese su clave: ";
				
				string clave;
				cin >> clave;
				
				usuarios.push_back(new Usuario(nombre,nomUsuario,clave));
				
				cout << nombre << " Se ha creado su usuario exitosamente" << "\n\n";
				
				break;
			}
			case 2: {
				
				cout << "***INGRESAR***" << "\n\n"
					 << "Ingrese su nombre de usuario: ";
				
				string nomUsuario;
				cin >> nomUsuario;
				
				cout << "Ingrese su clave: ";
				string clave;
				cin >> clave;
				
				bool pasa = false;
				Usuario* uActual = nullptr;
				
				for(int i = 0; i < usuarios.size(); i++) {
					if(usuarios[i]->nomUsuario == nomUsuario && usuarios[i]->clave == clave) {
						uActual = usuarios[i];
						pasa = true;
						break;
					}
				}
				
				if(pasa) {
					
					bool conectado = true;
					
					while(conectado) {
					
					vector<Post*> pub;
					
					cout << endl
						 << "BIENVENIDO: " << uActual->nomUsuario
						 << "\n\n";
					
					int numPost = 0;
					
					for(int i = 0; i < uActual->seguidos.size(); i++) {
						
						Usuario* seg = uActual->seguidos[i];
						vector<Post> *segPosts = &(seg->posts); 
						
						cout << ": Por " << seg->nomUsuario << ":" 
							 << endl;
						
						for(int j = 0; j < segPosts->size(); j++){
							pub.push_back(&segPosts->at(j));
							cout << "# " << numPost++ << "------------------------" << endl
								 << ":: " << segPosts->at(j).titulo << "::" << endl
								 << "[ " << segPosts->at(j).contenido << " ]" << endl
								 << "{ likes:" << segPosts->at(j).likes << " } "
								 << "{ hates:" << segPosts->at(j).hates << "} " << endl
								 << ": COMENTARIOS :" << endl;
							
							vector<string> *coment = &(segPosts->at(j).comentarios);
							for (int k = 0; k < coment->size(); k += 2) {
								cout << "_______________________________" << endl
									 << " De: " << coment->at(k) << endl
									 << "     [" << coment->at(k+1) << "]" << endl
									 << "_______________________________" << endl;
							}
						}
					}
					
					cout << ": 	Mis Posts :" 
						 << endl;
					
					vector<Post> *segPosts = &(uActual->posts);
						
					for(int j = 0; j < segPosts->size(); j++){
						pub.push_back(&segPosts->at(j));
						cout << "# " << numPost++ << "------------------------" << endl
							 << ":: " << segPosts->at(j).titulo << "::" << endl
							 << "[ " << segPosts->at(j).contenido << " ]" << endl
							 << "{ likes:" << segPosts->at(j).likes << " } "
							 << "{ hates:" << segPosts->at(j).hates << "} " << endl
							 << ": COMENTARIOS :" << endl;
							
						vector<string> *coment = &(segPosts->at(j).comentarios);
						for (int k = 0; k < coment->size(); k += 2) {
							cout << "_______________________________" << endl
								 << " De: " << coment->at(k) << endl
								 << "     [" << coment->at(k+1) << "]" << endl
								 << "_______________________________" << endl;
						}
					}
					
					cout << "----------------------------" << "\n\n"
						 << "****HOME****" << endl
						 << "(1) Crear post" << endl
						 << "(2) Comentar post" << endl
						 << "(3) Dar like" << endl
						 << "(4) Dar hate" << endl
						 << "(5) Seguir Usuario" << endl
						 << "(6) Dejar de seguir a un usuario" << endl
						 << "(7) Salir" << endl
						 << "su opcion: ";
					
					int choice;
					cin >> choice;
					
					while(!cin || (choice < 1 || choice > 7)) {
						cin.clear();
						cin.ignore(100,'\n');
						cout << "Por favor ingrese una opcion valida: ";
						cin >> choice;
					}
					
					switch(choice) {
						case 1: {
							
							cin.ignore(100,'\n');
							cout << endl
								 << "****Crear Post***" << endl
								 << "Ingrese el titulo de su post: ";
							
							string titulo;
							getline(cin,titulo);
							
							cout << "Ingrese el contenido de su post: ";
							
							string contenido;
							getline(cin,contenido);
							
							uActual->posts.push_back(Post(titulo,contenido,0,0));
							
							break;
						}
						case 2: {
							
							if(pub.size() == 0) {
								cout << "No hay posts que comentar." << endl;
								break;
							}
							
							cout << endl
								 << "***Comentar post***" << endl
								 << "Ingrese el indice del post: ";
							
							int indice;
							cin >> indice;
							
							while(!cin || (indice < 0 || indice >= pub.size())) {
								cin.clear();
								cin.ignore(100,'\n');
								cout << "Por favor ingrese una opcion valida: ";
								cin >> indice;
							}
							
							cin.ignore(100,'\n');
							cout << "Ingrese su comentario: ";
							string comentario;
							getline(cin,comentario);
							
							pub[indice]->comentarios.push_back(uActual->nomUsuario);
							pub[indice]->comentarios.push_back(comentario);
							
							break;
						}
						case 3: {
							
							if(pub.size() == 0) {
								cout << "No hay posts" << endl;
								break;
							}
							
							cout << "***Dar like***" << endl
								 << "Ingrese el indice del post: ";
							
							int indice;
							cin >> indice;
							
							while(!cin || (indice < 0 || indice >= pub.size())) {
								cin.clear();
								cin.ignore(100,'\n');
								cout << "Por favor ingrese una opcion valida: ";
								cin >> indice;
							}
							
							pub[indice]->likes++;
							
							break;
						}
						case 4: {
							
							if(pub.size() == 0) {
								cout << "No hay posts" << endl;
								break;
							}
							
							cout << "***Dar hate***" << endl
								 << "Ingrese el indice del post: ";
							
							int indice;
							cin >> indice;
							
							while(!cin || (indice < 0 || indice >= pub.size())) {
								cin.clear();
								cin.ignore(100,'\n');
								cout << "Por favor ingrese una opcion valida: ";
								cin >> indice;
							}
							
							pub[indice]->hates++;
							
							break;
						}
						case 5: {
							
							cout << "***Seguir usuario***" << endl;
							
							for(int i = 0; i < usuarios.size() ; i++) {
								cout << i 
								 	 << ": " << usuarios[i]->nomUsuario << endl;
							}
							
							cout << "Ingrese el indice del post: ";
							
							int indice;
							cin >> indice;
							
							while(!cin || (indice < 0 || indice >= usuarios.size() || usuarios[indice] == uActual)) {
								cin.clear();
								cin.ignore(100,'\n');
								cout << "Por favor ingrese una opcion valida: ";
								cin >> indice;
							}
							
							uActual->seguidos.push_back(usuarios[indice]);
							
							cout << "Siguiendo un nuevo usuario" << endl;
							
							break;
						}
						case 6: {
							
							cout << endl
								 << "***Dejar de seguir***" << endl;
							
							for(int i = 0; i < uActual->seguidos.size(); i++) {
								cout << i 
								 	 << ": " << uActual->seguidos[i]->nomUsuario << endl;
							}
							
							int indice;
							cin >> indice;
							
							while(!cin || (indice < 0 || indice >= uActual->seguidos.size())) {
								cin.clear();
								cin.ignore(100,'\n');
								cout << "Por favor ingrese una opcion valida: ";
								cin >> indice;
							}
							
							uActual->seguidos.erase(uActual->seguidos.begin() + indice);
							
							cout << "Se ha dejado de seguir a un usuario" << endl;
							
							break;
						}
						case 7: {
							
							cout << "saliendo ..." << endl;
							conectado = false;
							break;
						}
					}
					}
					
				} else {
					cout << endl
						 << "No se ha encontrado un usuario con ese nombre y clave"
						 << endl;
				}
				
				break;
			}
			case 3: {
				cout << "Saliendo ...";
				loop = false;
				break;
			}
		}
	}
	guardarUsuarios(usuarios);
	return 0;
	
}

//Funcion que guarda los usuarios
void guardarUsuarios(vector<Usuario*> &usuarios) {
	
	// file pointer 
    fstream fout; 
  
    // opens an existing csv file or creates a new file. 
    fout.open("Usuarios.txt", ios::out | ios::app); 
  
   	for(int i = 0; i < usuarios.size(); i++) {
   		
   		fout << usuarios[i]->toString() << endl;
   		
	}
	
	fout.close();
}

//Funcion que lee los usuarios
void leerUsuarios(vector<Usuario*> &usuarios) {
	
	int conteo = 0;
	
	 // File pointer 
    fstream fin; 
  
    // Open an existing file 
    fin.open("Usuarios.txt", ios::in); 
  
    // Read the Data from the file 
    // as String Vector 
    vector<string> row; 
    string line, word, temp; 
  
    while (fin >> temp) { 
  
        row.clear(); 
  
        // read an entire row and 
        // store it in a string variable 'line' 
        getline(fin, line); 
  
        // used for breaking words 
        stringstream s(line); 
  
        // read every column data of a row and 
        // store it in a string variable, 'word' 
        while (getline(s, word, '|')) { 
  
            // add all the column data 
            // of a row to a vector 
            row.push_back(word); 
        } 
  		
  		vector<string> row2;
  		stringstream s2(row[0]);
  		
  		while (getline(s2, word, ',')) { 
  
            // add all the column data 
            // of a row to a vector 
            row2.push_back(word); 
        } 
  		
  		Usuario *user = new Usuario(row2[0],row2[1],row2[2]);
  		
  		usuarios.push_back(user);
  		conteo++;
  		
  		for(int i = 1; i < row.size(); i++) {
  			
  			vector<string> row3;
  			stringstream s3(row[i]);
  			
  			while (getline(s3, word, ',')) { 
  
            	row3.push_back(word); 
        	} 
        	
        	Post *post = new Post(row3[0],row3[1],stoi(row3[2]),stoi(row3[3]));
        	
        	for(int j = 4; j < row3.size(); j += 2) {
        		
        		post->comentarios.push_back(row3[j]);
        		post->comentarios.push_back(row3[j+1]);
			}
        	
        	user->posts.push_back(*post);
		}
    }
	
	//cout << "conteo: " << conteo << endl;
//	cout << "size array: " << usuarios.size() << endl;
	
//	for (int i = 0; i < usuarios.size(); i++) {
//		cout << usuarios[i]->toString() << endl;
//	}
	
}


