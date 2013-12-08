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
             * An ordinary annuity pays out the same C dollars at the end of each
             * year for n years. With a rate of r, the future value at the end of
             * the nth year is equal to the following:
             * \f$
             * \displaystyle\sum_{i=0}^{n-1} C(1 + r)^{i} = C\frac{(1+r)^{n} - 1}{r}
             * \f$
             * </p>
             */
            const double OrdinaryAnnuity(const double, const int, const double);

            virtual ~Annuities();
    };

} /* namespace finance */

#endif /* FINANCE_ANNUITIES_HPP */
