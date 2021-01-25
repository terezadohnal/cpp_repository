//
// Created by Tereza  Dohnalova on 24/01/2021.
//

#include "Klic.h"

Klic::Klic(std::string nazev, int unikatniKod) : UnikatniPredmet(nazev, unikatniKod){}

int Klic::getUnikatniKod() {
    return m_unikatniKod;
}

std::string Klic::getNazev() {
    return m_nazev;
}