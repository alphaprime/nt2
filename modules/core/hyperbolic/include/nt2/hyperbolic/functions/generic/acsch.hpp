//==============================================================================
//         Copyright 2003 - 2011 LASMEA UMR 6602 CNRS/Univ. Clermont II
//         Copyright 2009 - 2011 LRI    UMR 8623 CNRS/Univ Paris Sud XI
//
//          Distributed under the Boost Software License, Version 1.0.
//                 See accompanying file LICENSE.txt or copy at
//                     http://www.boost.org/LICENSE_1_0.txt
//==============================================================================
#ifndef NT2_HYPERBOLIC_FUNCTIONS_GENERIC_ACSCH_HPP_INCLUDED
#define NT2_HYPERBOLIC_FUNCTIONS_GENERIC_ACSCH_HPP_INCLUDED

#include <nt2/hyperbolic/functions/acsch.hpp>
#include <nt2/include/functions/rec.hpp>
#include <nt2/include/functions/asinh.hpp>
#include <nt2/include/functions/is_eqz.hpp>
#include <nt2/include/functions/if_else.hpp>
#include <nt2/include/functions/if_allbits_else.hpp>
#include <nt2/include/functions/bitwise_or.hpp>
#include <nt2/include/constants/nan.hpp>
#include <nt2/include/functions/simd/tofloat.hpp>

namespace nt2 { namespace ext
{
  NT2_FUNCTOR_IMPLEMENTATION( nt2::tag::acsch_, tag::cpu_
                            , (A0)
                            , (generic_< arithmetic_<A0> >)
                            )
  {
    typedef typename boost::dispatch::meta::as_floating<A0>::type result_type;
    NT2_FUNCTOR_CALL(1)
    {
      result_type a = nt2::tofloat(a0);
      result_type r = nt2::asinh(nt2::rec(a));
#ifndef BOOST_SIMD_NO_INVALIDS
      return r;
#else
      return if_else(is_eqz(a0), bitwise_or(a, nt2::Inf<result_type>()), r);
#endif
    }
  };

  NT2_FUNCTOR_IMPLEMENTATION( nt2::tag::acsch_, tag::cpu_
                            , (A0)
                            , (generic_< unspecified_<A0> >)
                            )
  {
    typedef typename boost::dispatch::meta::as_floating<A0>::type result_type;
    NT2_FUNCTOR_CALL(1)
    {
      result_type r = nt2::asinh(nt2::rec(a0));
#ifndef BOOST_SIMD_NO_INVALIDS
      return r;
#else
      return if_nan_else(is_eqz(a0), r);
#endif
    }
  };
} }

#endif
