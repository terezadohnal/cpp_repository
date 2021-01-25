//
// Created by Tereza  Dohnalova on 14/12/2020.
//

#ifndef MAIN_CPP_NEPRITEL_H
#define MAIN_CPP_NEPRITEL_H

#include <iostream>
#include "Inventar.h"


class Nepritel {

    std::string m_nazev;
    int m_sila;
    int m_zivoty;
    int m_obrana;
    Inventar* m_inventar;

public:
    // Konstruktor
    Nepritel(std::string nazev, int sila, int zivoty, int obrana, Predmet* predmet);

    // -----------------------------------------------------------------------------

    // Gettery
    std::string getJmeno();
    int getSila();
    int getZivoty();
    int getObrana();
    Predmet* getPredmet();

    // ------------------------------------------------

    // Printy
    void printInfo();

    // ------------------------------------------------

    // Přídávání, odebírání, existence

    bool existujePredmet();

    void pridejPredmetDoInventare(Predmet* predmet);

    //void smazPredmetZInventare();

    // ------------------------------------------------
};


#endif //MAIN_CPP_NEPRITEL_H
