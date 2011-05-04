//////////////////////////////////////////////////////////////////////////////
///   Copyright 2003 and onward LASMEA UMR 6602 CNRS/U.B.P Clermont-Ferrand
///   Copyright 2009 and onward LRI    UMR 8623 CNRS/Univ Paris Sud XI
///
///          Distributed under the Boost Software License, Version 1.0
///                 See accompanying file LICENSE.txt or copy at
///                     http://www.boost.org/LICENSE_1_0.txt
//////////////////////////////////////////////////////////////////////////////
#define NT2_UNIT_MODULE "nt2 dual toolbox - two_sum/simd Mode"

//////////////////////////////////////////////////////////////////////////////
// Test behavior of dual components in simd mode
//////////////////////////////////////////////////////////////////////////////
/// created by jt the 05/03/2011
/// modified by jt the 03/05/2011
#include <nt2/toolbox/dual/dual.hpp>
#include <nt2/sdk/memory/is_aligned.hpp>
#include <nt2/sdk/memory/aligned_type.hpp>
#include <nt2/sdk/memory/load.hpp>
#include <nt2/sdk/memory/buffer.hpp>
#include <boost/type_traits/is_same.hpp>
#include <nt2/sdk/functor/meta/call.hpp>
#include <nt2/sdk/unit/tests.hpp>
#include <nt2/sdk/unit/module.hpp>
#include <nt2/sdk/constant/real.hpp>
#include <nt2/sdk/constant/infinites.hpp>
#include <nt2/include/functions/max.hpp>
#include <nt2/toolbox/dual/include/two_sum.hpp>

NT2_TEST_CASE_TPL ( two_sum_real__2_0,  NT2_REAL_TYPES)
{
  using nt2::two_sum;
  using nt2::tag::two_sum_;
  using nt2::load; 
  using nt2::simd::native;
  using nt2::meta::cardinal_of;
  typedef NT2_SIMD_DEFAULT_EXTENSION  ext_t;
  typedef typename nt2::meta::upgrade<T>::type   u_t;
  typedef native<T,ext_t>                        n_t;
  typedef n_t                                     vT;
  typedef typename nt2::meta::as_integer<T>::type iT;
  typedef native<iT,ext_t>                       ivT;
  typedef typename nt2::meta::call<two_sum_(vT,vT)>::type r_t;
  typedef typename nt2::meta::call<two_sum_(T,T)>::type sr_t;
  typedef typename nt2::meta::scalar_of<r_t>::type ssr_t;
  double ulpd;
  ulpd=0.0;
  r_t res;
  res = two_sum(nt2::One<vT>(), nt2::Eps<vT>()/nt2::Two<vT>());
  std::cout << boost::fusion::at_c<0>(res)<< ", " << boost::fusion::at_c<1>(res) << std::endl;

//   nt2::dual<vT> a(nt2::One<vT>(), nt2::Eps<vT>()/nt2::Four<vT>());
//   std::cout << "(" << a.hi() << ", " << a.lo() << ")" << std::endl;
//   a +=  nt2::One<vT>();
//   std::cout << "(" << a.hi() << ", " << a.lo() << ")" << std::endl;
//   a +=  a;
//   std::cout << "(" << a.hi() << ", " << a.lo() << ")" << std::endl;

} // end of test for real_
