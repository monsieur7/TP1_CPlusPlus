#include <vector>
#include <sstream>
#include <iostream>
#include <cstdlib>

#include "Client.h"
#include "Produit.h"
#include "FileStore.h"
#pragma once
enum class Status {
    LIVREE,
    PAS_LIVREE

}; 

class Commande : public FileStore {
    private:
        int commande;
        Client _client;
        std::vector<Produit> _liste_produit;
        int _id;
        Status _status;
        std::string toString(Status status); // transform enum to string (no ther way, we are not in python)
    public:
        Commande(int id, Client client);

        int getId() const;
        int getNombreDeProduit() const;
        const Client& getClient() const;
        void setStatus(Status status);
        const Status& getStatus() const;
        const std::vector<Produit>& getListeProduit() const;

        void addProduit(Produit produit);
        //void changeStatus(Status status);

        friend std::ostream& operator << (std::ostream& os, Commande commande){// can't put it in Commande.cpp otherwise linker complains :( 
            std::stringstream ss;
            auto liste_produit = commande.getListeProduit();
            for (auto it = liste_produit.begin(); it != liste_produit.end(); it++){
                ss << " "  << *it;
            }
            
            

            os << "Id commande: " << commande.getId() << " client: " << commande.getClient() << 
            " status du produit: " << commande.toString(commande.getStatus()) << " liste des produits: " << ss.str();
            return os;
    }       
    
    std::string toFile() const;
        
};