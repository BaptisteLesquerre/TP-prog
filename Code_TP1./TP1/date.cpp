//
// Created by Elie on 12/12/2022.
//


#include "date.h"

#include "iostream"


Date::Date(int jour, int mois, int annee) {
    int max_day;
    bool bissextile = 0;

    _annee = annee;

    if (annee % 4 == 0) {
        bissextile = 1;
    }

    if (0 <= mois <= 12) {
        _mois = mois;

        if (mois == 2) {
            if (bissextile == 1) {
                max_day = 29;
            } else {
                max_day = 28;
            }
        }

        else if (mois % 2 == 0) {
            max_day = 30;
        }

        else {
            max_day = 31;
        }

        if (0 <= jour <= max_day){
            _jour = jour;
        }

    }
}

int Date::GetJour() {
    return _jour;
}

int Date::GetMois() {
    return _mois;
}

int Date::GetAnnee() {
    return _annee;
}

void Date::SetJour(int jour) {
    _jour = jour;
}

void Date::SetMois(int mois) {
    _mois = mois;
}

void Date::SetAnnee(int annee) {
    _annee = annee;
}

void Date::Display() {
    std::cout << _jour << " / " << _mois << " / " << _annee << std::endl;
}
