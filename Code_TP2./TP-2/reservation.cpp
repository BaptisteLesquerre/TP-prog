#include "reservation.h"
#include "date.h"
#include "hotel.h"
#include "client.h"
#include<iostream>

Reservation::Reservation(std::string id_reservation,Date nuit_debut, int nb_nuit, std::string id_hotel, int numero_chambre, std::string id_client, int montant)
{
    _nuit_debut = nuit_debut;
    _nb_nuits = nb_nuit;
    _id_hotel = id_hotel;
    _numero_chambre = numero_chambre;
    _id_client = id_client;
    _montant = montant;
    _id_reservation = id_reservation;

}

Date Reservation::getNuitDebut()
{
    return _nuit_debut;
}

int Reservation::getNbNuits()
{
    return _nb_nuits;
}

int Reservation::getNumeroChambre()
{
    return _numero_chambre;
}

int Reservation::getMontant()
{
    return _montant;
}

std::string Reservation::getIdHotel()
{
    return _id_hotel;
}

std::string Reservation::getIdClient()
{
    return _id_client;
}

std::string Reservation::getid_reservation()
{
    return _id_reservation;
}

void Reservation::setNuitDebut(Date nuit_debut)
{
    _nuit_debut = nuit_debut;
}

void Reservation::setNbNuits(int nb_nuits)
{
    _nb_nuits = nb_nuits;
}

void Reservation::setNumeroChambre(int numero_chambre)
{
    _numero_chambre = numero_chambre;
}

void Reservation::setMontant(int montant)
{
    _montant = montant;
}

void Reservation::setIdHotel(std::string id_hotel)
{
    _id_hotel = id_hotel;
}

void Reservation::setIdClient(std::string id_client)
{
    _id_client = id_client;
}

//helper pour afficher de différentes manières les réservations.....................................................................................
std::string Reservation::tostring() const {
    return _id_reservation +")"+"date première nuit : " + std::to_string(_nuit_debut.day()) + "/" + std::to_string(_nuit_debut.month()) + "/" + std::to_string(_nuit_debut.year())  + " | " + "nombre de nuits : " + std::to_string(_nb_nuits) + " | " +"id hotel : " + _id_hotel + " | " +"id client : " + _id_client + " | " +"numéro de chambre : " + std::to_string(_numero_chambre) + " | " +"montant : " + std::to_string(_montant);
}


std::ostream& operator<<(std::ostream& os,const Reservation& reservation){
        os << reservation.tostring() <<std::endl;
        return os;
}

void display(std::vector<Reservation> rtab ){
    //affiche toutes les réservations d'un tableau de réservation
    std::string c ="";
			for (int i = 1; i < rtab.size(); i++){
				c = c + rtab.at(i).tostring() + "||";
			}
    std::cout<<" "<<std::endl;
    std::cout<< c<<std::endl;
	std::cout<<" "<<std::endl;
}

void display_reservation(std::vector<Reservation> rtab ){
    //affiche une réservation selon son identifiant donné en paramètre 
    std::string a;
    std::cout<<"Donnez le l'identifiant de la réservation"<<std::endl;
    std::cin>>a;
    for( int i=0; i<rtab.size(); i=i+1){
        if (a==rtab.at(i).getid_reservation()){
            std::cout<< rtab.at(i).tostring() <<std::endl;
        }
    } 
}

bool display_reservation_clientid(std::vector<Reservation> rtab, std::string client){
    //fonction utilisée par display_reservation_client pour affichervtoutes les réservations
    //d'un client selon son identifiant
    bool r = false;
    for( int i=0; i<rtab.size(); i=i+1){
        if (client==rtab.at(i).getIdClient()){
            std::cout<< rtab.at(i).tostring() <<std::endl;
            r = true;
        }
    } 
    return r;
}

void display_reservation_client( std::vector<Reservation> rtab, std::vector<Client> ctab ){
    //affiche toutes les réservations d'un client 
    std::string client;
    std::cout<<"Donnez le client"<<std::endl;
    std::cin>>client;
    bool idclient = display_reservation_clientid(rtab,client);
    if (idclient==false){
        for( int i=0; i<rtab.size(); i=i+1){
           if (client==ctab.at(i).nom()){ 
             std::string client2 = ctab.at(i).idclient();
             bool idclient = display_reservation_clientid(rtab,client2);
           }
        }
    }
}

//helper pour saisir et modifier des réservations..................................................................................................
int calcul_montant(int idchambre, hotel::Hotel h1, int nbdenuits){
    for(int i=0; i<h1.tabchambre().size(); i= i+1){
        if (idchambre==h1.tabchambre().at(i).GetNumero()){
            return nbdenuits*(h1.tabchambre().at(i).GetPrice());
        }
    }
}

bool creneau_valide(Reservation r,std::vector<int>& chambre_dispo,std::vector<Reservation>& reservationtab,Date datebegin,int nbdenuits){
//verifie si pour chaque reservation la date de debut et de fin sont dans le creneau
//initialise un tableau de chambre disponible
    Date dateend = datebegin + nbdenuits;
    Date a;
    bool creneau_valide = false;
    for (int i =0; i < reservationtab.size() ; i = i+1 ){
        a = reservationtab.at(i).getNuitDebut();
        if (( ((a + reservationtab.at(i).getNbNuits())>= datebegin) & (datebegin>= a)) or ((a <= dateend) &(dateend<= (a + reservationtab.at(i).getNbNuits())))){
        }
        else if (reservationtab.at(i).getid_reservation()==r.getid_reservation()){
            creneau_valide = true;
            chambre_dispo.push_back(reservationtab.at(i).getNumeroChambre());
        }
        else{
            creneau_valide = true;
            chambre_dispo.push_back(reservationtab.at(i).getNumeroChambre());
        }
    }
    return creneau_valide;
}

bool search_chambre(int nbdenuits, std::string typechambre, Reservation& r, std::vector<int>& chambre_dispo, hotel::Hotel h1){
//parcourir les chambre dispo a la recherche de la bonne 
// soit l'associer et renvoyer true sinon renvoyer false 
    bool disponible = false;
    for (int i = 0; i < chambre_dispo.size(); i = i+1 ){
        for (int j = 0; j < h1.tabchambre().size(); j=j+1){
            if (( h1.tabchambre().at(j).GetNumero()== chambre_dispo.at(i)) & (typechambre == h1.tabchambre().at(j).GetType())){
                r.setNumeroChambre(h1.tabchambre().at(j).GetNumero());
                r.setMontant(calcul_montant(h1.tabchambre().at(j).GetNumero(),h1,nbdenuits));
                disponible = true;
                return disponible;
            }
        }
    }  
}

void chambre_libre(std::vector<int>& chambre_dispo,std::vector<Reservation>& rtab,hotel::Hotel h1){
    //permet d'ajouter au tableau des chambres disponibles toutes celles sans réservations
    for (int i=0; i < h1.tabchambre().size(); i = i+1){
        bool reserve = true;
        for (int j=0; j<rtab.size(); j=j+1){
            if (h1.tabchambre().at(i).GetNumero()==rtab.at(j).getNumeroChambre()){
                reserve = false;
            }               
        }
        if (reserve == true){
            chambre_dispo.push_back(h1.tabchambre().at(i).GetNumero());
        }        
    }
}

void saisi_reservation1(std::vector<Reservation>& rtab,Reservation& r ,hotel::Hotel h1,std::string idclient){
    //permet en itéragissant avec l'utilisateur de créer une réservation
    std::vector<int> chambre_dispo;
    bool datevalide = false;
    int nbdenuits;
    int jour;
    int moi;
    int année;
    
    while(datevalide == false){
        datevalide = true;
        std::cout<<"saisissez le nombre de nuit "<<std::endl;
        std::cin>> nbdenuits;
        r.setNbNuits(nbdenuits);

        std::cout<<"saisissez la date : "<<std::endl;
        std::cout<<""<<std::endl;
        std::cout<<"saisissez le jour "<<std::endl;
        std::cin>> jour;
        int jour1 = (int) jour;
        std::cout<<"saisissez le moi "<<std::endl;
        std::cin>> moi;
        int moi1 = (int) moi;
        std::cout<<"saisissez l'année "<<std::endl;
        std::cin>> année;
        int année1 = (int) année;
        Date date(jour1, moi1, année1);
        r.setNuitDebut(date);

        chambre_libre(chambre_dispo ,rtab, h1);
        if (rtab.size()==1){
             datevalide = true;
        }
        else{
            if (creneau_valide(r,chambre_dispo,rtab,date,nbdenuits)==true){
                datevalide = true;
            }
            else if (chambre_dispo.size()==0){
                datevalide = false;
                std::cout<<"créneau non disponible, veuillez resaisir"<<std::endl;
            }
        }
    }
   
    //recherche chambre
    std::string typechambre;
    std::cout<<"saisissez le type de chambre souhaité"<<std::endl;
    std::cin>>typechambre;
    bool reservation_comp = false;
    while(reservation_comp==false){
        if(search_chambre(nbdenuits, typechambre,r,chambre_dispo,h1)==true){
            reservation_comp=true;
        }
        else{
        std::cout<<"choisissez un autre type de chambre"<<std::endl;
        std::cin >>typechambre;
        }
    }
    std::cout<< "vous avez réservé la chambre n°"<<r.getNumeroChambre()<<std::endl;
    std::cout<< "le cout par nuit de la chambre est de : "<< r.getMontant()/nbdenuits<< std::endl;
}

void saisi_reservation2(std::vector<Reservation>& rtab,Reservation& r ,hotel::Hotel h1,std::string idclient){
    saisi_reservation1(rtab,r,h1,idclient);
    rtab.push_back(r);
}

void reservation_creator(hotel::Hotel h1,std::vector<Client> tab_client, std::vector<Reservation> rtab){
    //helper principale permetant de créer, modifier et suprimer lesz réservations 
    //contenues dans un tableau (cette fonction utilise d'autre sous-fonctions)
	std::string encore_reserve = "yes";
	Date datedef;
        int nb=0;
	while(encore_reserve == "yes"){
            nb=nb+1;
	    std::string ids =saisi_client(tab_client);
	    Reservation r(std::to_string(nb),datedef,0,h1.idhotel(),0,ids,0);
	    saisi_reservation2(rtab, r, h1, ids);
	    display(rtab);

            modif_reservation(rtab,h1);
            delete_reservation(rtab);
            
            std::cout<<"Procéder à une nouvelle réservation?"<<std::endl;
			std::cin>> encore_reserve;
	}
}

std::string modif_reservation(std::vector<Reservation>& rtab,hotel::Hotel h1){
    //permet de modifier une réservation en conservant l'identifiant de l'hotel et
    //celui du client
    std::string check;
    std::cout<<"Voulez vous modifier une réservation?"<<std::endl;
    std::cin>>check;
    if ((check=="yes") or (check=="oui")){
        std::string id;
        std::cout<< "donnez l'identifiant de la reservation"<<std::endl;
        std::cin>>id;
        for (int i=0; i<rtab.size(); i=i+1){
            if(id==rtab.at(i).getid_reservation()){                
                saisi_reservation1(rtab,rtab.at(i),h1,rtab.at(i).getIdClient());
                display(rtab);
                return "";
            }
        }
    }
}

std::string delete_reservation(std::vector<Reservation>& rtab){
    //suprime une réservation choissit
    std::string check;
    std::cout<<"voulez vous suprimer une réservation?"<<std::endl;
    std::cin>>check;
    if ((check=="yes") or (check=="oui")){
        std::string id;
        std::cout<< "Donnez l'identifiant de la réservation."<<std::endl;
        std::cin>>id;
        for (auto it=rtab.begin();it != rtab.end();it=it+1) {
            if((*it).getid_reservation()==id){
                std::cout<< *it <<std::endl;
                rtab.erase(it);
                display(rtab);
                return "";
            }
        }
    }
}
