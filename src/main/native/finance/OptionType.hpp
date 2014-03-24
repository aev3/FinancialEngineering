/*
 * OptionType.hpp
 *
 *  Created on: Mar 23, 2014
 */

#ifndef FINANCE_OPTION_TYPE_HPP
#define FINANCE_OPTION_TYPE_HPP

#include <type_traits>

namespace finance
{

    enum class OPT_TYPE
    {
        AMER = 0, EURO = 1, PUT = 2, CALL = 4
    };

} /* namespace finance */

#endif /* FINANCE_OPTIONTYPE_HPP */
