//==============================================================================
//         Copyright 2003 - 2012   LASMEA UMR 6602 CNRS/Univ. Clermont II
//         Copyright 2009 - 2012   LRI    UMR 8623 CNRS/Univ Paris Sud XI
//
//          Distributed under the Boost Software License, Version 1.0.
//                 See accompanying file LICENSE.txt or copy at
//                     http://www.boost.org/LICENSE_1_0.txt
//==============================================================================
#include <nt2/exponential/include/functions/log1p.hpp>
#include <nt2/sdk/functor/meta/call.hpp>
#include <nt2/sdk/unit/tests/ulp.hpp>
#include <nt2/sdk/unit/module.hpp>
#include <nt2/include/constants/log_2.hpp>
#include <nt2/constant/constant.hpp>
#include <nt2/include/functions/splat.hpp>


NT2_TEST_CASE_TPL ( log1p_real__1_0,  NT2_SIMD_REAL_TYPES)
{
  using nt2::log1p;
  using nt2::tag::log1p_;
  using boost::simd::native;
  typedef NT2_SIMD_DEFAULT_EXTENSION  ext_t;
  typedef native<T,ext_t>                vT;
  typedef typename nt2::meta::call<log1p_(vT)>::type r_t;

  // specific values tests
#ifndef BOOST_SIMD_NO_INVALIDS
  NT2_TEST_ULP_EQUAL(log1p(nt2::Inf<vT>()), nt2::Inf<r_t>(), 0.5);
  NT2_TEST_ULP_EQUAL(log1p(nt2::Minf<vT>()), nt2::Nan<r_t>(), 0.5);
  NT2_TEST_ULP_EQUAL(log1p(nt2::Nan<vT>()), nt2::Nan<r_t>(), 0.5);
#endif
  NT2_TEST_ULP_EQUAL(log1p(nt2::Eps<vT>()), nt2::Eps<r_t>(), 0.5);
  NT2_TEST_ULP_EQUAL(log1p(nt2::Mone<vT>()), nt2::Minf<r_t>(), 0.5);
  NT2_TEST_ULP_EQUAL(log1p(nt2::One<vT>()), nt2::Log_2<r_t>(), 0.5);
  NT2_TEST_ULP_EQUAL(log1p(nt2::Zero<vT>()), nt2::Zero<r_t>(), 0.5);
  NT2_TEST_ULP_EQUAL(log1p(nt2::Smallestposval<vT>()), nt2::Smallestposval<vT>(), 0.5);
} // end of test for floating_
