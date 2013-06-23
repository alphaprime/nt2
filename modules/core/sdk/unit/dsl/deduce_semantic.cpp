//==============================================================================
//         Copyright 2003 - 2012   LASMEA UMR 6602 CNRS/Univ. Clermont II
//         Copyright 2009 - 2012   LRI    UMR 8623 CNRS/Univ Paris Sud XI
//
//          Distributed under the Boost Software License, Version 1.0.
//                 See accompanying file LICENSE.txt or copy at
//                     http://www.boost.org/LICENSE_1_0.txt
//==============================================================================
#include <nt2/table.hpp>
#include <nt2/core/container/dsl/deduce_semantic.hpp>

#include <nt2/sdk/unit/module.hpp>
#include <nt2/sdk/unit/tests/relation.hpp>
#include <nt2/sdk/unit/tests/type_expr.hpp>

NT2_TEST_CASE( deduce_semantic_terminal )
{
  using nt2::meta::deduce_semantic;
  using boost::mpl::_;

  nt2::container::table<float> t;

  NT2_TEST_EXPR_TYPE(t, deduce_semantic<_>, nt2::tag::table_);
}

NT2_TEST_CASE( deduce_semantic_expr )
{
  using nt2::meta::deduce_semantic;
  using boost::mpl::_;

  nt2::container::table<float> t;

  NT2_TEST_EXPR_TYPE(t + 3.f, deduce_semantic<_>, nt2::tag::table_);
  NT2_TEST_EXPR_TYPE(3.f * t, deduce_semantic<_>, nt2::tag::table_);
  NT2_TEST_EXPR_TYPE(t - t, deduce_semantic<_>, nt2::tag::table_);
}
