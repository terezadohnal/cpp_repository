//
// Created by Tereza  Dohnalova on 10/12/2020.


#ifndef MAIN_CPP_HRDINA_H
#define MAIN_CPP_HRDINA_H

#include <iostream>
#include <vector>
#include "Predmet.h"
#include "Nepritel.h"
#include "Inventar.h"
#include "Klic.h"


// Uložení pozice pomocí struct (Přepravka)

struct Pozice2d{
    int x;
    int y;
};

/*struct Posun2d{
    int x;
    int y;
};
*/
class Hrdina {

    std::string m_jmeno;
    int m_zivoty;
    int m_sila;
    int m_obrana;
    Inventar* m_inventar;
    Pozice2d m_aktualniPozice;
    bool m_schopnostPlavitSe;
    std::vector<Klic*> m_klicenka;

public:

    //Konstruktor

    Hrdina(std::string jmeno);

    // -----------------------------------------------

    // Gettery

    int getSila();

    int getZivoty();

    int getObrana();

    std::string getJmeno();

    bool getSchopnostPlavitSe();

    std::vector<Klic*> getKlicenka();

    // -------------------------------------------------

    // Správa schopností

    void setSchopnostPlavitSe(bool schopnostPlavitSe);

    // -------------------------------------------------

    // Kontrola

    bool kontrolaSchopnostiSePlavit();

    // --------------------------------------------------

    // Správa věcí

    void pridejPredmetDoInventare(Predmet* predmet);

    void vypisPredmetyVInventari();

    void pridejKlicDoKlicenky(Klic* klic);

    // --------------------------------------------------


    //Správa životů
    void setZivot(int noveZivoty);

    void doplnZivot(int okolik);

    // ----------------------------------------------------

    //Posunuti hrdiny
    void provedPosunuti(int kam);

    Pozice2d getAktualniPozice();
    //return m_aktualniPozice;

    // ---------------------------------------------------

    // Printy

    void printInfo();
};


#endif //MAIN_CPP_HRDINA_H
