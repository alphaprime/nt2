//==============================================================================
//         Copyright 2003 - 2012   LASMEA UMR 6602 CNRS/Univ. Clermont II
//         Copyright 2009 - 2012   LRI    UMR 8623 CNRS/Univ Paris Sud XI
//
//          Distributed under the Boost Software License, Version 1.0.
//                 See accompanying file LICENSE.txt or copy at
//                     http://www.boost.org/LICENSE_1_0.txt
//==============================================================================
#include <boost/simd/ieee/include/functions/nextafter.hpp>
#include <boost/simd/sdk/simd/native.hpp>
#include <boost/type_traits/is_same.hpp>
#include <boost/dispatch/functor/meta/call.hpp>
#include <nt2/sdk/unit/tests.hpp>
#include <nt2/sdk/unit/module.hpp>
#include <boost/simd/constant/constant.hpp>

NT2_TEST_CASE_TPL ( nextafter_real__2_0,  BOOST_SIMD_SIMD_REAL_TYPES)
{
  using boost::simd::nextafter;
  using boost::simd::tag::nextafter_;
  using boost::simd::native;
  using boost::simd::meta::cardinal_of;
  typedef BOOST_SIMD_DEFAULT_EXTENSION  ext_t;
  typedef typename boost::dispatch::meta::upgrade<T>::type   u_t;
  typedef native<T,ext_t>                        n_t;
  typedef n_t                                     vT;
  typedef typename boost::dispatch::meta::as_integer<T>::type iT;
  typedef native<iT,ext_t>                       ivT;
  typedef typename boost::dispatch::meta::call<nextafter_(vT,vT)>::type r_t;
  typedef typename boost::simd::meta::scalar_of<r_t>::type sr_t;
  typedef typename boost::simd::meta::scalar_of<r_t>::type ssr_t;
  NT2_TEST_EQUAL(nextafter(boost::simd::Inf<vT>(), boost::simd::Inf<vT>())[0]   ,nextafter(boost::simd::Inf<T>(), boost::simd::Inf<T>())   );
  NT2_TEST_EQUAL(nextafter(boost::simd::Minf<vT>(), boost::simd::One<vT>())[0]  ,nextafter(boost::simd::Minf<T>(), boost::simd::One<T>())  );
  NT2_TEST_EQUAL(nextafter(boost::simd::Mone<vT>(), boost::simd::One<vT>())[0]  ,nextafter(boost::simd::Mone<T>(), boost::simd::One<T>())  );
  NT2_TEST_EQUAL(nextafter(boost::simd::Nan<vT>(), boost::simd::One<vT>())[0]   ,nextafter(boost::simd::Nan<T>(), boost::simd::One<T>())   );
  NT2_TEST_EQUAL(nextafter(boost::simd::One<vT>(), boost::simd::Inf<vT>())[0]   ,nextafter(boost::simd::One<T>(), boost::simd::Inf<T>())   );
  NT2_TEST_EQUAL(nextafter(boost::simd::Valmax<vT>(), boost::simd::Inf<vT>())[0],nextafter(boost::simd::Valmax<T>(), boost::simd::Inf<T>()));
  NT2_TEST_EQUAL(nextafter(boost::simd::Zero<vT>(), boost::simd::One<vT>())[0]  ,nextafter(boost::simd::Zero<T>(), boost::simd::One<T>())  );
} // end of test for floating_
