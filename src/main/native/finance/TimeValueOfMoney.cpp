//
// Created by Art Vossberg on 07-12-2013.
// Copyright (c) 2013 Art Vossberg. All rights reserved.
//

#include "TimeValueOfMoney.hpp"

#include <cmath>

namespace finance
{

    TimeValueOfMoney::TimeValueOfMoney()
    {
        // Default no arg ctor
    }

    /**
    * <p>
    * Discounted present value of a future payment where:
    * <i>C</i> = the payment amount; i.e., cash,
    * <i>n</i> = the number of periods or years, and
    * <i>r</i> = the interest rate
    * </p>
    */
    const double TimeValueOfMoney::DiscountedPresentValueOfFuturePayment(const double C,
        const int n,
        const double r)
    {
        /*
        * \f[
        *   P = C \times (1 + r)^{-n}
        * \f]
        */
        return C * std::pow(1 + r, -n);
    }

    /**
    * <p>
    * Algorithm for obtaining future value of a present payment where:
    * <i>C</i> = the payment amount; i.e., cash,
    * <i>n</i> = the number of periods or years, and
    * <i>r</i> = the interest rate
    * </p>
    */
    const double TimeValueOfMoney::FutureValueOfPresentPayment(const double C,
        const int n,
        const double r)
    {
        /*
        * \f[
        *   FV = P\left(1 + r \right)^n
        * \f]
        */
        return C * std::pow(1 + r, n);
    }

    /**
    * <p>
    * Algorithm for discrete compounding to obtain future value of a present
    * payments where:
    * <i>C</i> = the payment amount; i.e., cash,
    * <i>n</i> = the number of periods or years,
    * <i>r</i> = the interest rate, and
    * <i>p</i> = the number of compounding periods per annum
    * </p>
    */
    const double TimeValueOfMoney::DiscreteCompoundingFutureValueOfPresentPayment(const double C,
        const int n,
        const double r,
        const int p)
    {
        /*
        * \f[
        *   FV = P\left(1 + \frac{r}{m}\right)^{nm}
        * \f]
        */
       return C * std::pow(1 + (r / p), p * n);
    }

    /**
    * <p>
    * Algorithm for obtaining future value of a present payment using
    * continuous compounding where:
    * <i>C</i> = the payment amount; i.e., cash,
    * <i>n</i> = the number of periods or years, and
    * <i>r</i> = the interest rate
    * </p>
    */
    const double TimeValueOfMoney::ContinuousCompoundingFutureValueOfPresentPayment(
                    const double C,
                    const int n,
                    const double r)
    {
        /*
        * \f[
        *   FV = Pe^{rn}
        * \f]
        */
        return C * std::exp(n * r);
    }

    TimeValueOfMoney::~TimeValueOfMoney()
    {
        // TODO Auto-generated destructor stub
    }

} // namespace finance
