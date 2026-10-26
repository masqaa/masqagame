#ifndef POSTAC_H
#define POSTAC_H
#include <string>

class Postac {

private:
  std::string nazwa;
  int hp, hpMax, atak, obrona, esencja;

public:
  Postac(const std::string &nazwa, int hpMax, int atak, int obrona,
         int esencja);
  virtual int akcja() = 0;
  virtual std::string opis() const = 0;
  virtual int atakuj();
  virtual void otrzymajObrazenia(int obrazenia);
  virtual void info();
  bool zyje() const;
  void wyleczHp(int ilosc);
  void dodajMane(int ilosc);

  std::string getNazwa() const { return this->nazwa; };
  int getHp() const { return this->hp; };
  int getHpMax() const { return this->hpMax; };
  int getAtak() const { return this->atak; };
  int getObrona() const { return this->obrona; };
  int getEsencja() const { return this->esencja; };

  void setHp(int newHp);
  void setNazwa(const std::string &newNazwa);
  void setHpMax(int newHpMax);
  void setAtak(int newAtak);
  void setObrona(int newObrona);
  void setEsencja(int newEsencja);

  virtual ~Postac() = default;
};
#endif