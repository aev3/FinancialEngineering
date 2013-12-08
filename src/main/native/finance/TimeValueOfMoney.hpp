//
// Created by Art Vossberg on 07-12-2013.
// Copyright (c) 2013 Art Vossberg. All rights reserved.
//


#ifndef FINANCE_TIME_VALUE_OF_MONEY_HPP
#define FINANCE_TIME_VALUE_OF_MONEY_HPP


namespace finance
{


    class TimeValueOfMoney
    {

    public:

        TimeValueOfMoney();

        /**
        * \f[
        *   P = C \times (1 + r)^{-n}
        * \f]
        */
        const double DiscountedPresentValueOfFuturePayment(const double, const int, const double);

        /**
        * \f[
        *   FV = P\left(1 + r \right)^n
        * \f]
        */
        const double FutureValueOfPresentPayment(const double, const int, const double);

        /**
        * <p>
        * Compounding the value of a present payment over the number of years
        * times the number of periods per annum.
        * </p>
        *
        * \f[
        *   FV = P\left(1 + \frac{r}{m}\right)^{nm}
        * \f]
        */
        const double DiscreteCompoundingFutureValueOfPresentPayment(const double, const int, const double, const int);

        /**
         * <p>
         * Compounding the value of a present payment over the number of years
         * with continuous compounding.
         * </p>
         *
         * \f[
         *   FV = Pe^{rn}
         * \f]
         */
        const double ContinuousCompoundingFutureValueOfPresentPayment(const double, const int, const double);

        virtual ~TimeValueOfMoney();

    };

} // namespace

#endif // FINANCE_TIME_VALUE_OF_MONEY_HPP
