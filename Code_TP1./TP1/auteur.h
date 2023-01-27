//
// Created by Elie on 05/01/2023.
//

#ifndef TP1_AUTEUR_H
#define TP1_AUTEUR_H

#include "date.h"

#include "iostream"
#include "string"

class Auteur {
private:
    std::string _identifiant;
    std::string _nom;
    std::string _prenom;
    Date _date_de_naissance;

public:
    Auteur(Date date_de_naissance = Date(), std::string identifiant = "0000", std::string nom = "default_nom", std::string prenom = "default_prenom");

    std::string GetIdentifiant();
    std::string GetNom();
    std::string GetPrenom();
    Date GetDateDeNaissance();
};


#endif //TP1_AUTEUR_H
