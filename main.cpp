#include "postacie/Gracz.h"
#include "postacie/Wrog.h"
#include "systemy/SystemWalki.h"
#include <cstdlib>
#include <ctime>
#include <iostream>
#include <string>

int main() {
  srand(time(nullptr));

  std::cout << "Sprzeciwiłeś się władzy i za to zapłaciłeś. Wygnano Cię w głąb "
               "starego lasu, w którym dawno temu mieszkały czarownice.\n";
  std::cout << "One też zostały wygnane, ale ich magia przetrwała i zmieniła "
               "wszystko, co tu żyje.\n";
  std::cout << "Las otacza magiczna bariera, przez którą nie da się "
               "przejść.Jedyną nadzieją jest stary magik, który za 1000 "
               "esencji otworzy Ci przejście.\n";
  std::cout << "Esencję zostawiają po sobie pokonane stworzenia. Walcz, "
               "zbieraj esencję i odzyskaj wolność.\n";

  std::string nazwaGracza;
  std::cout << "\nTwoja nazwa: \n";
  std::cin >> nazwaGracza;
  std::cout << std::endl;

  Gracz ty(nazwaGracza, 15, 10, 8, 0);

  std::cout << "\nWybierz:\n 1 - Atak\n 2 - Mocny atak (jednorazowe)\n 3 - "
               "Uleczenie (jednorazowe)\n 4 - Ucieczka (tracisz całe złoto)\n";

  char odpowiedz = 'T';
  while (odpowiedz == 'T' || odpowiedz == 't') {

    int rodzajWroga = rand() % 100;

    if (rodzajWroga < 45) {
      Wrog wrog("POSPOLITY - PANCERNY JEŻ", 8, 10, 5, 50);
      std::cout << wrog.opis() << "\n";
      std::cout << "\nDawny jeż spod chaty czarownic, którego igły zamieniają "
                   "się w żelazne kolce. Potrafią boleśnie ukłuć, lecz "
                   "doświadczony wędrowiec szybko sobie z nimi radzi.\n";
      walka(ty, wrog);

    } else if (rodzajWroga < 65) {
      Wrog wrog("OBROŃCA - KRUK WIEDŹMY", 12, 10, 7, 100);
      std::cout << wrog.opis()
                << "\nDawny posłaniec czarownic, teraz pilnuje, aby w lesie "
                   "wszystko stało na swoim miejscu. Nie zadaje groźnych ran, "
                   "ale odbija większość ciosów.\n";
      std::cout << "\n";
      walka(ty, wrog);

    } else if (rodzajWroga < 90) {
      Wrog wrog("GROŹNY - PRZEKLĘTY JELEŃ", 8, 13, 5, 150);
      std::cout << wrog.opis() << "\n";
      std::cout << "\nJeleń, któremu zaklęcie czarownic zamieniło poroże w "
                   "ostre w ostrza. Atakuje nagle i z ogromną siłą, ale jego "
                   "ciało jest kruche.\n";
      walka(ty, wrog);

    } else {
      Wrog wrog("NAJGROŹNIEJSZY - WILK CZAROWNIC", 20, 12, 6, 300);
      std::cout << wrog.opis() << "\n";
      std::cout << "\nPrzywódca sfory, którą czarownice wychowały na "
                   "strażników lasu, wielki, stary i przesiąknięty ich magią. "
                   "Spotyka się go rzadko, a jego esencja jest warta więcej "
                   "niż jakakolwiek inna w lesie.\n";
      walka(ty, wrog);
    }

    if (ty.getEsencja() >= 1000) {
      std::cout << "Nazbierałeś wystarczająco złota, aby się uwolnić!\n";
      std::cout << "Gratulacje ukończenia gry!\n";
      break;
    }

    ty.setHp(ty.getHpMax());

    odpowiedz = ' ';
    while (odpowiedz != 'T' && odpowiedz != 't' && odpowiedz != 'N' &&
           odpowiedz != 'n'){
      std::cout << "Czy chcesz zagrać z kolejnym wrogiem? (T/N)\n";
    std::cin >> odpowiedz;
    std::cin.ignore(1000, '\n');
           }
  }
  return 0;
}