//==============================================================================
//         Copyright 2003 - 2011   LASMEA UMR 6602 CNRS/Univ. Clermont II
//         Copyright 2009 - 2011   LRI    UMR 8623 CNRS/Univ Paris Sud XI
//
//          Distributed under the Boost Software License, Version 1.0.
//                 See accompanying file LICENSE.txt or copy at
//                     http://www.boost.org/LICENSE_1_0.txt
//==============================================================================
#ifndef NT2_CORE_CONTAINER_DSL_DETAILS_SEMANTIC_ELEMENTWISE_HPP_INCLUDED
#define NT2_CORE_CONTAINER_DSL_DETAILS_SEMANTIC_ELEMENTWISE_HPP_INCLUDED

#include <boost/proto/traits.hpp>
#include <boost/dispatch/meta/scalar_of.hpp>
#include <boost/dispatch/dsl/semantic_of.hpp>
#include <nt2/sdk/functor/meta/call.hpp>

#include <boost/dispatch/details/parameters.hpp>
#include <boost/preprocessor/repetition/repeat_from_to.hpp>
#include <boost/preprocessor/repetition/enum_params.hpp>
#include <boost/type_traits/is_base_and_derived.hpp>
#include <boost/mpl/placeholders.hpp>
#include <boost/mpl/vector.hpp>
#include <boost/mpl/sort.hpp>
#include <boost/mpl/if.hpp>

namespace nt2 { namespace ext
{
  //============================================================================
  // default kind_of for 0-2 arity
  //============================================================================
  template<typename Domain, typename Expr>
  struct kind_of<nt2::tag::terminal_, Domain, 0, Expr>
  {
    typedef typename Expr::kind_type  type;
  };

  template<typename Tag, typename Domain, typename Expr>
  struct kind_of<Tag, Domain, 1, Expr>
  {
    typedef typename boost::proto::result_of::child_c<Expr&,0>::value_type  A0;
    typedef typename A0::kind_type                                        type;
  };

  template<typename Tag, typename Domain, typename Expr>
  struct kind_of<Tag, Domain, 2, Expr>
  {
    typedef typename boost::proto::result_of::child_c<Expr&,0>::value_type A0;
    typedef typename boost::proto::result_of::child_c<Expr&,1>::value_type A1;
    typedef typename A0::kind_type                                      base0;
    typedef typename A1::kind_type                                      base1;

    typedef typename boost::mpl::if_< boost::is_base_and_derived<base0,base1>
                                    , base1
                                    , base0
                                    >::type                             type;

  };

  //============================================================================
  // default kind_of, sort semantic by order of closeness to their
  // common parent.
  //============================================================================
  #define M1(z,n,t)                                                            \
  typedef typename boost::proto::result_of::child_c<Expr&,n>::value_type A##n; \
  typedef typename A##n::kind_type                                    base##n; \
  /**/

  #define M0(z,n,t)                                                            \
  template<typename Tag, typename Domain, typename Expr>                       \
  struct kind_of<Tag, Domain, n, Expr>                                         \
  {                                                                            \
    BOOST_PP_REPEAT(n, M1, ~)                                                  \
    typedef boost::mpl::vector##n<BOOST_PP_ENUM_PARAMS(n,base)> bases;         \
    typedef boost::mpl::sort< bases                                            \
                            , boost::is_base_and_derived< boost::mpl::_        \
                                                        , boost::mpl::_        \
                                                        >                      \
                            >                                   sorting;       \
    typedef typename boost::mpl::at_c<typename sorting::type,n-1>::type type;  \
  };                                                                           \
  /**/

  BOOST_PP_REPEAT_FROM_TO(3, BOOST_DISPATCH_MAX_ARITY, M0, ~)

  #undef M0
  #undef M1
} }


#endif

