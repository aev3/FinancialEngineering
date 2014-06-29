/*
 * VanillaOptionTest.cpp
 *
 *  Created on: Jun 29, 2014
 */

#include "VanillaOption.hpp"

#include <iostream>

/* Namespace references for 'main' applications breaks build. */
//namespace finance
//{

int main (int argc, char **argv)
{
  /* Instantiate the VanillaOption class. */
  finance::VanillaOption option;  //

  /* Calculate the call and put prices */
  double call = option.calc_call_price ();
  double put = option.calc_put_price ();

  /* Output the option parameters */
  std::cout << "Strike, K: " << option.getK () << std::endl;
  std::cout << "Risk-free rate, r: " << option.getr () << std::endl;
  std::cout << "Time to maturity, T: " << option.getT () << std::endl;
  std::cout << "Spot price, S: " << option.getS () << std::endl;
  std::cout << "Volatility of asset, sigma: " << option.getsigma ()
      << std::endl;

  /* Output the option prices */
  std::cout << "Call Price: " << call << std::endl;
  std::cout << "Put Price: " << put << std::endl;

  return( 0 );
}

//} /* namespace finance */
