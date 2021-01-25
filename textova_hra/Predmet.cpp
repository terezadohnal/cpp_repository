//
// Created by Tereza  Dohnalova on 14/12/2020.
//

#include "Predmet.h"


Predmet::Predmet(std::string nazev, int bonuskutoku, int bonuskzivotum, int bonuskobrane){

    m_nazev = nazev;
    m_bonusKUtoku = bonuskutoku;
    m_bonusKZivotum = bonuskzivotum;
    m_bonusKObrane = bonuskobrane;
}

// ---------------------------------------------------------------------------------------

std::string Predmet::getNazev() {
    return m_nazev;
}

int Predmet::getBonusKUtoku() {
    return m_bonusKUtoku;
}

int Predmet::getBonusKZivotum() {
    return m_bonusKZivotum;
}

int Predmet::getBonusKObrane() {
    return m_bonusKObrane;
}

// ---------------------------------------------------------------------------------------

void Predmet::vypisInfo() {
    std::cout << "Název předmětu: " << getNazev() << std::endl;
    std::cout << "Bonus k útoku: " << getBonusKUtoku() << std::endl;
    std::cout << "Bonus k obraně: " << getBonusKObrane() << std::endl;
    std::cout << "Bonus k životům: " << getBonusKZivotum() << std::endl;
}
