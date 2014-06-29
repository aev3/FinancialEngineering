/*
 * BlackScholesMerton.cpp
 *
 *  Created on: Jun 28, 2014
 */

#include "BlackScholesMerton.hpp"

#include <cmath>

namespace finance
{
    const double BlackScholesMerton::PI = 3.141592653589793238462643;

    BlackScholesMerton::BlackScholesMerton()
    {
        /* Default no argument constructor */
    }


    /**
     * The Black and Scholes (1973) Stock option formula
     *
     * @param CallPutFlag
     * @param S
     * @param X
     * @param T
     * @param r
     * @param v
     * @return
     */
     double BlackScholesMerton::Valuation(char CallPutFlag,
                                             double S,
                                             double X,
                                             double T,
                                             double r,
                                             double v)
    {
        double d1;
        double d2;
        d1 = (log(S/X)+(r+v*v/2)*T)/(v*sqrt(T));
        d2 = d1-v*sqrt(T);
        if(CallPutFlag == 'c')
        {
            return( S * CND(d1)-X * exp(-r*T)*CND(d2) );
        }
        else if(CallPutFlag == 'p')
        {
            return( X * exp(-r * T) * CND(-d2) - S * CND(-d1) );
        }
    }

    /**
     * The cumulative normal distribution function.
     *
     * @param X
     * @return
     */
    double BlackScholesMerton::CND( double X )
    {
        double L;
        double K;
        double w ;
        double const a1 = 0.31938153;
        double const a2 = -0.356563782;
        double const a3 = 1.781477937;
        double const a4 = -1.821255978;
        double const a5 = 1.330274429;

        L = fabs(X);
        K = 1.0 / (1.0 + 0.2316419 * L);
        w = 1.0 - 1.0/sqrt(2 * PI) * exp(-L *L / 2) * (a1 * K + a2 * K *K + a3 * pow(K,3) + a4 * pow(K,4) + a5 * pow(K,5));

        if (X < 0 )
        {
            w= 1.0 - w;
        }
        return( w );
    }


    BlackScholesMerton::~BlackScholesMerton()
    {
        /* Default destructor */
    }

} /* namespace finance */
