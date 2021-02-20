#include <iostream>
#include <cmath>
#include <random>
using namespace std;

#include "vanilla2.h"
#include "parameters.h"

/* Monte Carlo option pricer */
double mc_price(const VanillaOption & opt,
		double spot, const Parameters &vol,
		const Parameters &r,
		size_t numpaths)
{
    default_random_engine generator;

    double expiry = opt.get_expiry();
    double variance = vol.integral_square(0,expiry);
    double sigma = sqrt(variance);
    double ito_correction = -0.5 * variance;
    normal_distribution < double >dist(0, sigma);
    double moved_spot = spot * exp(r.integral(0,expiry) + ito_correction);
    double this_spot;
    double total = 0;

    for (size_t i = 0; i < numpaths; i++) {
	double deviate = dist(generator);
	double this_spot = moved_spot * exp(deviate);
	double this_payoff = opt.pay_off(this_spot);
	total += this_payoff;
    }

    double mu = total / numpaths;
    return mu * exp(-r.integral(0, expiry));

}

int main()
{
    double expiry;
    double strike;
    double spot;
    double vol;
    double r;
    size_t num_paths;

    cout << "Enter expiry (years):";
    cin >> expiry;

    cout << "Enter strike price:";
    cin >> strike;

    cout << "Enter spot price:";
    cin >> spot;

    cout << "Enter volatility:";
    cin >> vol;

    cout << "Enter r (interest rate):";
    cin >> r;

    cout << "Number of paths:";
    cin >> num_paths;

    PayOffCall c(strike);
    PayOffPut p(strike);

    VanillaOption call(c, expiry);
    VanillaOption put(p, expiry);

    ParametersConstant vp(vol);
    ParametersConstant rp(r);
    
    double call_result = mc_price(call, spot, vp, rp, num_paths);
    double put_result = mc_price(put, spot, vp, rp, num_paths);


    cout << "the price is " << call_result << "for the call and "
	<< put_result << "for the put \n";

    return 0;
}
