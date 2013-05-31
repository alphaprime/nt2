//==============================================================================
//         Copyright 2003 - 2012   LASMEA UMR 6602 CNRS/Univ. Clermont II
//         Copyright 2009 - 2012   LRI    UMR 8623 CNRS/Univ Paris Sud XI
//
//          Distributed under the Boost Software License, Version 1.0.
//                 See accompanying file LICENSE.txt or copy at
//                     http://www.boost.org/LICENSE_1_0.txt
//==============================================================================
#define NT2_UNIT_MODULE "nt2 arithmetic toolbox - fma/scalar Mode"

//////////////////////////////////////////////////////////////////////////////
// cover test behavior of arithmetic components in scalar mode
//////////////////////////////////////////////////////////////////////////////

#include <nt2/arithmetic/include/functions/fma.hpp>
#include <boost/simd/sdk/simd/io.hpp>
#include <vector>
#include <nt2/table.hpp>
#include <nt2/include/constants/valmin.hpp>
#include <nt2/include/constants/valmax.hpp>
#include <nt2/include/constants/mone.hpp>
#include <nt2/include/constants/one.hpp>
#include <nt2/sdk/unit/tests.hpp>
#include <nt2/sdk/unit/tests/ulp.hpp>
#include <nt2/sdk/unit/module.hpp>
#include <nt2/sdk/unit/tests/type_expr.hpp>


NT2_TEST_CASE_TPL ( fma_real__1_0_1,  (float))
{

  using nt2::fma;
  using nt2::tag::fma_;
  typedef typename nt2::meta::call<fma_(T, T, T)>::type r_t;
  typedef T wished_r_t;

  // return type conformity test
  NT2_TEST_TYPE_IS( r_t, wished_r_t );


  nt2::uint32_t NR = NT2_NB_RANDOM_TEST;
  std::vector<T> in1(NR), in2(NR), in3(NR);
  std::vector<r_t> ref(NR), out(NR);
  nt2::roll(in1, nt2::Mone<T>()/2, nt2::One<T>()/2);
  nt2::roll(in2, nt2::Mone<T>()/2, nt2::One<T>()/2);
  nt2::roll(in3, nt2::Mone<T>()/2, nt2::One<T>()/2);
  for(nt2::uint32_t i=0; i < NR ; ++i)
  {
    out[i] = fma(in1[i], in2[i], in3[i]);
    ref[i] = in1[i]*in2[i]+in3[i];
  }

  NT2_TEST_ULP_EQUAL(ref, out, 0);

}

NT2_TEST_CASE_TPL ( fma_real__1_0_2,  NT2_INTEGRAL_TYPES)
{

  using nt2::fma;
  using nt2::tag::fma_;
  typedef typename nt2::meta::call<fma_(T, T, T)>::type r_t;
  typedef T wished_r_t;

  // return type conformity test
  NT2_TEST_TYPE_IS( r_t, wished_r_t );
  static const nt2::uint32_t NR = NT2_NB_RANDOM_TEST;
  std::vector<T> in1(NR), in2(NR), in3(NR);
  std::vector<r_t> ref(NR), out(NR);
  nt2::roll(in1, nt2::Valmin<T>(), nt2::Valmax<T>());
  nt2::roll(in2, nt2::Valmin<T>(), nt2::Valmax<T>());
  nt2::roll(in3, nt2::Valmin<T>(), nt2::Valmax<T>());
  for(nt2::uint32_t i=0; i < NR ; ++i)
  {
    out[i] = fma(in1[i], in2[i], in3[i]);
    ref[i] = in1[i]*in2[i]+in3[i];
  }

  NT2_TEST_ULP_EQUAL(ref, out, 0);

}


