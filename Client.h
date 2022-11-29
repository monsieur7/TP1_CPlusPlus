#include <iostream>
#include <vector>
#include <cstdlib>

#ifndef CLIENT_H
#define CLIENT_H

class Client{

	public:
		Client(int identifiant, std::string prenom, std::string nom, std::vector<std::string> panier);
		int getIdentifiant();
        std::string getPrenom();
        std::string getNom();
        std::vector<std::string> getPanier();

		
		

	private:
		int _identifiant;
        std::string prenom;
        std::string nom;
		std::vector<std::string> _panier;

};


#endif