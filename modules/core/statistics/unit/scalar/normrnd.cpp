//==============================================================================
//         Copyright 2003 - 2012   LASMEA UMR 6602 CNRS/Univ. Clermont II
//         Copyright 2009 - 2012   LRI    UMR 8623 CNRS/Univ Paris Sud XI
//
//          Distributed under the Boost Software License, Version 1.0.
//                 See accompanying file LICENSE.txt or copy at
//                     http://www.boost.org/LICENSE_1_0.txt
//==============================================================================
#define NT2_UNIT_MODULE "nt2 statistics toolbox - normrnd/scalar Mode"

//////////////////////////////////////////////////////////////////////////////
// unit test behavior of statistics  components in scalar mode
//////////////////////////////////////////////////////////////////////////////
/// created  by jt the 22/02/2011
///
#include <nt2/include/functions/normrnd.hpp>
#include <nt2/include/functions/kstest.hpp>
#include <nt2/include/functions/caucdf.hpp>
#include <nt2/include/functions/unifrnd.hpp>
#include <nt2/include/functions/unifcdf.hpp>
#include <nt2/include/functions/normcdf.hpp>
#include <nt2/include/functions/rand.hpp>
#include <nt2/include/functions/ones.hpp>
#include <nt2/include/functions/zeros.hpp>
#include <nt2/include/functions/linspace.hpp>
#include <nt2/include/functions/sort.hpp>
#include <nt2/include/functions/reshape.hpp>
#include <nt2/sdk/unit/tests.hpp>
#include <nt2/sdk/unit/module.hpp>
#include <nt2/sdk/memory/buffer.hpp>
#include <nt2/constant/constant.hpp>
#include <nt2/options.hpp>
#include <nt2/table.hpp>
#include <nt2/sdk/meta/type_id.hpp>

template < class S > struct cau_cdf
{
  cau_cdf(const S& med,  const S& scal) : med_(med), scal_(scal){}

  template < class A >  typename nt2::meta::call<nt2::tag::caucdf_(const  A&, const  S&,  const S&)>::type
  operator()(const A& a) const
  {
    return nt2::caucdf(a, med_, scal_);
  }
private :
  S med_, scal_;
};

template < class S > struct unif_cdf
{
  unif_cdf(const S& a,  const S& b) : a_(a), b_(b){}

  template < class A >  typename nt2::meta::call<nt2::tag::unifcdf_(const  A&, const  S&,  const S&)>::type
  operator()(const A& a) const
  {
    return nt2::unifcdf(a, a_, b_);
  }
private :
  S a_, b_;
};


template < class S > struct norm_cdf
{
  norm_cdf(const S& ,  const S& sig) : mu_(), sig_(sig){}

  template < class A >  typename nt2::meta::call<nt2::tag::normcdf0_(const  A&, const  S&,  const S&)>::type
  operator()(const A& a) const
  {
    return nt2::normcdf(a, mu_, sig_);
  }
private :
  S mu_, sig_;
};

NT2_TEST_CASE_TPL ( normks,  NT2_REAL_TYPES)
{

  T mu = 0;
  T sig = 1;
  nt2::table<T> a = nt2::sort(normrnd(mu, sig, nt2::of_size(1, 1000)), 2);
  norm_cdf<T>  ca(mu, sig);
  T d, p;
  nt2:: kstest(a, ca, d, p);
  //Kolmogorov smirnov at 5% must succeed
  NT2_TEST_GREATER_EQUAL(p, 0.05);
}

NT2_TEST_CASE_TPL ( cauks,  NT2_REAL_TYPES)
{

  T med = 0;
  T scal = 1;
  nt2::table<T> a = nt2::sort(normrnd(med, scal, nt2::of_size(1, 1000)), 2);
  cau_cdf<T>  ca(med, scal);
  T d, p;
  nt2:: kstest(a, ca, d, p);
  //Kolmogorov smirnov at 5% must fail
  NT2_TEST_LESSER_EQUAL(p, 0.05);
}

NT2_TEST_CASE_TPL ( unifks,  NT2_REAL_TYPES)
{

  T a = -1;
  T b = 1;
  nt2::table<T> v = nt2::sort(normrnd(a, b, nt2::of_size(1, 1000)), 2);
  unif_cdf<T>  cu(a, b);
  T d, p;
  nt2:: kstest(v, cu, d, p);
  //Kolmogorov smirnov at 5% must fail
  NT2_TEST_LESSER_EQUAL(p, 0.05);
}
