#include <iostream>
#include "Magasin.h"
int main(void){
    Magasin dijon;
    Produit lait("lait", "lait 1L entier", 10, 1.00, 1);
    std::cout << lait << std::endl;
    return 0;
}