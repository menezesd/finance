#include "vanilla.h"

VanillaOption::VanillaOption(const PayOff&
                                                  ThePayOff_, double Expiry_)
                                          : expiry(Expiry_)
{
      the_payoff = ThePayOff_.clone();
}

double VanillaOption::GetExpiry() const
{

      return expiry;
}

double VanillaOption::OptionPayOff(double spot) const
{

      return (*the_payoff)(spot);
}

VanillaOption::VanillaOption(const VanillaOption& original)
{

      expiry = original.expiry;
      the_payoff = original.the_payoff->clone();
}
