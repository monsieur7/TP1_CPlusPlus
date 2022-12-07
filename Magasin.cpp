#include "Magasin.h"
#include <cstdlib>
#include <iterator>
#include <algorithm>
#include <array>
#include <vector>


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
    _commandes.back().setStatus(Status::PAS_LIVREE);
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
void Magasin::afficherClient(){
    std::cout << "clients " << _clients.size() << std::endl;
    for(auto& i : _clients){
        std::cout << i << std::endl;
    }
}
void Magasin::afficherClientId(int id){
    for(auto& i : _clients){
        if(i.getIdentifiant() == id)
            std::cout << i.getIdentifiant() << std::endl;
    }
}
void Magasin::afficherClientNom(std::string nom){
    for(auto& i : _clients){
        if(i.getNom() == nom)
            std::cout << i << std::endl;
    }
}
void Magasin::afficherClientPrenom(std::string prenom){
    for(auto& i : _clients){
        if(i.getPrenom() == prenom)
            std::cout << i << std::endl;
    }
}
//Problem with this ? need to fix it 

bool Magasin::validerCommande(int numeroCommande){
    int compteurPresents = 0;
    Commande commandeATraiter = _commandes[numeroCommande];
    for(auto it = commandeATraiter.getListeProduit().begin(); it != commandeATraiter.getListeProduit().end(); it++){
        if(getProduitById(it->getId()).getQuantite() <= it->getQuantite()){
            return false;
        }
    }
    return true;
		
}
  
void Magasin::majStatusCommande(Commande commande, Status nouveauStatus){
    commande.setStatus(nouveauStatus);
    
    //Pas compris ce qu'il faut faire ici
}
        
void Magasin::affichageCommande(){
    for(auto& i : _commandes){
        std::cout << i << std::endl;
    }
}
        
void Magasin::affichageCommandeParClient(Client client){
    for(auto& i : _commandes){
        if(i.getClient().getIdentifiant() == client.getIdentifiant()){
            std::cout << "Commande de " << client.getPrenom() << " " << client.getNom() << ": " <<
            i << std::endl;

        }
    }
}


void Magasin::addProduitPanier(Client client, Produit produit){
    for(auto& i : _clients){
        if(client.getIdentifiant() == i.getIdentifiant()){
            i.ajouterProduit(produit);
        }
    }
}
void Magasin::deleteProduitPanier(Client client, Produit produit){
for(auto& i : _clients){
        if(client.getIdentifiant() == i.getIdentifiant()){
            i.supprimerProduit(produit);
        }
    }
}
void Magasin::updateQuantitePanier(Client client, Produit produit, int quantite){
for(auto& i : _clients){
        if(client.getIdentifiant() == i.getIdentifiant()){
            i.modifierQuantite(quantite, produit);
        }
    }
}

Produit& Magasin::getProduitById(int id){
    for(auto &i : _produits){
        if(i.getId() == id){
            return i;
        }
    }
    throw std::runtime_error("pas de produits trouvés avec cette id !");
}
