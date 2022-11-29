#include <iostream>
#include <vector>
#include <cstdlib>
#include "Produit.h"


#ifndef CLIENT_H
#define CLIENT_H

class Client{

	public:
		Client(int identifiant, std::string prenom, std::string nom, std::vector<Produit> panier);
		int getIdentifiant();
        std::string getPrenom();
        std::string getNom();
        std::vector<Produit> getPanier();
        void ajouterProduit(Produit produit);
        void viderPanier();
        void modifierQuantite(int quantite, Produit produit);
        void supprimerProduit(Produit produit);
        std::ostream& operator << (std::ostream& os);



	private:
		int _identifiant;
        std::string prenom;
        std::string nom;
		std::vector<Produit> _panier;

};


#endif