#ifndef VANILLA_H
#define VANILLA_H

#include "payoff3.h"

class VanillaOption
{
public:
  VanillaOption(const PayOff &p, double expiry);
  VanillaOption(const VanillaOption &orig);
  VanillaOption& operator=(const VanillaOption& orig);
  ~VanillaOption();
  double get_expiry() const;
  double pay_off(double Spot) const;

private:
	double expiry;
	PayOff *the_payoff;
};

#endif
