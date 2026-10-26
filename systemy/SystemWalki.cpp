#include "SystemWalki.h"
#include <cstdlib>
#include <iostream>

void walka(Gracz &gracz, Wrog &wrog) {

  bool uleczono = false;
  bool uleczonoWroga = false;
  bool mocnyAtak = false;
  bool uciekl = false;

  while (gracz.getHp() > 0 && wrog.getHp() > 0) {

    // WYŚWIETLANE
    std::cout << "\nTwoje Punkty Życia: " << gracz.getHp() << std::endl;
    std::cout << "Punkty Życia Wroga: " << wrog.getHp() << std::endl;

    // GRACZ ATAKUJE
    int wybor = gracz.akcja();
    if (wybor == 1) {
      int los = rand() % 100;
      if (los < 70) {
        wrog.otrzymajObrazenia(gracz.atakuj());
      } else if (los < 85) {
        std::cout << "Zabrakło Ci sił na mocny cios!!\n";
        wrog.otrzymajObrazenia(gracz.atakuj() * 0.8);
      } else {
        std::cout << "Potknąłeś się. Tracisz szanse na atak.\n";
      }
    } else if (wybor == 2) {
      if (!mocnyAtak) {
        wrog.otrzymajObrazenia(gracz.atakuj() * 1.5);
        mocnyAtak = true;
        std::cout << "Zadałeś mocny cios!" << std::endl;
      } else {
        std::cout << "Już wykorzystałeś mocny atak" << std::endl;
      }
    } else if (wybor == 3) {
      if (!uleczono) {
        gracz.wyleczHp(2);
        uleczono = true;
        std::cout << "Uleczono!" << std::endl;
      } else {
        std::cout << "Już się uleczyłeś!" << std::endl;
      }
    } else if (wybor == 4) {
      uciekl = true;
      break;
    } else {
      std::cout << "Błąd!" << std::endl;
    }

    // WRÓG ATAKUJE
    if (wrog.getHp() > 0) {
      int wyborWroga = wrog.akcja();
      if (wyborWroga == 1) {
        std::cout << "Wróg atakuje!" << std::endl;
        gracz.otrzymajObrazenia(wrog.atakuj());
      } else if (wyborWroga == 2) {
        if (!uleczonoWroga) {
          wrog.wyleczHp(2);
          uleczonoWroga = true;
          std::cout << "Wróg się uleczył!" << std::endl;
        } else {
          std::cout << "Wróg nie ma już sił na leczenie." << std::endl;
        }
      } else if (wyborWroga == 3) {
        std::cout << "Wróg zadaje mocny atak!" << std::endl;
        gracz.otrzymajObrazenia(wrog.atakuj() * 1.5);
      } else {
        std::cout << "Wróg się potknął, atakuj, póki możesz!" << std::endl;
      }
    }
  }

  // WYNIK
  if (gracz.getHp() == 0) {
    std::cout << "Przegrałeś! Straciłeś część esencji." << std::endl;
    wrog.setEsencja(gracz.getEsencja() * 0.4 + wrog.getEsencja());
    gracz.setEsencja(gracz.getEsencja() * 0.4);
    std::cout << "Aktualna ilość esencji: " << gracz.getEsencja()
              << std::endl;
  } else if (uciekl) {
    wrog.setEsencja(wrog.getEsencja() + gracz.getEsencja() * 0.2);
    gracz.setEsencja(gracz.getEsencja() * 0.8);
    std::cout << "Uciekłeś. Wróg zabrał część twojej esencji.\n Aktualna "
                 "ilość: "
              << gracz.getEsencja() << std::endl;
  } else {
    std::cout << "Gratulacje! Pokonałeś wroga! Otrzymujesz nagrodę."
              << std::endl;
    gracz.setEsencja(gracz.getEsencja() + wrog.getEsencja());
    std::cout << "Otrzymałeś " << wrog.getEsencja()
              << ". Aktualna ilość esencji: "
              << gracz.getEsencja() << std::endl;
  }
}