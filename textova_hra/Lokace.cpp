//
// Created by Tereza  Dohnalova on 11/12/2020.
//

#include "Lokace.h"

Lokace::Lokace(std::string typ) {
    m_typ = typ;
    if (m_typ == "louka" || m_typ == "cesta") {
        m_pohyb = true;
    } else{
        m_pohyb = false;
    }

    m_inventar = new Inventar();
    m_nepritel = nullptr;
    m_klic = nullptr;
    m_dvere = nullptr;
}

// -----------------------------------------------

std::string Lokace::getTyp() {
    return m_typ;
}

bool Lokace::getPohyb() {
    return m_pohyb;
}

Predmet * Lokace::getPredmet() {
    return m_inventar->getPredmet();
}

Nepritel * Lokace::getNepritel() {
    return m_nepritel;
}

Klic * Lokace::getKlic() {
    return m_klic;
}

Dvere* Lokace::getDvere() {
    return m_dvere;
}

// -----------------------------------------------

void Lokace::setNepritel(Nepritel *nepritel) {
    m_nepritel = nepritel;
}

void Lokace::setDvere(Dvere *dvere) {
    m_dvere = dvere;
}

void Lokace::setKlic(Klic *klic) {
    m_klic = klic;
}

// --------------------------------------------------------

/*void Lokace::printInfo() {
    std::cout << "Lokace je typu: " << getTyp();
    if (getPohyb() == 1){
        std::cout << " a lze po ni chodit." << std::endl;
    } else{
        std::cout << " a nelze po ni chodit." << std::endl;
    }
}
 */

void Lokace::printPredmetInfo() {
    m_inventar->getPredmet()->vypisInfo();
}

void Lokace::printNepritelInfo() {
    m_nepritel->printInfo();
}

void Lokace::printKlicInfo() {
    std::cout << m_klic->getNazev() << std::endl;
}

// ----------------------------------------------------

bool Lokace::existujePredmet() {
    if (m_inventar->zjistiVelikostInventare() == 0){
        return false;
    }else{
        return true;
    }
}

bool Lokace::existujeNepritel() {
    if(m_nepritel != nullptr){
        return true;
    } else {
        return false;
    }
}

bool Lokace::existujeReka() {
    if (m_typ == "voda"){
        return true;
    } else {
        return false;
    }
}

bool Lokace::existujeKlic() {
    if (m_klic != nullptr){
        return true;
    } else {
        return false;
    }
}

bool Lokace::existujiDvere() {
    if (m_dvere != nullptr){
        return true;
    } else {
        return false;
    }
}

// -------------------------------------------------------

void Lokace::pridejPredmetDoInventare(Predmet* predmet) {
    m_inventar->pridejPredmet(predmet);
}

void Lokace::smazPredmetZInventare() {
    m_inventar->odeberPredmet();
}

