#include "vanilla2.h"

VanillaOption::VanillaOption(const PayOffBridge& p, double e)
                              : the_payoff(p), expiry(e)
{
}

double VanillaOption::get_expiry() const
{

      return expiry;
}

double VanillaOption::pay_off(double spot) const
{

      return the_payoff(spot);
}
