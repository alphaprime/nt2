//==============================================================================
//         Copyright 2003 - 2012   LASMEA UMR 6602 CNRS/Univ. Clermont II
//         Copyright 2009 - 2012   LRI    UMR 8623 CNRS/Univ Paris Sud XI
//
//          Distributed under the Boost Software License, Version 1.0.
//                 See accompanying file LICENSE.txt or copy at
//                     http://www.boost.org/LICENSE_1_0.txt
//==============================================================================
#include <boost/simd/bitwise/include/functions/lo.hpp>
#include <boost/simd/sdk/simd/native.hpp>
#include <boost/dispatch/meta/downgrade.hpp>

#include <boost/type_traits/is_same.hpp>
#include <boost/dispatch/functor/meta/call.hpp>
#include <nt2/sdk/unit/tests.hpp>
#include <nt2/sdk/unit/module.hpp>
#include <boost/simd/constant/constant.hpp>

NT2_TEST_CASE_TPL ( lo_real__1_0,  BOOST_SIMD_SIMD_REAL_TYPES)
{
  using boost::simd::lo;
  using boost::simd::tag::lo_;
  using boost::simd::native;
  using boost::simd::meta::cardinal_of;
  typedef typename boost::dispatch::meta::as_integer<T,unsigned>::type ir_t;
  typedef typename boost::dispatch::meta::downgrade<ir_t>::type dtype;
  typedef typename boost::simd::meta::scalar_of<ir_t>::type scal;
  typedef BOOST_SIMD_DEFAULT_EXTENSION  ext_t;
  typedef typename boost::dispatch::meta::upgrade<T>::type   u_t;
  typedef native<T,ext_t>                        n_t;
  typedef n_t                                     vT;
  typedef typename boost::dispatch::meta::as_integer<T>::type iT;
  typedef native<iT,ext_t>                       ivT;
  typedef typename boost::dispatch::meta::call<lo_(vT)>::type r_t;
  typedef typename boost::simd::meta::scalar_of<r_t>::type sr_t;
  typedef typename boost::simd::meta::scalar_of<r_t>::type ssr_t;

  // specific values tests
  NT2_TEST_EQUAL(lo(boost::simd::Nan<vT>())[0], boost::simd::Mone<dtype>());
  NT2_TEST_EQUAL(lo(boost::simd::One<vT>())[0], boost::simd::Zero<dtype>());
  NT2_TEST_EQUAL(lo(boost::simd::Zero<vT>())[0], boost::simd::Zero<dtype>());
} // end of test for floating_

NT2_TEST_CASE_TPL ( lo_sintgt_8__1_0,  BOOST_SIMD_SIMD_SIGNED_INT_GT_8_TYPES)
{
  using boost::simd::lo;
  using boost::simd::tag::lo_;
  using boost::simd::native;
  using boost::simd::meta::cardinal_of;
  typedef typename boost::dispatch::meta::as_integer<T,unsigned>::type ir_t;
  typedef typename boost::dispatch::meta::downgrade<ir_t>::type dtype;
  typedef typename boost::simd::meta::scalar_of<ir_t>::type scal;
  typedef BOOST_SIMD_DEFAULT_EXTENSION  ext_t;
  typedef typename boost::dispatch::meta::upgrade<T>::type   u_t;
  typedef native<T,ext_t>                        n_t;
  typedef n_t                                     vT;
  typedef typename boost::dispatch::meta::as_integer<T>::type iT;
  typedef native<iT,ext_t>                       ivT;
  typedef typename boost::dispatch::meta::call<lo_(vT)>::type r_t;
  typedef typename boost::simd::meta::scalar_of<r_t>::type sr_t;
  typedef typename boost::simd::meta::scalar_of<r_t>::type ssr_t;

  // specific values tests
  NT2_TEST_EQUAL(lo(boost::simd::One<vT>())[0], boost::simd::One<dtype>());
  NT2_TEST_EQUAL(lo(boost::simd::Zero<vT>())[0], boost::simd::Zero<dtype>());
} // end of test for sintgt_8_
