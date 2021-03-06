//==============================================================================
//         Copyright 2003 - 2012   LASMEA UMR 6602 CNRS/Univ. Clermont II
//         Copyright 2009 - 2012   LRI    UMR 8623 CNRS/Univ Paris Sud XI
//
//          Distributed under the Boost Software License, Version 1.0.
//                 See accompanying file LICENSE.txt or copy at
//                     http://www.boost.org/LICENSE_1_0.txt
//==============================================================================
#include <boost/simd/reduction/include/functions/first.hpp>
#include <boost/simd/sdk/simd/native.hpp>
#include <boost/type_traits/is_same.hpp>
#include <boost/dispatch/functor/meta/call.hpp>
#include <nt2/sdk/unit/tests.hpp>
#include <nt2/sdk/unit/module.hpp>
#include <boost/simd/constant/constant.hpp>

NT2_TEST_CASE_TPL ( first_real__1_0,  BOOST_SIMD_SIMD_REAL_TYPES)
{
  using boost::simd::first;
  using boost::simd::tag::first_;
  using boost::simd::native;
  using boost::simd::meta::cardinal_of;
  typedef typename boost::dispatch::meta::scalar_of<T>::type sT;
  typedef BOOST_SIMD_DEFAULT_EXTENSION  ext_t;
  typedef typename boost::dispatch::meta::upgrade<T>::type   u_t;
  typedef native<T,ext_t>                        n_t;
  typedef n_t                                     vT;
  typedef typename boost::dispatch::meta::as_integer<T>::type iT;
  typedef native<iT,ext_t>                       ivT;
  typedef typename boost::dispatch::meta::call<first_(vT)>::type r_t;
  typedef typename boost::simd::meta::scalar_of<r_t>::type sr_t;
  typedef typename boost::simd::meta::scalar_of<r_t>::type ssr_t;

  // specific values tests
  NT2_TEST_EQUAL(first(boost::simd::Inf<vT>()), boost::simd::Inf<sr_t>());
  NT2_TEST_EQUAL(first(boost::simd::Minf<vT>()), boost::simd::Minf<sr_t>());
  NT2_TEST_EQUAL(first(boost::simd::Mone<vT>()), boost::simd::Mone<sr_t>());
  NT2_TEST_EQUAL(first(boost::simd::Nan<vT>()), boost::simd::Nan<sr_t>());
  NT2_TEST_EQUAL(first(boost::simd::One<vT>()), boost::simd::One<sr_t>());
  NT2_TEST_EQUAL(first(boost::simd::Zero<vT>()), boost::simd::Zero<sr_t>());
  NT2_TEST_EQUAL(first(boost::simd::Ten <vT>()), boost::simd::Ten <sr_t>());
} // end of test for floating_
NT2_TEST_CASE_TPL ( first_int__1_0,  BOOST_SIMD_SIMD_INTEGRAL_TYPES)//(int32_t))
{
  using boost::simd::first;
  using boost::simd::tag::first_;
  using boost::simd::native;
  using boost::simd::meta::cardinal_of;
  typedef typename boost::dispatch::meta::scalar_of<T>::type sT;
  typedef BOOST_SIMD_DEFAULT_EXTENSION  ext_t;
  typedef typename boost::dispatch::meta::upgrade<T>::type   u_t;
  typedef native<T,ext_t>                        n_t;
  typedef n_t                                     vT;
  typedef typename boost::dispatch::meta::as_integer<T>::type iT;
  typedef native<iT,ext_t>                       ivT;
  typedef typename boost::dispatch::meta::call<first_(vT)>::type r_t;
  typedef typename boost::simd::meta::scalar_of<r_t>::type sr_t;
  typedef typename boost::simd::meta::scalar_of<r_t>::type ssr_t;

  // specific values tests
  NT2_TEST_EQUAL(first(boost::simd::One<vT>()), boost::simd::One<sr_t>());
  NT2_TEST_EQUAL(first(boost::simd::Zero<vT>()), boost::simd::Zero<sr_t>());
  NT2_TEST_EQUAL(first(boost::simd::Ten <vT>()), boost::simd::Ten <sr_t>());
} // end of test for floating_
