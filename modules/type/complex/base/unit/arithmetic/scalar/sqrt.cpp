//==============================================================================
//         Copyright 2003 - 2012   LASMEA UMR 6602 CNRS/Univ. Clermont II
//         Copyright 2009 - 2012   LRI    UMR 8623 CNRS/Univ Paris Sud XI
//
//          Distributed under the Boost Software License, Version 1.0.
//                 See accompanying file LICENSE.txt or copy at
//                     http://www.boost.org/LICENSE_1_0.txt
//==============================================================================
#include <nt2/arithmetic/include/functions/sqrt.hpp>

#include <complex>
#include <nt2/sdk/complex/complex.hpp>

#include <nt2/include/functions/pure.hpp>
#include <nt2/include/functions/sqr.hpp>
#include <nt2/include/functions/plus.hpp>
#include <nt2/include/constants/i.hpp>
#include <boost/type_traits/is_same.hpp>
#include <boost/dispatch/functor/meta/call.hpp>
#include <nt2/sdk/unit/tests.hpp>
#include <nt2/sdk/unit/module.hpp>
#include <nt2/constant/constant.hpp>
#include <nt2/sdk/complex/meta/as_complex.hpp>
#include <nt2/sdk/complex/meta/as_real.hpp>
#include <nt2/sdk/complex/dry.hpp>

#include <complex>
#include <nt2/sdk/complex/complex.hpp>

NT2_TEST_CASE_TPL ( sqrt_real__1_0,  (double))//BOOST_SIMD_REAL_TYPES)
{

  using nt2::sqrt;
  using nt2::tag::sqrt_;
  typedef typename std::complex<T> cT;
  typedef typename boost::dispatch::meta::as_integer<T>::type iT;
  typedef typename boost::dispatch::meta::call<sqrt_(cT)>::type r_t;
  typedef typename nt2::meta::scalar_of<r_t>::type sr_t;
  typedef typename nt2::meta::scalar_of<r_t>::type ssr_t;
  typedef cT wished_r_t;

  // return type conformity test
  //  NT2_TEST( (boost::is_same < r_t, wished_r_t >::value) );

  // specific values tests
   NT2_TEST_ULP_EQUAL(nt2::sqrt(cT(1)), cT(1), 0);
   NT2_TEST_EQUAL(nt2::sqrt(cT(nt2::Inf<T>())), cT(nt2::Inf<T>()));
   NT2_TEST_EQUAL(nt2::sqrt(cT(nt2::Inf<T>(),nt2::Inf<T>())),cT(nt2::Inf<T>(),nt2::Inf<T>()));
   NT2_TEST_EQUAL(nt2::sqrt(cT(nt2::Nan<T>(),nt2::Nan<T>())),cT(nt2::Nan<T>(),nt2::Nan<T>()));
   NT2_TEST_EQUAL(nt2::sqrt(cT(nt2::Inf<T>(),nt2::Nan<T>())),cT(nt2::Nan<T>(),nt2::Nan<T>()));
   NT2_TEST_EQUAL(nt2::sqrt(cT(nt2::Zero<T>(),nt2::Inf<T>())),cT(nt2::Inf<T>(),nt2::Inf<T>()));
   NT2_TEST_EQUAL(nt2::sqrt(cT(nt2::Minf<T>())), cT(0, nt2::Inf<T>()));
   NT2_TEST_EQUAL(nt2::sqrt(cT(nt2::Mone<T>())), cT(0, nt2::One<T>()));
   NT2_TEST_EQUAL(nt2::sqrt(cT(nt2::Nan<T>())), cT(nt2::Nan<T>(),nt2::Nan<T>()));
   NT2_TEST_EQUAL(nt2::sqrt(cT(nt2::One<T>())), cT(nt2::One<T>()));
   NT2_TEST_EQUAL(nt2::sqrt(cT(nt2::Zero<T>())), cT(nt2::Zero<T>()));
   std::complex < T > a(1, 0);
   NT2_TEST_EQUAL(nt2::sqrt(a), cT(nt2::One<T>()));
   std::complex < T > b(nt2::Zero<T>(), nt2::Inf<T>());

   NT2_TEST_EQUAL(nt2::sqrt(nt2::pure(b)), cT(nt2::Inf<T>(), nt2::Inf<T>()));

  NT2_TEST_EQUAL(nt2::sqrt(cT(nt2::Zero<T>(),nt2::Zero<T>())), cT(nt2::Zero<T>(),nt2::Zero<T>()));
  NT2_TEST_EQUAL(nt2::sqrt(cT(nt2::Mzero<T>(),nt2::Zero<T>())),cT(nt2::Zero<T>(),nt2::Zero<T>()));
  NT2_TEST_EQUAL(nt2::sqrt(cT(nt2::Minf<T>(),nt2::Zero<T>())), cT(nt2::Zero<T>(),nt2::Inf<T>()));


  NT2_TEST_EQUAL(nt2::sqrt(cT(nt2::One<T>(), nt2::Inf<T>())), cT(nt2::Inf<T>(),nt2::Inf<T>()));
  NT2_TEST_EQUAL(nt2::sqrt(cT(nt2::Inf<T>(), nt2::Inf<T>())), cT(nt2::Inf<T>(),nt2::Inf<T>()));
  NT2_TEST_EQUAL(nt2::sqrt(cT(nt2::Minf<T>(),nt2::Inf<T>())), cT(nt2::Inf<T>(),nt2::Inf<T>()));
  NT2_TEST_EQUAL(nt2::sqrt(cT(nt2::Nan <T>(),nt2::Inf<T>())), cT(nt2::Nan<T>(),nt2::Nan<T>()));
  NT2_TEST_EQUAL(nt2::sqrt(cT(nt2::One<T>(), nt2::Nan<T>())), cT(nt2::Nan<T>(),nt2::Nan<T>()));
  NT2_TEST_EQUAL(nt2::sqrt(cT(nt2::Inf<T>(), nt2::Nan<T>())), cT(nt2::Nan<T>(),nt2::Nan<T>()));
  NT2_TEST_EQUAL(nt2::sqrt(cT(nt2::Minf<T>(),nt2::Nan<T>())), cT(nt2::Nan<T>(),nt2::Nan<T>()));
  NT2_TEST_EQUAL(nt2::sqrt(cT(nt2::Nan <T>(),nt2::Nan<T>())), cT(nt2::Nan<T>(),nt2::Nan<T>()));
  NT2_TEST_EQUAL(nt2::sqrt(cT(nt2::Minf<T>(),nt2::One<T>())), cT(nt2::Zero<T>(),nt2::Inf<T>()));
  NT2_TEST_EQUAL(nt2::sqrt(cT(nt2::Minf<T>(),nt2::Mone<T>())),cT(nt2::Zero<T>(),nt2::Minf<T>()));
  NT2_TEST_EQUAL(nt2::sqrt(cT(nt2::Inf<T>(),nt2::Nan<T>())),  cT(nt2::Nan<T>(),nt2::Nan<T>()));
  NT2_TEST_EQUAL(nt2::sqrt(cT(nt2::Nan<T>(),nt2::One<T>())),  cT(nt2::Nan<T>(),nt2::Nan<T>()));
  NT2_TEST_EQUAL(nt2::sqrt(cT(nt2::Nan<T>(),nt2::Nan<T>())),  cT(nt2::Nan<T>(),nt2::Nan<T>()));

  NT2_TEST_EQUAL(nt2::sqrt(cT(nt2::One<T>(), -nt2::Inf<T>())), cT(nt2::Inf<T>(),-nt2::Inf<T>()));
  NT2_TEST_EQUAL(nt2::sqrt(cT(nt2::Inf<T>(), -nt2::Inf<T>())), cT(nt2::Inf<T>(),-nt2::Inf<T>()));
  NT2_TEST_EQUAL(nt2::sqrt(cT(nt2::Minf<T>(),-nt2::Inf<T>())), cT(nt2::Inf<T>(),-nt2::Inf<T>()));
  NT2_TEST_EQUAL(nt2::sqrt(cT(nt2::Nan <T>(),-nt2::Inf<T>())), cT(nt2::Nan<T>(),-nt2::Nan<T>()));
  NT2_TEST_EQUAL(nt2::sqrt(cT(nt2::One<T>(), -nt2::Nan<T>())), cT(nt2::Nan<T>(),-nt2::Nan<T>()));
  NT2_TEST_EQUAL(nt2::sqrt(cT(nt2::Inf<T>(), -nt2::Nan<T>())), cT(nt2::Nan<T>(),-nt2::Nan<T>()));
  NT2_TEST_EQUAL(nt2::sqrt(cT(nt2::Minf<T>(),-nt2::Nan<T>())), cT(nt2::Nan<T>(),-nt2::Nan<T>()));
  NT2_TEST_EQUAL(nt2::sqrt(cT(nt2::Nan <T>(),-nt2::Nan<T>())), cT(nt2::Nan<T>(),-nt2::Nan<T>()));
  NT2_TEST_EQUAL(nt2::sqrt(cT(nt2::Minf<T>(),-nt2::One<T>())), cT(nt2::Zero<T>(),-nt2::Inf<T>()));
  NT2_TEST_EQUAL(nt2::sqrt(cT(nt2::Minf<T>(),-nt2::Mone<T>())),cT(nt2::Zero<T>(),-nt2::Minf<T>()));
  NT2_TEST_EQUAL(nt2::sqrt(cT(nt2::Inf<T>(), -nt2::Nan<T>())), cT(nt2::Nan<T>(),nt2::Nan<T>()));
  NT2_TEST_EQUAL(nt2::sqrt(cT(nt2::Nan<T>(), -nt2::One<T>())), cT(nt2::Nan<T>(),-nt2::Nan<T>()));
  NT2_TEST_EQUAL(nt2::sqrt(cT(nt2::Nan<T>(), -nt2::Nan<T>())), cT(nt2::Nan<T>(),-nt2::Nan<T>()));
  NT2_TEST_ULP_EQUAL(nt2::sqrt(cT(0, 2)), cT(1, 1), 1);

  for(T i=-5; i <=  T(5) ; i+= T(0.5))
    {
      for(T j =-5; j < T(5); j+= T(0.5))
        {
          std::cout << i << "+i*(" << j << ") -> " << nt2::sqrt(cT(i, j)) << std::endl;
          NT2_TEST_ULP_EQUAL(nt2::sqr(nt2::sqrt(cT(i, j))), cT(i, j), 10);
        }
    }
} // end of test for floating_

// csqrt(conj(z)) = conj(csqrt(z)).
//  csqrt((+/-)0 + i0) returns +0 + i0.
//  csqrt(x + i inf) returns +inf + i inf, for all x (including NaN).
//  csqrt(x + iNaN) returns NaN + iNaN and optionally raises the invalid floating-point exception, for finite x.
//  csqrt($B!](Binf + iy) returns +0 + i inf, for finite positive-signed y.
//  csqrt(+inf + iy) returns +inf + i0, for finite positive-signed y.
//  csqrt($B!](Binf + iNaN) returns NaN (+/-) i inf (where the sign of the imag part of the
// result is unspecified).
//  csqrt(+inf + iNaN) returns +inf + iNaN.
//  csqrt(NaN + iy) returns NaN + iNaN and optionally raises the invalid floating-point exception, for finite y.
//  csqrt(NaN + iNaN) returns NaN + iNaN.
