//////////////////////////////////////////////////////////////////////////////
///   Copyright 2003 and onward LASMEA UMR 6602 CNRS/U.B.P Clermont-Ferrand
///   Copyright 2009 and onward LRI    UMR 8623 CNRS/Univ Paris Sud XI
///
///          Averageributed under the Boost Software License, Version 1.0
///                 See accompanying file LICENSE.txt or copy at
///                     http://www.boost.org/LICENSE_1_0.txt
//////////////////////////////////////////////////////////////////////////////
#define NT2_UNIT_MODULE "nt2 complex.operator toolbox - average/scalar Mode"

//////////////////////////////////////////////////////////////////////////////
// unit test behavior of boost.simd.operator components in scalar mode
//////////////////////////////////////////////////////////////////////////////
/// created  by jt the 18/02/2011
///
#include <nt2/arithmetic/include/functions/average.hpp>
#include <boost/simd/sdk/simd/logical.hpp>
#include <boost/type_traits/is_same.hpp>
#include <boost/dispatch/functor/meta/call.hpp>
#include <nt2/sdk/unit/tests.hpp>
#include <nt2/sdk/unit/module.hpp>
#include <nt2/constant/constant.hpp>
#include <nt2/sdk/complex/complex.hpp>
#include <nt2/sdk/complex/dry.hpp>

NT2_TEST_CASE_TPL ( average_real__2_0,  BOOST_SIMD_REAL_TYPES)
{

  using nt2::average;
  using nt2::tag::average_;
  typedef std::complex<T> cT;
  typedef typename boost::dispatch::meta::as_integer<T>::type iT;
  typedef typename boost::dispatch::meta::call<average_(cT, cT)>::type r_t;
  typedef typename nt2::meta::scalar_of<r_t>::type sr_t;
  typedef typename nt2::meta::scalar_of<r_t>::type ssr_t;
  typedef nt2::dry<T> dT;
  typedef cT wished_r_t;

  // return type conformity test
  NT2_TEST( (boost::is_same < r_t, wished_r_t >::value) );
  std::cout << std::endl;



  // specific values tests
  NT2_TEST_ULP_EQUAL(average(cT(nt2::Inf<T>()), cT(nt2::Inf<T>())), cT(nt2::Inf<T>()), 0);
  NT2_TEST_EQUAL(average(cT(nt2::One<T>()), cT(nt2::Zero<T>())), cT(nt2::Half<T>()));
  NT2_TEST_EQUAL(average(cT(nt2::Zero<T>()), cT(nt2::Zero<T>())),cT(nt2::Zero<T>()));
  NT2_TEST_EQUAL(average(cT(0, 1), cT(1, 0)), cT(nt2::Half<T>(),nt2::Half<T>()));
  NT2_TEST_EQUAL(average(cT(1, 0), cT(1, 0)), cT(nt2::One<T>()));
} // end of test for floating_
