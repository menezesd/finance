#include "vanilla.h"

VanillaOption::VanillaOption(const PayOff & ThePayOff_, double Expiry_)
:expiry(Expiry_)
{
    the_payoff = ThePayOff_.clone();
}


double VanillaOption::get_expiry() const
{

    return expiry;
}

double VanillaOption::pay_off(double spot) const
{

    return (*the_payoff) (spot);
}

VanillaOption::VanillaOption(const VanillaOption & original)
{

    expiry = original.expiry;
    the_payoff = original.the_payoff->clone();
}


VanillaOption & VanillaOption::operator=(const VanillaOption & original)
{
    if (this != &original) {
	expiry = original.expiry;
	delete the_payoff;
	the_payoff = original.the_payoff->clone();
    }
    return *this;
}

VanillaOption::~VanillaOption()
{
    delete the_payoff;
}
