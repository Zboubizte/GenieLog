#ifndef _OBJET_HPP_
#define _OBJET_HPP_

#include <string>
using namespace std;

class Objet
{
	private:
		string type;
		int valeur;
	public:
		Objet();
		Objet(string);
};

#endif
