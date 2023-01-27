//
// Created by Elie on 05/01/2023.
//

#include "auteur.h"

Auteur::Auteur(Date date_de_naissance, std::string identifiant, std::string nom, std::string prenom) {
    _date_de_naissance = date_de_naissance;
    _identifiant = identifiant;
    _nom = nom;
    _prenom = prenom;
}

std::string Auteur::GetIdentifiant() {
    return _identifiant;
}

std::string Auteur::GetNom() {
    return _nom;
}

std::string Auteur::GetPrenom() {
    return _prenom;
}

Date Auteur::GetDateDeNaissance() {
    return _date_de_naissance;
}