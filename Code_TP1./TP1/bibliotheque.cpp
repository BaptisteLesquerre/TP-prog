//
// Created by Elie on 05/01/2023.
//

#include "bibliotheque.h"

Bibliotheque::Bibliotheque(std::string nom_biblioteque, std::string adress) {
    _nom_bibliotheque = nom_biblioteque;
    _adress = adress;

    std::cout << "La bibliotheque " << _nom_bibliotheque << " a ete cree avec succe" << std::endl;
}

std::vector<Livre> Bibliotheque::GetLivreList() {
    return _livre_list;
}

std::vector<Emprunt> Bibliotheque::GetEmpruntList() {
    return _emprunt_list;
}

std::string Bibliotheque::GetNomBibliotheque() {
    return _nom_bibliotheque;
}

std::string Bibliotheque::GetAdress() {
    return _adress;
}

void Bibliotheque::AddLecteur(Lecteur lecteur) {
    //on cree une variable 'check' de type iterator
    std::vector<std::string>::iterator check;
    //check prend la valeur de l'index ou se trouve l'element si il est dans la list, et prend la valeur du dernier index sinon
    check = std::find(_lecteur_id_list.begin(), _lecteur_id_list.end(), lecteur.GetIdentifiant());
    if (check == _lecteur_id_list.end()){
        _lecteur_list.push_back(lecteur);
        _lecteur_id_list.push_back(lecteur.GetIdentifiant());
        std::cout << "Lecteur ajoute avec succe !" << std::endl;
    }
    else{
        std::cout << "Ce lecteur est deja inscirt a la bibliotheque" << std::endl;
    }
}

void Bibliotheque::AddLivre(Livre livre) {
    std::vector<int>::iterator check;
    check = std::find(_livre_ISBN_list.begin(), _livre_ISBN_list.end(), livre.GetISBN());

    if (check == _livre_ISBN_list.end()){
        _livre_list.push_back(livre);
        _livre_ISBN_list.push_back(livre.GetISBN());
        std::cout << "Livre ajoute avec succe !" << std::endl;
    }
    else{
        std::cout << "Ce livre est deja inscirt dans la bibliotheque" << std::endl;
    }
}

void Bibliotheque::AddAuteur(Auteur auteur) {
    std::vector<std::string>::iterator check;
    check = std::find(_auteur_id_list.begin(), _auteur_id_list.end(), auteur.GetIdentifiant());

    if (check == _auteur_id_list.end()){
        _auteur_list.push_back(auteur);
        _auteur_id_list.push_back(auteur.GetIdentifiant());
        std::cout << "Auteur ajoute avec succe !" << std::endl;
    }
    else{
        std::cout << "Cette auteur est deja inscirt a la bibliotheque" << std::endl;
    }
}

void Bibliotheque::AddEmprunt(Emprunt emprunt) {
    _emprunt_list.push_back(emprunt);
}