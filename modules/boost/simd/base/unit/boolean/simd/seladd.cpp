//==============================================================================
//         Copyright 2003 - 2012   LASMEA UMR 6602 CNRS/Univ. Clermont II
//         Copyright 2009 - 2012   LRI    UMR 8623 CNRS/Univ Paris Sud XI
//
//          Distributed under the Boost Software License, Version 1.0.
//                 See accompanying file LICENSE.txt or copy at
//                     http://www.boost.org/LICENSE_1_0.txt
//==============================================================================
#include <boost/simd/boolean/include/functions/seladd.hpp>
#include <boost/simd/sdk/simd/native.hpp>
#include <boost/simd/include/functions/is_nez.hpp>

#include <boost/type_traits/is_same.hpp>
#include <boost/dispatch/functor/meta/call.hpp>
#include <nt2/sdk/unit/tests.hpp>
#include <nt2/sdk/unit/module.hpp>
#include <boost/simd/constant/constant.hpp>


NT2_TEST_CASE_TPL ( seladd_real__3_0,  BOOST_SIMD_SIMD_REAL_TYPES)
{
  using boost::simd::seladd;
  using boost::simd::tag::seladd_;
  using boost::simd::native;
  using boost::simd::meta::cardinal_of;
  using boost::simd::logical;
  typedef BOOST_SIMD_DEFAULT_EXTENSION  ext_t;
  typedef typename boost::dispatch::meta::upgrade<T>::type   u_t;
  typedef native<T,ext_t>                        n_t;
  typedef n_t                                     vT;
  typedef typename boost::dispatch::meta::as_integer<T>::type iT;
  typedef native<iT,ext_t>                       ivT;
  typedef native<logical<T> ,ext_t>              vlT;
  typedef typename boost::dispatch::meta::call<seladd_(vlT,vT,vT)>::type r_t;
  typedef typename boost::simd::meta::scalar_of<r_t>::type sr_t;
  typedef typename boost::simd::meta::scalar_of<r_t>::type ssr_t;

  // specific values tests
  NT2_TEST_EQUAL(seladd(boost::simd::is_nez(boost::simd::Zero<vT>()),boost::simd::splat<vT>(1),boost::simd::splat<vT>(2))[0], T(1));
  NT2_TEST_EQUAL(seladd(boost::simd::is_nez(boost::simd::Nan<vT>()),boost::simd::splat<vT>(1),boost::simd::splat<vT>(2))[0], T(3));
  NT2_TEST_EQUAL(seladd(boost::simd::is_nez(boost::simd::Nan<vT>()),boost::simd::Inf<vT>(),boost::simd::Inf<vT>())[0], boost::simd::Inf<sr_t>());
  NT2_TEST_EQUAL(seladd(boost::simd::is_nez(boost::simd::Nan<vT>()),boost::simd::Inf<vT>(),boost::simd::Minf<vT>())[0], boost::simd::Nan<sr_t>());
  NT2_TEST_EQUAL(seladd(boost::simd::is_nez(boost::simd::Nan<vT>()),boost::simd::Minf<vT>(),boost::simd::Minf<vT>())[0],boost::simd::Minf<sr_t>());
  NT2_TEST_EQUAL(seladd(boost::simd::is_nez(boost::simd::Nan<vT>()),boost::simd::Minf<vT>(),boost::simd::Inf<vT>())[0], boost::simd::Nan<sr_t>());
  NT2_TEST_EQUAL(seladd(boost::simd::is_nez(boost::simd::Nan<vT>()),boost::simd::Nan<vT>(),boost::simd::Nan<vT>())[0], boost::simd::Nan<sr_t>());
  NT2_TEST_EQUAL(seladd(boost::simd::is_nez(boost::simd::Nan<vT>()),boost::simd::Zero<vT>(),boost::simd::Zero<vT>())[0],boost::simd::Zero<sr_t>());
} // end of test for floating_

NT2_TEST_CASE_TPL ( seladd_integer__3_0,  BOOST_SIMD_SIMD_INTEGRAL_TYPES)
{
  using boost::simd::seladd;
  using boost::simd::tag::seladd_;
  using boost::simd::native;
  using boost::simd::meta::cardinal_of;
  using boost::simd::logical;
  typedef BOOST_SIMD_DEFAULT_EXTENSION  ext_t;
  typedef typename boost::dispatch::meta::upgrade<T>::type   u_t;
  typedef native<T,ext_t>                        n_t;
  typedef n_t                                     vT;
  typedef typename boost::dispatch::meta::as_integer<T>::type iT;
  typedef native<iT,ext_t>                       ivT;
  typedef native<logical<T> ,ext_t>              vlT;
  typedef typename boost::dispatch::meta::call<seladd_(vlT,vT,vT)>::type r_t;
  typedef typename boost::simd::meta::scalar_of<r_t>::type sr_t;
  typedef typename boost::simd::meta::scalar_of<r_t>::type ssr_t;


  // specific values tests
  NT2_TEST_EQUAL(seladd(boost::simd::is_nez(boost::simd::One<vT>()),boost::simd::splat<vT>(1),boost::simd::splat<vT>(2))[0], T(3));
  NT2_TEST_EQUAL(seladd(boost::simd::is_nez(boost::simd::Zero<vT>()),boost::simd::splat<vT>(1),boost::simd::splat<vT>(2))[0], T(1));
  NT2_TEST_EQUAL(seladd(boost::simd::is_nez(boost::simd::Zero<vT>()),boost::simd::Zero<vT>(),boost::simd::Zero<vT>())[0], boost::simd::Zero<sr_t>());
} // end of test for integer_
