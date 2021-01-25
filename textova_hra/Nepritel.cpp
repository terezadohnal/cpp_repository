//
// Created by Tereza  Dohnalova on 14/12/2020.
//

#include "Nepritel.h"

Nepritel::Nepritel(std::string nazev, int sila, int zivoty, int obrana, Predmet* predmet)
{
    m_nazev = nazev;
    m_sila = sila;
    m_zivoty = zivoty;
    m_obrana = obrana;

    m_inventar = new Inventar();
    pridejPredmetDoInventare(predmet);

}

// -----------------------------------------------------------

std::string Nepritel::getJmeno() {
    return m_nazev;
}

int Nepritel::getSila() {
    return m_sila;
}

int Nepritel::getZivoty() {
    return m_zivoty;
}

int Nepritel::getObrana() {
    return m_obrana;
}

Predmet * Nepritel::getPredmet() {
    return m_inventar->getPredmet();
}

// -----------------------------------------------------------------

void Nepritel::printInfo() {
    std::cout << "Jméno nepřítele: " << m_nazev << std::endl;
    std::cout << "Síla: " << m_sila << std::endl;
    std::cout << "Životy: " << m_zivoty << std::endl;
    std::cout << "Obrana: " << m_obrana << std::endl;
    if (m_inventar->getPredmet() != nullptr){
        std::cout << "V jeho inventáři se nachází: " << std::endl;
        m_inventar->vypisPredmetyVInventari();
    }
}

// ----------------------------------------------------------------

bool Nepritel::existujePredmet() {
    if (m_inventar->getPredmet() != nullptr){
        return true;
    }else{
        return false;
    }
}

void Nepritel::pridejPredmetDoInventare(Predmet* predmet) {
    m_inventar->pridejPredmet(predmet);
}

/*
void Nepritel::smazPredmetZInventare() {
    m_inventar->odeberPredmet();
}
 */