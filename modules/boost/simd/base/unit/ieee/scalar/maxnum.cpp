//==============================================================================
//         Copyright 2003 - 2012   LASMEA UMR 6602 CNRS/Univ. Clermont II
//         Copyright 2009 - 2012   LRI    UMR 8623 CNRS/Univ Paris Sud XI
//
//          Distributed under the Boost Software License, Version 1.0.
//                 See accompanying file LICENSE.txt or copy at
//                     http://www.boost.org/LICENSE_1_0.txt
//==============================================================================
#define NT2_UNIT_MODULE "nt2 boost.simd.ieee toolbox - maxnum/scalar Mode"

//////////////////////////////////////////////////////////////////////////////
// unit test behavior of boost.simd.ieee components in scalar mode
//////////////////////////////////////////////////////////////////////////////
/// created by jt the 04/12/2010
///
#include <boost/simd/ieee/include/functions/maxnum.hpp>
#include <boost/simd/sdk/simd/native.hpp>
#include <boost/simd/include/functions/max.hpp>

#include <boost/type_traits/is_same.hpp>
#include <boost/dispatch/functor/meta/call.hpp>
#include <nt2/sdk/unit/tests.hpp>
#include <nt2/sdk/unit/module.hpp>
#include <boost/simd/constant/constant.hpp>


NT2_TEST_CASE_TPL ( maxnum_real__2_0,  BOOST_SIMD_REAL_TYPES)
{

  using boost::simd::maxnum;
  using boost::simd::tag::maxnum_;
  typedef typename boost::dispatch::meta::as_integer<T>::type iT;
  typedef typename boost::dispatch::meta::call<maxnum_(T,T)>::type r_t;
  typedef typename boost::simd::meta::scalar_of<r_t>::type sr_t;
  typedef typename boost::simd::meta::scalar_of<r_t>::type ssr_t;
  typedef typename boost::common_type<T,T>::type wished_r_t;


  // return type conformity test
  NT2_TEST( (boost::is_same < r_t, wished_r_t >::value) );
  std::cout << std::endl;

  // specific values tests
  NT2_TEST_EQUAL(maxnum(boost::simd::Inf<T>(), boost::simd::Inf<T>()), boost::simd::Inf<r_t>());
  NT2_TEST_EQUAL(maxnum(boost::simd::Minf<T>(), boost::simd::Minf<T>()), boost::simd::Minf<r_t>());
  NT2_TEST_EQUAL(maxnum(boost::simd::Mone<T>(), boost::simd::Mone<T>()), boost::simd::Mone<r_t>());
  NT2_TEST_EQUAL(maxnum(boost::simd::Nan<T>(), boost::simd::Nan<T>()), boost::simd::Nan<r_t>());
  NT2_TEST_EQUAL(maxnum(boost::simd::Nan<T>(),boost::simd::One<T>()), boost::simd::One<r_t>());
  NT2_TEST_EQUAL(maxnum(boost::simd::One<T>(), boost::simd::One<T>()), boost::simd::One<r_t>());
  NT2_TEST_EQUAL(maxnum(boost::simd::One<T>(),boost::simd::Nan<T>()), boost::simd::One<r_t>());
  NT2_TEST_EQUAL(maxnum(boost::simd::Zero<T>(), boost::simd::Zero<T>()), boost::simd::Zero<r_t>());
} // end of test for floating_

NT2_TEST_CASE_TPL ( maxnum_unsigned_int__2_0,  BOOST_SIMD_UNSIGNED_TYPES)
{

  using boost::simd::maxnum;
  using boost::simd::tag::maxnum_;
  typedef typename boost::dispatch::meta::as_integer<T>::type iT;
  typedef typename boost::dispatch::meta::call<maxnum_(T,T)>::type r_t;
  typedef typename boost::simd::meta::scalar_of<r_t>::type sr_t;
  typedef typename boost::simd::meta::scalar_of<r_t>::type ssr_t;
  typedef typename boost::common_type<T,T>::type wished_r_t;


  // return type conformity test
  NT2_TEST( (boost::is_same < r_t, wished_r_t >::value) );
  std::cout << std::endl;

  // specific values tests
  NT2_TEST_EQUAL(maxnum(boost::simd::One<T>(), boost::simd::One<T>()), boost::simd::One<r_t>());
  NT2_TEST_EQUAL(maxnum(boost::simd::Zero<T>(), boost::simd::Zero<T>()), boost::simd::Zero<r_t>());
} // end of test for unsigned_int_

NT2_TEST_CASE_TPL ( maxnum_signed_int__2_0,  BOOST_SIMD_INTEGRAL_SIGNED_TYPES)
{

  using boost::simd::maxnum;
  using boost::simd::tag::maxnum_;
  typedef typename boost::dispatch::meta::as_integer<T>::type iT;
  typedef typename boost::dispatch::meta::call<maxnum_(T,T)>::type r_t;
  typedef typename boost::simd::meta::scalar_of<r_t>::type sr_t;
  typedef typename boost::simd::meta::scalar_of<r_t>::type ssr_t;
  typedef typename boost::common_type<T,T>::type wished_r_t;


  // return type conformity test
  NT2_TEST( (boost::is_same < r_t, wished_r_t >::value) );
  std::cout << std::endl;

  // specific values tests
  NT2_TEST_EQUAL(maxnum(boost::simd::Mone<T>(), boost::simd::Mone<T>()), boost::simd::Mone<r_t>());
  NT2_TEST_EQUAL(maxnum(boost::simd::One<T>(), boost::simd::One<T>()), boost::simd::One<r_t>());
  NT2_TEST_EQUAL(maxnum(boost::simd::Zero<T>(), boost::simd::Zero<T>()), boost::simd::Zero<r_t>());
} // end of test for signed_int_
