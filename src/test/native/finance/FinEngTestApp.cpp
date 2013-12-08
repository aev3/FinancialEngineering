//
//  main.cpp
//  FinancialEngineeringExamples
//
//  Created by Art Vossberg on 07-12-2013.
//  Copyright (c) 2013 AWOLart.com. All rights reserved.
//

#include <iostream>

#include "Annuities.hpp"
#include "TimeValueOfMoney.hpp"
#include "CashFlows.hpp"

int main(int argc, const char *argv[])
{
	double rate = 0.10;
	int years = 4;
	double payment = 100000.00;
	int per_annum_periods = 12;

	finance::CashFlows cf;
	double cfs = cf.DiscountedPresentValueOfCashFlows(payment, rate, years);
	std::cout << "Discounted Present Value of Cash Flows = " << cfs
			<< std::endl;

	finance::TimeValueOfMoney tvm;

	double pv = tvm.DiscountedPresentValueOfFuturePayment(rate, years, payment);
	std::cout << "Discounted Present Value of Future Payment = " << pv
			<< std::endl;

	double fv = tvm.FutureValueOfPresentPayment(rate, years, pv);
	std::cout << "Future Value of Present Payment = " << fv << std::endl;

	double cfv1 = tvm.CompoundingFutureValueOfPresentPayment(rate, years,
			payment, 1);
	std::cout << "Compounded Future Value of Present Payment (1*4)= " << cfv1
			<< std::endl;

	double cfv4 = tvm.CompoundingFutureValueOfPresentPayment(rate, years,
			payment, 4);
	std::cout << "Compounded Future Value of Present Payment (4*4)= " << cfv4
			<< std::endl;

	double cfv12 = tvm.CompoundingFutureValueOfPresentPayment(rate, years,
			payment, per_annum_periods);
	std::cout << "Compounded Future Value of Present Payment (12*4)= " << cfv12
			<< std::endl;

	double cfv360 = tvm.CompoundingFutureValueOfPresentPayment(rate, years,
			payment, 360);
	std::cout << "Compounded Future Value of Present Payment (360*4)= "
			<< cfv360 << std::endl;

    double cfv_cont = tvm.ContinuousCompoundingFutureValueOfPresentPayment(rate,
            years, payment);
    std::cout
            << "Continuous Compounded Future Value of Present Payment (360*inf)= "
            << cfv_cont << std::endl;

    finance::Annuities ann;
    double ord_ann = ann.OrdinaryAnnuity(payment, years, rate);
    std::cout
            << "Future Value of Ordinary Annuity = "
            << ord_ann << std::endl;

    double fv_ann_due = ann.FutureValueOfAnnuityDue(1000.00, 5, 0.05);
    std::cout
            << "Future Value of Annuity Due = "
            << fv_ann_due << std::endl;

    double pv_ann_due = ann.PresentValueOfAnnuityDue(1000.00, 5, 0.05);
    std::cout
            << "Present Value of Annuity Due = "
            << pv_ann_due << std::endl;

    double pv_gen_ann = ann.PresentValueOfGeneralAnnuity(1000.00, 5, 0.05, 1);
    std::cout
            << "Present Value of General Annuity = "
            << pv_gen_ann << std::endl;

    double pv_gen_ann_ex = ann.PresentValueOfGeneralAnnuity(5000.00, 9, 0.07125, 12);
    std::cout
            << "Present Value of General Annuity [Example 3.2.2] = "
            << pv_gen_ann_ex << std::endl;

	return 0;

}

