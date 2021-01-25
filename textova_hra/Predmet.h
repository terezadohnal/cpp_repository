//
// Created by Tereza  Dohnalova on 14/12/2020.
//

#ifndef MAIN_CPP_PREDMET_H
#define MAIN_CPP_PREDMET_H
#include <iostream>


class Predmet {

    std::string m_nazev;
    int m_bonusKUtoku;
    int m_bonusKZivotum;
    int m_bonusKObrane;

public:

    // Konstruktor

    Predmet(std::string nazev, int bonusKUtoku, int bonusKZivotum, int bonusKObrane);

    // ------------------------------------------------------------------------------

    // Gettery

    std::string getNazev();

    int getBonusKUtoku();

    int getBonusKZivotum();

    int getBonusKObrane();

    // ------------------------------------------------------------------------------

    // Print

    void vypisInfo();

};


#endif //MAIN_CPP_PREDMET_H

