#include <iostream>
#include "Magasin.h"
int main(void){
    Magasin dijon;
    Produit lait("lait", "lait 1L entier", 10, 1.00, 1);
    dijon.addProduit(lait);
    dijon.afficherProduit("lait");
    dijon.updateQuantiteProduit("lait", 12);
    dijon.afficherProduit();

    Client client(1, (std::string)"Nolane", (std::string)"DELILLE");

    return 0;
}