#include "Client.h"
#include "Produit.h"
#include <vector>
#include <iostream>
#include <algorithm>


Client::Client(int identifiant, std::string prenom, std::string nom, std::vector<Produit> panier) :
_identifiant(identifiant), _prenom(prenom),_nom(nom),_panier(panier){}

int Client::getIdentifiant(){
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

void Client::viderPanier(){
    _panier.clear();
}

void Client::modifierQuantite(int quantite, Produit produit){

}
        
void Client::supprimerProduit(Produit produit){
    _panier.erase(std::remove_if(_panier.begin(), _panier.end(), [produit](Produit& pdt){return produit.getId() == pdt.getId();}), _panier.end());

}
        
