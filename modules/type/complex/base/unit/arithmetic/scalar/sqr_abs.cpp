//==============================================================================
//         Copyright 2003 - 2012   LASMEA UMR 6602 CNRS/Univ. Clermont II
//         Copyright 2009 - 2012   LRI    UMR 8623 CNRS/Univ Paris Sud XI
//
//          Distributed under the Boost Software License, Version 1.0.
//                 See accompanying file LICENSE.txt or copy at
//                     http://www.boost.org/LICENSE_1_0.txt
//==============================================================================
#define NT2_UNIT_MODULE "nt2 boost.simd.arithmetic toolbox - sqr_abs/scalar Mode"

//////////////////////////////////////////////////////////////////////////////
// unit test behavior of boost.simd.arithmetic components in scalar mode
//////////////////////////////////////////////////////////////////////////////
/// created by jt the 30/11/2010
///
#include <nt2/arithmetic/include/functions/sqr_abs.hpp>
#include <nt2/include/constants/i.hpp>
#include <boost/type_traits/is_same.hpp>
#include <boost/dispatch/functor/meta/call.hpp>
#include <nt2/sdk/unit/tests.hpp>
#include <nt2/sdk/unit/module.hpp>
#include <nt2/constant/constant.hpp>


NT2_TEST_CASE_TPL ( sqr_abs_real__1_0,  BOOST_SIMD_REAL_TYPES)
{

  using nt2::sqr_abs;
  using nt2::tag::sqr_abs_;
  typedef typename boost::dispatch::meta::as_integer<T>::type iT;
  typedef typename boost::dispatch::meta::call<sqr_abs_(T)>::type r_t;
  typedef typename nt2::meta::scalar_of<r_t>::type sr_t;
  typedef typename nt2::meta::scalar_of<r_t>::type ssr_t;
  typedef typename std::complex<T> cT;
  typedef T wished_r_t;

  // return type conformity test
  NT2_TEST( (boost::is_same < r_t, wished_r_t >::value) );

  // std::cout << nt2::type_id(nt2::I<T>()) << std::endl;
  // specific values tests
   NT2_TEST_ULP_EQUAL(sqr_abs(cT(1)), T(1), 0);
   NT2_TEST_EQUAL(sqr_abs(cT(nt2::Inf<T>())), nt2::Inf<T>());
   NT2_TEST_EQUAL(sqr_abs(cT(nt2::Minf<T>())), nt2::Inf<T>());
   NT2_TEST_EQUAL(sqr_abs(cT(nt2::Mone<T>())), nt2::One<T>());
   NT2_TEST_EQUAL(sqr_abs(cT(nt2::Nan<T>())), nt2::Nan<T>());
   NT2_TEST_EQUAL(sqr_abs(cT(nt2::One<T>())), nt2::One<T>());
   NT2_TEST_EQUAL(sqr_abs(cT(nt2::Valmax<T>())), nt2::Inf<T>());
   NT2_TEST_EQUAL(sqr_abs(cT(nt2::Valmin<T>())), nt2::Inf<T>());
   NT2_TEST_EQUAL(sqr_abs(cT(nt2::Zero<T>())), nt2::Zero<T>());
   std::complex < T > a(1, 0);
   NT2_TEST_EQUAL(sqr_abs(a), nt2::One<T>());
   std::complex < T > b(1, 2);
   NT2_TEST_EQUAL(sqr_abs(b), nt2::Five<T>());
} // end of test for floating_

