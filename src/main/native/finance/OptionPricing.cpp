/*
 * OptionPricing.cpp
 *
 *  Created on: Mar 21, 2014
 *      Author: art
 */

#include "OptionPricing.hpp"
#include "TimeValueOfMoney.hpp"

// Standard mathematical library
#include <cmath>
// included for max() operator
#include <algorithm>

namespace finance
{
    double
    OptionPricing::SinglePeriodEuroCall(const double& S, const double& X,
                                        const double& r, const double& u,
                                        const double& d)
    {
        double p_up = (std::exp(r) - d) / (u - d);
        double p_down = 1.0 - p_up;
        double c_u = std::max(0.0, ((u * S) - X));
        double c_d = std::max(0.0, ((d * S) - X));
        double price = std::exp(-r) * ((p_up * c_u) + (p_down * c_d));
        return price;
    }

    OptionPricing::OptionPricing()
    {
        // TODO Auto-generated constructor stub

    }

    OptionPricing::~OptionPricing()
    {
        // TODO Auto-generated destructor stub
    }

    /**
     * Sp = stock price
     * Pu = price up
     * Pd = price down
     * Op = price of option
     * Ep = exercise price
     * Ns = number of shares purchased
     * R = risk free interest rate
     */
    double
    OptionPricing::formula(double Sp, double Pu, double Pd, double Op,
                           double Ep, int Ns, double R)
    {
        return ((1 + R) * (1 * Sp - Op));
    }

    /**
     * cP = call price
     * pP = put price
     * X  = exercise price
     * D = dividend
     * R = risk free interest rate
     */
    double
    OptionPricing::putCallParity(double cP, double pP, double X, double D,
                                 double R)
    {
        TimeValueOfMoney tvm;
        auto pdvD = tvm.DiscountedPresentValueOfFuturePayment(X, D, R);
        auto pdvX = tvm.DiscountedPresentValueOfFuturePayment(X, D, R);
        return (cP - pP + pdvD + pdvX);
    }

    /**
     * s = Stock price
     * u = 1 + fraction up
     * d = 1 + fraction down
     * C = value of option (derived)
     * Cu = price of option times u
     * Cd = price of option times d
     * k = Exercise [or Strike] Price
     * r = risk free interest rate
     * H = Hedge ratio [ number of shares/number of options]
     * put = call price + pdv(exercise price) - stock price + pdv(dividend)
     */
    double
    OptionPricing::pricing(double s, double u, double d, double k, double r)
    {
        double S = 30.00;
        double up = 15.00;
        double down = 15.00;
        double Cu = 45.00;
        double Cd = 15.00;
        double H = (Cu - Cd) / ((u - d) * S);
        double R = 0.10;
        //double K = 34;
        //double value = ( (1 + R - down) / (up - down) ) * ( (Cu) / ( 1 + R ) )
        //		 + ( ( ( up - 1 - R ) / ( up - down ) ) * ( (Cd) / ( 1 + R ) ) );
        //value =  u * H * S - Cu;
        //value = (1 + R ) * ( ( H * S ) - 30 );
        double value = 45 + 30.91 - 30;
        return (value);
    }

} /* namespace finance */
