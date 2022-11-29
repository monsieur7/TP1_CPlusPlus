#include <string>

class Produit {
    private:
        std::string _titre;
        std::string _description;
        int _quantite;
        float _prix;
    public:
    Produit(std::string titre, std::string description, int quantitie, float prix);
    std::string getTitre();
    std::string getDescription();
    int getQuantite();
    float getPrix();
    void setTitre(std::string titre);
    void setDescription(std::string description);
    void setQuantité(int quantite);
    void setPrix(int prix);


};