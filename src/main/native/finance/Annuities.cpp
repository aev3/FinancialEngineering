/*
 * Annuities.cpp
 *
 *  Created on: Dec 7, 2013
 *      Author: art
 */

#include "Annuities.hpp"

#include <cmath>

namespace finance
{

    Annuities::Annuities()
    {
        // TODO Auto-generated constructor stub

    }

    /**
     * <p>
     * An ordinary annuity where C = the per period cash flow, n = the number
     * of periods, and r = the interest rate.
     * </p>
     */
    const double Annuities::OrdinaryAnnuity(const double C,
                    const int n,
                    const double r)
    {
        double fV = 0.0;
        for(int i = 0; i < n; ++i)
        {
           fV = fV + C * std::pow(1 + r, i);
        }

        return fV;
    }


    Annuities::~Annuities()
    {
        // TODO Auto-generated destructor stub
    }

} /* namespace finance */
