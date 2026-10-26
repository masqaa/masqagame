# Moja pierwsza gra zrobiona w języku C++

Gra została stworzona w celu nauczenia się działania języka C++ oraz jego faktycznego zastosowania.

## Zastosowane rozwiązania
 
- Abstrakcyjna klasa bazowa `Postac` z czysto wirtualnymi metodami `akcja()` i `opis()`, nadpisywanymi (`override`) w klasach pochodnych `Gracz` i `Wrog`.
- Pola prywatne dostępne przez gettery i settery, które pilnują poprawnych zakresów wartości (np. HP nie spada poniżej zera).
- Postacie tylko zwracają wybraną akcję, a przebieg walki obsługuje osobny moduł `SystemWalki`.
- Akcje wrogów, wynik ataku gracza i rodzaj przeciwnika są losowane z ustalonymi szansami (`rand()` i progi 0–99).
- Obsługa błędnych danych z `std::cin` (`clear()`, `ignore()`) oraz ponowne pytanie przy niepoprawnej odpowiedzi.
- Stan gracza zachowywany między walkami (przekazywanie przez referencję), warunek zwycięstwa i wyjścia z gry.

## Mechanika
 
- 4 akcje gracza: atak, mocny atak (raz na walkę), leczenie (raz na walkę), ucieczka
- 4 typy przeciwników o różnych statystykach i rzadkości
- losowe zdarzenia w walce: potknięcie, słabszy i mocniejszy cios
- konsekwencje wyniku walki: zdobycie, utrata połowy lub 1/5 esencji
