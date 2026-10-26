
#include "Gracz.h"
#include <iostream>

Gracz::Gracz(const std::string &nazwa, int hpMax, int atak, int obrona,
             int esencja)
    : Postac(nazwa, hpMax, atak, obrona, esencja) {}

int Gracz::akcja() {
  int wybor = 0;
  std::cout << "Twój wybór (1-4): ";
  std::cin >> wybor;
  std::cin.clear();
  std::cin.ignore(1000, '\n');
  std::cout << std::endl;
  return wybor;
}

std::string Gracz::opis() const {

  return "\nGracz: " + getNazwa() + "\nHp: " + std::to_string(getHp()) +
         "\nEsencja: " + std::to_string(getEsencja());
}