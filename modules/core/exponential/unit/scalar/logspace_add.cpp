//==============================================================================
//         Copyright 2003 - 2012   LASMEA UMR 6602 CNRS/Univ. Clermont II
//         Copyright 2009 - 2012   LRI    UMR 8623 CNRS/Univ Paris Sud XI
//
//          Distributed under the Boost Software License, Version 1.0.
//                 See accompanying file LICENSE.txt or copy at
//                     http://www.boost.org/LICENSE_1_0.txt
//==============================================================================
#define NT2_UNIT_MODULE "nt2 exponential toolbox - logspace_add/scalar Mode"

//////////////////////////////////////////////////////////////////////////////
// unit test behavior of exponential components in scalar mode
//////////////////////////////////////////////////////////////////////////////
/// created by jt the 08/12/2010
///
#include <nt2/exponential/include/functions/logspace_add.hpp>
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
#include <nt2/sdk/memory/buffer.hpp>
#include <nt2/constant/constant.hpp>




NT2_TEST_CASE_TPL ( logspace_add_real__2_1,  NT2_REAL_TYPES)
{

  using nt2::logspace_add;
  using nt2::tag::logspace_add_;
  typedef typename nt2::meta::as_integer<T>::type iT;
  typedef typename nt2::meta::call<logspace_add_(T,T)>::type r_t;
  typedef typename nt2::meta::scalar_of<r_t>::type sr_t;
  typedef typename nt2::meta::upgrade<T>::type u_t;
  typedef typename boost::dispatch::meta::as_floating<T>::type wished_r_t;


  // return type conformity test
  NT2_TEST( (boost::is_same < r_t, wished_r_t >::value) );
  double ulpd;
  ulpd=0.0;


  // specific values tests
  NT2_TEST_ULP_EQUAL(logspace_add(nt2::Inf<T>(),nt2::Inf<T>()), nt2::Inf<sr_t>(), 0);
  NT2_TEST_ULP_EQUAL(logspace_add(nt2::Inf<T>(),nt2::Zero<T>()), nt2::Inf<sr_t>(), 0);
  NT2_TEST_ULP_EQUAL(logspace_add(nt2::Minf<T>(),nt2::Zero<T>()), nt2::Zero<sr_t>(), 0);
  NT2_TEST_ULP_EQUAL(logspace_add(nt2::Inf<T>(),nt2::Nan <T>()), nt2::Nan<sr_t>(), 0);
  NT2_TEST_ULP_EQUAL(logspace_add(nt2::Minf<T>(),nt2::Minf<T>()), nt2::Minf<sr_t>(), 0);
  NT2_TEST_ULP_EQUAL(logspace_add(nt2::Mone<T>(),nt2::Mone<T>()), nt2::Mone<sr_t>()+nt2::Log_2<sr_t>(), 0);
  NT2_TEST_ULP_EQUAL(logspace_add(nt2::Nan<T>(),nt2::Nan<T>()), nt2::Nan<sr_t>(), 0);
  NT2_TEST_ULP_EQUAL(logspace_add(nt2::One<T>(),nt2::One<T>()), nt2::One<sr_t>()+nt2::Log_2<sr_t>(), 0);
  NT2_TEST_ULP_EQUAL(logspace_add(nt2::Two <T>(), nt2::Two <T>()), nt2::Two <sr_t>()+nt2::Log_2<sr_t>(), 0);
  NT2_TEST_ULP_EQUAL(logspace_add(nt2::Zero<T>(),nt2::Zero<T>()), nt2::Log_2<sr_t>(), 0);
} // end of test for floating_
