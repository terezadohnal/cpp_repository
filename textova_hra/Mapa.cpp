//
// Created by Tereza  Dohnalova on 11/12/2020.
//

#include "Mapa.h"

Mapa::Mapa() {

    for (int i = 0; i < m_mapa.size(); ++i) {
        for (int j = 0; j < m_mapa.size(); ++j) {
            m_mapa[i][j] = nullptr;
        }
    }

}

// ---------------------------------------------------------------------------------------------------------------------------------------------------------

void Mapa::vytvorMapu() {

    // std::array<std::array<std::string, 16>, 16> m_data;

    std::string m_data[16][16] = {
            /*0.*/{"les", "les", "les", "les", "voda", "voda", "voda", "les", "les", "les", "hrad", "hrad", "hrad", "hrad",
                          "hrad", "les"},
            /*1.*/{"les", "cesta", "les", "les", "cesta", "voda", "voda", "voda", "les", "les", "hrad", "hrad", "hrad", "hrad",
                          "hrad", "les"},
            /*2.*/{"les", "cesta", "cesta", "les", "les", "cesta", "voda", "voda", "voda", "les", "hrad", "cesta", "cesta", "cesta",
                          "hrad", "les"},
            /*3.*/{"les", "les", "cesta", "les", "les", "cesta", "les", "voda", "voda", "les", "hrad", "cesta", "cesta", "cesta",
                          "hrad", "les"},
            /*4.*/{"les", "les", "cesta", "cesta", "cesta", "cesta", "cesta", "voda", "voda", "les", "hrad", "hrad", "cesta", "hrad",
                          "hrad", "les"},
            /*5.*/{"les", "les", "cesta", "les", "les", "les", "les", "voda", "voda", "les", "les", "louka", "louka", "louka",
                          "les", "les"},
            /*6.*/{"les", "les", "cesta", "les", "les", "cesta", "les", "voda", "voda", "louka", "louka", "louka", "louka", "louka",
                          "louka", "louka"},
            /*7.*/{"cesta", "cesta", "cesta", "cesta", "cesta", "cesta", "les", "voda", "voda", "voda", "voda", "voda", "voda", "louka",
                          "louka", "louka"},
            /*8.*/{"les", "les", "les", "cesta", "les", "cesta", "les", "voda", "voda", "louka", "louka", "voda", "voda", "louka",
                          "louka", "louka"},
            /*9.*/{"les", "les", "les", "cesta", "les", "les", "les", "voda", "voda", "louka", "jeskyně", "jeskyně", "jeskyně", "jeskyně",
                          "louka", "louka"},
            /*10.*/{"cesta", "cesta", "cesta", "cesta", "cesta", "cesta", "cesta", "voda", "voda", "louka", "louka", "cesta", "cesta", "jeskyne",
                          "louka", "louka"},
            /*11.*/{"cesta", "les", "cesta", "les", "les", "cesta", "les", "voda", "voda", "louka", "jeskyně", "jeskyně", "jeskyně", "jeskyně",
                          "louka", "louka"},
            /*12.*/{"cesta", "les", "cesta", "les", "les", "cesta", "les", "voda", "voda", "voda", "louka", "louka", "louka", "louka",
                          "louka", "louka"},
            /*13.*/{"cesta", "les", "cesta", "les", "les", "cesta", "cesta", "voda", "voda", "voda", "voda", "voda", "voda", "voda",
                          "voda", "louka"},
            /*14.*/{"cesta", "les", "cesta", "cesta", "cesta", "cesta", "voda", "voda", "voda", "louka", "louka", "voda", "voda", "voda",
                          "louka", "louka"},
            /*15.*/{"cesta", "cesta", "cesta", "les", "les", "voda", "voda", "voda", "voda", "voda", "louka", "louka", "louka", "louka",
                          "louka", "louka"},
    };

    for (int i = 0; i < m_mapa.size(); ++i) {
        for (int j = 0; j < m_mapa.size(); ++j) {
            m_mapa[i][j] = new Lokace(m_data[i][j]);
        }
    }

    pridejPredmetyDoMapy();
    pridejNepriteleDoMapy();
    pridejKlicDoMapy();
    pridejDvereDoMapy();

}

// ---------------------------------------------------------------------------------------------------------------------------------------------------------

std::string Mapa::getTypLokace(int x, int y) {
    return m_mapa[y][x]->getTyp();
}

Predmet * Mapa::getPredmetVLokaci(int x, int y) {
    return m_mapa[y][x]->getPredmet();
}

Nepritel * Mapa::getNepritelVLokaci(int x, int y) {
    return m_mapa[y][x]->getNepritel();
}

Klic * Mapa::getKlicVLokaci(int x, int y) {
    return m_mapa[y][x]->getKlic();
}

Dvere* Mapa::getDvereVLokaci(int x, int y) {
    return m_mapa[y][x]->getDvere();
}

// ---------------------------------------------------------------------------------------------------------------------------------------------------------

bool Mapa::kontrolaSchudnosti(int x, int y) {
    if (m_mapa[y][x]->getPohyb()){
        return true;
    }else {
        return false;
    }
}

bool Mapa::kontrolaPredmetu(int x, int y) {
    if (m_mapa[y][x]->existujePredmet()){
        return true;
    } else{
        return false;
    }
}

bool Mapa::kontrolaNepritele(int x, int y) {
    if (m_mapa[y][x]->existujeNepritel()){
        return true;
    } else{
        return false;
    }
}

bool Mapa::kontrolaReky(int x, int y) {
    if (m_mapa[y][x]->existujeReka()){
        return true;
    } else {
        return false;
    }
}

bool Mapa::kontrolaDveri(int x, int y) {
    if (m_mapa[y][x]->existujiDvere()){
        return true;
    } else {
        return false;
    }
}

bool Mapa::kontrolaKlice(int x, int y) {
    if (m_mapa[y][x]->existujeKlic()){
        return true;
    } else {
        return false;
    }
}

// ---------------------------------------------------------------------------------------------------------------------------------------------------------

void Mapa::pridejPredmetDoLokace(Predmet* predmet, int x, int y) {
    m_mapa[y][x]->pridejPredmetDoInventare(predmet);
}

void Mapa::pridejPredmetyDoMapy() {
    pridejPredmetDoLokace(new Predmet("Dýka",2,0,0),3,7);
    pridejPredmetDoLokace(new Predmet("Lektvar zdraví",0,6,0),5,7);
    pridejPredmetDoLokace(new Predmet("Lektvar zdraví",0,6,0),3,10);
    pridejPredmetDoLokace(new Predmet("Lektvar zdraví",0,8,0),6,4);
    pridejPredmetDoLokace(new Predmet("Helma",0,0,6),5,2);
    pridejPredmetDoLokace(new Predmet("Palcát",1,0,0),14,6);
    pridejPredmetDoLokace(new Predmet("Lektvar zdraví",0,8,0),15,10);
    pridejPredmetDoLokace(new Predmet("Štít",0,0,1),9,14);
    pridejPredmetDoLokace(new Predmet("Pádlo", 0, 0, 0), 1, 1);
    pridejPredmetDoLokace(new Predmet("Loď", 0, 0, 0), 6, 13);
    pridejPredmetDoLokace(new Predmet("Princezna Fiona",0,0,0), 12, 2);
}

void Mapa::pridejNepriteleDoLokace(Nepritel *nepritel, int x, int y) {
    m_mapa[y][x]->setNepritel(nepritel);
}

void Mapa::pridejNepriteleDoMapy() {
    pridejNepriteleDoLokace(new Nepritel("Zloděj", 2, 9, 0, new Predmet("Rukavice", 0, 0, 1)), 2, 6);
    pridejNepriteleDoLokace(new Nepritel("Kostlivec", 3, 5, 1, new Predmet("Meč Ohně", 3, 0, 0)), 3, 8);
    pridejNepriteleDoLokace(new Nepritel("Darth Vader", 11, 4, 3, nullptr), 2, 3);
    pridejNepriteleDoLokace(new Nepritel("Zombík", 3, 10, 3, nullptr), 3, 4);
    pridejNepriteleDoLokace(new Nepritel("Drak", 10, 20, 2, nullptr), 10, 10);
}

void Mapa::pridejDvereDoLokace(Dvere *dvere, int x, int y) {
    m_mapa[y][x]->setDvere(dvere);
}

void Mapa::pridejDvereDoMapy() {
    pridejDvereDoLokace(new Dvere("Dveře poraženého kostlivce", 123), 3,9);
    pridejDvereDoLokace(new Dvere("Dveře poraženého draka", 456), 11,10);
    pridejDvereDoLokace(new Dvere("Dveře zachráněné princezny", 789), 12,4);
}

void Mapa::pridejKlicDoLokace(Klic *klic, int x, int y) {
    m_mapa[y][x]->setKlic(klic);
}

void Mapa::pridejKlicDoMapy() {
    pridejKlicDoLokace(new Klic("Klíč ke dveřím poraženého kostlivce", 123), 2, 4);
    pridejKlicDoLokace(new Klic("Klíč ke dveřím poraženého draka", 456), 12, 14);
    pridejKlicDoLokace(new Klic("Klíč ke dveřím zachráněné princezny", 789), 12, 10);
}

void Mapa::smazKlicZLokace(int x, int y) {
    m_mapa[y][x]->setKlic(nullptr);
}

void Mapa::smazPredmetZLokace(int x, int y) {
    m_mapa[y][x]->smazPredmetZInventare();
}

void Mapa::smazNepriteleZLokace(int x, int y) {
    m_mapa[y][x]->setNepritel(nullptr);
}

// ---------------------------------------------------------------------------------------------------------------------------------------------------------

void Mapa::printPredmetVLokaci(int x, int y) {
    m_mapa[y][x]->printPredmetInfo();
}

void Mapa::printNepriteleVLokaci(int x, int y) {
    m_mapa[y][x]->printNepritelInfo();
}

void Mapa::printKlicVLokaci(int x, int y) {
    m_mapa[y][x]->printKlicInfo();
}

/*void Mapa::printLokace(int x, int y) {
    m_mapa[y][x]->printInfo();
}
 */