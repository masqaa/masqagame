#include "Wrog.h"
#include <cstdlib>

Wrog::Wrog(const std::string &nazwa, int hpMax, int atak, int obrona,
           int esencja)
    : Postac(nazwa, hpMax, atak, obrona, esencja) {}

int Wrog::akcja() {
  int dzialanie = rand() % 100;
  if (dzialanie < 60) {
    return 1;
  } else if (dzialanie < 75) {
    return 2;
  } else if (dzialanie < 85) {
    return 3;
  } else {
    return 4;
  }
}

std::string Wrog::opis() const {

  return "\nWróg: " + getNazwa() + "\nHp: " + std::to_string(getHp()) +
         "\nEsencja do Zdobycia: " + std::to_string(getEsencja());
}