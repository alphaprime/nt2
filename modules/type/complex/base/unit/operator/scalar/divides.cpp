//==============================================================================
//         Copyright 2003 - 2012   LASMEA UMR 6602 CNRS/Univ. Clermont II
//         Copyright 2009 - 2012   LRI    UMR 8623 CNRS/Univ Paris Sud XI
//
//          Distributed under the Boost Software License, Version 1.0.
//                 See accompanying file LICENSE.txt or copy at
//                     http://www.boost.org/LICENSE_1_0.txt
//==============================================================================
#define NT2_UNIT_MODULE "nt2 complex.operator toolbox - divides/scalar Mode"

//////////////////////////////////////////////////////////////////////////////
// unit test behavior of boost.simd.operator components in scalar mode
//////////////////////////////////////////////////////////////////////////////
/// created  by jt the 18/02/2011
///
#include <nt2/operator/include/functions/divides.hpp>
#include <boost/simd/sdk/simd/logical.hpp>
#include <boost/type_traits/is_same.hpp>
#include <boost/dispatch/functor/meta/call.hpp>
#include <nt2/sdk/unit/tests.hpp>
#include <nt2/sdk/unit/module.hpp>
#include <nt2/constant/constant.hpp>

NT2_TEST_CASE_TPL ( divides_real__2_0,  BOOST_SIMD_REAL_TYPES)
{

  using nt2::divides;
  using nt2::tag::divides_;
  typedef std::complex<T> cT;
  typedef typename boost::dispatch::meta::as_integer<T>::type iT;
  typedef typename boost::dispatch::meta::call<divides_(cT,cT)>::type r_t;
  typedef typename nt2::meta::scalar_of<r_t>::type sr_t;
  typedef typename nt2::meta::scalar_of<r_t>::type ssr_t;
  typedef cT wished_r_t;

  // return type conformity test
  NT2_TEST( (boost::is_same < r_t, wished_r_t >::value) );
  std::cout << std::endl;



  // specific values tests
  NT2_TEST_ULP_EQUAL(nt2::divides(cT(nt2::Inf<T>()),  cT(nt2::Inf<T>())),  cT(nt2::Nan<T>(), nt2::Zero<T>()), 0);
  NT2_TEST_EQUAL(nt2::divides(cT(nt2::Minf<T>()), cT(nt2::Minf<T>())), cT(nt2::Nan<T>(), nt2::Zero<T>()));
  NT2_TEST_EQUAL(nt2::divides(cT(nt2::Nan<T>()),  cT(nt2::Nan<T>())),  cT(nt2::Nan <T>(), nt2::Zero<T>()));
  NT2_TEST_EQUAL(nt2::divides(cT(nt2::One<T>()),  cT(nt2::Zero<T>())), cT(nt2::Inf<T>(), nt2::Zero<T>()));
  NT2_TEST_EQUAL(nt2::divides(cT(nt2::Zero<T>()), cT(nt2::Zero<T>())), cT(nt2::Nan<T>(), nt2::Zero<T>()));
  NT2_TEST_EQUAL(nt2::divides(cT(0, 1), cT(0, 1)), cT(1, 0));
  NT2_TEST_EQUAL(nt2::divides(cT(1, 0), T(1))    , cT(1, 0));
  NT2_TEST_EQUAL(nt2::divides(cT(0, 2), cT(0, 1)), cT(2, 0));
  NT2_TEST_EQUAL(nt2::divides(cT(1, 1), cT(1, -1)), cT(0, 1));
  NT2_TEST_EQUAL(nt2::divides(cT(0, 1), cT(nt2::Inf<T>())), cT(0));
  NT2_TEST_EQUAL(nt2::divides(T(1), cT(nt2::Inf<T>())), cT(0));

  NT2_TEST_EQUAL(nt2::divides(cT(nt2::Inf<T>(), nt2::Inf<T>()),  cT(nt2::Zero<T>(), nt2::Zero<T>())), cT(nt2::Inf<T>(), nt2::Inf<T>())  );
  NT2_TEST_EQUAL(nt2::divides(cT(nt2::One<T>(), nt2::Inf<T>()),  cT(nt2::Zero<T>(), nt2::Zero<T>())), cT(nt2::Inf<T>(), nt2::Inf<T>())  );
  NT2_TEST_EQUAL(nt2::divides(cT(nt2::One<T>(), nt2::One<T>()),  cT(nt2::Zero<T>(), nt2::Zero<T>())), cT(nt2::Inf<T>(), nt2::Inf<T>())  );
  NT2_TEST_EQUAL(nt2::divides(cT(nt2::Inf<T>(), nt2::One<T>()),  cT(nt2::Zero<T>(), nt2::Zero<T>())), cT(nt2::Inf<T>(), nt2::Inf<T>())  );
  NT2_TEST_EQUAL(nt2::divides(cT(nt2::Inf<T>(), nt2::Zero<T>()), cT(nt2::Zero<T>(), nt2::Zero<T>())), cT(nt2::Inf<T>(), nt2::Zero<T>()) );
  NT2_TEST_EQUAL(nt2::divides(cT(nt2::Zero<T>(),nt2::Inf<T>()),  cT(nt2::Zero<T>(), nt2::Zero<T>())), cT(nt2::Zero<T>(), nt2::Inf<T>())  );


  NT2_TEST_EQUAL(nt2::divides(cT(nt2::Inf<T>(), nt2::Inf<T>()),  cT(nt2::One<T>(),  nt2::Zero<T>())), cT(nt2::Inf<T>(), nt2::Inf<T>())  );
  NT2_TEST_EQUAL(nt2::divides(cT(nt2::One<T>(), nt2::Inf<T>()),  cT(nt2::Zero<T>(), nt2::One<T>())),  cT(nt2::Inf<T>(), nt2::Mone<T>()) );
  NT2_TEST_EQUAL(nt2::divides(cT(nt2::Inf<T>(), nt2::Inf<T>()),  cT(nt2::One<T>(),  nt2::One<T>())),  cT(nt2::Inf<T>(), nt2::Nan<T>()) );
  NT2_TEST_EQUAL(nt2::divides(cT(nt2::Inf<T>(), nt2::One<T>()),  cT(nt2::One<T>(),  nt2::One<T>())),  cT(nt2::Inf<T>(), nt2::Minf<T>()) );

  NT2_TEST_EQUAL(nt2::divides(cT(nt2::One<T>(), nt2::Zero<T>()), cT(nt2::Inf<T>(),  nt2::Zero<T>())), cT(nt2::Zero<T>(), nt2::Zero<T>()) );
  NT2_TEST_EQUAL(nt2::divides(cT(nt2::One<T>(), nt2::Zero<T>()), cT(nt2::Zero<T>(), nt2::Inf<T>())),  cT(nt2::Zero<T>(), nt2::Zero<T>()) );
  NT2_TEST_EQUAL(nt2::divides(cT(nt2::One<T>(), nt2::One<T>()),  cT(nt2::Inf<T>(),  nt2::One<T>())),  cT(nt2::Zero<T>(), nt2::Zero<T>()) );
  NT2_TEST_EQUAL(nt2::divides(cT(nt2::One<T>(), nt2::One<T>()),  cT(nt2::One<T>(),  nt2::Inf<T>())),  cT(nt2::Zero<T>(), nt2::Zero<T>()) );

} // end of test for floating_
