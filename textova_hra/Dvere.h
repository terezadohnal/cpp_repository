//
// Created by Tereza  Dohnalova on 24/01/2021.
//

#ifndef MAIN_CPP_DVERE_H
#define MAIN_CPP_DVERE_H

#include "UnikatniPredmet.h"

class Dvere : public UnikatniPredmet {
public:

    Dvere(std::string nazev, int unikatniKod);

    // -----------------------------------------

    int getUnikatniKod() override;

    std::string getNazev() override;

};


#endif //MAIN_CPP_DVERE_H
