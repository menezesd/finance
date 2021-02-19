#ifndef PAYOFF_H
#define PAYOFF_H

class PayOff
{
public:
  enum OptionType { CALL, PUT, DIGITALCALL, DIGITALPUT };
 PayOff(double s, OptionType t) :
   strike(s), type (t)
    {}
 double operator()(double Spot) const;
 private:
  double strike;
  OptionType type;
};

#endif
