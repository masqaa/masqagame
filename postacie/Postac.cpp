#include "Postac.h"
#include <iostream>

// POSTAĆ
Postac::Postac(const std::string &nazwa, int hpMax, int atak, int obrona,
               int esencja)
    : nazwa(nazwa), hp(hpMax), hpMax(hpMax), atak(atak), obrona(obrona),
      esencja(esencja) {}

// tu akcja i opis w .h

// ATAK
int Postac::atakuj() { return atak; }

// OTRZYMAJ OBRAŻENIA
void Postac::otrzymajObrazenia(int obrazenia) {
  if (obrazenia > obrona) {
    setHp(hp - (obrazenia - obrona));
  } else {
    std::cout << "Miss!\n";
  }
}

// INFO
void Postac::info() {
  std::cout << "Nazwa: " << nazwa << "\nHP: " << hp
            << "\nEsencja: " << esencja << std::endl;
}

// ŻYJE
bool Postac::zyje() const { return hp > 0; }

// WYLECZ HP
void Postac::wyleczHp(int ilosc) { setHp(hp + ilosc); }

// ----------------------
// SETTERY
// ----------------------

// NAZWA
void Postac::setNazwa(const std::string &newNazwa) { nazwa = newNazwa; }

// HP
void Postac::setHp(int newHp) {
  if (newHp < 0) {
    hp = 0;
  } else if (newHp > hpMax) {
    hp = hpMax;
  } else {
    hp = newHp;
  }
}

void Postac::setHpMax(int newHpMax) {
  hpMax = newHpMax;
  setHp(hp);
}

// ATAK
void Postac::setAtak(int newAtak) {
  if (newAtak < 0) {
    atak = 0;
  } else {
    atak = newAtak;
  }
}

// OBRONA
void Postac::setObrona(int newObrona) {
  if (newObrona < 0) {
    obrona = 0;
  } else {
    obrona = newObrona;
  }
}

// ESENCJA
void Postac::setEsencja(int newEsencja) {
  if (newEsencja < 0) {
    esencja = 0;
  } else {
    esencja = newEsencja;
  }
}