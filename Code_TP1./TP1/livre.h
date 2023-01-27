//
// Created by Elie on 18/12/2022.
//

#ifndef TP1_LIVRE_H
#define TP1_LIVRE_H

#include "date.h"
#include "auteur.h"

#include <iostream>
#include <string>
#include <vector>


class Livre {
private:
    std::string _titre;
    Auteur _auteur;
    std::string _langue;
    std::string _genre;
    Date _date_livre;
    int _ISBN;
    std::vector<std::string> _id_list;
    bool _is_free;

public:
    Livre(std::string titre, std::string langue, std::string genre, Date date_livre, int ISBN, Auteur auteur = Auteur(), bool is_free = 1);

    std::string GetTitre();
    std::string GetLangue();
    std::string GetGenre();
    int GetISBN();
    bool GetIsFree();
    std::vector<std::string> GetIdList();
    Auteur GetAuteur();

    void AddIdToList(std::string identifiant);

    void SetIsFree(bool is_free);
    void DisplayDate();
};


#endif //TP1_LIVRE_H
