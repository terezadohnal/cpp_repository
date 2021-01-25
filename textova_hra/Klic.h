//
// Created by Tereza  Dohnalova on 24/01/2021.
//

#ifndef MAIN_CPP_KLIC_H
#define MAIN_CPP_KLIC_H

#include "UnikatniPredmet.h"

class Klic : UnikatniPredmet {
public:

    Klic(std::string nazev, int unikatniKod);

    // ----------------------------------------

    int getUnikatniKod() override;

    std::string getNazev() override;
};


#endif //MAIN_CPP_KLIC_H
