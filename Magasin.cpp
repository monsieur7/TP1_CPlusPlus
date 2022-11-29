#include "Magasin.h"

Magasin::Magasin(){
    ;
};
void Magasin::addProduit(Produit produit){
    for (auto &i : _produits){
        if(i.getId() == produit.getId()){
            throw std::runtime_error("Le produit a ajouté existe déja");
        }
    }
    _produits.push_back(produit);
    // check for produit id
}
void Magasin::addClient(Client client){
    for(auto &i : _clients){
        if(i.getIdentifiant() == client.getIdentifiant()){
            throw std::runtime_error("Le client a ajouté existe déja");
        }
    }
    _clients.push_back(client);
}
void Magasin::addCommande(Commande commande){
    for(auto &i : _commandes){
        if(i.getId() == commande.getId()){
            throw std::runtime_error("La commande a ajouté existe déja");
        }
    }
    _commandes.push_back(commande);
}

void Magasin::afficherProduit(){
    std::cout << "produits " << _produits.size() << std::endl;
    for(auto& i : _produits){
        std::cout << i << std::endl;
    }
}
void Magasin::afficherProduit(std::string nom){
    for(auto& i : _produits){
        if(i.getTitre() == nom){
            std::cout << i << std::endl;
        }
    }
}
void Magasin::updateQuantiteProduit(std::string nom, int quantite){
    for(auto& i : _produits){
        if(i.getTitre() == nom){
            i.setQuantite(quantite);
        }
    }
}



