//==============================================================================
//         Copyright 2003 - 2012   LASMEA UMR 6602 CNRS/Univ. Clermont II
//         Copyright 2009 - 2012   LRI    UMR 8623 CNRS/Univ Paris Sud XI
//
//          Distributed under the Boost Software License, Version 1.0.
//                 See accompanying file LICENSE.txt or copy at
//                     http://www.boost.org/LICENSE_1_0.txt
//==============================================================================
#define NT2_UNIT_MODULE "nt2 boost.simd.arithmetic toolbox - sqr/scalar Mode"

//////////////////////////////////////////////////////////////////////////////
// unit test behavior of boost.simd.arithmetic components in scalar mode
//////////////////////////////////////////////////////////////////////////////
/// created by jt the 01/12/2010
///
#include <boost/simd/arithmetic/include/functions/sqr.hpp>
#include <boost/simd/include/functions/mul.hpp>
#include <boost/type_traits/is_same.hpp>
#include <boost/dispatch/functor/meta/call.hpp>
#include <nt2/sdk/unit/tests.hpp>
#include <nt2/sdk/unit/module.hpp>
#include <boost/simd/constant/constant.hpp>


NT2_TEST_CASE_TPL ( sqr_real__1_0,  BOOST_SIMD_REAL_TYPES)
{

  using boost::simd::sqr;
  using boost::simd::tag::sqr_;
  typedef typename boost::dispatch::meta::as_integer<T>::type iT;
  typedef typename boost::dispatch::meta::call<sqr_(T)>::type r_t;
  typedef typename boost::simd::meta::scalar_of<r_t>::type sr_t;
  typedef typename boost::simd::meta::scalar_of<r_t>::type ssr_t;
  typedef typename boost::common_type<T,T>::type wished_r_t;


  // return type conformity test
  NT2_TEST( (boost::is_same < r_t, wished_r_t >::value) );
  std::cout << std::endl;



  // specific values tests
  NT2_TEST_ULP_EQUAL(sqr(boost::simd::Inf<T>()), boost::simd::Inf<T>(), 0);
  NT2_TEST_ULP_EQUAL(sqr(boost::simd::Minf<T>()), boost::simd::Inf<T>(), 0);
  NT2_TEST_ULP_EQUAL(sqr(boost::simd::Mone<T>()), boost::simd::One<T>(), 0);
  NT2_TEST_ULP_EQUAL(sqr(boost::simd::Nan<T>()), boost::simd::Nan<T>(), 0);
  NT2_TEST_ULP_EQUAL(sqr(boost::simd::One<T>()), boost::simd::One<T>(), 0);
  NT2_TEST_ULP_EQUAL(sqr(boost::simd::Zero<T>()), boost::simd::Zero<T>(), 0);
  for(T i=-5; i <=  T(5) ; i+= T(0.5))
    {
      for(T j =-5; j < T(5); j+= T(0.5))
        {
          std::cout << i << "+i*(" << j << ") -> " << nt2::sqrt(cT(i, j)) << std::endl;
          NT2_TEST_ULP_EQUAL(nt2::sqr(cT(i, j)), nt2::mul(cT(i, j),cT(i, j)) , 10);
        }
    }
} // end of test for floating_

