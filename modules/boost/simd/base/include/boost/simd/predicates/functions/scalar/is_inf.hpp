//==============================================================================
//         Copyright 2003 - 2011 LASMEA UMR 6602 CNRS/Univ. Clermont II
//         Copyright 2009 - 2011 LRI    UMR 8623 CNRS/Univ Paris Sud XI
//
//          Distributed under the Boost Software License, Version 1.0.
//                 See accompanying file LICENSE.txt or copy at
//                     http://www.boost.org/LICENSE_1_0.txt
//==============================================================================
#ifndef BOOST_SIMD_PREDICATES_FUNCTIONS_SCALAR_IS_INF_HPP_INCLUDED
#define BOOST_SIMD_PREDICATES_FUNCTIONS_SCALAR_IS_INF_HPP_INCLUDED

#include <boost/simd/predicates/functions/is_inf.hpp>
#include <boost/simd/include/functions/scalar/abs.hpp>
#include <boost/simd/include/constants/inf.hpp>
#include <boost/simd/include/constants/false.hpp>
#include <boost/simd/sdk/meta/as_logical.hpp>
#include <boost/simd/sdk/config.hpp>

namespace boost { namespace simd { namespace ext
{
  BOOST_SIMD_FUNCTOR_IMPLEMENTATION( boost::simd::tag::is_inf_, tag::cpu_
                            , (A0)
                            , (scalar_< fundamental_<A0> >)
                            )
  {
    typedef typename meta::as_logical<A0>::type result_type;
    inline result_type operator()(A0 const&) const
    {
      return boost::simd::False<result_type>();
    }
  };

  BOOST_SIMD_FUNCTOR_IMPLEMENTATION( boost::simd::tag::is_inf_, tag::cpu_
                            , (A0)
                            , (scalar_< floating_<A0> >)
                            )
  {
    typedef typename meta::as_logical<A0>::type result_type;
    #ifdef BOOST_SIMD_NO_INFINITIES
    inline result_type operator()(const A0&) const { return False<result_type>(); }
    #else
    BOOST_SIMD_FUNCTOR_CALL(1) { return result_type(boost::simd::abs(a0) == boost::simd::Inf<A0>());}
    #endif
  };
} } }


#endif
