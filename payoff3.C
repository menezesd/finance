
#include "payoff3.h"

#define min(X,Y) (X < Y) ? X : Y
#define max(X,Y) (X > Y) ? X : Y

PayOffCall::PayOffCall(double s):strike(s)
{
}

PayOffPut::PayOffPut(double s):strike(s)
{
}


PayOffDigitalCall::PayOffDigitalCall(double s):strike(s)
{
}

PayOffDigitalPut::PayOffDigitalPut(double s):strike(s)
{
}

double PayOffCall::operator() (double spot)
const {
    return max(spot - strike, 0.0);
} double PayOffPut::operator() (double spot) const
{
    return max(strike - spot, 0.0);
}

double PayOffDigitalCall::operator() (double spot)
const {
    return (strike >= spot);
} double PayOffDigitalPut::operator() (double spot) const
{
    return (strike <= spot);
}

PayOffDoubleDigital::PayOffDoubleDigital(double ll,
					 double ul):lower_level(ll),
upper_level(ul)
{
}

double PayOffDoubleDigital::operator() (double spot)
const {

    return (lower_level <= spot && spot <= upper_level);
}

PayOff *PayOffCall::clone() const
{
    return new PayOffCall(*this);
}


PayOff *PayOffPut::clone() const
{
    return new PayOffPut(*this);
}

PayOff *PayOffDigitalPut::clone() const
{
    return new PayOffDigitalPut(*this);
}

PayOff *PayOffDigitalCall::clone() const
{
    return new PayOffDigitalCall(*this);
}

PayOff *PayOffDoubleDigital::clone() const
{
    return new PayOffDoubleDigital(*this);
}
