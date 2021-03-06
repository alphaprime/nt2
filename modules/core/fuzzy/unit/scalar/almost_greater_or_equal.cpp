//==============================================================================
//         Copyright 2003 - 2012   LASMEA UMR 6602 CNRS/Univ. Clermont II
//         Copyright 2009 - 2012   LRI    UMR 8623 CNRS/Univ Paris Sud XI
//
//          Distributed under the Boost Software License, Version 1.0.
//                 See accompanying file LICENSE.txt or copy at
//                     http://www.boost.org/LICENSE_1_0.txt
//==============================================================================
#define NT2_UNIT_MODULE "nt2 fuzzy toolbox - almost_greater_or_equal/scalar Mode"

//////////////////////////////////////////////////////////////////////////////
// unit test behavior of fuzzy components in scalar mode
//////////////////////////////////////////////////////////////////////////////
/// created  by jt the 04/03/2011
///
#include <nt2/fuzzy/include/functions/almost_greater_or_equal.hpp>
#include <nt2/sdk/simd/logical.hpp>

#include <boost/type_traits/is_same.hpp>
#include <nt2/sdk/functor/meta/call.hpp>
#include <nt2/sdk/meta/as_integer.hpp>
#include <nt2/sdk/meta/as_floating.hpp>
#include <nt2/sdk/meta/as_signed.hpp>
#include <nt2/sdk/meta/upgrade.hpp>
#include <nt2/sdk/meta/downgrade.hpp>
#include <nt2/sdk/meta/scalar_of.hpp>
#include <boost/dispatch/meta/as_floating.hpp>
#include <boost/type_traits/common_type.hpp>
#include <nt2/sdk/unit/tests.hpp>
#include <nt2/sdk/unit/module.hpp>

#include <nt2/constant/constant.hpp>


NT2_TEST_CASE_TPL ( almost_greater_or_equal_real__3_0,  NT2_REAL_TYPES)
{

  using nt2::almost_greater_or_equal;
  using nt2::tag::almost_greater_or_equal_;
  typedef typename nt2::meta::as_integer<T>::type iT;
  typedef typename nt2::meta::call<almost_greater_or_equal_(T,T,iT)>::type r_t;
  typedef typename nt2::meta::scalar_of<r_t>::type ssr_t;
  typedef typename nt2::meta::upgrade<T>::type u_t;
  typedef typename nt2::meta::as_logical<T>::type wished_r_t;


  // return type conformity test
  NT2_TEST( (boost::is_same < r_t, wished_r_t >::value) );
  std::cout << std::endl;
  double ulpd;
  ulpd=0.0;


  // specific values tests
  NT2_TEST_EQUAL(almost_greater_or_equal(T(0),T(0),iT(1)), nt2::True<r_t>());
  NT2_TEST_EQUAL(almost_greater_or_equal(T(0),T(1),iT(1)), nt2::False<r_t>());
} // end of test for floating_

NT2_TEST_CASE_TPL ( almost_greater_or_equal_signed_int__3_0,  NT2_INTEGRAL_SIGNED_TYPES)
{

  using nt2::almost_greater_or_equal;
  using nt2::tag::almost_greater_or_equal_;
  typedef typename nt2::meta::as_integer<T>::type iT;
  typedef typename nt2::meta::call<almost_greater_or_equal_(T,T,iT)>::type r_t;
  typedef typename nt2::meta::scalar_of<r_t>::type ssr_t;
  typedef typename nt2::meta::upgrade<T>::type u_t;
  typedef typename nt2::meta::as_logical<T>::type wished_r_t;


  // return type conformity test
  NT2_TEST( (boost::is_same < r_t, wished_r_t >::value) );
  std::cout << std::endl;
  double ulpd;
  ulpd=0.0;


  // specific values tests
  NT2_TEST_EQUAL(almost_greater_or_equal(T(0),T(0),iT(1)), nt2::True<r_t>());
  NT2_TEST_EQUAL(almost_greater_or_equal(T(0),T(1),iT(1)), nt2::True<r_t>());
} // end of test for signed_int_

NT2_TEST_CASE_TPL ( almost_greater_or_equal_unsigned_int__3_0,  NT2_UNSIGNED_TYPES)
{

  using nt2::almost_greater_or_equal;
  using nt2::tag::almost_greater_or_equal_;
  typedef typename nt2::meta::as_integer<T>::type iT;
  typedef typename nt2::meta::call<almost_greater_or_equal_(T,T,iT)>::type r_t;
  typedef typename nt2::meta::scalar_of<r_t>::type ssr_t;
  typedef typename nt2::meta::upgrade<T>::type u_t;
  typedef typename nt2::meta::as_logical<T>::type wished_r_t;


  // return type conformity test
  NT2_TEST( (boost::is_same < r_t, wished_r_t >::value) );
  std::cout << std::endl;
  double ulpd;
  ulpd=0.0;


  // specific values tests
  NT2_TEST_EQUAL(almost_greater_or_equal(T(0),T(0),iT(1)), nt2::True<r_t>());
  NT2_TEST_EQUAL(almost_greater_or_equal(T(0),T(1),iT(1)), nt2::True<r_t>());
} // end of test for unsigned_int_
