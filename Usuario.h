#ifndef USUARIO_H
#define USUARIO_H
#include <vector>
#include <string>
#include "Post.h"

using std::vector;
using std::string;

class Usuario
{
	public:
		Usuario();
		
		Usuario(string,string,string);
		
		//ATRIBUTOS
		string nombre;
		string nomUsuario;
		string clave;
		vector<Usuario*> seguidos;
		vector<Post> posts;
		
		//FUNCIONES
		string toString();
		
		~Usuario();
	protected:
};

#endif
