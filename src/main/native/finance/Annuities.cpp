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


    /**
     * <p>
     * An Annuity Due where C = the per period cash flow, n = the number
     * of periods, and r = the interest rate.
     * </p>
     */
    const double Annuities::FutureValueOfAnnuityDue(const double C,
                    const int n,
                    const double r)
    {
        /*
        double fV = C * (std::pow(1 + r, n) - 1 ) / r * (1 + r);
        for(int i = 1; i <= n; ++i)
        {
           fV = fV + C * (std::pow(1 + r, i) - 1 ) / r * (1 + r);
        }
        */
        return C * (std::pow(1 + r, n) - 1 ) / r * (1 + r);
    }


    /**
     * <p>
     * An Annuity Due where C = the per period cash flow, n = the number
     * of periods, and r = the interest rate.
     * </p>
     */
    const double Annuities::PresentValueOfAnnuityDue(const double C,
                    const int n,
                    const double r)
    {
        /*
        double pV = 0.0;
        for(int i = 1; i <= n; ++i)
        {
           pV = pV + C * 1 - std::pow(1 + r, -i) * (1 + r);
        }
        */
        return C * 1 - std::pow(1 + r, -n) * (1 + r);
    }


    /**
     * <p>
     * A <b>General Annuity</b> where C = the per period cash flow, n = the number
     * of periods, r = the interest rate, and m = the number of payments per
     * period.
     * </p>
     */
    const double Annuities::PresentValueOfGeneralAnnuity(const double C,
                    const int n,
                    const double r,
                    const int m)
    {
        return C * (1 - std::pow(1 + (r/m), -n*m)) / (r/m);
    }


    Annuities::~Annuities()
    {
        // TODO Auto-generated destructor stub
    }

} /* namespace finance */
