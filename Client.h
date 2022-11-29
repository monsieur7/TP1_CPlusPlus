#include <iostream>
#include <vector>
#include <cstdlib>
#include "Produit.h"

#include <sstream>

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
    friend std::ostream& operator << (std::ostream& os, Client client){
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