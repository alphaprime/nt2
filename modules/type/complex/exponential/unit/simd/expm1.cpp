//==============================================================================
//         Copyright 2003 - 2012   LASMEA UMR 6602 CNRS/Univ. Clermont II
//         Copyright 2009 - 2012   LRI    UMR 8623 CNRS/Univ Paris Sud XI
//
//          Distributed under the Boost Software License, Version 1.0.
//                 See accompanying file LICENSE.txt or copy at
//                     http://www.boost.org/LICENSE_1_0.txt
//==============================================================================
#define NT2_UNIT_MODULE "nt2 complex.operator toolbox - expm1/simd Mode"

//////////////////////////////////////////////////////////////////////////////
// unit test behavior of boost.simd.operator components in scalar mode
//////////////////////////////////////////////////////////////////////////////
/// created  by jt the 18/02/2011
///
#include <nt2/include/functions/expm1.hpp>
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
#include <nt2/include/constants/exp_1.hpp>

NT2_TEST_CASE_TPL ( expm1_real__2_0,  BOOST_SIMD_SIMD_REAL_TYPES)
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
  NT2_TEST_ULP_EQUAL(nt2::expm1(vcT(nt2::Inf<vT>(), nt2::Zero<vT>()))[0], cT(nt2::Inf<T>()),1);
  NT2_TEST_ULP_EQUAL(nt2::expm1(vcT(nt2::Minf<vT>(), nt2::Zero<vT>()))[0],cT(nt2::Mone<T>()),1);
  NT2_TEST_ULP_EQUAL(nt2::expm1(vcT(nt2::Nan<vT>(), nt2::Zero<vT>()))[0], cT(nt2::Nan<T>()),1);
  NT2_TEST_ULP_EQUAL(nt2::expm1(vcT(nt2::One<vT>(), nt2::Zero<vT>()))[0], cT(nt2::Exp_1<T>()-nt2::One<cT>()),1);
  NT2_TEST_ULP_EQUAL(nt2::expm1(vcT(nt2::Zero<vT>(), nt2::Zero<vT>()))[0],cT(nt2::Zero<T>()),1);

  NT2_TEST_ULP_EQUAL(nt2::expm1(vcT(nt2::Zero<vT>(), nt2::Pi<vT>()))[0],  cT(nt2::Mtwo<T>()),1);

  NT2_TEST_ULP_EQUAL(nt2::expm1(vcT(nt2::Zero<vT>(), nt2::Pio_2<vT>()))[0],   cT(-1, 1),1);
  NT2_TEST_ULP_EQUAL(nt2::expm1(vcT(nt2::Mzero<vT>(), nt2::Zero<vT>()))[0], cT(nt2::Zero<T>()), 1);
  NT2_TEST_ULP_EQUAL(nt2::expm1(vcT(nt2::Inf  <vT>(), nt2::Zero<vT>()))[0], cT(nt2::Inf<T>(), nt2::Zero<T>()), 1);
  NT2_TEST_ULP_EQUAL(nt2::expm1(vcT(nt2::Nan  <vT>(), nt2::Zero<vT>()))[0], cT(nt2::Nan <T>(), nt2::Zero<T>()), 1);

  NT2_TEST_ULP_EQUAL(nt2::expm1(vcT(nt2::One  <vT>(), nt2::Inf <vT>()))[0], cT(nt2::Nan<T>(), nt2::Nan<T>()), 1);
  NT2_TEST_ULP_EQUAL(nt2::expm1(vcT(nt2::One  <vT>(), nt2::Nan <vT>()))[0], cT(nt2::Nan<T>(), nt2::Nan<T>()), 1);
  NT2_TEST_ULP_EQUAL(nt2::expm1(vcT(nt2::Minf <vT>(), nt2::One <vT>()))[0], cT(nt2::Mone<T>()), 1);
  NT2_TEST_ULP_EQUAL(nt2::expm1(vcT(nt2::Minf <vT>(), nt2::Mone<vT>()))[0], cT(nt2::Mone<T>()), 1);
  NT2_TEST_ULP_EQUAL(nt2::expm1(vcT(nt2::Inf  <vT>(), nt2::One <vT>()))[0], cT(nt2::Inf <T>(),nt2::Inf <T>() ), 1);
  NT2_TEST_ULP_EQUAL(nt2::expm1(vcT(nt2::Inf  <vT>(), nt2::Mone<vT>()))[0], cT(nt2::Inf <T>(),nt2::Minf <T>() ), 1);
  NT2_TEST_ULP_EQUAL(nt2::expm1(vcT(nt2::Minf <vT>(), nt2::Inf<vT>()))[0],  cT(nt2::Mone<T>()), 1);
  NT2_TEST_ULP_EQUAL(nt2::expm1(vcT(nt2::Inf  <vT>(), nt2::Inf<vT>()))[0],  cT(nt2::Nan <T>(), nt2::Nan<T>()), 1);
  NT2_TEST_ULP_EQUAL(nt2::expm1(vcT(nt2::Minf <vT>(), nt2::Nan<vT>()))[0],  cT(nt2::Mone<T>()), 1);
  NT2_TEST_ULP_EQUAL(nt2::expm1(vcT(nt2::Inf  <vT>(), nt2::Nan<vT>()))[0],  cT(nt2::Nan <T>(), nt2::Nan<T>()), 1);
  NT2_TEST_ULP_EQUAL(nt2::expm1(vcT(nt2::Nan  <vT>(), nt2::One<vT>()))[0],  cT(nt2::Nan <T>(), nt2::Nan<T>()), 1);
  NT2_TEST_ULP_EQUAL(nt2::expm1(vcT(nt2::Nan  <vT>(), nt2::Nan<vT>()))[0],  cT(nt2::Nan <T>(), nt2::Nan<T>()), 1);

  NT2_TEST_ULP_EQUAL(nt2::expm1(vcT(nt2::One  <vT>(), -nt2::Inf <vT>()))[0], cT(nt2::Nan<T>(), nt2::Nan<T>()), 1);
  NT2_TEST_ULP_EQUAL(nt2::expm1(vcT(nt2::One  <vT>(), -nt2::Nan <vT>()))[0], cT(nt2::Nan<T>(), nt2::Nan<T>()), 1);
  NT2_TEST_ULP_EQUAL(nt2::expm1(vcT(nt2::Minf <vT>(),  nt2::One <vT>()))[0], cT(nt2::Mone<T>()), 1);
  NT2_TEST_ULP_EQUAL(nt2::expm1(vcT(nt2::Minf <vT>(),  nt2::Mone<vT>()))[0], cT(nt2::Mone<T>()), 1);
  NT2_TEST_ULP_EQUAL(nt2::expm1(vcT(nt2::Inf  <vT>(),  nt2::One <vT>()))[0], cT(nt2::Inf <T>(),  nt2::Inf<T>()), 1);
  NT2_TEST_ULP_EQUAL(nt2::expm1(vcT(nt2::Inf  <vT>(),  nt2::Mone<vT>()))[0], cT(nt2::Inf <T>(), -nt2::Inf<T>()), 1);
  NT2_TEST_ULP_EQUAL(nt2::expm1(vcT(nt2::Minf <vT>(), -nt2::Inf<vT>()))[0],  cT(nt2::Mone<T>()), 1);
  NT2_TEST_ULP_EQUAL(nt2::expm1(vcT(nt2::Inf  <vT>(), -nt2::Inf<vT>()))[0],  cT(nt2::Nan <T>(), -nt2::Nan<T>()), 1);
  NT2_TEST_ULP_EQUAL(nt2::expm1(vcT(nt2::Minf <vT>(), -nt2::Nan<vT>()))[0],  cT(nt2::Mone<T>()), 1);
  NT2_TEST_ULP_EQUAL(nt2::expm1(vcT(nt2::Inf  <vT>(), -nt2::Nan<vT>()))[0],  cT(nt2::Nan <T>(), -nt2::Nan<T>()), 1);
  NT2_TEST_ULP_EQUAL(nt2::expm1(vcT(nt2::Nan  <vT>(), -nt2::One<vT>()))[0],  cT(nt2::Nan <T>(), -nt2::Nan<T>()), 1);
  NT2_TEST_ULP_EQUAL(nt2::expm1(vcT(nt2::Nan  <vT>(), -nt2::Nan<vT>()))[0],  cT(nt2::Nan <T>(), -nt2::Nan<T>()), 1);


} // end of test for floating_
