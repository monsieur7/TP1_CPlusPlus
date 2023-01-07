#include "Client.h"
#include "Produit.h"
#include "Commande.h"
#include <iostream>
#include <vector>
#include <algorithm>

class Magasin : public FileStore{
    private:
        std::vector<Produit> _produits;
        std::vector <Client> _clients;
        std::vector<Commande> _commandes;
        std::string _nom = "EasyStore";
    public:
        Magasin();
        void addProduit(Produit produit);
        void addClient(Client client);
        void addCommande(Commande commande);

        void afficherProduit();
        void afficherProduit(std::string nom);

        Produit& getProduitById(int id); 
        void updateQuantiteProduit(std::string nom, int quantite);

        bool validerCommande(int numeroCommande);
        void majStatusCommande(Commande commande, Status nouveauStatus);
        void affichageCommande();   
        void affichageCommandeParClient(Client client);

        void afficherClient();
        void afficherClientId(int id);
        void afficherClientNom(std::string nom);
        void afficherClientPrenom(std::string prenom);

        void addProduitPanier(Client client, Produit produit);
        void deleteProduitPanier(Client client, Produit produit);
        void updateQuantitePanier(Client client, Produit produit, int quantite);
    
        void addProduitInCommande(int commande_id, Produit produit);
        const std::string& getNom() const;

        std::string toFile() const; //TODO THIS -<
        //TODO : add a product method (and other things) 




};