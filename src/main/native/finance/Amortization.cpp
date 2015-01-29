/*
 * Amortization.cpp
 *
 *  Created on: Dec 9, 2013
 *      Author: art
 */

#include <Amortization.hpp>

#include <cmath>

#include <iostream>     // std::cout, std::fixed
#include <iomanip>      // std::setprecision

namespace finance
{

    Amortization::Amortization()
    {
        // TODO Auto-generated constructor stub

    }

    /**
     *
     * @param C represents payment or principal amount
     * @param n represents the number of periods or years
     * @param r represents the interest rate on a per annum basis
     * @param m represents the number of compounding periods for n
     *
     * @return double representing the payment amount
     */
    const double
    Amortization::payment(const double C, const int n, const double r,
                          const int m)
    {
        double payment = 0.0;

        /* \f$ (1+\frac{r}{m})^{nm} \f$ */
        double monthly = std::pow(1 + (r / m), (n * m));

        payment = C * ((r / m) * monthly / (monthly - 1));

        return payment;

    }

    /**
     *
     * @param C represents payment or principal amount
     * @param n represents the number of periods or years
     * @param r represents the interest rate on a per annum basis
     * @param m represents the number of compounding periods for n
     *
     * @return double representing the payment amounts
     */
    const int_vec_double_map
    Amortization::amortize(const double C, const int n, const double r,
                           const int m)
    {
        int_vec_double_map amortizing_map;

        double p_and_i_pmt = payment(C, n, r, m);

        double principal = C;
        double i_pmt = 0.0;
        double i_paid = 0.0;
        double p_pmt = 0.0;
        double p_paid = 0.0;

        for(int i = 1; i <= n * m; ++i)
        {
            std::vector<double> p_and_i_vector;

            /*
             * The total payment amount is already calculated and is equal to
             * 'p_and_i_pmt' variable declared and defined above. To
             * determine how much of that "P & i" goes toward interest, multiply
             * the remaining principal balance by the monthly interest rate. And,
             * add this interest strip to 'i_paid' value.
             */
            i_pmt = principal * (r / m);
            p_and_i_vector.push_back(i_pmt);
            i_paid += i_pmt;

            /*
             * The remainder goes toward the mortgage's principal balance.
             * Again, add this principal strip to the 'p_paid' value.
             */
            p_pmt = p_and_i_pmt - i_pmt;
            p_and_i_vector.push_back(p_pmt);
            p_paid += p_pmt;

            p_and_i_vector.push_back(C - p_paid);

            /*
             * Reduce the outstanding principal amount by the 'p_pmt' amount
             * paid in this period.
             */
            principal = principal - p_pmt;

            amortizing_map.insert(std::make_pair(i, p_and_i_vector));

        }

        return amortizing_map;

    }

    /**
     * <p>
     * Print out the amortization table.
     * <p/>
     *
     * @param map map of type K/V, where K is int and V is vector<double>
     */
    void
    Amortization::print(int_vec_double_map map)
    {
        std::cout << "Period\t" << "Interest\t" << "Principal\t" << "Balance"
                << std::endl;
        for(auto iter = map.begin(); iter != map.end(); ++iter)
        {
            std::cout << std::setprecision(2) << std::fixed << std::setfill(' ')
                    << std::setw(4) << iter->first << "\t" << iter->second[0]
                    << "\t\t" << iter->second[1] << "\t\t" << iter->second[2]
                    << "\n";
        }

    }

    Amortization::~Amortization()
    {
        // TODO Auto-generated destructor stub
    }

} /* namespace finance */
