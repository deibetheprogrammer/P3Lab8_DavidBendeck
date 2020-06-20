#include "Post.h"
#include <vector>
#include <string>

using namespace std;

Post::Post()
{
}

Post::Post(string titulo, string contenido, int likes = 0, int hates = 0) {
	this->titulo = titulo;
	this->contenido = contenido;
	this->likes = likes;
	this->hates = hates;
}

string Post::toString() {
	
	string post = titulo + ',' + contenido + ',' + to_string(likes) + ',' + to_string(hates);
	
	for(int i = 0; i < comentarios.size(); i += 2) {
		post += ',' + comentarios[i] + ',' + comentarios[i+1];
	}
	
	return post;
	
}

Post::~Post()
{
}
