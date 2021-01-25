//
// Created by Tereza  Dohnalova on 24/01/2021.
//

#ifndef MAIN_CPP_UNIKATNIPREDMET_H
#define MAIN_CPP_UNIKATNIPREDMET_H

#include <iostream>


class UnikatniPredmet {
protected:
    std::string m_nazev;
    int m_unikatniKod;

public:

    // Konstruktor

    UnikatniPredmet(std::string nazev, int unikatniKod);

    // -------------------------------------------------

    // Virtualní gettery

    virtual int getUnikatniKod() = 0;
    virtual std::string getNazev() = 0;

};


#endif //MAIN_CPP_UNIKATNIPREDMET_H
