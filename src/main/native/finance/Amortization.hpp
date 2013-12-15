/*
 * Amortization.hpp
 *
 *  Created on: Dec 9, 2013
 *      Author: art
 */

#ifndef FINANCE_AMORTIZATION_HPP
#define FINANCE_AMORTIZATION_HPP

#include <map>
#include <vector>

namespace finance
{

    /**
     * Typedef for amortizing map that will contain K/V pair, where K is the key
     * and is of type int and V is the value and is of type vector<double>;
     */
    typedef std::map<int, std::vector<double> > int_vec_double_map;

    class Amortization
    {
        private:


        public:

            /**
             * <p>
             *  Default no argument constructor
             * </p>
             */
            Amortization();


            /**
             * <p>
             * This is a relatively simple method that calculates the principal and
             * interest, "P & i", amortization payment in connection with a common
             * fixed rate mortgage loan.
             * </p>
             *
             * <p>
             * \f[
             *   A = C \frac{i(1+i)^n}
             *   {(1+i)^n - 1}
             * \f]
             * </p>
             *
             */
            const double payment(const double C,
                            const int n,
                            const double r,
                            const int m);
             /**
              *
              * @param C
              * @param n
              * @param r
              * @param m
              *
              * @return
              */
             const int_vec_double_map amortize(const double C,
                            const int n,
                            const double r,
                            const int m);

            /**
             * <p>
             * Simple function to print the amortization schedule.
             * </p>
             *
             * @param map of type std::map<int, std::vector<double> > that is
             * typedef 'int_vec_double_map'
             */
            void print(int_vec_double_map);

            /**
             * <p>
             *  Default destructor
             * </p>
             */
            virtual ~Amortization();

    };

} /* namespace finance */

#endif /* FINANCE_AMORTIZATION_HPP */
