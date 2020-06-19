#include "Post.h"
#include <vector>
#include <string>

using std::vector;
using std::string;

Post::Post()
{
}

Post::Post(string titulo, string contenido) {
	this->titulo = titulo;
	this->contenido = contenido;
}

string Post::toString() {
	
}

Post::~Post()
{
}
