/*
 * OptionPricing_test.cpp
 *
 *  Created on: Mar 21, 2014
 *      Author: art
 */

#include "OptionPricing.hpp"
#include "BinomialOption.hpp"
#include "OptionType.hpp"

#include <iostream>
#include <iomanip>      // std::setprecision

#include <cmath>        // std::sqrt

/**
 * Sp = stock price
 * Pu = price up
 * Pd = price down
 * Op = price of option
 * Ep = exercise price
 * Ns = number of shares purchased
 * R = risk free interest rate
 * Hr = hedge ratio [calculated]
 */
int
main (int argc, const char *argv[])
{
    double Sp = 10.0;
    double Pu = 1 + 0.25;
    double Pd = 1 + 0.25;
    double Op = 12.0;
    double Ep = 12.5;
    int Ns = 100;
    double R = 0.01;
    /* Start Time Value of Money */
    finance::OptionPricing opr;
    double value1 = opr.formula (Sp, Pu, Pd, Op, Ep, Ns, R);
    std::cout << "VALUE1 = " << value1 << std::endl;
    /**
     * cP = call price
     * pP = put price
     * X  = exercise price
     * D = dividend
     * R = risk free interest rate
     */
    double cP = 10.0;
    double pP = 10.0;
    double X = 40.0;
    double D = 0.0;
    double value2 = opr.putCallParity (cP, pP, X, D, R);
    std::cout << "VALUE2 = " << value2 << std::endl;

    double value3 = opr.pricing (cP, pP, X, D, R);
    std::cout << "VALUE3 = " << value3 << std::endl;

    /**
     * @param S - Spot Price [30.00]
     * @param X - Exercise Price [34.00]
     * @param r - Interest Rate per period [0.10]
     * @param u - Up movement
     * @param d - Down movement
     */
    double value4 = opr.SinglePeriodEuroCall(30.00, 34.00, 0.10, 45.00, 15.00);
    std::cout << "VALUE4 = " << value4 << std::endl;

    finance::BinomialOption bo;
    bo.setOptionType(finance::OPT_TYPE::EURO);
    bo.setStockPrice(30.00);
    bo.setExercisePrice(34.00);
    bo.setRiskFreeRate(0.10);
    bo.setSigma(0.00004);
    bo.setSteps(1);
    bo.setCurrentDate(0);
    bo.setMaturityDate(1);
    double value5 = bo.price();
    std::cout << "VALUE5 = " << value5 << std::endl;

    return (0);
}

