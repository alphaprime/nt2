//==============================================================================
//         Copyright 2003 - 2012   LASMEA UMR 6602 CNRS/Univ. Clermont II
//         Copyright 2009 - 2012   LRI    UMR 8623 CNRS/Univ Paris Sud XI
//
//          Distributed under the Boost Software License, Version 1.0.
//                 See accompanying file LICENSE.txt or copy at
//                     http://www.boost.org/LICENSE_1_0.txt
//==============================================================================
#include <nt2/bitwise/include/functions/rol.hpp>
#include <vector>
#include <nt2/include/constants/valmin.hpp>
#include <nt2/include/constants/valmax.hpp>

#include <nt2/sdk/unit/tests/cover.hpp>
#include <nt2/sdk/unit/module.hpp>
#include <nt2/sdk/meta/as_integer.hpp>
#include <boost/simd/sdk/simd/native.hpp>
#include <boost/simd/sdk/simd/io.hpp>

NT2_TEST_CASE_TPL ( rol_all_types,  NT2_SIMD_INTEGRAL_TYPES)
{
  using nt2::rol;
  using nt2::tag::rol_;
  using boost::simd::native;
  typedef NT2_SIMD_DEFAULT_EXTENSION  ext_t;
  typedef native<T,ext_t>                nT;
  typedef typename nt2::meta::as_integer<T>::type iT;
  typedef typename nt2::meta::call<rol_(T, iT)>::type r_t;

  // random verifications
  nt2::uint32_t NR  = NT2_NB_RANDOM_TEST;
  std::vector<T> in1(NR);
  std::vector<iT> in2(NR);
  nt2::roll(in1, nt2::Valmin<T>()/2, nt2::Valmax<T>()/2);
  nt2::roll(in2, nt2::Valmin<T>()/2, nt2::Valmax<T>()/2);

  std::vector<r_t> ref(NR);
  for(nt2::uint32_t i=0; i < NR ; ++i) ref[i] = rol(in1[i], in2[i]);
  NT2_COVER_ULP_EQUAL(rol_, ((nT, in1))((nT, in2)), ref, 0);

}
