//
// Created by Tereza  Dohnalova on 28/12/2020.
//

#ifndef MAIN_CPP_HRA_H
#define MAIN_CPP_HRA_H
#include <iostream>
#include "Mapa.h"
#include "Hrdina.h"


class Hra {

    Mapa* m_mapaHry;
    Hrdina* m_hrdina;
    int m_predeslaVolba;
    bool m_konecHry;

public:

    // V kontruktoru se vytvoří Hrdina a mapa
    Hra();

    // --------------------------------------------

    // Správa menu

    void printMenu();

    void printZakladniMenu();

    void printMenuPredmetu();

    void printMenuNepritele();

    void printMenuKlice();

    // --------------------------------------------

    // Předešlá volba pohybu

    int getPredeslaVolba();

    void setPredeslaVolba(int volba);

    // ---------------------------------------------

    // Konec hry

    void provedKontroluSouradnicProKonecHry();

    //bool getKonecHry();

    void setKonecHry(bool konecHry);

    // ---------------------------------------------

    // Zkontroluje, zda se nachází v lokaci předmět
    bool existujePredmetVLokaci();

    bool existujeNepritelVLokaci();

    bool existujeKlicVLokaci();

    // ----------------------------------------------

    //Metoda pro vykonání boje
    bool provedBoj(Nepritel* nepritel);

    // Metoda pro volbu pohybu 1-4
    void provedVolbuAkce(int volbaAkce);

    // Metoda pro volbu sběru 6
    void provedVolbuAkceProSberPredmetu();

    //Metoda pro volbu boje 7
    void provedVolbuAkceProBoj();

    // Metoda pro vykonání pohybu
    void provedAkci();

    // Metoda pro ověření kódu klíče a dveří
    bool provedKontroluKodu(Dvere* dvere);

    // Metoda, která se zvolává, v ní jsou vloženy všechny metody potřebné k fungování hry
    void hrej();


};


#endif //MAIN_CPP_HRA_H
