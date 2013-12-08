/*
 * Annuities.hpp
 *
 *  Created on: Dec 7, 2013
 *      Author: art
 */

#ifndef FINANCE_ANNUITIES_HPP
#define FINANCE_ANNUITIES_HPP

namespace finance
{

    class Annuities
    {
        public:

            Annuities();

            /**
             * <p>
             * An <b>Ordinary Annuity</b> pays out the same C dollars at the end of each
             * year for n years. With a rate of r, the <b>Future Value</b> of the
             * annuity at the end of the nth year is equal to the following:
             * \f$
             * \displaystyle\sum_{i=0}^{n-1} C(1 + r)^{i} = C\frac{(1+r)^{n} - 1}{r}.
             * \f$
             * </p>
             */
            const double OrdinaryAnnuity(const double, const int, const double);

            /**
             * <p>
             * For <b>Annuity Due</b>, cash flows are received at the beginning of each
             * year The <b>Future Value</b> is as follows:
             * \f$
             * \displaystyle\sum_{i=1}^{n} C(1 + r)^{i} = C\frac{(1+r)^{n} - 1}{r}
             * (1 + r).
             * \f$
             * </p>
             */
            const double FutureValueOfAnnuityDue(const double, const int, const double);

            /**
             * <p>
             * For <b>Annuity Due</b>, cash flows are received at the beginning of each
             * year. The <b>Present Value</b> is as follows:
             * \f$
             * \displaystyle\sum_{i=1}^{n} C\left(1 + r\right)^{-i} = C\frac{1-(1+r)^{-n}}{r}
             * (1 + r).
             * \f$
             * </p>
             */
            const double PresentValueOfAnnuityDue(const double, const int, const double);

            /**
             * <p>
             * For <b>General Annuity</b>, cash flows are received at the beginning of each
             * year. The <b>Present Value</b> is as follows:
             * \f$
             * \displaystyle\sum_{i=1}^{nm} C\left(1 + \frac{r}{m}\right)^{-i}
             * = C\frac{1-(1+\frac{r}{m})^{-nm}}{\frac{r}{m}}.
             * \f$
             * </p>
             */
            const double PresentValueOfGeneralAnnuity(const double, const int, const double, const int);

            virtual ~Annuities();
    };

} /* namespace finance */

#endif /* FINANCE_ANNUITIES_HPP */
