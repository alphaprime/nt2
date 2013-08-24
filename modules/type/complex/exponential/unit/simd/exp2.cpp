//==============================================================================
//         Copyright 2003 - 2012   LASMEA UMR 6602 CNRS/Univ. Clermont II
//         Copyright 2009 - 2012   LRI    UMR 8623 CNRS/Univ Paris Sud XI
//
//          Distributed under the Boost Software License, Version 1.0.
//                 See accompanying file LICENSE.txt or copy at
//                     http://www.boost.org/LICENSE_1_0.txt
//==============================================================================
#define NT2_UNIT_MODULE "nt2 complex.operator toolbox - exp2/simd Mode"

//////////////////////////////////////////////////////////////////////////////
// unit test behavior of boost.simd.operator components in scalar mode
//////////////////////////////////////////////////////////////////////////////
/// created  by jt the 18/02/2011
///
#include <nt2/include/functions/exp2.hpp>
#include <boost/simd/sdk/simd/native.hpp>
#include <nt2/include/functions/atan2.hpp>
#include <nt2/include/functions/extract.hpp>
#include <boost/simd/sdk/simd/logical.hpp>
#include <boost/type_traits/is_same.hpp>
#include <boost/dispatch/functor/meta/call.hpp>
#include <nt2/sdk/unit/tests.hpp>
#include <nt2/sdk/unit/module.hpp>
#include <nt2/constant/constant.hpp>
#include <nt2/sdk/complex/complex.hpp>
#include <nt2/sdk/complex/dry.hpp>
#include <nt2/sdk/complex/meta/as_complex.hpp>
#include <nt2/sdk/complex/meta/as_dry.hpp>

NT2_TEST_CASE_TPL ( exp2_real__2_0,  BOOST_SIMD_SIMD_REAL_TYPES)
{
  using boost::simd::native;
  typedef NT2_SIMD_DEFAULT_EXTENSION  ext_t;
  typedef std::complex<T>                         cT;
  typedef native<T ,ext_t>                        vT;
  typedef native<cT ,ext_t>                      vcT;
  typedef typename nt2::meta::as_dry<T>::type          dT;
  typedef native<dT ,ext_t>                           vdT;


  typedef vcT r_t;
  // specific values tests
  NT2_TEST_ULP_EQUAL(nt2::exp2(vcT(nt2::Inf<vT>(), nt2::Zero<vT>()))[0], cT(nt2::Inf<T>()),0.75);
  NT2_TEST_ULP_EQUAL(nt2::exp2(vcT(nt2::Minf<vT>(), nt2::Zero<vT>()))[0],cT(nt2::Zero<T>()),0.75);
  NT2_TEST_ULP_EQUAL(nt2::exp2(vcT(nt2::Nan<vT>(), nt2::Zero<vT>()))[0], cT(nt2::Nan<T>()),0.75);
  NT2_TEST_ULP_EQUAL(nt2::exp2(vcT(nt2::One<vT>(), nt2::Zero<vT>()))[0], cT(nt2::Two<T>()),0.75);
  NT2_TEST_ULP_EQUAL(nt2::exp2(vcT(nt2::Zero<vT>(), nt2::Zero<vT>()))[0],cT(nt2::One<T>()),0.75);
  NT2_TEST_ULP_EQUAL(nt2::exp2(vcT(nt2::Two<vT>(), nt2::Zero<vT>()))[0], cT(nt2::Four<T>()),0.75);


  NT2_TEST_ULP_EQUAL(nt2::exp2(vcT(nt2::Zero<vT>(),  nt2::Zero<vT>()))[0], cT(nt2::One<T>()), 0.75);
  NT2_TEST_ULP_EQUAL(nt2::exp2(vcT(nt2::Mzero<vT>(), nt2::Zero<vT>()))[0], cT(nt2::One<T>()), 0.75);
  NT2_TEST_ULP_EQUAL(nt2::exp2(vcT(nt2::Inf  <vT>(), nt2::Zero<vT>()))[0], cT(nt2::Inf<T>(), nt2::Zero<T>()), 0.75);
  NT2_TEST_ULP_EQUAL(nt2::exp2(vcT(nt2::Nan  <vT>(), nt2::Zero<vT>()))[0], cT(nt2::Nan <T>(), nt2::Zero<T>()), 0.75);

  NT2_TEST_ULP_EQUAL(nt2::exp2(vcT(nt2::One  <vT>(), nt2::Inf <vT>()))[0], cT(nt2::Nan<T>(), nt2::Nan<T>()), 0.75);
  NT2_TEST_ULP_EQUAL(nt2::exp2(vcT(nt2::One  <vT>(), nt2::Nan <vT>()))[0], cT(nt2::Nan<T>(), nt2::Nan<T>()), 0.75);
  NT2_TEST_ULP_EQUAL(nt2::exp2(vcT(nt2::Minf <vT>(), nt2::One <vT>()))[0], cT(nt2::Zero<T>()), 0.75);
  NT2_TEST_ULP_EQUAL(nt2::exp2(vcT(nt2::Minf <vT>(), nt2::Mone<vT>()))[0], cT(nt2::Zero<T>()), 0.75);
  NT2_TEST_ULP_EQUAL(nt2::exp2(vcT(nt2::Inf  <vT>(), nt2::One <vT>()))[0], cT(nt2::Inf <T>()*nt2::exp2(cT(nt2::Zero<T>(), nt2::One <T>()))), 0.75);
  NT2_TEST_ULP_EQUAL(nt2::exp2(vcT(nt2::Inf  <vT>(), nt2::Mone<vT>()))[0], cT(nt2::Inf <T>()*nt2::exp2(cT(nt2::Zero<T>(), nt2::Mone<T>()))), 0.75);
  NT2_TEST_ULP_EQUAL(nt2::exp2(vcT(nt2::Minf <vT>(), nt2::Inf<vT>()))[0],  cT(nt2::Zero<T>()), 0.75);
  NT2_TEST_ULP_EQUAL(nt2::exp2(vcT(nt2::Inf  <vT>(), nt2::Inf<vT>()))[0],  cT(nt2::Nan <T>(), nt2::Nan<T>()), 0.75);
  NT2_TEST_ULP_EQUAL(nt2::exp2(vcT(nt2::Minf <vT>(), nt2::Nan<vT>()))[0],  cT(nt2::Zero<T>()), 0.75);
  NT2_TEST_ULP_EQUAL(nt2::exp2(vcT(nt2::Inf  <vT>(), nt2::Nan<vT>()))[0],  cT(nt2::Nan <T>(), nt2::Nan<T>()), 0.75);
  NT2_TEST_ULP_EQUAL(nt2::exp2(vcT(nt2::Nan  <vT>(), nt2::One<vT>()))[0],  cT(nt2::Nan <T>(), nt2::Nan<T>()), 0.75);
  NT2_TEST_ULP_EQUAL(nt2::exp2(vcT(nt2::Nan  <vT>(), nt2::Nan<vT>()))[0],  cT(nt2::Nan <T>(), nt2::Nan<T>()), 0.75);

  NT2_TEST_ULP_EQUAL(nt2::exp2(vcT(nt2::One  <vT>(), -nt2::Inf <vT>()))[0], cT(nt2::Nan<T>(), nt2::Nan<T>()), 0.75);
  NT2_TEST_ULP_EQUAL(nt2::exp2(vcT(nt2::One  <vT>(), -nt2::Nan <vT>()))[0], cT(nt2::Nan<T>(), nt2::Nan<T>()), 0.75);
  NT2_TEST_ULP_EQUAL(nt2::exp2(vcT(nt2::Minf <vT>(), -nt2::One <vT>()))[0], cT(nt2::Zero<T>()), 0.75);
  NT2_TEST_ULP_EQUAL(nt2::exp2(vcT(nt2::Minf <vT>(), -nt2::Mone<vT>()))[0], cT(nt2::Zero<T>()), 0.75);
  NT2_TEST_ULP_EQUAL(nt2::exp2(vcT(nt2::Inf  <vT>(), -nt2::One <vT>()))[0], cT(nt2::Inf <T>()*nt2::exp2(cT(nt2::Zero<T>(), -nt2::One <T>()))), 0.75);
  NT2_TEST_ULP_EQUAL(nt2::exp2(vcT(nt2::Inf  <vT>(), -nt2::Mone<vT>()))[0], cT(nt2::Inf <T>()*nt2::exp2(cT(nt2::Zero<T>(), -nt2::Mone<T>()))), 0.75);
  NT2_TEST_ULP_EQUAL(nt2::exp2(vcT(nt2::Minf <vT>(), -nt2::Inf<vT>()))[0],  cT(nt2::Zero<T>()), 0.75);
  NT2_TEST_ULP_EQUAL(nt2::exp2(vcT(nt2::Inf  <vT>(), -nt2::Inf<vT>()))[0],  cT(nt2::Nan <T>(), -nt2::Nan<T>()), 0.75);
  NT2_TEST_ULP_EQUAL(nt2::exp2(vcT(nt2::Minf <vT>(), -nt2::Nan<vT>()))[0],  cT(nt2::Zero<T>()), 0.75);
  NT2_TEST_ULP_EQUAL(nt2::exp2(vcT(nt2::Inf  <vT>(), -nt2::Nan<vT>()))[0],  cT(nt2::Nan <T>(), -nt2::Nan<T>()), 0.75);
  NT2_TEST_ULP_EQUAL(nt2::exp2(vcT(nt2::Nan  <vT>(), -nt2::One<vT>()))[0],  cT(nt2::Nan <T>(), -nt2::Nan<T>()), 0.75);
  NT2_TEST_ULP_EQUAL(nt2::exp2(vcT(nt2::Nan  <vT>(), -nt2::Nan<vT>()))[0],  cT(nt2::Nan <T>(), -nt2::Nan<T>()), 0.75);


} // end of test for floating_
