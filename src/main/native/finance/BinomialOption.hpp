/*
 * BinomialOption.hpp
 *
 *  Created on: Mar 24, 2014
 */

#ifndef FINANCE_BINOMIAL_OPTION_HPP
#define FINANCE_BINOMIAL_OPTION_Hpp

#include "OptionType.hpp"

namespace finance
{

    class BinomialOption
    {
    private:

        OPT_TYPE optionType;

        /**
         * S: Price of the underlying, e,g., stock price.
         */
        double stockPrice;

         /**
          * X: Exercise price.
          */
        double exercisePrice;

         /**
          * r: Risk free interest rate.
          */
         double riskFreeRate;

         /**
          * sigma: Standard deviation of the underlying asset, e.g., stock.
          */
         double sigma;

         /**
          * t: Current date.
          */
         long currentDate;

         /**
          * T: Maturity date.
          */
         long maturityDate;

         /**
          * T-t: Time to maturity.
          */
         long timeToMaturity;

         /**
          * steps: Number of steps in binomial model
          */
         int steps;

    public:

         BinomialOption();

        virtual ~BinomialOption();

        const double& price();

        /**
         * <p>
         * S = spot price
         * X = exercise price
         * r = interest rate (per period)
         * u = up movement
         * d = down movement)
         * </p>
         */
        const double& pricingEuroCall(const double& S, const double& X,
                                      const double& r, const double& u,
                                      const double& d);

        void setOptionType(const OPT_TYPE);

        void setStockPrice(const double&);
        void setExercisePrice(const double&);
        void setRiskFreeRate(const double&);
        void setSigma(const double&);
        void setCurrentDate(const long&);
        void setMaturityDate(const long&);
        void setTimeToMaturity(const long&);
        void setSteps(const int&);

        /**
          * <p>
          * S = Stock price
          * X = Exercise price
          * r = interest rate (per period)
          * u = up movement
          * d = down movement)
          * </p>
          */
        const double& onePeriodPricing(const double& S, const double& X,
                                       const double& r, const double& u,
                                       const double& d);
    };

    /**
     * @param type OPT_TYPE [enum]
     */
    inline void BinomialOption::setOptionType(const OPT_TYPE type)
    {
        optionType = type;
    }

    /**
     * @param S - Price of the underlying, e.g. stock price.
     */
    inline void BinomialOption::setStockPrice(const double& S)
    {
        stockPrice = S;
    }

    /**
     *
     * @param X - Exercise price.
     */
    inline void BinomialOption::setExercisePrice(const double& X)
    {
        exercisePrice = X;
    }

    /**
     * @param r - Risk free interest rate.
     */
    inline void BinomialOption::setRiskFreeRate(const double& r)
    {
        riskFreeRate = r;
    }

    /**
     *
     * @param std_dev - Standard deviation of the underlying asset, e.g., stock.
     */
    inline void BinomialOption::setSigma(const double& std_dev)
    {
        sigma = std_dev;
    }

    /**
     * @param t - current date.
     */
    inline void BinomialOption::setCurrentDate(const long& t)
    {
        currentDate = t;
    }

    /**
     * @param T - maturity date.
     */
    inline void BinomialOption::setMaturityDate(const long& T)
    {
        maturityDate = T;
    }

    /**
    *
     * @param tT - time to maturity.
     */
    inline void BinomialOption::setTimeToMaturity(const long& tT)
    {
        timeToMaturity = tT;
    }

    /**
     * @param stps - number of steps in binomial tree.
     */
    inline void BinomialOption::setSteps(const int& stps)
    {
        steps = stps;
    }


}

/* namespace finance */

#endif /* FINANCE_BINOMIAL_OPTION_HPP */
