//
// Created by Tereza  Dohnalova on 10/12/2020.
//

#include "Hrdina.h"

Hrdina::Hrdina(std::string jmeno) {
    m_jmeno = jmeno;
    m_zivoty = 10;
    m_obrana = 0;
    m_sila = 1;
    m_aktualniPozice.x = 0;
    m_aktualniPozice.y = 7;
    m_inventar = new Inventar();
    m_schopnostPlavitSe = false;
    for (Klic* klic:m_klicenka){
        klic = nullptr;
    }
}

// -------------------------------------------------------------

int Hrdina::getSila(){
    return m_sila + m_inventar->getSila();
}

int Hrdina::getZivoty(){
    return m_zivoty;
}
int Hrdina::getObrana(){
    return m_obrana + m_inventar->getObrana();
}
std::string Hrdina::getJmeno() {
    return m_jmeno;
}

bool Hrdina::getSchopnostPlavitSe() {
    return m_schopnostPlavitSe;
}

std::vector<Klic *> Hrdina::getKlicenka() {
    return m_klicenka;
}

// -----------------------------------------------------------

void Hrdina::setSchopnostPlavitSe(bool schopnostPlavitSe) {
    m_schopnostPlavitSe = schopnostPlavitSe;
}

// -----------------------------------------------------------

void Hrdina::setZivot(int noveZivoty){
    m_zivoty = noveZivoty;
}

void Hrdina::doplnZivot(int okolik) {
    m_zivoty += okolik;
}

// -----------------------------------------------------------

void Hrdina::provedPosunuti(int kam) {

    if (kam == 1){
        m_aktualniPozice.y -= 1;
    }else if (kam == 2){
        m_aktualniPozice.y += 1;
    }else if (kam == 3){
        m_aktualniPozice.x += 1;
    }else{
        m_aktualniPozice.x -= 1;
    }
}

Pozice2d Hrdina::getAktualniPozice(){
    return m_aktualniPozice;
}

// -----------------------------------------------------------

bool Hrdina::kontrolaSchopnostiSePlavit() {
    bool mamPadlo = false;
    bool mamLod = false;

    for (Predmet* predmet:m_inventar->getPredmety()) {
        if (predmet->getNazev() == "Pádlo"){
            mamPadlo = true;
        }
        if (predmet->getNazev() == "Loď"){
            mamLod = true;
        }
    }

    if (mamPadlo and mamLod){
        return true;
    }else{
        return false;
    }
}

// ------------------------------------------------------------------------------------------

//Správa věcí v Inventáři

void Hrdina::pridejPredmetDoInventare(Predmet* predmet) {
    if (predmet->getBonusKZivotum() != 0){
        doplnZivot(predmet->getBonusKZivotum());
        std::cout << std::endl;
        std::cout << "Hrdina vypil lektvar a má " << getZivoty() << " životů." << std::endl;
        std::cout << std::endl;
    }else{
        m_inventar->pridejPredmet(predmet);
    }
    setSchopnostPlavitSe(kontrolaSchopnostiSePlavit());
}

void Hrdina::vypisPredmetyVInventari() {
    m_inventar->vypisPredmetyVInventari();
}

void Hrdina::pridejKlicDoKlicenky(Klic *klic) {
    m_klicenka.push_back(klic);
}

// -----------------------------------------------------------

void Hrdina::printInfo() {
    std::cout << std::endl;
    std::cout << "Stav hrdiny " << m_jmeno << std::endl;
    std::cout << "Počet životů: " << m_zivoty << std::endl;
    std::cout << "Síla: " << getSila() << std::endl;
    std::cout << "Obrana: " << getObrana() << std::endl;
    if (m_schopnostPlavitSe){
        std::cout << "Hrdina se umí plavit po řece." << std::endl;
    }else {
        std::cout << "Hrdina se neumí plavit po řece." << std::endl;
    }
    std::cout << std::endl;
}