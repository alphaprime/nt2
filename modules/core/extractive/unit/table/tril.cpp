//==============================================================================
//         Copyright 2003 - 2012   LASMEA UMR 6602 CNRS/Univ. Clermont II
//         Copyright 2009 - 2012   LRI    UMR 8623 CNRS/Univ Paris Sud XI
//
//          Distributed under the Boost Software License, Version 1.0.
//                 See accompanying file LICENSE.txt or copy at
//                     http://www.boost.org/LICENSE_1_0.txt
//==============================================================================
#define NT2_UNIT_MODULE "nt2::tril function"

#include <nt2/table.hpp>
#include <nt2/include/functions/tril.hpp>
#include <nt2/include/functions/oneplus.hpp>
#include <nt2/include/functions/is_greater_equal.hpp>
#include <nt2/include/functions/whereij.hpp>
#include <nt2/include/functions/reshape.hpp>

#include <nt2/sdk/unit/module.hpp>
#include <nt2/sdk/unit/tests/relation.hpp>
#include <nt2/sdk/meta/as_logical.hpp>

NT2_TEST_CASE_TPL( tril_scalar, NT2_TYPES )
{
  T x = nt2::tril(T(42));
  NT2_TEST_EQUAL( x, T(42) );

  x = nt2::tril(T(42),1);
  NT2_TEST_EQUAL( x, T(42) );

  x = nt2::tril(T(42),0);
  NT2_TEST_EQUAL( x, T(42) );

  x = nt2::tril(T(42),-1);
  NT2_TEST_EQUAL( x, T(0) );
}

NT2_TEST_CASE_TPL( tril, NT2_TYPES )
{
  nt2::table<T> xx, x, y = nt2::reshape(nt2::_(T(1), T(20)), 4, 5);
  x = nt2::tril(y);
  xx = nt2::whereij(nt2::functor<nt2::tag::is_greater_equal_>(),  y, T(0));
  NT2_TEST_EQUAL(x, xx);
}

struct fct1
{
  template < class A0, class A1>
  typename nt2::meta::as_logical<A0>::type
  operator ()(const A0& i, const A1& j) const
  {
    return nt2::ge(nt2::oneplus(i), j);
  }
};
struct fct2
{
  template < class A0, class A1>
  typename nt2::meta::as_logical<A0>::type
  operator ()(const A0& i, const A1& j) const
  {
    return nt2::ge(i, nt2::oneplus(j));
  }
};

NT2_TEST_CASE_TPL( offset_tril, NT2_TYPES )
{
  nt2::table<T> xx, x, y = nt2::reshape(nt2::_(T(1), T(20)), 4, 5);
  x = nt2::tril(y, 1);
  xx = nt2::whereij(fct1(),  y, T(0));
  NT2_TEST_EQUAL(x, xx);

  x = nt2::tril(y,-1);
  xx = nt2::whereij(fct2(),  y, T(0));
  NT2_TEST_EQUAL(x, xx);
}
