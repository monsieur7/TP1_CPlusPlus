#include <vector>
#include <sstream>
#include <iostream>
#include <cstdlib>

#include "Client.h"
#include "Produit.h"
enum class Status {
    LIVREE,
    PAS_LIVREE

};
class Commande {
    private:
        int commande;
        Client _client;
        std::vector<Produit> _liste_produit;
        std::vector<Status> _status_produit;
        int _id;
    public:
        Commande(int id, Client client);
        int getId();
        const Client& getClient();
        std::vector<Produit> getListeProduit();
        std::vector<Status> getListeStatus();
        void addProduit(Produit produit);
        void changeStatus(Status status, int it);
        int getNombreDeProduit();

        friend std::ostream& operator << (std::ostream& os, Commande commande){
        std::stringstream ss;
        std::stringstream ss2;
        auto liste_produit = commande.getListeProduit();
        auto liste_status = commande.getListeStatus();
        for (auto it = liste_produit.begin(); it != liste_produit.end(); it++){
            ss << " "  << *it;
        }
        /*
        for (auto it2 = liste_status.begin(); it2 != liste_status.end(); it2++){
            ss2 << " "  << *it2;
        }
        */

        os << "Id commande: " << commande.getId() << " client: " << commande.getClient() << 
        " liste des produits: " << ss.str() /*<< " status du produit: " << ss2.str()*/;
        return os;
    }
        



};