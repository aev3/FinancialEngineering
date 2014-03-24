/*
 * OptionPricing.hpp
 *
 *  Created on: Mar 21, 2014
 *      Author: art
 */

#ifndef FINANCE_OPTION_PRICING_HPP
#define FINANCE_OPTION_PRICING_HPP

namespace finance
{

  class OptionPricing
  {
  public:

    OptionPricing ();

    virtual~OptionPricing ();

    double formula(double Sp, double Pu, double Pd, double Op, double Ep, int Ns, double R);

    double putCallParity(double callPrice, double putPrice, double X, double D, double R);

    double pricing(double, double, double, double, double);

    /**
     * <p>
     * Option and other derivative pricing is one of the prime ``success stories''
     * of modern finance. An option is a derivative security, the cash flows from
     * the security is a function of the price of some other security, typically
     * called the underlying security. A call option is a right, but not obligation,
     * to buy a given quantity of the underlying security at a given price, called
     * the exercise price $K$, within a certain time interval. A put option is the
     * right, but not obligation, to sell a given quantity of the underlying security
     * to an agreed excercise price within a given time interval. If an option can
     * only be exercised (used) at a given date (the time interval is one day),
     * the option is called an European Option. If the option can be used in a whole
     * time period up to a given date, the option is called American.
     * </p>
     * <p>
     * An option will only be used if it is valuable to the option holder. In the
     * case of a call option, this is when the exercise price $K$ is lower than
     * the price one alternatively could buy the underlying security for, which
     * is the current price of the underlying security. Hence, options have never
     * negative cash flows at maturity. Thus, for anybody to be willing to offer
     * an option, they must have a cost when entered into. This cost, or price,
     * is typically called an option premium. As notation, let $C$ signify the
     * price of a call option, $P$ the price of a put option and $S$ the price
     * of the underlying security. All of these prices are indexed by time. We
     * typically let $0$ be ``now'' and $T$ the final maturity date of the option.
     * From the definition of the options, it is clear that at their last possible
     * exercise date, the maturity date, they have cash flows.
     * </p>
     *
     * @param S - Spot Price
     * @param X - Exercise Price
     * @param r - Interaest Rate per period
     * @param u - Up movement
     * @param d - Down movement
     *
     * @return double - the price of the option
     */
    double SinglePeriodEuroCall(const double& S, const double& X,
                                const double& r, const double& u,
                                const double& d);

  };

} /* namespace finance */

#endif /* FINANCE_OPTION_PRICING_HPP */
