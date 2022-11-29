#include "Produit.h"

Produit::Produit(std::string titre, std::string description, int quantitie, float prix)
:_titre(titre), _description(description), _quantite(quantitie), _prix(prix)
{
}
std::string Produit::getTitre(){
    return _titre;
}
std::string Produit::getDescription(){
    return _description;
}
int Produit::getQuantite(){
    return _quantite;
}
float Produit::getPrix(){
    return _prix;
}
void Produit::setTitre(std::string titre){
    _titre = titre;
}
void Produit::setDescription(std::string description){
    _description = description;
}
void Produit::setQuantite(int quantite){
    _quantite = quantite;
}
void Produit::setPrix(int prix){
    if(prix < 0) throw std::exception("Le prix doit être supérieur à 0")
    else _prix = prix;
}