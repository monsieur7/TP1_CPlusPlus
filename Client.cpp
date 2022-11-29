#include "Client.h"
#include "Produit.h"
#include <vector>
#include <iostream>



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
<<<<<<< HEAD

=======
    auto it_end = std::remove(_panier.begin(),_panier.end(),produit);
    _panier.erase(it_end,_produit.end());
>>>>>>> a97a3ab6a8fd9f10a1b249b59b63cafe17a74db4
}
        
std::ostream& operator << (std::ostream& os){
    std::vector<int>::iterator it;
    std::string contenu_panier = "";
    it = _panier.begin();
    for (it=_board.begin(); it<_board.end(); it++){
        contenu_panier += " " + *it;
    }
    std::string a_afficher = "Id: " + _identifiant + " prenom: " + _prenom + " nom: " + _nom +
     " Contenu du panier: " + contenu_panier;
}