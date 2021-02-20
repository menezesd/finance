#include "payoff_bridge.h"

PayOffBridge::PayOffBridge(const PayOffBridge & orig)
{
    the_payoff = orig.the_payoff->clone();
}

PayOffBridge::PayOffBridge(const PayOff & i)
{
    the_payoff = i.clone();
}

PayOffBridge::~PayOffBridge()
{
    delete the_payoff;
}

PayOffBridge & PayOffBridge::operator=(const PayOffBridge & original) {

    if (this != &original) {

	delete the_payoff;
	the_payoff = original.the_payoff->clone();
    }
    return *this;
}
