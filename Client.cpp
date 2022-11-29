#include "Client.h"
#include "Produit.h"
#include <vector>
#include <iostream>



Client::Client(int identifiant, std::string prenom, std::string nom, std::vector<Produit> panier) :
_identifiant(identifiant), _prenom(prenom),_nom(nom),_panier(panier){}

std::string Client::getIdentifiant(){
    return _identifiant;
}

std::string Client::getPrenom(){
    return _prenom;
}
        
std::string Client::getNom(){
    return _nom; 
}

std::vector<Produit> Client::getPanier(){
    return _panier;
}

void Client::ajouterProduit(Produit produit){
    _panier.push_back(produit);
}

void viderPanier(){
    _panier.clear();
}

void modifierQuantite(int quantite, Produit produit){

}
        
void supprimerProduit(Produit produit){

}
        
//ostream& operator << (ostream& os){}