//==============================================================================
//         Copyright 2003 - 2012   LASMEA UMR 6602 CNRS/Univ. Clermont II
//         Copyright 2009 - 2012   LRI    UMR 8623 CNRS/Univ Paris Sud XI
//
//          Distributed under the Boost Software License, Version 1.0.
//                 See accompanying file LICENSE.txt or copy at
//                     http://www.boost.org/LICENSE_1_0.txt
//==============================================================================
#ifndef BOOST_SIMD_ARITHMETIC_FUNCTIONS_ARG_HPP_INCLUDED
#define BOOST_SIMD_ARITHMETIC_FUNCTIONS_ARG_HPP_INCLUDED
#include <boost/simd/include/functor.hpp>
#include <boost/dispatch/include/functor.hpp>

namespace boost { namespace simd
{
  namespace tag
  {
    /*!
      @brief  abs generic tag

      Represents the arg function in generic contexts.

      @par Models:
      Hierarchy
    **/
    struct arg_ : ext::elementwise_<arg_>
    {
      /// @brief Parent hierarchy
      typedef ext::elementwise_<arg_> parent;
    };
  }
  /*!
    Computes the angular orientation of its parameter.

    @par semantic:
    For any given value @c x of type @c T:

    @code
    as_floating<T> r = arg(x);
    @endcode

    is equivalent to:

    @code
    as_floating<T> r = (is_nan(x)) ? x :(x < zero) ? pi : zero;
    @endcode

    @par Note:

    The function always returns a floating value.
    Always 0 or \f$\pi\f$ according to the input sign.
    This function is the restriction to real numbers of the complex argument
    function.

    @par Alias

    angle

    @param  a0   of type T

    @return      a value of the floating type associated to T.

  **/
  BOOST_DISPATCH_FUNCTION_IMPLEMENTATION(tag::arg_, arg, 1)
  BOOST_DISPATCH_FUNCTION_IMPLEMENTATION(tag::arg_, angle, 1)
} }

#endif
