#include <vector>
#include <sstream>
#include <iostream>
#include <cstdlib>

#include "Client.h"
#include "Produit.h"
#pragma once
enum class Status {
    LIVREE,
    PAS_LIVREE

}; 
// for printing the status as a string
class Commande {
    private:
        int commande;
        Client _client;
        std::vector<Produit> _liste_produit;
        std::vector<Status> _status_produit;
        int _id;
        std::string toString(Status status); // transform enum to string (no ther way, we are not in python)
    public:
        Commande(int id, Client client);
        int getId() const;
        void addProduit(Produit produit);
        void changeStatus(Status status, int it);
        int getNombreDeProduit() const;
        const Client& getClient() const;
        const std::vector<Produit>& getListeProduit() const;
        const std::vector<Status>& getListeStatus() const;

        friend std::ostream& operator << (std::ostream& os, Commande commande){
            std::stringstream ss;
            std::stringstream ss2;
            auto liste_produit = commande.getListeProduit();
            auto liste_status = commande.getListeStatus();
            for (auto it = liste_produit.begin(); it != liste_produit.end(); it++){
                ss << " "  << *it;
            }
            
            for (auto it2 = liste_status.begin(); it2 != liste_status.end(); it2++){
                ss2 << " "  << commande.toString(*it2);
            }
            

            os << "Id commande: " << commande.getId() << " client: " << commande.getClient() << 
            " liste des produits: " << ss.str() << " status du produit: " << ss2.str();
            return os;
    }
        



};