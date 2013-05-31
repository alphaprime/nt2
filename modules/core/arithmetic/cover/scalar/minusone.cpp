//==============================================================================
//         Copyright 2003 - 2012   LASMEA UMR 6602 CNRS/Univ. Clermont II
//         Copyright 2009 - 2012   LRI    UMR 8623 CNRS/Univ Paris Sud XI
//
//          Distributed under the Boost Software License, Version 1.0.
//                 See accompanying file LICENSE.txt or copy at
//                     http://www.boost.org/LICENSE_1_0.txt
//==============================================================================
#define NT2_UNIT_MODULE "nt2 arithmetic toolbox - minusone/scalar Mode"

//////////////////////////////////////////////////////////////////////////////
// cover test behavior of arithmetic components in scalar mode
//////////////////////////////////////////////////////////////////////////////
#include <nt2/arithmetic/include/functions/minusone.hpp>
#include <vector>
#include <nt2/include/constants/valmin.hpp>
#include <nt2/include/constants/valmax.hpp>
#include <nt2/sdk/unit/tests.hpp>
#include <nt2/sdk/unit/tests/ulp.hpp>
#include <nt2/sdk/unit/module.hpp>
#include <nt2/sdk/unit/tests/type_expr.hpp>


NT2_TEST_CASE_TPL ( minusone_real__1_0,  NT2_SIGNED_TYPES)
{

  using nt2::minusone;
  using nt2::tag::minusone_;
  typedef typename nt2::meta::call<minusone_(T)>::type r_t;
  typedef T wished_r_t;

  // return type conformity test
  NT2_TEST_TYPE_IS( r_t, wished_r_t );

  nt2::uint32_t NR = NT2_NB_RANDOM_TEST;
  std::vector<T> in1(NR);
  nt2::roll(in1, nt2::Valmin<T>()/2, nt2::Valmax<T>()/2);
  std::vector<r_t>  ref(NR), out(NR);
  for(nt2::uint32_t i=0; i < NR ; ++i)
  {
    out[i] = minusone(in1[i]);
    ref[i] = in1[i]-1;
  }

  NT2_TEST_ULP_EQUAL(ref, out, 0);
}

NT2_TEST_CASE_TPL ( minusone_real__1_0_1,  NT2_UNSIGNED_TYPES)
{

  using nt2::minusone;
  using nt2::tag::minusone_;
  typedef typename nt2::meta::call<minusone_(T)>::type r_t;
  typedef T wished_r_t;

  // return type conformity test
  NT2_TEST_TYPE_IS( r_t, wished_r_t );

  nt2::uint32_t NR = NT2_NB_RANDOM_TEST;
  std::vector<T> in1(NR);
  nt2::roll(in1, 1, nt2::Valmax<T>()/2);
  std::vector<r_t>  ref(NR), out(NR);
  for(nt2::uint32_t i=0; i < NR ; ++i)
  {
    out[i] = minusone(in1[i]);
    ref[i] = in1[i]-1;
  }

  NT2_TEST_ULP_EQUAL(ref, out, 0);
}
