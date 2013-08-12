//==============================================================================
//         Copyright 2003 - 2011   LASMEA UMR 6602 CNRS/Univ. Clermont II
//         Copyright 2009 - 2011   LRI    UMR 8623 CNRS/Univ Paris Sud XI
//
//          Distributed under the Boost Software License, Version 1.0.
//                 See accompanying file LICENSE.txt or copy at
//                     http://www.boost.org/LICENSE_1_0.txt
//==============================================================================
#ifndef BOOST_SIMD_DSL_FUNCTIONS_GENERIC_RUN_HPP_INCLUDED
#define BOOST_SIMD_DSL_FUNCTIONS_GENERIC_RUN_HPP_INCLUDED

#include <boost/simd/dsl/functions/run.hpp>
#include <boost/simd/sdk/functor/hierarchy.hpp>
#include <boost/simd/include/functions/terminal.hpp>
#include <boost/simd/sdk/functor/preprocessor/call.hpp>

#include <boost/simd/sdk/simd/native_fwd.hpp>
#include <boost/simd/sdk/simd/meta/vector_of.hpp>
#include <boost/simd/sdk/meta/cardinal_of.hpp>
#include <boost/simd/sdk/meta/scalar_of.hpp>
#include <boost/dispatch/meta/as.hpp>

#include <boost/dispatch/details/parameters.hpp>
#include <boost/preprocessor/repetition/repeat_from_to.hpp>
#include <boost/preprocessor/selection/min.hpp>
#include <boost/preprocessor/arithmetic/inc.hpp>

namespace boost { namespace simd { namespace ext
{
  /* Adapt Data with Expr whenever it is a target */
  template<class Expr, class Data>
  struct adapt_data
  {
    typedef Data const& type;
    BOOST_FORCEINLINE static type call(Data const& data)
    {
      return data;
    }
  };

  template<class Expr, class Data>
  struct adapt_data< Expr, boost::dispatch::meta::as_<Data> >
  {
    typedef boost::dispatch::meta::as_<typename Expr::value_type> type;
    BOOST_FORCEINLINE static type call(boost::dispatch::meta::as_<Data> const&)
    {
      return type();
    }
  };

  template<class Expr, class T, class X>
  struct adapt_data< Expr, boost::dispatch::meta::as_< boost::simd::native<T, X> > >
  {
    typedef boost::dispatch::meta::as_<
      typename boost::simd::meta::vector_of<
        typename Expr::value_type
      , boost::simd::meta::cardinal_of< boost::simd::native<T, X> >::value
      >::type
    > type;
    BOOST_FORCEINLINE static type call(boost::dispatch::meta::as_< boost::simd::native<T, X> > const&)
    {
      return type();
    }
  };

  //============================================================================
  // Run an expression without state nor data
  //============================================================================
  #define M0(z,n,t)                                                                                \
  (BOOST_DISPATCH_MAKE_CALL_TYPE(tag::run_, run_, 1, ((typename boost::proto::result_of::child_c<Expr&, n>::type)))) \
  /**/

  #define M1(z,n,t)                                                                                \
  BOOST_DISPATCH_MAKE_CALL(tag::run_, run_, 1, (boost::proto::child_c<n>(expr)))                        \
  /**/

  #define M2(z,n,t)                                                                                \
  BOOST_SIMD_FUNCTOR_IMPLEMENTATION ( run_, tag::formal_                                           \
                                    , (Expr)(T)(D)                                                 \
                                    , ((node_<Expr, unspecified_<T>, boost::mpl::long_<n>, D>))    \
                                    )                                                              \
  {                                                                                                \
    BOOST_DISPATCH_MAKE_CALL_TYPEDEF_GEN(T, n, (BOOST_PP_ENUM(n, M0, ~)), result_type);            \
    result_type operator()(Expr& expr) const                                                       \
    {                                                                                              \
      return BOOST_DISPATCH_MAKE_CALL_GEN(T, n, (BOOST_PP_ENUM(n, M1, ~)));                        \
    }                                                                                              \
  };                                                                                               \
  /**/

  BOOST_PP_REPEAT_FROM_TO( 1
                         , BOOST_PP_INC(BOOST_PP_MIN( BOOST_DISPATCH_MAX_ARITY
                                                    , BOOST_PROTO_MAX_ARITY
                                                    )
                                       )
                         , M2
                         , ~
                         )
  #undef M0
  #undef M1
  #undef M2

  //============================================================================
  // Run an expression with a state and a data
  //============================================================================

  #define M0(z,n,t)                                                                                \
  (BOOST_DISPATCH_MAKE_CALL_TYPE(tag::run_, run_, 3,                                               \
    ( (typename boost::proto::result_of::child_c<Expr&, n>::type)                                  \
    , State const&                                                                                 \
    , (typename adapt_data< typename boost::proto::result_of::                                     \
                                    child_c<Expr&, n>::value_type                                  \
                         , Data                                                                    \
                         >::type)                                                                  \
    )                                                                                              \
  ))                                                                                               \
  /**/

  #define M1(z,n,t)                                                                                \
  (BOOST_DISPATCH_MAKE_CALL(tag::run_, run_, 3,                                                    \
    ( boost::proto::child_c<n>(expr)                                                               \
    , state                                                                                        \
    , (adapt_data<typename boost::proto::result_of::child_c<Expr&, n>::value_type, Data>::call(data)) \
    )                                                                                              \
  ))                                                                                               \
  /**/

  #define M2(z,n,t)                                                                                \
  BOOST_SIMD_FUNCTOR_IMPLEMENTATION ( run_, tag::cpu_                                              \
                                    , (Expr)(T)(D)(State)(Data)                                    \
                                    , ((node_<Expr, unspecified_<T>, boost::mpl::long_<n>, D>))    \
                                      (unspecified_<State>)                                        \
                                      (unspecified_<Data>)                                         \
                                    )                                                              \
  {                                                                                                \
    BOOST_DISPATCH_MAKE_CALL_TYPEDEF_GEN(T, n, (BOOST_PP_ENUM(n, M0, ~)), result_type);            \
    result_type operator()(Expr& expr, State const& state, Data const& data) const                 \
    {                                                                                              \
      return BOOST_DISPATCH_MAKE_CALL_GEN(T, n, (BOOST_PP_ENUM(n, M1, ~)));                        \
    }                                                                                              \
  };                                                                                               \
  /**/

  BOOST_PP_REPEAT_FROM_TO( 1
                         , BOOST_PP_INC(BOOST_PP_MIN( BOOST_DISPATCH_MAX_ARITY
                                                    , BOOST_PROTO_MAX_ARITY
                                                    )
                                       )
                         , M2
                         , ~
                         )
  #undef M0
  #undef M1
  #undef M2

  //============================================================================
  // Run an expression with a state and data - Terminal cases
  // When run on a terminal, we directly jump into the terminal functor
  //============================================================================
  BOOST_SIMD_FUNCTOR_IMPLEMENTATION ( run_, tag::cpu_
                                    , (A0)(T)(D)
                                    , ((node_<A0, unspecified_<T>, mpl::long_<0>, D>))
                                    )
  {
    BOOST_DISPATCH_MAKE_CALL_TYPEDEF_GEN(T, 1, (A0&), result_type);

    BOOST_FORCEINLINE result_type
    operator()(A0& a0) const
    {
      return BOOST_DISPATCH_MAKE_CALL_GEN(T, 1, (a0));
    }
  };

  BOOST_SIMD_FUNCTOR_IMPLEMENTATION ( run_, tag::cpu_
                                    , (A0)(T)(D)(State)(Data)
                                    , ((node_<A0, unspecified_<T>, mpl::long_<0>, D>))
                                      (unspecified_<State>)
                                      (unspecified_<Data>)
                                    )
  {
    BOOST_DISPATCH_MAKE_CALL_TYPEDEF_GEN(T, 3, (A0&, State const&, Data const&), result_type);

    BOOST_FORCEINLINE result_type
    operator()(A0& a0, State const& state, Data const& data) const
    {
      return BOOST_DISPATCH_MAKE_CALL_GEN(T, 3, (a0, state, data));
    }
  };
} } }

#endif
