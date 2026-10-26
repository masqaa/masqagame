#ifndef WROG_H
#define WROG_H
#include "Postac.h"

class Wrog final : public Postac {

public:
  Wrog(const std::string &nazwa, int hpMax, int atak, int obrona, int esencja);

  virtual int akcja() override;
  std::string opis() const override;

  virtual ~Wrog() = default;
};
#endif