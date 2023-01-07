#include <string>
#include <iostream>
#pragma once
//TODO : const for getters !
class Produit : public FileStore{
    private:
        std::string _titre;
        std::string _description;
        int _quantite;
        float _prix;
        int _id;
    public:
        Produit(std::string titre, std::string description, int quantitie, float prix, int id);
        
        std::string getTitre() const;
        std::string getDescription() const;
        int getQuantite() const;
        float getPrix() const;
        int getId() const;

        void setTitre(std::string titre);
        void setDescription(std::string description);
        void setQuantite(int quantite);
        void setPrix(int prix);
        void setId(int id);

        friend std::ostream& operator<<(std::ostream& os, Produit& produit );
        std::string toFile() const; //TODO : toFile

};