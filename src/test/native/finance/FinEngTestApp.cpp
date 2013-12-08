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
    double payment = 1000.00;
    int years = 4;
	double rate = 0.10;
	int per_annum_periods = 12;

	/* Start Time Value of Money */
	finance::TimeValueOfMoney tvm;

	double pv = tvm.DiscountedPresentValueOfFuturePayment(payment, years, rate);
	std::cout << "Discounted Present Value of Future Payment = " << pv
			<< std::endl;

	double fv = tvm.FutureValueOfPresentPayment(pv, years, rate);
	std::cout << "Future Value of Present Payment = " << fv << std::endl;

	double cfv1 = tvm.DiscreteCompoundingFutureValueOfPresentPayment(payment,
	                years, rate, 1);
	std::cout << "Discrete Compounded Future Value of Present Payment (1*4)= " << cfv1
			<< std::endl;

	double cfv4 = tvm.DiscreteCompoundingFutureValueOfPresentPayment(payment,
                    years, rate, 4);
	std::cout << "Discrete Compounded Future Value of Present Payment (4*4)= " << cfv4
			<< std::endl;

	double cfv12 = tvm.DiscreteCompoundingFutureValueOfPresentPayment(payment,
                    years, rate, per_annum_periods);
	std::cout << "Discrete Compounded Future Value of Present Payment (12*4)= " << cfv12
			<< std::endl;

	double cfv360 = tvm.DiscreteCompoundingFutureValueOfPresentPayment(payment,
                    years, rate, 360);
	std::cout << "Discrete Compounded Future Value of Present Payment (360*4)= "
			<< cfv360 << std::endl;

    double cfv_cont = tvm.ContinuousCompoundingFutureValueOfPresentPayment(payment,
                    years, rate);
    std::cout
            << "Continuously Compounded Future Value of Present Payment (360*inf)= "
            << cfv_cont << std::endl;

    /* Start Cash Flows */
    finance::CashFlows cf;
    double cfs = cf.DiscountedPresentValueOfCashFlows(payment, years, rate);
    std::cout << "Discounted Present Value of Cash Flows = " << cfs
            << std::endl;

    /* Start Annuities */
    finance::Annuities ann;
    double ord_ann = ann.OrdinaryAnnuity(payment, years, rate);
    std::cout
            << "Future Value of Ordinary Annuity = "
            << ord_ann << std::endl;

    double fv_ann_due = ann.FutureValueOfAnnuityDue(payment, years, rate);
    std::cout
            << "Future Value of Annuity Due = "
            << fv_ann_due << std::endl;

    double pv_ann_due = ann.PresentValueOfAnnuityDue(payment, years, rate);
    std::cout
            << "Present Value of Annuity Due = "
            << pv_ann_due << std::endl;

    double pv_gen_ann = ann.PresentValueOfGeneralAnnuity(payment, years, rate, 1);
    std::cout
            << "Present Value of General Annuity = "
            << pv_gen_ann << std::endl;

    double pv_gen_comp_ann = ann.PresentValueOfGeneralAnnuity(5000, 9, 0.07125, 12);
    std::cout
            << "Present Value of Quarterly Compounding of General Annuity = "
            << pv_gen_comp_ann << std::endl;


    double pv_gen_comp_perp = ann.PresentValueOfPerpetualAnnuity(5000, 0.07125);
    std::cout
            << "Present Value of Perpetual Annuity = "
            << pv_gen_comp_perp << std::endl;


	return 0;

}

