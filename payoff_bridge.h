#ifndef PAYOFFBRIDGE_H
#define PAYOFFBRIDGE_H

#include "payoff3.h"

class PayOffBridge
{
public:
  PayOffBridge (const PayOffBridge & original);
    PayOffBridge (const PayOff & innerPayOff);
  inline double operator () (double Spot) const;
   ~PayOffBridge ();
    PayOffBridge & operator= (const PayOffBridge & original);
private:
    PayOff * the_payoff;
};

inline double
PayOffBridge::operator () (double Spot)
     const
     {
       return the_payoff->operator  () (Spot);
     }

#endif
