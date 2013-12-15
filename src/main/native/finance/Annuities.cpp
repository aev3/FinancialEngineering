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
     * An <b>Ordinary Annuity</b> where
     * <i>C</i> = the per period cash flow,
     * <i>n</i> = the number of periods, and
     * <i>r</i> = the interest rate.
     * </p>
     */
    const double Annuities::OrdinaryAnnuity(const double C,
                    const int n,
                    const double r)
    {
        /*
         * \f$
         * \displaystyle\sum_{i=0}^{n-1} C(1 + r)^{i} = C\frac{(1+r)^{n} - 1}{r}.
         * \f$
         */
        double fV = 0.0;
        for(int i = 0; i < n; ++i)
        {
           fV = fV + C * std::pow(1 + r, i);
        }

        return fV;
    }


    /**
     * <p>
     * An <b>Annuity Due</b> where <i>C</i> = the per period cash flow,
     * <i>n</i> = the number of periods, and
     * <i>r</i> = the interest rate.
     * </p>
     */
    const double Annuities::FutureValueOfAnnuityDue(const double C,
                    const int n,
                    const double r)
    {
        /*
         * \f$
         * \displaystyle\sum_{i=1}^{n} C(1 + r)^{i} = C\frac{(1+r)^{n} - 1}{r}
         * (1 + r).
         * \f$
         */
        return C * ((std::pow(1 + r, n) - 1 ) / r) * (1 + r);
    }


    /**
     * <p>
     * An <b>Annuity Due</b> where
     * <i>C</i> = the per period cash flow,
     * <i>n</i> = the number of periods, and
     * <i>r</i> = the interest rate.
     * </p>
     */
    const double Annuities::PresentValueOfAnnuityDue(const double C,
                    const int n,
                    const double r)
    {

        /*
         * \f$
         * \displaystyle\sum_{i=1}^{n} C\left(1 + r\right)^{-i} = C\frac{1-(1+r)^{-n}}{r}
         * \f$
         */
        return ( C / r ) * ( 1 - ( 1 / std::pow( 1 + r, n ) ) ) * ( 1 + r );
    }


    /**
     * <p>
     * A <b>General Annuity</b> where
     * <i>C</i> = the per period cash flow,
     * <i>n</i> = the number of periods,
     * <i>r</i> = the interest rate, and
     * <i>m</i> = the number of payments per period.
     * </p>
     */
    const double Annuities::PresentValueOfGeneralAnnuity(const double C,
                    const int n,
                    const double r,
                    const int m)
    {
        /*
          * \f$
          * \displaystyle\sum_{i=1}^{nm} C\left(1 + \frac{r}{m}\right)^{-i}
          * = C\frac{1-(1+\frac{r}{m})^{-nm}}{\frac{r}{m}}.
          * \f$
          */
        return C * (1 - std::pow(1 + (r/m), -n*m)) / (r/m);
    }


    /**
     * <p>
     * A <b>Perpetual Annuity</b> where
     * <i>C</i> = the per period cash flow and
     * <i>r</i> = the interest rate.
     * </p>
     */
    const double Annuities::PresentValueOfPerpetualAnnuity(const double C, const double r)
    {
        /*
         * PV = \frac{C}{r}.
         * \f$
         */
        return C/r;
    }

    Annuities::~Annuities()
    {
        // TODO Auto-generated destructor stub
    }

} /* namespace finance */
