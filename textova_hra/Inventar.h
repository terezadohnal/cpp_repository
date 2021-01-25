//
// Created by Tereza  Dohnalova on 14/12/2020.
//

#ifndef MAIN_CPP_INVENTAR_H
#define MAIN_CPP_INVENTAR_H
#include <iostream>
#include "Predmet.h"
#include <vector>

class Inventar {

    std::vector<Predmet*> m_predmety;

public:

    Inventar();

    // ----------------------------------

    // Přidání, odebrání

    void pridejPredmet(Predmet* predmet);

    void odeberPredmet();

    // ----------------------------------

    // Výpis

    void vypisPredmetyVInventari();

    // ----------------------------------

    // Velikost

    int zjistiVelikostInventare();

    // ----------------------------------

    // Gettery

    Predmet* getPredmet();

    int getSila();

    int getObrana();

    std::vector<Predmet*> getPredmety();

};

#endif //MAIN_CPP_INVENTAR_H