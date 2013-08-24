//==============================================================================
//         Copyright 2003 - 2012   LASMEA UMR 6602 CNRS/Univ. Clermont II
//         Copyright 2009 - 2012   LRI    UMR 8623 CNRS/Univ Paris Sud XI
//
//          Distributed under the Boost Software License, Version 1.0.
//                 See accompanying file LICENSE.txt or copy at
//                     http://www.boost.org/LICENSE_1_0.txt
//==============================================================================
#define NT2_UNIT_MODULE "nt2 boost.simd.operator toolbox - is_not_equal/scalar Mode"

//////////////////////////////////////////////////////////////////////////////
// unit test behavior of boost.simd.operator components in scalar mode
//////////////////////////////////////////////////////////////////////////////
/// created  by jt the 18/02/2011
///
#include <nt2/operator/include/functions/is_not_equal.hpp>
#include <boost/simd/sdk/simd/logical.hpp>
#include <boost/type_traits/is_same.hpp>
#include <boost/dispatch/functor/meta/call.hpp>
#include <nt2/sdk/unit/tests.hpp>
#include <nt2/sdk/unit/module.hpp>
#include <nt2/constant/constant.hpp>

NT2_TEST_CASE_TPL ( is_not_equal_real__2_0,  BOOST_SIMD_REAL_TYPES)
{

  using nt2::is_not_equal;
  using nt2::tag::is_not_equal_;
  typedef typename boost::dispatch::meta::as_integer<T>::type iT;
  typedef typename boost::dispatch::meta::call<is_not_equal_(T,T)>::type r_t;
  typedef typename nt2::meta::scalar_of<r_t>::type sr_t;
  typedef typename nt2::meta::scalar_of<r_t>::type ssr_t;
  typedef nt2::logical<T> wished_r_t;
  typedef std::complex<T> cT;

  // return type conformity test
  NT2_TEST( (boost::is_same < r_t, wished_r_t >::value) );
  std::cout << std::endl;



  // specific values tests
  NT2_TEST_EQUAL(is_not_equal(cT(nt2::Inf<T>()),  cT(nt2::Inf<T>())),  r_t(false));
  NT2_TEST_EQUAL(is_not_equal(cT(nt2::Minf<T>()), cT(nt2::Minf<T>())), r_t(false));
  NT2_TEST_EQUAL(is_not_equal(cT(nt2::Nan<T>()),  cT(nt2::Nan<T>())),  r_t(true));
  NT2_TEST_EQUAL(is_not_equal(cT(nt2::One<T>()),  cT(nt2::Zero<T>())), r_t(true));
  NT2_TEST_EQUAL(is_not_equal(cT(nt2::Zero<T>()), cT(nt2::Zero<T>())), r_t(false));
  NT2_TEST_EQUAL(is_not_equal(cT(0, 1), cT(0, 1)), r_t(false));
  NT2_TEST_EQUAL(is_not_equal(cT(1, 0), T(1))    , r_t(false));
  NT2_TEST_EQUAL(is_not_equal(cT(0, 2), cT(0, 1)), r_t(true));
} // end of test for floating_
