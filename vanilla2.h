#ifndef VANILLA_H
#define VANILLA_H

#include "payoff3.h"
#include "payoff_bridge.h"

class VanillaOption
{
public:
  VanillaOption(const PayOffBridge &p, double expiry);
  VanillaOption(const VanillaOption &orig);


  double get_expiry() const;
  double pay_off(double Spot) const;

private:
	double expiry;
	PayOffBridge the_payoff;
};

#endif
