#include "Client.h"
#include "Produit.h"
#include "Commande.h"
#include <iostream>
#include <vector>
#include <algorithm>

class Magasin {
    private:
        std::vector<Produit> _produits;
        std::vector <Client> _clients;
        std::vector<Commande> _commandes;
    public:
        Magasin();
        void addProduit(Produit produit);
        void addClient(Client client);
        void addCommande(Commande commande);
        void afficherProduit();
        void afficherProduit(std::string nom);
        void updateQuantiteProduit(std::string nom, int quantite);
        bool validerCommande(int numeroCommande);
        void majStatusCommande();
        void affichageCommande();
        void affichageCommandeParClient(Client client);




};