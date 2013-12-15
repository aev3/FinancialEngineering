/*
 * NewtonsMethod.cpp
 *
 *  Created on: Dec 14, 2013
 *      Author: art
 */

#include "NewtonsMethod.hpp"

#include <cmath>

namespace util
{

    NewtonsMethod::NewtonsMethod()
    {
        // TODO Auto-generated constructor stub

    }

    /**
     * <p>
     * Simple implementation of Sir Isaac's formulation for finding the square
     * root of a number.
     * </p>
     *
     * @param c double that represents the number to be used to calculate the
     * square root
     *
     * @return double representing the square root of 'c'
     */
    double NewtonsMethod::sqrt(double c)
    {
        if(c < 0.0) return std::nan("NaN");
        double epsilon = 1e-15;
        double t = c;
        while(std::abs(t - c/t) > epsilon * t)
        {
            t = (c/t + t) / 2.0;
        }

        return t;

    }

    NewtonsMethod::~NewtonsMethod()
    {
        // TODO Auto-generated destructor stub
    }

} /* namespace finance */
