#include "Produit.h"
#include <stdexcept>
Produit::Produit(std::string titre, std::string description, int quantitie, float prix, int id)
:_titre(titre), _description(description), _quantite(quantitie), _prix(prix), _id(id)
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
int Produit::getId() const{
    return _id;
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
    if(prix < 0) throw std::runtime_error("Le prix doit être supérieur à 0");
    else _prix = prix;
}

void Produit::setId(int id){
    _id = id;
}

std::ostream& operator<<(std::ostream& os, Produit& produit ){

    return os << produit._titre << " " << produit._id << " " << produit._description << "prix " << produit._prix << "quantite " << produit._quantite;
}
