//
// Created by Elie on 05/01/2023.
//

#include "emprunt.h"

Emprunt::Emprunt(Date date, Lecteur lecteur, Livre livre) {
    if (livre.GetIsFree() == 1){
        _date = date;
        _ISBN = livre.GetISBN();
        _identifiant = lecteur.GetIdentifiant();

        livre.SetIsFree(0);
        livre.AddIdToList(_identifiant);

        lecteur.AddISBNToList(_ISBN);
    }
    else{
        std::cout << "Ce livre n'est pas disponible pour le moment" << std::endl;
    }
}

Date Emprunt::GetDate() {
    return _date;
}

int Emprunt::GetISBN() {
    return _ISBN;
}

std::string Emprunt::GetIdentifiant() {
    return _identifiant;
}