#include "payoff.h"

#define max(X,Y) (X > Y) ? X : Y;
#define min(X,Y) (X < Y) ? X : Y;

double PayOff :: operator () (double spot) const
{
  switch(type)
    {
    case CALL:
      return max(spot - strike, 0.0);
    case PUT:
      return max(strike - spot, 0.0);
    case DIGITALCALL:
      return spot >= strike;
    case DIGITALPUT:
      return spot <= strike;
    default:
      throw("unknown option type");
    }
}
