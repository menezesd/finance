#include <iostream>
#include <cmath>
#include <random>
using namespace std;

/* Monte Carlo call pricer */
double call_price(double expiry, double strike, double spot, double vol,
		  double r, size_t numpaths)
{
  default_random_engine generator;

  double variance = vol * vol * expiry;
  double sigma = vol * sqrt(expiry);
  double ito_correction = -0.5 * variance;
  normal_distribution<double> dist(0, sigma);
  double moved_spot = spot * exp(r * expiry + ito_correction);
  double this_spot;
  double total = 0;

  for (size_t i = 0; i < numpaths; i++)
    {
      double deviate = dist(generator);
      double this_spot = moved_spot * exp(deviate);
      double this_payoff = (this_spot - strike > 0) ?
	this_spot - strike : 0;
      total += this_payoff;
    }

  double mu = total / numpaths;
  return mu * exp(-r * expiry);

}

int main ()
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

  double result = call_price(expiry, strike, spot, vol, r, num_paths);

  cout << "the price is " << result << '\n';

  return 0;
}

  
