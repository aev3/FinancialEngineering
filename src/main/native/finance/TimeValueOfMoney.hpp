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

        const double DiscountedPresentValueOfFuturePayment(const double, const int, const double);

        const double FutureValueOfPresentPayment(const double, const int, const double);

        /**
        * Compounding the value of a present payment over the number of years times the number of periods per annum.
        */
        const double CompoundingFutureValueOfPresentPayment(const double, const int, const double, const int);

        /**
        * Compounding the value of a present payment over the number of years with continuous compounding.
        */
        const double ContinuousCompoundingFutureValueOfPresentPayment(const double, const int, const double);

        virtual ~TimeValueOfMoney();

    };

} // namespace

#endif // FINANCE_TIME_VALUE_OF_MONEY_HPP
