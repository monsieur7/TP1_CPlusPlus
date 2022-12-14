#include "Commande.h"


Commande::Commande(int id, Client client)
    :_id(id), _client(client)
{
}
int Commande::getId() const{
    return _id;
}
const Client& Commande::getClient() const{
    return _client;
}
const Status& Commande::getStatus() const{
    return _status;
}
void Commande::addProduit(Produit produit){
    _liste_produit.push_back(produit);
}

void Commande::setStatus(Status status){
    _status = status;
}


int Commande::getNombreDeProduit()  const{
    return _liste_produit.size();
}

std::string Commande::toString(Status status){
    std::string ret = "";
    switch (status)
    {
    case Status::LIVREE : {
        ret = "LIVREE";
        break;
    }
    case Status::PAS_LIVREE : {
        ret = "PAS_LIVREE";
        break;
    }
    default:
        break;
    }
    return ret;
}

const std::vector<Produit>& Commande::getListeProduit() const {
    return _liste_produit;
}

std::string Commande::toFile() const {
    return "a"; // TODO : ONLY FOR TESTING
}