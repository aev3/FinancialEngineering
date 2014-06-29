/*
 * BlackScholesMertonTest.cpp
 *
 *  Created on: Mar 21, 2014
 *      Author: art
 */

#include "BlackScholesMerton.hpp"

#include <iostream>
#include <iomanip>      // std::setprecision

#include <cmath>        // std::sqrt

/**
 * type = put/call option type
 * S = stock price
 * X = strike price
 * T = time
 * r = riskless rate
 * v = volatility
 */
int
main (int argc, const char *argv[])
{
    char type = 'c';
    double S = 60.0;
    double X = 65.0;
    double T = 0.25;
    double r = 0.08;
    double v = 0.30;
    finance::BlackScholesMerton bsm;
    double valuation = bsm.Valuation(type,S,X,T,r,v);
    std::cout << "black-scholes-merton calculation = " << valuation << std::endl;

    return( 0 );
}

