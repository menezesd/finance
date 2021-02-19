
#ifdef VANILLA_H
#define VANILLA_H

#include "payoff.h"

class VanillaOption
{
public:
	VanillaOption(const PayOff &p, double expiry);
	VanillaOption(const VanillaOption &orig);
	~VanillaOption();
	double GetExpiry() const;
	double OptionPayOff(double Spot) const;

private:
	double Expiry;
	PayOff *the_payoff;
}

#endif
