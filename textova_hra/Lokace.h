//
// Created by Tereza  Dohnalova on 11/12/2020.
//

#ifndef MAIN_CPP_LOKACE_H
#define MAIN_CPP_LOKACE_H
#include <iostream>
#include "Nepritel.h"
#include "Predmet.h"
#include "Inventar.h"
#include "Klic.h"
#include "Dvere.h"

// Chceme mít typy lokací: Cesta, Les, Řeka, Voda, Jeskyně, Hrad

enum class TypyLokaci{
    Cesta, Les, Řeka, Louka, Jeskyně, Hrad
};

class Lokace {
    std::string m_typ;
    bool m_pohyb;
    Inventar* m_inventar;
    Nepritel* m_nepritel;
    Klic* m_klic;
    Dvere* m_dvere;

public:

    //Konstruktor pro obyčejnou lokaci
    Lokace(std::string typ);

    // -----------------------------------------------

    // Gettery

    std::string getTyp();

    bool getPohyb();

    Predmet* getPredmet();

    Nepritel* getNepritel();

    Klic* getKlic();

    Dvere* getDvere();

    // -----------------------------------------------

    // Seter

    void setNepritel(Nepritel* nepritel);

    void setDvere(Dvere* dvere);

    void setKlic(Klic* klic);

    // -----------------------------------------------

    // Printy

    //void printInfo();

    void printPredmetInfo();

    void printNepritelInfo();

    void printKlicInfo();

    // ----------------------------------------------

    // Existence

    bool existujePredmet();

    bool existujeNepritel();

    bool existujeReka();

    bool existujeKlic();

    bool existujiDvere();

    // -----------------------------------------------

    // Přídání, odebrání

    void pridejPredmetDoInventare(Predmet* predmet);

    void smazPredmetZInventare();

};


#endif //MAIN_CPP_LOKACE_H
