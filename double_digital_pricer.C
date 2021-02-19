#include <iostream>
#include <cmath>
#include <random>
using namespace std;

/* Monte Carlo pricer for double digital options */
double dd_price(double expiry, double lower_strike,
		 double upper_strike, double spot, double vol,
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
      double this_payoff;
      if (lower_strike <= this_spot && this_spot <= upper_strike) {
	this_payoff = 1.00;
      } else this_payoff = 0;
      total += this_payoff;
    }

  double mu = total / numpaths;
  return mu * exp(-r * expiry);

}

int main ()
{
  double expiry;
  double lstrike;
  double ustrike;
  double spot;
  double vol;
  double r;
  size_t num_paths;

  cout << "Enter expiry (years):";
  cin >> expiry;

  cout << "Enter lower strike price:";
  cin >> lstrike;

  cout << "Enter upper strike price:";
  cin >> ustrike;

  cout << "Enter spot price:";
  cin >> spot;

  cout << "Enter volatility:";
  cin >> vol;

  cout << "Enter r (interest rate):";
  cin >> r;

  cout << "Number of paths:";
  cin >> num_paths;

  double result = dd_price(expiry, lstrike, ustrike, spot, vol, r, num_paths);

  cout << "the price is " << result << '\n';

  return 0;
}

  
