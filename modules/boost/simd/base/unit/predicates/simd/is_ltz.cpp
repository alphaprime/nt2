//==============================================================================
//         Copyright 2003 - 2012   LASMEA UMR 6602 CNRS/Univ. Clermont II
//         Copyright 2009 - 2012   LRI    UMR 8623 CNRS/Univ Paris Sud XI
//
//          Distributed under the Boost Software License, Version 1.0.
//                 See accompanying file LICENSE.txt or copy at
//                     http://www.boost.org/LICENSE_1_0.txt
//==============================================================================
#include <boost/simd/predicates/include/functions/is_ltz.hpp>
#include <boost/simd/sdk/simd/native.hpp>
#include <boost/simd/sdk/simd/logical.hpp>
#include <boost/simd/include/functions/negate.hpp>
#include <boost/type_traits/is_same.hpp>
#include <boost/dispatch/functor/meta/call.hpp>
#include <nt2/sdk/unit/tests.hpp>
#include <nt2/sdk/unit/module.hpp>
#include <boost/simd/constant/constant.hpp>

NT2_TEST_CASE_TPL ( is_ltz_real__1_0,  BOOST_SIMD_SIMD_REAL_TYPES)
{
  using boost::simd::is_ltz;
  using boost::simd::tag::is_ltz_;
  using boost::simd::native;
  using boost::simd::meta::cardinal_of;
  typedef BOOST_SIMD_DEFAULT_EXTENSION  ext_t;
  typedef typename boost::dispatch::meta::upgrade<T>::type   u_t;
  typedef native<T,ext_t>                        n_t;
  typedef n_t                                     vT;
  typedef typename boost::dispatch::meta::as_integer<T>::type iT;
  typedef native<iT,ext_t>                       ivT;
  typedef typename boost::dispatch::meta::call<is_ltz_(vT)>::type r_t;
  typedef typename boost::simd::meta::scalar_of<r_t>::type sr_t;
  typedef typename boost::simd::meta::scalar_of<r_t>::type ssr_t;

  // specific values tests
  NT2_TEST_EQUAL(is_ltz(-boost::simd::Zero<vT>())[0], boost::simd::False<sr_t>());
  NT2_TEST_EQUAL(is_ltz(boost::simd::Half<vT>())[0], boost::simd::False<sr_t>());
  NT2_TEST_EQUAL(is_ltz(boost::simd::Inf<vT>())[0], boost::simd::False<sr_t>());
  NT2_TEST_EQUAL(is_ltz(boost::simd::Minf<vT>())[0], boost::simd::True<sr_t>());
  NT2_TEST_EQUAL(is_ltz(boost::simd::Mone<vT>())[0], boost::simd::True<sr_t>());
  NT2_TEST_EQUAL(is_ltz(boost::simd::Nan<vT>())[0], boost::simd::False<sr_t>());
  NT2_TEST_EQUAL(is_ltz(boost::simd::One<vT>())[0], boost::simd::False<sr_t>());
  NT2_TEST_EQUAL(is_ltz(boost::simd::Quarter<vT>())[0], boost::simd::False<sr_t>());
  NT2_TEST_EQUAL(is_ltz(boost::simd::Two<vT>())[0], boost::simd::False<sr_t>());
  NT2_TEST_EQUAL(is_ltz(boost::simd::Zero<vT>())[0], boost::simd::False<sr_t>());
} // end of test for floating_

NT2_TEST_CASE_TPL ( is_ltz_integer__1_0, BOOST_SIMD_SIMD_INTEGRAL_SIGNED_TYPES)
{
  using boost::simd::is_ltz;
  using boost::simd::tag::is_ltz_;
  using boost::simd::native;
  using boost::simd::meta::cardinal_of;
  typedef BOOST_SIMD_DEFAULT_EXTENSION  ext_t;
  typedef typename boost::dispatch::meta::upgrade<T>::type   u_t;
  typedef native<T,ext_t>                        n_t;
  typedef n_t                                     vT;
  typedef typename boost::dispatch::meta::as_integer<T>::type iT;
  typedef native<iT,ext_t>                       ivT;
  typedef typename boost::dispatch::meta::call<is_ltz_(vT)>::type r_t;
  typedef typename boost::simd::meta::scalar_of<r_t>::type sr_t;
  typedef typename boost::simd::meta::scalar_of<r_t>::type ssr_t;
  typedef typename r_t::value_type vsr_t;

  // specific values tests
  NT2_TEST_EQUAL(is_ltz(boost::simd::One<vT>())[0], vsr_t(false));
  NT2_TEST_EQUAL(is_ltz(boost::simd::Two<vT>())[0], vsr_t(false));
  NT2_TEST_EQUAL(is_ltz(boost::simd::Zero<vT>())[0], vsr_t(false));
  NT2_TEST_EQUAL(is_ltz(boost::simd::Mone<vT>())[0], vsr_t(true));
} // end of test for integral_
