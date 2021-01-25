//
// Created by Tereza  Dohnalova on 24/01/2021.
//

#include "Dvere.h"

Dvere::Dvere(std::string nazev, int unikatniKod) : UnikatniPredmet(nazev, unikatniKod){}

int Dvere::getUnikatniKod() {
    return m_unikatniKod;
}

std::string Dvere::getNazev() {
    return m_nazev;
}
