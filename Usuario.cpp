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
	
}

Usuario::~Usuario()
{
}
