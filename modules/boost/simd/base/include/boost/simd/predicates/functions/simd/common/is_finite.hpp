//==============================================================================
//         Copyright 2003 - 2011 LASMEA UMR 6602 CNRS/Univ. Clermont II
//         Copyright 2009 - 2011 LRI    UMR 8623 CNRS/Univ Paris Sud XI
//
//          Distributed under the Boost Software License, Version 1.0.
//                 See accompanying file LICENSE.txt or copy at
//                     http://www.boost.org/LICENSE_1_0.txt
//==============================================================================
#ifndef BOOST_SIMD_PREDICATES_FUNCTIONS_SIMD_COMMON_IS_FINITE_HPP_INCLUDED
#define BOOST_SIMD_PREDICATES_FUNCTIONS_SIMD_COMMON_IS_FINITE_HPP_INCLUDED

#include <boost/simd/predicates/functions/is_finite.hpp>
#include <boost/simd/include/functions/simd/minus.hpp>
#include <boost/simd/include/functions/simd/is_eqz.hpp>
#include <boost/simd/include/constants/true.hpp>
#include <boost/simd/sdk/meta/as_logical.hpp>
#include <boost/simd/sdk/config.hpp>

namespace boost { namespace simd { namespace ext
{
  BOOST_SIMD_FUNCTOR_IMPLEMENTATION ( boost::simd::tag::is_finite_, tag::cpu_, (A0)(X)
                                    , ((simd_<arithmetic_<A0>,X>))
                                    )
  {
    typedef typename meta::as_logical<A0>::type result_type;
    inline result_type operator()(const A0&) const
    {
      return boost::simd::True<result_type>();
    }
  };

  BOOST_SIMD_FUNCTOR_IMPLEMENTATION ( boost::simd::tag::is_finite_, tag::cpu_, (A0)(X)
                                    , ((simd_<floating_<A0>,X>))
                                    )
  {
    typedef typename meta::as_logical<A0>::type result_type;

    #ifdef BOOST_SIMD_NO_INFINITIES
    inline result_type operator()(const A0&) const { return True<result_type>(); }
    #else
    BOOST_SIMD_FUNCTOR_CALL(1) { return is_eqz(a0-a0); }
    #endif
  };
} } }

#endif
