//==============================================================================
//         Copyright 2003 - 2011 LASMEA UMR 6602 CNRS/Univ. Clermont II
//         Copyright 2009 - 2011 LRI    UMR 8623 CNRS/Univ Paris Sud XI
//
//          Distributed under the Boost Software License, Version 1.0.
//                 See accompanying file LICENSE.txt or copy at
//                     http://www.boost.org/LICENSE_1_0.txt
//==============================================================================
#ifndef NT2_HYPERBOLIC_FUNCTIONS_GENERIC_SINHCOSH_HPP_INCLUDED
#define NT2_HYPERBOLIC_FUNCTIONS_GENERIC_SINHCOSH_HPP_INCLUDED
#include <nt2/hyperbolic/functions/sinhcosh.hpp>
#include <boost/fusion/include/std_pair.hpp>
#include <nt2/trigonometric/functions/scalar/impl/trigo.hpp>
#include <nt2/trigonometric/functions/simd/common/impl/trigo.hpp>
#include <boost/simd/sdk/simd/meta/is_native.hpp>

namespace nt2 { namespace ext
{

  NT2_FUNCTOR_IMPLEMENTATION( sinhcosh_
                            , tag::cpu_
                            , (A0)
                            , ((generic_< floating_<A0> >))
                              ((generic_< floating_<A0> >))
                            )
  {
    typedef A0 result_type;
    typedef typename boost::simd::meta::is_native<A0>::type is_native_t;
    BOOST_FORCEINLINE result_type operator()(A0 const& a0,A0 & a2) const
    {
      A0 a1;
      sinhcosh(tofloat(a0),a1, a2);
      return a1;
    }
  };

  NT2_FUNCTOR_IMPLEMENTATION( sinhcosh_, tag::cpu_
                            , (A0)
                            , (generic_< floating_<A0> >)
                            )
  {
    typedef std::pair<A0, A0>                      result_type;
    typedef typename boost::simd::meta::is_native<A0>::type     is_native_t;

    BOOST_FORCEINLINE result_type operator()(A0 const& a0) const
    {
      result_type res;
      sinhcosh(tofloat(a0), res.first, res.second);
      return res;
    }
  };

//   NT2_FUNCTOR_IMPLEMENTATION( sinhcosh_, tag::cpu_
//                             , (A0)
//                             , ((generic_< floating_<A0> >))
//                               ((generic_< floating_<A0> >))
//                               ((generic_< floating_<A0> >))
//                             )
//   {
//     typedef void result_type;
//     typedef typename boost::simd::meta::is_native<A0>::type is_native_t;

//     BOOST_FORCEINLINE result_type operator()(A0 const& a0,A0 & a1,A0 & a2) const
//     {
//       typedef typename meta::as_logical<A1>::type ltype;
//       a2 =  nt2::abs(a0);
//       a1 = a0;
//       if (a2 == Inf<A0>()) return;
//       const A0 u = expm1(a2);
//       const A0 up1 = oneplus(u);
//       const A0 tmp =u/up1;
//       a1 = negif(is_negative(a0), Half<A0>()*tmp*(oneplus(up1)));
//       a2 = oneplus(Half<A0>()*tmp*u);
//     }
//   };

} }

#endif
