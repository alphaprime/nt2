//==============================================================================
//         Copyright 2003 - 2012   LASMEA UMR 6602 CNRS/Univ. Clermont II
//         Copyright 2009 - 2012   LRI    UMR 8623 CNRS/Univ Paris Sud XI
//
//          Distributed under the Boost Software License, Version 1.0.
//                 See accompanying file LICENSE.txt or copy at
//                     http://www.boost.org/LICENSE_1_0.txt
//==============================================================================
#include <boost/simd/bitwise/include/functions/ror.hpp>
#include <boost/simd/sdk/simd/native.hpp>
#include <boost/type_traits/is_same.hpp>
#include <boost/dispatch/functor/meta/call.hpp>
#include <nt2/sdk/unit/tests.hpp>
#include <nt2/sdk/unit/module.hpp>
#include <boost/simd/constant/constant.hpp>

NT2_TEST_CASE_TPL ( ror_integer__2_0,  BOOST_SIMD_SIMD_INTEGRAL_TYPES)
{
  using boost::simd::ror;
  using boost::simd::tag::ror_;
  using boost::simd::native;
  using boost::simd::meta::cardinal_of;
  typedef BOOST_SIMD_DEFAULT_EXTENSION  ext_t;
  typedef typename boost::dispatch::meta::upgrade<T>::type   u_t;
  typedef native<T,ext_t>                        n_t;
  typedef n_t                                     vT;
  typedef typename boost::dispatch::meta::as_integer<T>::type iT;
  typedef native<iT,ext_t>                       ivT;
  typedef typename boost::dispatch::meta::call<ror_(vT,ivT)>::type r_t;
  typedef typename boost::simd::meta::scalar_of<r_t>::type sr_t;
  typedef typename boost::simd::meta::scalar_of<r_t>::type ssr_t;

  // specific values tests
  NT2_TEST_EQUAL(ror(boost::simd::splat<vT>(2),boost::simd::splat<vT>(2))[0], sr_t(boost::simd::One<T>()<<(sizeof(T)*8-1)));
  NT2_TEST_EQUAL(ror(boost::simd::Mone<vT>(),boost::simd::splat<vT>(1))[0], boost::simd::Mone<T>());
  NT2_TEST_EQUAL(ror(boost::simd::Mone<vT>(),boost::simd::splat<vT>(5))[0], boost::simd::Mone<T>());
  NT2_TEST_EQUAL(ror(boost::simd::One<vT>(),boost::simd::splat<vT>(1))[0], sr_t(boost::simd::One<T>()<<(sizeof(T)*8-1)));
  NT2_TEST_EQUAL(ror(boost::simd::Zero<vT>(),boost::simd::splat<vT>(1))[0], boost::simd::Zero<T>());
} // end of test for integer_
