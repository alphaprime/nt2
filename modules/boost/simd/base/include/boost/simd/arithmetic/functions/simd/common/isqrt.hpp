//==============================================================================
//         Copyright 2003 - 2011 LASMEA UMR 6602 CNRS/Univ. Clermont II
//         Copyright 2009 - 2011 LRI    UMR 8623 CNRS/Univ Paris Sud XI
//
//          Distributed under the Boost Software License, Version 1.0.
//                 See accompanying file LICENSE.txt or copy at
//                     http://www.boost.org/LICENSE_1_0.txt
//==============================================================================
#ifndef BOOST_SIMD_ARITHMETIC_FUNCTIONS_SIMD_COMMON_ISQRT_HPP_INCLUDED
#define BOOST_SIMD_ARITHMETIC_FUNCTIONS_SIMD_COMMON_ISQRT_HPP_INCLUDED

#include <boost/simd/arithmetic/functions/isqrt.hpp>
#include <boost/simd/include/functions/simd/sqrt.hpp>
#include <boost/simd/include/functions/simd/toints.hpp>
#include <boost/dispatch/meta/as_integer.hpp>

namespace boost { namespace simd { namespace ext
{
  BOOST_SIMD_FUNCTOR_IMPLEMENTATION(boost::simd::tag::isqrt_, tag::cpu_,
                       (A0)(X),
                       ((simd_< floating_<A0>, X >))
                      )
  {
    typedef typename dispatch::meta::as_integer<A0>::type result_type;
    BOOST_SIMD_FUNCTOR_CALL_REPEAT(1)
    {
      return boost::simd::toints(boost::simd::sqrt(a0));
    }
  };
} } }

#endif
