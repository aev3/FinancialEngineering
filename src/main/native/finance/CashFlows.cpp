//
// Created by Art Vossberg on 07-12-2013.
// Copyright (c) 2013 Art Vossberg. All rights reserved.
//

#include "CashFlows.hpp"

#include <cmath>

namespace finance
{

    CashFlows::CashFlows()
    {
        // No argument default ctor
    }

    /**
    * \f$
    * \textrm{Algorithm for discounted present value of future cash flows where: }
    * C \textrm{ represents the casdh flow at time }  t
    * \textrm{ and } r \textrm{ represents the interest rate, }
    * n  \textrm{ represents the number of periods, and }
    * m \textrm{ represents the number of times interest is compounded for the
    * period. }
    * \f$
    *
    * \f[
    * 	PV = \displaystyle\sum_{i=1}^{n} \frac{C_t}{(1+y)^{n}}
    * \f]
    */
    const double CashFlows::DiscountedPresentValueOfCashFlows(const double C, const double rate, int term)
    {
        double pV = 0.0;
        double z = 1 + rate;
        while(term > 0)
        {
            pV = pV + C / std::pow(z, term);
            --term;
        }

        return pV;
    }

    CashFlows::~CashFlows()
    {
        // Do Nothing default dtor
    }

} // namespace
