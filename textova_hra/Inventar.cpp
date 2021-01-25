//
// Created by Tereza  Dohnalova on 14/12/2020.
//

#include "Inventar.h"

Inventar::Inventar() {
    for (Predmet* predmet:m_predmety) {
        predmet = nullptr;
    }
};

// -----------------------------------------------

void Inventar::pridejPredmet(Predmet* predmet) {
    m_predmety.push_back(predmet);
}

void Inventar::odeberPredmet() {
    m_predmety.erase(m_predmety.begin());
}

// -----------------------------------------------

int Inventar::zjistiVelikostInventare() {
    return m_predmety.size();
}

// -----------------------------------------------

void Inventar::vypisPredmetyVInventari() {
    int cislo=1;

    for (Predmet* predmet : m_predmety){

        std::cout << std::endl;
        std::cout << cislo << ".";
        predmet->vypisInfo();
        std::cout << std::endl;
        cislo++;
    }
}

// -----------------------------------------------

Predmet * Inventar::getPredmet() {
    return m_predmety.at(0);
}

int Inventar::getSila() {
    int celkemSila = 0;
    for (Predmet* predmet:m_predmety) {
        celkemSila += predmet->getBonusKUtoku();
    }
    return celkemSila;
}

int Inventar::getObrana() {
    int celkemObrana = 0;
    for (Predmet* predmet:m_predmety) {
        celkemObrana += predmet->getBonusKObrane();
    }
    return celkemObrana;
}

std::vector<Predmet *> Inventar::getPredmety() {
    return m_predmety;
}