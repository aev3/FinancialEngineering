/*
 * BinomialOption.cpp
 *
 *  Created on: Mar 24, 2014
 */

#include "BinomialOption.hpp"

// For output
#include <iostream>

// std::setprecision
#include <iomanip>

// Standard mathematical library
#include <cmath>

// included for max() operator
#include <algorithm>

// Standard library vector
#include <vector>

namespace finance
{

    BinomialOption::BinomialOption()
    {
        stockPrice = 0.0;
        exercisePrice = 0.0;
        riskFreeRate = 0.0;
        sigma = 0.0;
        currentDate = 0;
        maturityDate = 0;
        timeToMaturity = 0;
        steps = 0;
        optionType = OPT_TYPE::EURO;
    }

    const double& BinomialOption::pricingEuroCall(const double& S,
            const double& X,
            const double& r,
            const double& u,
            const double& d)
    {

        double p_up = (std::exp(r) - d)/(u - d);
        double p_down = 1.0 - p_up;
        double c_u = std::max(0.0,(u*S - X));
        double c_d = std::max(0.0,(d*S - X));
        double call_price = std::exp(-r)*(p_up*c_u + p_down*c_d);
        /*
        double uS0 = u * S;
        double dS0 = d * S;
        double Cu = uS0 - X;
        double Cd = dS0 - X;
        double H = ( ( Cu - Cd ) / ( uS0 - dS0 ) );
        double HdS0 = H * dS0;
        double PV = ( ( HdS0 / ( 1 + r ) ) );
        double HS0 = H * S;
        double C = HS0 - PV;
        return C;
        */
        return call_price;
    };

    const double& BinomialOption::price()
    {
        double R = std::exp(riskFreeRate * (currentDate / steps));
        double Rinv = 1.0 / R;
        double u = std::exp(sigma * std::sqrt(currentDate / steps));
        double d = 1.0 / u;
        double p_up = (R - d) / (u - d);
        double p_down = 1.0 - p_up;

        std::vector<double> prices(steps + 1);       // price of underlying
        prices[0] = stockPrice * std::pow(d, steps); // fill in the endnodes.
        double uu = u * u;
        for(int i = 1; i <= steps; ++i)
        {
            prices[i] = uu * prices[i - 1];
        }

        // value of corresponding call
        std::vector<double> call_values(steps + 1);
        for(int i = 0; i <= steps; ++i)
        {
            // call payoffs at maturity
            call_values[i] = std::max(0.0, (prices[i] - exercisePrice));
        }

        for(int step = steps - 1; step >= 0; --step)
        {
            for(int i = 0; i <= step; ++i)
            {
                call_values[i] = (p_up * call_values[i + 1]
                        + p_down * call_values[i]) * Rinv;
                prices[i] = d * prices[i + 1];
                // check for exercise
                call_values[i] = std::max(call_values[i],
                                          prices[i] - exercisePrice);
            };
        };

        return (call_values[0]);

    };

    const double& BinomialOption::onePeriodPricing(const double& S, const double& X,
                                                   const double& r, const double& u,
                                                   const double& d)
    {
        double uS0 = S * u;
        double dS0 = S * d;
        std::cout   << std::setprecision(2) << std::fixed
                    << std::setfill (' ') << std::setw(4)
                    << "uS0 = " << uS0
                    << " and dS0 = " << dS0
                    << std::endl;
        double Cu = uS0 - X;
        double Cd = std::max(0.0,(dS0 - X));
        std::cout   << std::setprecision(2) << std::fixed
                    << std::setfill (' ') << std::setw(4)
                    << "Cu = " << Cu
                    << " and Cd = " << Cd
                    << std::endl;
        double H = ( Cu - Cd) / ( uS0 - dS0 );
        std::cout   << std::setprecision(3) << std::fixed
                    << std::setfill (' ') << std::setw(4)
                    << "H = " << H << std::endl;
        return( H );
    }


    BinomialOption::~BinomialOption()
    {
        // TODO Auto-generated destructor stub
    }

} /* namespace finance */
