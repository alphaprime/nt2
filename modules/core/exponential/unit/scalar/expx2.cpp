//==============================================================================
//         Copyright 2003 - 2012   LASMEA UMR 6602 CNRS/Univ. Clermont II
//         Copyright 2009 - 2012   LRI    UMR 8623 CNRS/Univ Paris Sud XI
//
//          Distributed under the Boost Software License, Version 1.0.
//                 See accompanying file LICENSE.txt or copy at
//                     http://www.boost.org/LICENSE_1_0.txt
//==============================================================================
#include <nt2/exponential/include/functions/expx2.hpp>
#include <nt2/exponential/include/functions/cbrt.hpp>
#include <nt2/sdk/functor/meta/call.hpp>
#include <nt2/sdk/unit/tests/ulp.hpp>
#include <nt2/sdk/unit/tests/type_expr.hpp>
#include <nt2/sdk/unit/module.hpp>
#include <nt2/sdk/meta/as_floating.hpp>

#include <nt2/constant/constant.hpp>
#include <nt2/include/constants/exp_1.hpp>


NT2_TEST_CASE_TPL ( expx2_real__1_0,  NT2_REAL_TYPES)
{

  using nt2::expx2;
  using nt2::tag::expx2_;
  typedef typename nt2::meta::call<expx2_(T)>::type r_t;
  typedef typename boost::dispatch::meta::as_floating<T>::type wished_r_t;

  NT2_TEST_TYPE_IS(r_t, wished_r_t);

  // specific values tests
#ifndef BOOST_SIMD_NO_INVALIDS
  NT2_TEST_ULP_EQUAL(expx2(nt2::Inf<T>()), nt2::Inf<r_t>(), 1.0);
  NT2_TEST_ULP_EQUAL(expx2(nt2::Minf<T>()), nt2::Inf<r_t>(), 1.0);
  NT2_TEST_ULP_EQUAL(expx2(nt2::Nan<T>()), nt2::Nan<r_t>(), 1.0);
#endif
  NT2_TEST_ULP_EQUAL(expx2(nt2::Mone<T>()), nt2::Exp_1<r_t>(), 1.0);
  NT2_TEST_ULP_EQUAL(expx2(nt2::One<T>()), nt2::Exp_1<r_t>(), 1.0);
  NT2_TEST_ULP_EQUAL(expx2(nt2::Zero<T>()), nt2::One<r_t>(), 1.0);
} // end of test for floating_

NT2_TEST_CASE_TPL ( expx2_unsigned_int__1_0,  NT2_UNSIGNED_TYPES)
{

  using nt2::expx2;
  using nt2::tag::expx2_;
  typedef typename nt2::meta::call<expx2_(T)>::type r_t;
  typedef typename boost::dispatch::meta::as_floating<T>::type wished_r_t;

  NT2_TEST_TYPE_IS(r_t, wished_r_t);

  // specific values tests
  NT2_TEST_ULP_EQUAL(expx2(nt2::One<T>()), nt2::Exp_1<r_t>(), 1.0);
  NT2_TEST_ULP_EQUAL(expx2(nt2::Zero<T>()), nt2::One<r_t>(), 1.0);
} // end of test for unsigned_int_

NT2_TEST_CASE_TPL ( expx2_signed_int__1_0,  NT2_INTEGRAL_SIGNED_TYPES)
{

  using nt2::expx2;
  using nt2::tag::expx2_;
  typedef typename nt2::meta::call<expx2_(T)>::type r_t;
  typedef typename boost::dispatch::meta::as_floating<T>::type wished_r_t;

  NT2_TEST_TYPE_IS(r_t, wished_r_t);

  // specific values tests
  NT2_TEST_ULP_EQUAL(expx2(nt2::Mone<T>()), nt2::Exp_1<r_t>(), 1.0);
  NT2_TEST_ULP_EQUAL(expx2(nt2::One<T>()), nt2::Exp_1<r_t>(), 1.0);
  NT2_TEST_ULP_EQUAL(expx2(nt2::Zero<T>()), nt2::One<r_t>(), 1.0);
} // end of test for signed_int_
