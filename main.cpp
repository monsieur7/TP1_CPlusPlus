#include <iostream>
#include "Magasin.h"
//separating 32 and 64 bits version 
#ifdef _WIN64 
#include <windows.h>
#endif
#ifdef _WIN32 
#include <windows.h>
#endif

bool magasin;
Magasin * mag;
int product_id = 0; // automatic id 
int client_id = 0;

void sousMenuMagasin(){
    int c;
    std::string nom;
    std::cout << "que voulez vous faire ?" << std::endl;
    std::cout << "1 pour afficher les informations du magasin" << std::endl;
    std::cin >> c;
    if (c == 1){
        std::cout << "Votre magasin est " << mag->getNom() << std::endl;
        return;

    }
    std::cin.ignore();
}
void sousMenuProduit(){
    int c;
    std::cout << "que voulez vous faire ?" << std::endl;
    std::cout << "1 afficher les produits" << std::endl;
    std::cout << "2 rechercher un produit par nom" << std::endl;
    std::cout << "3 modifier la quantité d'un produit" << std::endl;
    std::cout << "4 ajouter un produit" << std::endl;
    std::cin >> c;

    switch(c){
        case 1: {
            mag->afficherProduit(); break;
        }
        case 2: {
            std::cout << "entrer le nom du produit a rechercher :";
            std::string nom;
            std::cin >> nom;
            mag->afficherProduit(nom); break;
        }
        case 3: {
            std::string nom;
            std::cout << "veuillez entrer le nom du produit a modifier :";
            std::cin >> nom;
            std::cout << std::endl;
            std::cout << "veuillez entrer la quantité du produit : ";
            int quantite;
            std::cin >> quantite;
            std::cout << std::endl;
            mag->updateQuantiteProduit(nom, quantite);
            mag->afficherProduit(); break;
        }
        case 4: {
            std::string nom;
            std::cout << "merci d'entrer le nom du nouveau produit a ajouter : " << std::endl;;
            std::cin >> nom;
            std::cout << std::endl;
            std::cout << "merci d'entrer la description du produit";
            std::string description;
            std::cin.ignore();
            std::getline(std::cin, description);
            std::cout << "merci d'entrer la quantite du produit"<< std::endl;
            int quantite;
            std::cin >> quantite;
            std::cout << "merci d'entrer le prix du produit"<< std::endl;
            float prix;
            std::cin >> prix;
            Produit temp(nom, description, quantite, prix, product_id);
            product_id++;
            mag->addProduit(temp);
            break; 
        }
        default: std::cout << "bad entry" <<std::endl; return ;
    }

}
void sousMenuClient(){
    int c;
    std::cout << "que voulez vous faire ?" << std::endl;
    std::cout << "1 créer un nouveau client" << std::endl;
    std::cout << "2 afficher la liste des clients" << std::endl;
    std::cout << "3 chercher un client par nom" << std::endl;
    std::cout << "4 chercher un client par prénom" << std::endl;
    std::cin >> c;
    switch(c){
        case 1: {
            std::cout << "veuillez entrer le nom du client";
            std::string nom;
            std::cin >> nom;
            std::cout << "veuillez entrer le prénom du client";
            std::string prenom;
            std::cin >> prenom;
            Client temp(client_id, prenom, nom);
            mag->addClient(temp);
            client_id++;
            break;
            
        }
        case 2: {
            mag->afficherClient();
            break;
        }
        case 3: {
            std::cout << "veuillez entrer le nom du client a rechercher" << std::endl;
            std::string nom;
            std::cin >> nom;
            mag->afficherClientNom(nom);
            break;
        }
        case 4: {
            std::cout << "veuillez entrer le prénom du client a rechercher" << std::endl;
            std::string prenom;
            std::cin >> prenom;
            mag->afficherClientPrenom(prenom);
            break;
        }
        default : {
            std::cout << "bad input" << std::endl;
            break;
        }

    }
}
void sousMenuCommandes(){
    std::cout << "que voulez vous faire ?" << std::endl;
    std::cout << "1 afficher les commandes " << std::endl;
    std::cout << "2 ajouter une commande" << std::endl;
    std::cout << "3 changer le status d'une commande" << std::endl;
    int c;
    std::cin >> c;
    switch(c){
        case 1: {
            mag->affichageCommande();
            break;
        }
        case 2: {

        }
        case 3: {

        }
        default: {
            std::cout << "bad input " << std::endl; 
            break;
        }

    }

}
int main(void){
#if defined( _WIN32) || defined(_WIN64)
// enabling buffering and utf8 characters for windows only
    SetConsoleOutputCP(CP_UTF8);
    setvbuf(stdout, nullptr, _IOFBF, 1000);
#endif
    mag = new Magasin();
    
   while(true){
    int c;
    
    std::cout << "que voulez vous faire ?" << std::endl;
    std::cout << "1 pour entrer dans le sous menu magasin"<< std::endl;
    std::cout << "2 pour rentrer dans le sous menu produit"<< std::endl;
    std::cout << "3 pour rentrer dans le sous menu client"<< std::endl;
    std::cout << "4 pour rentrer dans le sous menu commandes"<< std::endl;
    std::cin >> c;
    switch (c)
    {
    case 1: sousMenuMagasin(); break;
    case 2: sousMenuProduit(); break;
    case 3: sousMenuClient(); break;
    case 4: sousMenuCommandes(); break;
    default: std::cout << "bad input";
        break;
    }

   }
    delete mag;

    return 0;
}