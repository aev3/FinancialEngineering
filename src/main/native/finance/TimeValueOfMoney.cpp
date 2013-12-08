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
    * \f$
    * \textrm{Algorithm for continuous compounding: where } P \textrm{ represents
    * the present value, }  r  \textrm{ represents the interest rate, and }
    * n  \textrm{ represents the number of periods. }
    * \f$
    *
    * \f[
    *   P = FV \times (1 + r)^{-n}
    * \f]
    */
    const double TimeValueOfMoney::DiscountedPresentValueOfFuturePayment(const double rate,
        const int periods,
        const double fv)
    {
        return fv * std::pow(1 + rate, -periods);
    }

    /**
    * \f$
    * \textrm{Algorithm for continuous compounding: where } P \textrm{ represents
    * the present value, }  r  \textrm{ represents the interest rate, and }
    * n  \textrm{ represents the number of periods. }
    * \f$
    *
    * \f[
    *   FV = P\left(1 + r \right)^n
    * \f]
    */
    const double TimeValueOfMoney::FutureValueOfPresentPayment(const double rate,
        const int periods,
        const double pv)
    {
        return pv * std::pow(1 + rate, periods);
    }

    /**
    * \f$
    * \textrm{Algorithm for discrete compounding: where } P \textrm{ represents
    * the present value, }  r  \textrm{ represents the interest rate, }
    * n  \textrm{ represents the number of periods, and }
    * m \textrm{ represents the number of times interest is compounded for the
    * period. }
    * \f$
    *
    * \f[
    *   FV = P\left(1 + \frac{r}{m}\right)^{nm}
    * \f]
    */
    const double TimeValueOfMoney::CompoundingFutureValueOfPresentPayment(const double rate,
        const int years,
        const double pv,
        const int per_annum)
    {
        return pv * std::pow(1 + (rate / per_annum), per_annum * years);
    }

    /**
    * \f$
    * \textrm{Algorithm for continuous compounding: where } P \textrm{ represents
    * the present value, }  r  \textrm{ represents the interest rate, and }
    * n  \textrm{ represents the number of periods. }
    * \f$
    *
    * \f[
    *   FV = Pe^{rn}
    * \f]
    */
    const double TimeValueOfMoney::ContinuousCompoundingFutureValueOfPresentPayment(const double rate,
        const int years,
        const double pv)
    {
        return pv * std::exp(years * rate);
    }

    TimeValueOfMoney::~TimeValueOfMoney()
    {
        // TODO Auto-generated destructor stub
    }

} // namespace finance
