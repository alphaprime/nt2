//==============================================================================
//         Copyright 2003 - 2012   LASMEA UMR 6602 CNRS/Univ. Clermont II
//         Copyright 2009 - 2012   LRI    UMR 8623 CNRS/Univ Paris Sud XI
//
//          Distributed under the Boost Software License, Version 1.0.
//                 See accompanying file LICENSE.txt or copy at
//                     http://www.boost.org/LICENSE_1_0.txt
//==============================================================================
#define NT2_UNIT_MODULE "nt2 complex.operator toolbox - imag/scalar Mode"

//////////////////////////////////////////////////////////////////////////////
// unit test behavior of boost.simd.operator components in scalar mode
//////////////////////////////////////////////////////////////////////////////
/// created  by jt the 18/02/2011
///
#include <nt2/include/functions/imag.hpp>
#include <nt2/complex/functions/imag.hpp>
#include <boost/simd/sdk/simd/logical.hpp>
#include <boost/type_traits/is_same.hpp>
#include <boost/dispatch/functor/meta/call.hpp>
#include <nt2/sdk/unit/tests.hpp>
#include <nt2/sdk/unit/module.hpp>
#include <nt2/sdk/complex/dry.hpp>
#include <nt2/sdk/complex/meta/as_complex.hpp>
#include <nt2/constant/constant.hpp>
#include <nt2/sdk/complex/complex.hpp>

NT2_TEST_CASE_TPL ( imag_real__2_0,  BOOST_SIMD_REAL_TYPES)
{

  using nt2::imag;
  using nt2::tag::imag_;
  typedef std::complex<T> cT;
  typedef typename boost::dispatch::meta::as_integer<T>::type iT;
  typedef typename boost::dispatch::meta::call<imag_(cT)>::type r_t;
  typedef typename nt2::meta::scalar_of<r_t>::type sr_t;
  typedef typename nt2::meta::scalar_of<r_t>::type ssr_t;
  typedef nt2::dry<T> cdT;
  typedef T wished_r_t;

  // return type conformity test
  NT2_TEST( (boost::is_same < r_t, wished_r_t >::value) );
  std::cout << std::endl;



  // specific values tests
  NT2_TEST_EQUAL(nt2::imag(cT(nt2::Inf<T>())), nt2::Zero<T>());
  NT2_TEST_EQUAL(nt2::imag(cT(nt2::Minf<T>())),nt2::Zero<T>());
  NT2_TEST_EQUAL(nt2::imag(cT(nt2::Nan<T>())), nt2::Zero<T>());
  NT2_TEST_EQUAL(nt2::imag(cT(nt2::One<T>())), nt2::Zero<T>());
  NT2_TEST_EQUAL(nt2::imag(cT(nt2::Zero<T>())),nt2::Zero<T>());
  NT2_TEST_EQUAL(nt2::imag(cT(0, 1)), nt2::One<T>());
  NT2_TEST_EQUAL(nt2::imag(cT(1, 0)), nt2::Zero<T>());
  NT2_TEST_EQUAL(nt2::imag(cT(2, 2)), nt2::Two<T>());
  NT2_TEST_EQUAL(nt2::imag(cT(2,-2)), nt2::Mtwo<T>());
  NT2_TEST_EQUAL(nt2::imag(cdT(nt2::Inf<T>())), nt2::Zero<T>());
  NT2_TEST_EQUAL(nt2::imag(cdT(nt2::Minf<T>())),nt2::Zero<T>());
  NT2_TEST_EQUAL(nt2::imag(cdT(nt2::Nan<T>())), nt2::Zero<T>());
  NT2_TEST_EQUAL(nt2::imag(cdT(nt2::One<T>())), nt2::Zero<T>());
  NT2_TEST_EQUAL(nt2::imag(cdT(nt2::Zero<T>())),nt2::Zero<T>());

} // end of test for floating_
