#include <vector>
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
        int getId()  const;
        const Client& getClient()  const;
        void addProduit(Produit produit);
        void changeStatus(Status status, int it);
        int getNombreDeProduit()  const;
        



};