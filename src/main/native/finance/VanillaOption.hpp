/*
 * VanillaOption.hpp
 *
 *  Created: 2014-06-29
 */

#ifndef FINANCE_VANILLA_OPTION_HPP
#define FINANCE_VANILLA_OPTION_HPP

/* For std:pow */
#include <cmath>

namespace finance
{
    /**
     * <p>
     * Define the Vanilla Option class.
     * </p>
     */
    class VanillaOption
    {
        private:

            void init();
            void copy(const VanillaOption& rhs);

            double K;       // Strike price
            double r;       // Risk-free rate
            double T;       // Maturity time
            double S;       // Underlying asset price
            double sigma;   // Volatility of underlying asset

        public:

            /**
             * <p>
             * Default constructor - has no parameters.
             * </p>
             */
            VanillaOption();

            /**
             * <p>
             * Parameterized constructor.
             * </p>
             *
             * @param _K
             * @param _r
             * @param _T
             * @param _S
             * @param _sigma
             */
            VanillaOption(const double _K, const double _r, const double _T,
                            const double _S, const double _sigma);

            /**
             * <p>
             * Copy constructor.
             * </p>
             *
             * @param rhs
             */
            VanillaOption(const VanillaOption& rhs);

            /**
             * <p>
             * Assignment operator.
             * </p>
             *
             * @param rhs
             *
             * @return
             */
            VanillaOption& operator=(const VanillaOption& rhs);

            /**
             * <p>
             * Destructor is virtual.
             * </p>
             */
            virtual ~VanillaOption();

            /**
             * <p>
             * Selector ("getter") methods for our option parameters
             * </p>
             *
             * @return
             */
            double getK() const;
            double getr() const;
            double getT() const;
            double getS() const;
            double getsigma() const;

            /**
             * <p>
             * Option price calculation method for call option.
             * </p>
             *
             * @return
             */
            double calc_call_price() const;

            /**
             * <p>
             * Option price calculation method for put option.
             * </p>
             *
             * @return
             */
            double calc_put_price() const;
    };

    /**
     * Public access for the strike price, K
     *
     * @return double with value of K
     */
    inline double VanillaOption::getK() const
    {
        return K;
    }

    /**
     * Public access for the risk-free rate, r
     *
     * @return double with value of r
     */
    inline double VanillaOption::getr() const
    {
        return r;
    }

    /**
     * Public access for the time to maturity, T
     *
     * @return double with value of T
     */
    inline double VanillaOption::getT() const
    {
        return T;
    }

    /**
     * Public access for the spot price, S
     *
     * @return double with value of S
     */
    inline double VanillaOption::getS() const
    {
        return S;
    }

    /**
     * Public access for the volatility of the asset, sigma
     *
     * @return double with value of sigma
     */
    inline double VanillaOption::getsigma() const
    {
        return sigma;
    }

} /* namespace finance */

#endif /* FINANCE_VANILLA_OPTION_HPP */
