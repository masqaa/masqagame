#ifndef GRACZ_H
#define GRACZ_H
#include "Postac.h"

class Gracz final : public Postac {

public:
  Gracz(const std::string &nazwa, int hpMax, int atak, int obrona,
        int esencja);

  int akcja() override;
  std::string opis() const override;

  virtual ~Gracz() = default;
};

#endif