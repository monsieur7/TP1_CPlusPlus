#include "Client.h"
#include "Produit.h"
#include "Commande.h"

#include <vector>


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




};