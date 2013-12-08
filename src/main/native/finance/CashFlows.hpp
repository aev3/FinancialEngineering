//
// Created by Art Vossberg on 07-12-2013.
// Copyright (c) 2013 Art Vossberg. All rights reserved.
//


#ifndef FINANCE_CASH_FLOWS_HPP
#define FINANCE_CASH_FLOWS_HPP

namespace finance
{


    class CashFlows
    {
    public:

        CashFlows();

        const double DiscountedPresentValueOfCashFlows(const double C, const double rate, int term);

        virtual ~CashFlows();

    };

} // namespace

#endif // FINANCE_CASH_FLOWS_HPP
