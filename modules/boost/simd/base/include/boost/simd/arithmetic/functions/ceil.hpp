//==============================================================================
//         Copyright 2003 - 2012   LASMEA UMR 6602 CNRS/Univ. Clermont II
//         Copyright 2009 - 2012   LRI    UMR 8623 CNRS/Univ Paris Sud XI
//
//          Distributed under the Boost Software License, Version 1.0.
//                 See accompanying file LICENSE.txt or copy at
//                     http://www.boost.org/LICENSE_1_0.txt
//==============================================================================
#ifndef BOOST_SIMD_ARITHMETIC_FUNCTIONS_CEIL_HPP_INCLUDED
#define BOOST_SIMD_ARITHMETIC_FUNCTIONS_CEIL_HPP_INCLUDED
#include <boost/simd/include/functor.hpp>
#include <boost/dispatch/include/functor.hpp>

namespace boost { namespace simd { namespace tag
  {
    /*!
      @brief  ceil generic tag

      Represents the ceil function in generic contexts.

      @par Models:
      Hierarchy
    **/
    struct ceil_ : ext::elementwise_<ceil_>
    {
      /// @brief Parent hierarchy
      typedef ext::elementwise_<ceil_> parent;
    };
  }
  /*!
    Computes the ceil of its parameter.

    @par semantic:
    For any given value @c x of type @c T:

    @code
    T r = ceil(x);
    @endcode

    smallest integral value of type @c T greater or equal to @c x.

    @par Note:

    The function always returns a value of the same type as the entry.

    @param  x

    @return      an integral value of the same type as the input.

  **/
  BOOST_DISPATCH_FUNCTION_IMPLEMENTATION(tag::ceil_, ceil, 1)
} }

#endif
