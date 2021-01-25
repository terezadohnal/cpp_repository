//
// Created by Tereza  Dohnalova on 11/12/2020.

// Třída Mapa, která má za úkol sestavit mapu, po které se hrdina pohybuje a na které jsou uloženy určité lokace, předměty a nepřátelé.
//


#ifndef MAIN_CPP_MAPA_H
#define MAIN_CPP_MAPA_H
#include <iostream>
#include <array>
#include "Lokace.h"
#include "Predmet.h"


class Mapa {

    std::array<std::array<Lokace*, 16>, 16> m_mapa; // vektor vektoru


public:
    // Konstruktor, nezadáváme parametry, protože máme předem dané rozměry (16x16)
    Mapa();

    // ----------------------------------------------------------------

    // 2D mapa
    void vytvorMapu();

    // -----------------------------------------------------------------

    // Přídávání, odebírání z mapy/lokace

    void pridejPredmetDoLokace(Predmet* predmet, int x, int y);

    void pridejPredmetyDoMapy();

    void pridejNepriteleDoLokace(Nepritel* nepritel, int x, int y);

    void pridejNepriteleDoMapy();

    void pridejDvereDoLokace(Dvere* dvere, int x, int y);

    void pridejDvereDoMapy();

    void pridejKlicDoLokace(Klic* klic, int x, int y);

    void pridejKlicDoMapy();

    void smazPredmetZLokace(int x, int y);

    void smazNepriteleZLokace(int x, int y);

    void smazKlicZLokace(int x, int y);

    // ----------------------------------------------------------------

    // Gettery

    std::string getTypLokace(int x, int y);

    Predmet* getPredmetVLokaci(int x, int y);

    Nepritel* getNepritelVLokaci(int x, int y);

    Klic* getKlicVLokaci(int x, int y);

    Dvere* getDvereVLokaci(int x, int y);

    // -----------------------------------------

    // Kontrola

    bool kontrolaSchudnosti(int x, int y);

    bool kontrolaPredmetu(int x, int y);

    bool kontrolaNepritele(int x, int y);

    bool kontrolaReky(int x, int y);

    bool kontrolaKlice(int x, int y);

    bool kontrolaDveri(int x, int y);

    // -----------------------------------------

    // Printy

    //void printLokace(int x, int y);

    void printPredmetVLokaci(int x, int y);

    void printNepriteleVLokaci(int x, int y);

    void printKlicVLokaci(int x, int y);

    // ------------------------------------------

};


#endif //MAIN_CPP_MAPA_H
