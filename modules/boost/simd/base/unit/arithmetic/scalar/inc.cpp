//==============================================================================
//         Copyright 2003 - 2012   LASMEA UMR 6602 CNRS/Univ. Clermont II
//         Copyright 2009 - 2012   LRI    UMR 8623 CNRS/Univ Paris Sud XI
//
//          Distributed under the Boost Software License, Version 1.0.
//                 See accompanying file LICENSE.txt or copy at
//                     http://www.boost.org/LICENSE_1_0.txt
//==============================================================================
#define NT2_UNIT_MODULE "nt2 boost.simd.arithmetic toolbox - inc/scalar Mode"

//////////////////////////////////////////////////////////////////////////////
// unit test behavior of boost.simd.arithmetic components in scalar mode
//////////////////////////////////////////////////////////////////////////////

#include <boost/simd/arithmetic/include/functions/inc.hpp>
#include <boost/simd/sdk/simd/native.hpp>
#include <boost/type_traits/is_same.hpp>
#include <boost/simd/constant/constant.hpp>

#include <nt2/sdk/unit/module.hpp>
#include <nt2/sdk/unit/tests/basic.hpp>
#include <nt2/sdk/unit/tests/relation.hpp>

NT2_TEST_CASE_TPL ( inc_signed_int__2_0,  BOOST_SIMD_INTEGRAL_SIGNED_TYPES)
{
  using boost::simd::inc;
  using boost::simd::tag::inc_;
  typedef typename boost::dispatch::meta::call<inc_(T)>::type r_t;
  typedef typename boost::simd::meta::scalar_of<r_t>::type sr_t;
  typedef typename boost::simd::meta::scalar_of<r_t>::type ssr_t;
  typedef T wished_r_t;


  // return type conformity test
  NT2_TEST( (boost::is_same < r_t, wished_r_t >::value) );
  std::cout << std::endl;

  // specific values tests
  NT2_TEST_EQUAL(inc(boost::simd::Mone<T>()), boost::simd::Zero<T>());
  NT2_TEST_EQUAL(inc(boost::simd::One<T>()), boost::simd::Two<T>());
  NT2_TEST_EQUAL(inc(boost::simd::Valmax<T>()), boost::simd::Valmin<T>());
  NT2_TEST_EQUAL(inc(boost::simd::Zero<T>()), boost::simd::One<T>());
}

NT2_TEST_CASE_TPL ( inc_unsigned_int__2_0,  BOOST_SIMD_UNSIGNED_TYPES)
{
  using boost::simd::inc;
  using boost::simd::tag::inc_;
  typedef typename boost::dispatch::meta::call<inc_(T)>::type r_t;
  typedef typename boost::simd::meta::scalar_of<r_t>::type sr_t;
  typedef typename boost::simd::meta::scalar_of<r_t>::type ssr_t;
  typedef T wished_r_t;


  // return type conformity test
  NT2_TEST( (boost::is_same < r_t, wished_r_t >::value) );
  std::cout << std::endl;

  // specific values tests
  NT2_TEST_EQUAL(inc(boost::simd::One<T>()), boost::simd::Two<T>());
  NT2_TEST_EQUAL(inc(boost::simd::Valmax<T>()), boost::simd::Zero<T>());
  NT2_TEST_EQUAL(inc(boost::simd::Zero<T>()), boost::simd::One<T>());
}

NT2_TEST_CASE_TPL( inc_floating, BOOST_SIMD_REAL_TYPES)
{
  using boost::simd::inc;
  using boost::simd::tag::inc_;
  typedef typename boost::dispatch::meta::call<inc_(T)>::type r_t;
  typedef typename boost::simd::meta::scalar_of<r_t>::type sr_t;
  typedef typename boost::simd::meta::scalar_of<r_t>::type ssr_t;
  typedef T wished_r_t;


  // return type conformity test
  NT2_TEST( (boost::is_same < r_t, wished_r_t >::value) );
  std::cout << std::endl;

  // specific values tests
  NT2_TEST_EQUAL(inc(boost::simd::Mone<T>()), boost::simd::Zero<T>());
  NT2_TEST_EQUAL(inc(boost::simd::One<T>()), boost::simd::Two<T>());
  NT2_TEST_EQUAL(inc(boost::simd::Valmax<T>()), boost::simd::Valmax<T>());
  NT2_TEST_EQUAL(inc(boost::simd::Zero<T>()), boost::simd::One<T>());
}
