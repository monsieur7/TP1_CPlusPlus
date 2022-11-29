#include "Client.h"
#include "Produit.h"
#include <vector>
#include <iostream>
#include <algorithm>


Client::Client(int identifiant, std::string prenom, std::string nom) 
: _identifiant(identifiant), _prenom(prenom),_nom(nom){}

int Client::getIdentifiant() const{
    return _identifiant;
}

std::string Client::getPrenom() const{
    return _prenom;
}
        
std::string Client::getNom() const{
    return _nom; 
}

std::vector<Produit> Client::getPanier() const{
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
        
