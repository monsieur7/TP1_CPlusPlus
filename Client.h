#include <iostream>
#include <vector>
#include <cstdlib>
#include "Produit.h"

#include <sstream>

#ifndef CLIENT_H
#define CLIENT_H

class Client{
	public:
		Client(int identifiant, std::string prenom, std::string nom);
		int getIdentifiant() const;
        std::string getPrenom() const;
        std::string getNom() const;
        std::vector<Produit> getPanier() const;
        void ajouterProduit(Produit produit);
        void viderPanier();
        void modifierQuantite(int quantite, Produit produit);
        void supprimerProduit(Produit produit);
        friend std::ostream& operator << (std::ostream& os, Client client){ // cette fonction est dans le .h car sinon le linker n'y comprends rien avec l'autre opérateur de produit
            std::stringstream ss;
            auto panier = client.getPanier();
            for (auto it = panier.begin(); it != panier.end(); it++){
                ss << " "  << *it;
            }
            os << "Id: " << client.getIdentifiant() << " prenom: " << client.getPrenom() << " nom: " <<
            client.getNom() << " Contenu du panier: " << ss.str();
            return os;
    }


	private:
		int _identifiant;
        std::string _prenom;
        std::string _nom;
		std::vector<Produit> _panier;

};
#endif