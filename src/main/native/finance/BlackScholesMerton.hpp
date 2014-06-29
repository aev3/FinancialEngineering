/*
 * BlackScholesMerton.hpp
 *
 *  Created on: Jun 28, 2014
 */

#ifndef FINANCE_BLACK_SCHOLES_MERTON_HPP
#define FINANCE_BLACK_SCHOLES_MERTON_HPP

namespace finance
{

    class BlackScholesMerton
    {

    private:

        /**
         * <p>
         * The cumulative normal distribution function.
         * </p>
         *
         * @param X
         *
         * @return
         */
        double CND( double X);



    public:

        static const double PI;

        BlackScholesMerton();

        /**
         * <p>
         * Valuation for Black and Scholes (1973) Stock option formula
         * </p>
         *
         * @param CallPutFlag
         * @param S
         * @param X
         * @param T
         * @param r
         * @param v
         *
         * @return
         */
         double Valuation(char CallPutFlag, double S, double X, double T, double r, double v);

        virtual ~BlackScholesMerton();

    };

} /* namespace finance */

#endif /* FINANCE_BLACK_SCHOLES_MERTON_HPP */
