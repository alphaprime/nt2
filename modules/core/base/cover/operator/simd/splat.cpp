//==============================================================================
//         Copyright 2003 - 2012   LASMEA UMR 6602 CNRS/Univ. Clermont II
//         Copyright 2009 - 2012   LRI    UMR 8623 CNRS/Univ Paris Sud XI
//
//          Distributed under the Boost Software License, Version 1.0.
//                 See accompanying file LICENSE.txt or copy at
//                     http://www.boost.org/LICENSE_1_0.txt
//==============================================================================
#define NT2_UNIT_MODULE "nt2 operator toolbox - splat/simd Mode"

//////////////////////////////////////////////////////////////////////////////
// cover test behavior of operator components in simd mode
//////////////////////////////////////////////////////////////////////////////
/// created  by jt the 18/02/2011
///
#include <nt2/operator/include/functions/splat.hpp>
#include <boost/simd/sdk/simd/native.hpp>
#include <nt2/include/functions/max.hpp>

#include <boost/type_traits/is_same.hpp>
#include <nt2/sdk/functor/meta/call.hpp>
#include <nt2/sdk/unit/tests.hpp>
#include <nt2/sdk/unit/module.hpp>

#include <nt2/include/constants/real.hpp>
#include <nt2/include/constants/infinites.hpp>
#include <nt2/include/functions/aligned_load.hpp>
//COMMENTED


NT2_TEST_CASE_TPL ( splat_real__1_0,  NT2_REAL_TYPES)
{
//   using nt2::splat;
//   using nt2::tag::splat_;
//   using nt2::aligned_load;
//   using boost::simd::native;
//   using nt2::meta::cardinal_of;
//   typedef BOOST_SIMD_DEFAULT_EXTENSION  ext_t;
//   typedef typename nt2::meta::upgrade<T>::type   u_t;
//   typedef native<T,ext_t>                        n_t;
//   typedef n_t                                     vT;
//   typedef typename nt2::meta::as_integer<T>::type iT;
//   typedef native<iT,ext_t>                       ivT;
//   typedef typename nt2::meta::call<splat_(vT)>::type r_t;
//   typedef typename nt2::meta::call<splat_(T)>::type sr_t;
//   typedef typename nt2::meta::scalar_of<r_t>::type ssr_t;
//   double ulpd;
//   ulpd=0.0;

//   // random verifications
//   static const nt2::uint32_t NR = NT2_NB_RANDOM_TEST;
//   {
//     NT2_CREATE_BUF(tab_a0,T, NR, nt2::Valmin<T>()/2, nt2::Valmax<T>()/2);
//     double ulp0, ulpd ; ulpd=ulp0=0.0;
//     for(nt2::uint32_t j = 0; j < NR;j+=cardinal_of<n_t>::value)
//       {
//         vT a0 = aligned_load<vT>(&tab_a0[0],j);
//         r_t v = splat(a0);
//         for(int i = 0; i< cardinal_of<n_t>::value; i++)
//         {
//           int k = i+j*cardinal_of<n_t>::value;
//           NT2_TEST_EQUAL( v[i],ssr_t(nt2::splat (a0[i])));
//         }
//       }

//   }
} // end of test for floating_
