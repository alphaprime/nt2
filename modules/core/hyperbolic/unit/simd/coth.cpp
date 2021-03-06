//==============================================================================
//         Copyright 2003 - 2012   LASMEA UMR 6602 CNRS/Univ. Clermont II
//         Copyright 2009 - 2012   LRI    UMR 8623 CNRS/Univ Paris Sud XI
//
//          Distributed under the Boost Software License, Version 1.0.
//                 See accompanying file LICENSE.txt or copy at
//                     http://www.boost.org/LICENSE_1_0.txt
//==============================================================================
#include <nt2/hyperbolic/include/functions/coth.hpp>
#include <nt2/sdk/functor/meta/call.hpp>
#include <nt2/sdk/unit/tests/ulp.hpp>
#include <nt2/sdk/unit/module.hpp>

#include <nt2/constant/constant.hpp>
#include <nt2/include/functions/splat.hpp>

NT2_TEST_CASE_TPL ( coth_real__1_0,  NT2_SIMD_REAL_TYPES)
{
  using nt2::coth;
  using nt2::tag::coth_;
  using boost::simd::native;
  typedef NT2_SIMD_DEFAULT_EXTENSION  ext_t;
  typedef native<T,ext_t>                vT;
  typedef typename nt2::meta::call<coth_(vT)>::type r_t;

  // specific values tests
  NT2_TEST_ULP_EQUAL(coth(nt2::Inf<vT>()), nt2::One<r_t>(), 0.5);
  NT2_TEST_ULP_EQUAL(coth(nt2::Minf<vT>()), nt2::Mone<r_t>(), 0.5);
  NT2_TEST_ULP_EQUAL(coth(nt2::Mzero<vT>()), nt2::Minf<r_t>(), 0.5);
  NT2_TEST_ULP_EQUAL(coth(nt2::Nan<vT>()), nt2::Nan<r_t>(), 0.5);
  NT2_TEST_ULP_EQUAL(coth(nt2::Zero<vT>()), nt2::Inf<r_t>(), 0.5);
} // end of test for floating_
