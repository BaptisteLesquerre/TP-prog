#include "date.h"
#include "livre.h"
#include "lecteur.h"
#include "emprunt.h"
#include "auteur.h"
#include "bibliotheque.h"

#include <iostream>


int main(){
    Date date1(12, 06, 2020);
    Date date2(20, 07, 1969);


    Auteur auteur1( date2, "777", "jean", "david");


    Livre livre1("livre des etoile", "Francais", "Aventure", date1, 13214, auteur1);

    Lecteur lecteur1("LeGrandFilou", "Pi", "Ere");

    Emprunt emprunt1(date1, 13214, lecteur1.GetIdentifiant());

    std::cout << livre1.GetIdList()[0] << " | " << lecteur1.GetIdentifiant() << std::endl;

}

