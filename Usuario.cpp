#include "Usuario.h"
#include <string>

using std::string;

Usuario::Usuario()
{
}

Usuario::Usuario(string nombre, string nomUsuario, string clave) {
	this->nombre = nombre;
	this->nomUsuario = nomUsuario;
	this->clave = clave;
}

string Usuario::toString() {
	
	string usuario = nombre + "," + nomUsuario + "," + clave;
	
	for(int i = 0; i < posts.size(); i++) {
		usuario += "|" + posts[i].toString();
	}
	
	return usuario;
	
}

Usuario::~Usuario()
{
}
