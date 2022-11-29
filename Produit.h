#include <string>
#include <iostream>
#pragma once
class Produit {
    private:
        std::string _titre;
        std::string _description;
        int _quantite;
        float _prix;
        int _id;
    public:
        Produit(std::string titre, std::string description, int quantitie, float prix, int id);
        std::string getTitre();
        std::string getDescription();
        int getQuantite();
        float getPrix();
        int getId();
        void setTitre(std::string titre);
        void setDescription(std::string description);
        void setQuantite(int quantite);
        void setPrix(int prix);
        void setId(int id);
        friend std::ostream operator<<(std::ostream &os, Produit produit )

};