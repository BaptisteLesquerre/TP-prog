//
// Created by Elie on 05/01/2023.
//

#ifndef TP1_LECTEUR_H
#define TP1_LECTEUR_H

#include "emprunt.h"
#include "livre.h"
#include "emprunt.h"

#include "iostream"
#include "string"
#include "vector"
#include "algorithm"


class Lecteur {
private:
    std::string _identifiant;
    std::string _nom;
    std::string _prenom;
    std::vector<int> _ISBN_list;
    std::vector<Emprunt> _emprunt_list;

public:
    Lecteur(std::string identifiant, std::string nom, std::string prenom);

    std::string GetIdentifiant();
    std::string GetNom();
    std::string GetPrenom();
    std::vector<int> GetISBNList();

    void AddISBNToList(int ISBN);
    void RmISBNFromList(int ISBN);
    void Emprunter(Date& date, Livre& livre);
    void Restitutuer(Date& date, Livre& live);
};

void Display_ID();

#endif //TP1_LECTEUR_H
