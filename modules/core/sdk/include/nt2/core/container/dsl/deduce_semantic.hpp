//==============================================================================
//         Copyright 2003 - 2012   LASMEA UMR 6602 CNRS/Univ. Clermont II
//         Copyright 2009 - 2012   LRI    UMR 8623 CNRS/Univ Paris Sud XI
//
//          Distributed under the Boost Software License, Version 1.0.
//                 See accompanying file LICENSE.txt or copy at
//                     http://www.boost.org/LICENSE_1_0.txt
//==============================================================================
#ifndef NT2_CORE_CONTAINER_DSL_DEDUCE_SEMANTIC_HPP_INCLUDED
#define NT2_CORE_CONTAINER_DSL_DEDUCE_SEMANTIC_HPP_INCLUDED

#include <nt2/sdk/memory/forward/container.hpp>
#include <nt2/dsl/functions/terminal.hpp>
#include <boost/dispatch/meta/hierarchy_of.hpp>
#include <boost/proto/traits.hpp>

namespace nt2
{
  namespace tag { struct table_; }

  namespace ext
  {
    template<typename Tag, typename Domain, int Arity, typename Expr>
    struct deduce_semantic
    {
      typedef tag::table_ type;
    };

    template<typename Domain, typename Expr>
    struct deduce_semantic<nt2::tag::terminal_, Domain, 0, Expr>
    {
      typedef typename Expr::semantic_type  type;
    };
  }

  namespace meta
  {
    template<typename Expr>
    struct  deduce_semantic
          : ext::deduce_semantic< typename boost::dispatch::meta::
                                           hierarchy_of < typename boost::proto
                                                          ::tag_of<Expr>::type
                                                        >::type
                                , typename boost::proto::domain_of<Expr>::type
                                , boost::proto::arity_of<Expr>::value
                                , Expr
                                >
    {};

    template<typename Expr>
    struct deduce_semantic<Expr&> : deduce_semantic<Expr> {};

    template<typename Expr>
    struct deduce_semantic<Expr const> : deduce_semantic<Expr> {};
  }
}

#include <nt2/core/container/dsl/details/semantic/elementwise.hpp>

#endif
