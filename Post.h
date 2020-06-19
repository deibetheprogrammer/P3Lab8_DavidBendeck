#ifndef POST_H
#define POST_H
#include <vector>
#include <string>

using std::vector;
using std::string;

class Post
{
	public:
		Post();
		
		Post(string);
		
		//ATRIBUTOS
		string contenido;
		int likes;
		int hates;
		vector<string> comentarios;
		
		//FUNCIONES
		string toString();
		
		~Post();
	protected:
};

#endif
