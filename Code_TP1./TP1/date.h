//
// Created by Elie on 12/12/2022.
//

#ifndef TP1_DATE_H
#define TP1_DATE_H

#include "iostream"

class Date {
private:
    int _jour;
    int _mois;
    int _annee;

public:
    Date(int jour = 01, int mois = 01, int annee = 2000);

    int GetJour();
    int GetMois();
    int GetAnnee();

    void SetJour(int jour);
    void SetMois(int mois);
    void SetAnnee(int annee);

    void Display();

};

#endif //TP1_DATE_H