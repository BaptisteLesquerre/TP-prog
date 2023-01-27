//
// Created by Elie on 05/01/2023.
//

#include "lecteur.h"

Lecteur::Lecteur(std::string identifiant, std::string nom, std::string prenom) {
    _identifiant = identifiant;
    _nom = nom;
    _prenom = prenom;
}

std::string Lecteur::GetIdentifiant() {
    return _identifiant;
}

std::string Lecteur::GetNom() {
    return _nom;
}

std::vector<std::string> Lecteur::GetISBNList() {
    return _ISBN_list;
}

