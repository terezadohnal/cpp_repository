//
// Created by Tereza  Dohnalova on 28/12/2020.
//

#include "Hra.h"

Hra::Hra() {
    m_mapaHry = new Mapa();
    m_mapaHry->vytvorMapu();

    m_hrdina = new Hrdina("Artuš");
    m_predeslaVolba = 0;
    m_konecHry = false;
}

// --------------------------------------------------------------------------------------------------------------------------------------------------------------

void Hra::printMenu() {

    printZakladniMenu();

    if (existujePredmetVLokaci()){
        printMenuPredmetu();
    }

    if (existujeKlicVLokaci()){
        printMenuKlice();
    }

    if (existujeNepritelVLokaci()){
        printMenuNepritele();
    }
}

void Hra::printZakladniMenu() {

    int x = m_hrdina->getAktualniPozice().x;
    int y = m_hrdina->getAktualniPozice().y;

    std::cout << "Hrdina " << m_hrdina->getJmeno() << " se nachází v lokaci " << m_mapaHry->getTypLokace(x, y) << "[" << x << "," << y << "]" << std::endl;
    if (m_mapaHry->kontrolaDveri(x, y)){
        std::cout << "V této lokaci se nachází " << m_mapaHry->getDvereVLokaci(x, y)->getNazev() << ", přes které lze projít pouze se správním klíčem." << std::endl;
    }

    std::cout << "Pro pohyb po mapě zadejte následující číslo: " << std::endl;
    std::cout << std::endl;
    std::cout << "Sever : 1" << std::endl;
    std::cout << "Jih : 2" << std::endl;
    std::cout << "Východ : 3" << std::endl;
    std::cout << "Západ : 4" << std::endl;
    std::cout << std::endl;
    std::cout << "Pro výpis inventáře Hrdiny zadejte : 5" << std::endl;
    std::cout << "Pro výpis stavu hrdiny zadejte : 9 " << std::endl;
    std::cout << "Pro ukončení hry zadejte : 8 " << std::endl;
    std::cout << std::endl;
}

void Hra::printMenuPredmetu() {
    int x = m_hrdina->getAktualniPozice().x;
    int y = m_hrdina->getAktualniPozice().y;

    std::cout << "V této lokaci se nachází: " << std::endl;
    std::cout << std::endl;
    m_mapaHry->printPredmetVLokaci(x,y);

    std::cout << "Pro sebrání předmětu zmáčkněte : 6" << std::endl;
    std::cout << std::endl;
}

void Hra::printMenuKlice() {
    int x = m_hrdina->getAktualniPozice().x;
    int y = m_hrdina->getAktualniPozice().y;

    std::cout << "V této lokaci se nachází klíč: " << std::endl;
    std::cout << std::endl;
    m_mapaHry->printKlicVLokaci(x,y);

    std::cout << "Pro sebrání klíče zmáčkněte : 6" << std::endl;
    std::cout << std::endl;
}

void Hra::printMenuNepritele() {
    int x = m_hrdina->getAktualniPozice().x;
    int y = m_hrdina->getAktualniPozice().y;

    std::cout << "V této lokaci se nachází nepřítel: " << std::endl;
    std::cout << std::endl;
    m_mapaHry->printNepriteleVLokaci(x,y);

    std::cout << "Pro boj s nepřítelem zmáčkněte : 7" << std::endl;
    std::cout << std::endl;
}

// --------------------------------------------------------------------------------------------------------------------------------------------------------------


int Hra::getPredeslaVolba() {
    return m_predeslaVolba;
}

void Hra::setPredeslaVolba(int volba) {
    m_predeslaVolba = volba;
}

// --------------------------------------------------------------------------------------------------------------------------------------------------------------


/*bool Hra::getKonecHry() {
    return m_konecHry;
}
 */

void Hra::setKonecHry(bool konecHry) {
    m_konecHry = konecHry;
}

void Hra::provedKontroluSouradnicProKonecHry() {
    if (m_hrdina->getAktualniPozice().x == 12 and m_hrdina->getAktualniPozice().y == 2){
        std::cout << std::endl;
        std::cout << "Hrdina " << m_hrdina->getJmeno() << " zachránil princeznu Fionu." << std::endl;
        std::cout << "Gratulujeme k úspěšnému dokončení hry!" << std::endl;
        setKonecHry(true);
    }
}

// --------------------------------------------------------------------------------------------------------------------------------------------------------------

bool Hra::existujePredmetVLokaci() {
    int x = m_hrdina->getAktualniPozice().x;
    int y = m_hrdina->getAktualniPozice().y;

    if (m_mapaHry->kontrolaPredmetu(x,y)){
        return true;
    } else{
        return false;
    }
}

bool Hra::existujeKlicVLokaci() {
    int x = m_hrdina->getAktualniPozice().x;
    int y = m_hrdina->getAktualniPozice().y;

    if (m_mapaHry->kontrolaKlice(x,y)){
        return true;
    } else{
        return false;
    }
}

bool Hra::existujeNepritelVLokaci() {
    int x = m_hrdina->getAktualniPozice().x;
    int y = m_hrdina->getAktualniPozice().y;

    if (m_mapaHry->kontrolaNepritele(x,y)){
        return true;
    } else{
        return false;
    }
}

// --------------------------------------------------------------------------------------------------------------------------------------------------------------

bool Hra::provedBoj(Nepritel *nepritel) {
    int zivotyNepritele = nepritel->getZivoty();
    int obranaNepritele = nepritel->getObrana();
    int silaNepritele = nepritel->getSila();

    int zivotyHrdiny = m_hrdina->getZivoty();
    int obranaHrdiny = m_hrdina->getObrana();
    int silaHrdiny = m_hrdina->getSila();

    do {
        zivotyNepritele = zivotyNepritele - (silaHrdiny - obranaNepritele);
        zivotyHrdiny = zivotyHrdiny - (silaNepritele - obranaHrdiny);

    }while(zivotyNepritele > 0 and zivotyHrdiny > 0);

    if(zivotyNepritele <= 0){
        std::cout << "Hrdina " << m_hrdina->getJmeno() << " porazil nepřítele " << nepritel->getJmeno() << " a zbylo mu " << zivotyHrdiny << " životů." << std::endl;

        m_hrdina->setZivot(zivotyHrdiny);
        if (nepritel->existujePredmet()){
            m_hrdina->pridejPredmetDoInventare(nepritel->getPredmet());
            std::cout << "Hrdina získal předmět: " << std::endl;
            nepritel->getPredmet()->vypisInfo();
            std::cout << std::endl;
        }
        return true;

    } else {
        std::cout << "Hrdina " << m_hrdina->getJmeno() << " byl poražen nepřítelem " << nepritel->getJmeno() << ". Zkuste své štěstí ve hře znovu." << std::endl;
        return false;
    }
}

bool Hra::provedKontroluKodu(Dvere *dvere) {

    bool hrdinaMaSpravnyKlic = false;

    for(Klic* klic:m_hrdina->getKlicenka()){
        if(klic->getUnikatniKod() == dvere->getUnikatniKod()){
            hrdinaMaSpravnyKlic = true;
        }
    }

    return hrdinaMaSpravnyKlic;

}

void Hra::provedVolbuAkce(int volbaAkce) {
    int x = m_hrdina->getAktualniPozice().x;
    int y = m_hrdina->getAktualniPozice().y;

    int budouciX, budouciY;

    if (volbaAkce == 1){
        budouciX = x;
        budouciY = y-1;
    } else if (volbaAkce == 2){
        budouciX = x;
        budouciY = y+1;
    } else if (volbaAkce == 3){
        budouciX = x+1;
        budouciY = y;
    } else if (volbaAkce == 4){
        budouciX = x-1;
        budouciY = y;
    }

    if (m_mapaHry->kontrolaSchudnosti(budouciX, budouciY)) {
        if (m_mapaHry->kontrolaNepritele(x, y) && volbaAkce == getPredeslaVolba()) {
            std::cout << "Tímto směrem se nelze pohnout, jelikož se musíte poprat s nepřítelem." << std::endl;
        } else if(m_mapaHry->kontrolaDveri(x, y) and !provedKontroluKodu(m_mapaHry->getDvereVLokaci(x, y)) && volbaAkce == getPredeslaVolba()){
            std::cout << "Tímto směrem se nelze pohnout, neboť hrdina nemá správný klíč." << std::endl;
        }else {
            m_hrdina->provedPosunuti(volbaAkce);
        }
    }else if (m_mapaHry->kontrolaReky(budouciX,budouciY) and m_hrdina->getSchopnostPlavitSe()) {
        m_hrdina->provedPosunuti(volbaAkce);
    }else {
        std::cout << "Tímto směrem se nelze pohnout, zvolte jiný směr." << std::endl;
    }

}

void Hra::provedVolbuAkceProSberPredmetu() {
    int x = m_hrdina->getAktualniPozice().x;
    int y = m_hrdina->getAktualniPozice().y;

    if (existujePredmetVLokaci()){
        m_hrdina->pridejPredmetDoInventare(m_mapaHry->getPredmetVLokaci(x, y));
        m_mapaHry->smazPredmetZLokace(x, y);
    } else if(existujeKlicVLokaci()){
        m_hrdina->pridejKlicDoKlicenky(m_mapaHry->getKlicVLokaci(x, y));
        m_mapaHry->smazKlicZLokace(x, y);
    }
    else {
        std::cout << "Bylo zadáno chybné číslo, zkuste to znovu." << std::endl;
        std::cout << std::endl;
    }
}

void Hra::provedVolbuAkceProBoj() {
    int x = m_hrdina->getAktualniPozice().x;
    int y = m_hrdina->getAktualniPozice().y;

    bool vyhralHrdinaBoj = provedBoj(m_mapaHry->getNepritelVLokaci(x,y));
    if (vyhralHrdinaBoj){
        m_mapaHry->smazNepriteleZLokace(x,y);
    } else {
        setKonecHry(true);
    }
}

void Hra::provedAkci() {
    int volbaAkce;

    std::cin >> volbaAkce;

    if (volbaAkce == 1){
        provedVolbuAkce(1);

    }else if (volbaAkce == 2){
        provedVolbuAkce(2);

    }else if (volbaAkce == 3){
        provedVolbuAkce(3);

    }else if (volbaAkce == 4){
        provedVolbuAkce(4);

    }else if(volbaAkce == 5){
        m_hrdina->vypisPredmetyVInventari();

    }else if (volbaAkce == 6){
        provedVolbuAkceProSberPredmetu();

    }else if (volbaAkce == 7){
        provedVolbuAkceProBoj();

    }else if (volbaAkce == 8){
        setKonecHry(true);

    }else if (volbaAkce == 9){
        m_hrdina->printInfo();

    }else{
        std::cout << "Bylo zadáno chybné číslo, zkuste to znovu." << std::endl;
        std::cout << std::endl;
    }

    setPredeslaVolba(volbaAkce);
    provedKontroluSouradnicProKonecHry();
}

void Hra::hrej() {

    std::cout << std::endl;
    std::cout << "Hra začíná!" << std::endl;
    std::cout << std::endl;
    std::cout << "Vítej ve světě pohádek. Tvým úkolem zde je jednak přežít a hlavně zachránit princeznu Fionu, která je uvězněna ve věži." << std::endl;
    std::cout << "Na tvé cestě se můžeš setkat s loupežníkem, kostlivcem, dart vaderem a dokonce i s drakem!" << std::endl;
    std::cout << "Abys je úspěšně porazil, musíš mít dostatek životů, síly a ochrany." << std::endl;
    std::cout << "Své kroky pečlivě promysli, na tvé cestě se můžeš setkat s dalšíma nepříjemnýma překážkama, jako třeba řekou, kterou jde přeplout, když máš u sebe pádlo a loď, "<< std::endl;
    std::cout << "anebo dveře, kterými jde projít jen se správným klíčem. "<< std::endl;
    std::cout << "Hodně štěstí, budeš ho potřebovat!" << std::endl;
    std::cout << std::endl;


    do{
        printMenu();
        provedAkci();
    }while (m_konecHry == false);

}

/*
 *
 *
 *
 *
 void Hra::provedAkci() {
    int x = m_hrdina->getAktualniPozice().x;
    int y = m_hrdina->getAktualniPozice().y;

    int volbaAkce;

    std::cin >> volbaAkce;

    if (volbaAkce == 1){
        if (m_mapaHry->kontrolaSchudnosti(x, y-1)) {
            if (m_mapaHry->kontrolaNepritele(x, y) && volbaAkce == getPredeslaVolba()) {
                std::cout << "Tímto směrem se nelze pohnout, jelikož se musíte poprat s nepřítelem." << std::endl;
            } else if(m_mapaHry->kontrolaDveri(x, y) and !provedKontroluKodu(m_mapaHry->getDvereVLokaci(x, y)) && volbaAkce == getPredeslaVolba()){
                std::cout << "Tímto směrem se nelze pohnout, neboť hrdina nemá správný klíč." << std::endl;
            }else {
                m_hrdina->provedPosunuti(volbaAkce);
            }
        }else if (m_mapaHry->kontrolaReky(x,y-1) and m_hrdina->getSchopnostPlavitSe()) {
            m_hrdina->provedPosunuti(volbaAkce);
        }else {
            std::cout << "Tímto směrem se nelze pohnout, zvolte jiný směr." << std::endl;
        }

    }else if (volbaAkce == 2){
        if (m_mapaHry->kontrolaSchudnosti(x,y+1)){
            if (m_mapaHry->kontrolaNepritele(x, y) && volbaAkce == getPredeslaVolba()) {
                std::cout << "Tímto směrem se nelze pohnout, jelikož se musíte poprat s nepřítelem." << std::endl;
            } else if(m_mapaHry->kontrolaDveri(x, y) and !provedKontroluKodu(m_mapaHry->getDvereVLokaci(x, y)) && volbaAkce == getPredeslaVolba()) {
                std::cout << "Tímto směrem se nelze pohnout, neboť hrdina nemá správný klíč." << std::endl;
            }else {
                m_hrdina->provedPosunuti(volbaAkce);
            }
        }else if (m_mapaHry->kontrolaReky(x,y+1) and m_hrdina->getSchopnostPlavitSe()){
            m_hrdina->provedPosunuti(volbaAkce);
        }else{
            std::cout << "Tímto směrem se nelze pohnout, zvolte jiný směr." << std::endl;
        }

    } else if (volbaAkce == 3){
        if (m_mapaHry->kontrolaSchudnosti(x+1, y)){
            if (m_mapaHry->kontrolaNepritele(x, y) && volbaAkce == getPredeslaVolba()) {
                std::cout << "Tímto směrem se nelze pohnout, jelikož se musíte poprat s nepřítelem." << std::endl;
            } else if(m_mapaHry->kontrolaDveri(x, y) and !provedKontroluKodu(m_mapaHry->getDvereVLokaci(x, y)) && volbaAkce == getPredeslaVolba()) {
                std::cout << "Tímto směrem se nelze pohnout, neboť hrdina nemá správný klíč." << std::endl;
            }else {
                m_hrdina->provedPosunuti(volbaAkce);
            }
        }else if (m_mapaHry->kontrolaReky(x+1,y) and m_hrdina->getSchopnostPlavitSe()){
            m_hrdina->provedPosunuti(volbaAkce);
        }else{
            std::cout << "Tímto směrem se nelze pohnout, zvolte jiný směr." << std::endl;
        }

    }else if (volbaAkce == 4){
        if (m_mapaHry->kontrolaSchudnosti(x-1, y)){
            if (m_mapaHry->kontrolaNepritele(x, y) && volbaAkce == getPredeslaVolba()) {
                std::cout << "Tímto směrem se nelze pohnout, jelikož se musíte poprat s nepřítelem." << std::endl;
            } else if(m_mapaHry->kontrolaDveri(x, y) and !provedKontroluKodu(m_mapaHry->getDvereVLokaci(x, y)) && volbaAkce == getPredeslaVolba()){
                std::cout << "Tímto směrem se nelze pohnout, neboť hrdina nemá správný klíč." << std::endl;
            }else {
                m_hrdina->provedPosunuti(volbaAkce);
            }
        }else if (m_mapaHry->kontrolaReky(x-1,y) and m_hrdina->getSchopnostPlavitSe()){
            m_hrdina->provedPosunuti(volbaAkce);
        }else{
            std::cout << "Tímto směrem se nelze pohnout, zvolte jiný směr." << std::endl;
        }

    }else if(volbaAkce == 5){
        m_hrdina->vypisPredmetyVInventari();

    }else if (volbaAkce == 6){
        if (existujePredmetVLokaci()){
            m_hrdina->pridejPredmetDoInventare(m_mapaHry->getPredmetVLokaci(x, y));
            m_mapaHry->smazPredmetZLokace(x, y);
        } else if(existujeKlicVLokaci()){
            m_hrdina->pridejKlicDoKlicenky(m_mapaHry->getKlicVLokaci(x, y));
            m_mapaHry->smazKlicZLokace(x, y);
        }
        else {
            std::cout << "Bylo zadáno chybné číslo, zkuste to znovu." << std::endl;
            std::cout << std::endl;
        }

    }else if (volbaAkce == 7){
        bool vyhralHrdinaBoj = provedBoj(m_mapaHry->getNepritelVLokaci(x,y));
        if (vyhralHrdinaBoj){
            m_mapaHry->smazNepriteleZLokace(x,y);
        } else {
            setKonecHry(true);
        }
    }else if (volbaAkce == 8){
        setKonecHry(true);

    }else if (volbaAkce == 9){
        m_hrdina->printInfo();

    }else{
        std::cout << "Bylo zadáno chybné číslo, zkuste to znovu." << std::endl;
        std::cout << std::endl;
    }

    setPredeslaVolba(volbaAkce);
    provedKontroluSouradnicProKonecHry();
}
 *
 */