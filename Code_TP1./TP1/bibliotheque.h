//
// Created by Elie on 05/01/2023.
//

#ifndef TP1_BIBLIOTHEQUE_H
#define TP1_BIBLIOTHEQUE_H

#include "livre.h"
#include "emprunt.h"
#include "auteur.h"
#include "lecteur.h"

#include "algorithm"
#include "vector"
#include "string"


class Bibliotheque {
private:
    std::vector<Livre> _livre_list;
    std::vector<int> _livre_ISBN_list;
    std::vector<Emprunt> _emprunt_list;
    std::vector<Auteur> _auteur_list;
    std::vector<std::string> _auteur_id_list;
    std::vector<Lecteur> _lecteur_list;
    std::vector<std::string> _lecteur_id_list;
    std::string _nom_bibliotheque;
    std::string _adress;

public:
    Bibliotheque(std::string nom_biblioteque, std::string adress);

    std::vector<Livre> GetLivreList();
    std::vector<Emprunt> GetEmpruntList();
    std::vector<Auteur> GetAuteurList();
    std::vector<Lecteur> GetLecteurList();
    std::string GetNomBibliotheque();
    std::string GetAdress();

    void AddAuteur(Auteur auteur);
    void AddLivre(Livre livre);
    void AddLecteur(Lecteur lecteur);
    void AddEmprunt(Emprunt emprunt);



};


#endif //TP1_BIBLIOTHEQUE_H
