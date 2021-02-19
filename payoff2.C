
#include "payoff2.h"

#define min(X,Y) (X < Y) ? X : Y
#define max(X,Y) (X > Y) ? X : Y

PayOffCall::PayOffCall(double s) : strike(s)
{}

PayOffPut::PayOffPut(double s) : strike(s)
{}

double PayOffCall:: operator() (double spot) const
{
  return max(spot - strike, 0.0);
}

double PayOffPut:: operator() (double spot) const
{
  return max(strike - spot, 0.0);
}

