//==============================================================================
//         Copyright 2003 - 2011  LASMEA UMR 6602 CNRS/Univ. Clermont II
//         Copyright 2009 - 2011  LRI    UMR 8623 CNRS/Univ Paris Sud XI
//
//          Distributed under the Boost Software License, Version 1.0.
//                 See accompanying file LICENSE.txt or copy at
//                     http://www.boost.org/LICENSE_1_0.txt
//==============================================================================
#ifndef BOOST_DISPATCH_FUNCTOR_PREPROCESSOR_CALL_HPP_INCLUDED
#define BOOST_DISPATCH_FUNCTOR_PREPROCESSOR_CALL_HPP_INCLUDED

/*!
 * \file
 * \brief Defines macros for building a \ref boost::dispatch::ext::call specialization
 */

#include <boost/dispatch/details/typeof.hpp>
#include <boost/dispatch/meta/result_of.hpp>
#include <boost/dispatch/preprocessor/strip.hpp>
#include <boost/dispatch/functor/preprocessor/dispatch.hpp>
#include <boost/preprocessor/repetition/enum_params.hpp>
#include <boost/preprocessor/repetition/enum_binary_params.hpp>
#include <boost/preprocessor/repetition/repeat.hpp>
#include <boost/preprocessor/repetition/enum.hpp>
#include <boost/preprocessor/array/elem.hpp>

//==============================================================================
/*!
 * Generates a \ref boost::dispatch::ext::call specialization \c operator() prototype.
 * In this function, arguments are defined as \c a0,...,an-1.
 *
 * \param N Number of parameters for the current \ref boost::dispatch::ext::call
 *
 * \usage
 *
 * \code
 * BOOST_DISPATCH_CALL(3)
 * {
 *   return a0 + a1/a2;
 * }
 * \endcode
 */
//==============================================================================
#define BOOST_DISPATCH_CALL(N)                                                 \
result_type operator()( BOOST_PP_ENUM_BINARY_PARAMS(N,A,const& a) ) const      \
/**/

//==============================================================================
/*!
 * Generates a \ref boost::dispatch::ext::call specialization \c operator() prototype
 * along with a result_type typedef.
 *
 * \param N Number of parameters for the current \ref boost::dispatch::ext::call
 * \param Args Arguments to the function, with type and name
 * \param Body Function body, must be a single expression
 *
 * \usage
 *
 * \code
 * BOOST_DISPATCH_RETURNS(3, (A0 const& a0, A1 const& a1, A2 const& a2),
 *   a0 + a1/a2
 * )
 * \endcode
 */
//==============================================================================
#define BOOST_DISPATCH_RETURNS(N, Args, Body)                                  \
BOOST_PP_REPEAT(N, BOOST_DISPATCH_RETURNS_, (N, Args))                         \
typedef BOOST_DISPATCH_TYPEOF(Body) result_type;                               \
BOOST_FORCEINLINE result_type operator()Args const { return Body; }            \
/**/

#define BOOST_DISPATCH_RETURNS_(z, n, Args)                                    \
static BOOST_PP_ARRAY_ELEM(n, Args);                                           \
/**/

//==============================================================================
/*!
 * Generates a \ref boost::dispatch::ext::call specialization \c operator() prototype.
 * In this function, arguments are defined as \c a0,...,an-1 of the same type
 * \c A0.
 *
 * \param N Number of parameters for the current \ref boost::dispatch::ext::call
 *
 * \usage
 *
 * \code
 * BOOST_DISPATCH_CALL_REPEAT(3)
 * {
 *   return a0 + a1/a2;
 * }
 * \endcode
 */
//==============================================================================
#define BOOST_DISPATCH_CALL_REPEAT(N)                                          \
result_type operator()( BOOST_PP_ENUM_PARAMS(N,A0 const& a) ) const            \
/**/

#define BOOST_DISPATCH_IMPLEMENT_BODY(Tag, Site, Types, Seq, M)                \
template< BOOST_PP_ENUM( BOOST_PP_SEQ_SIZE(Types), M, Types ) >                \
struct BOOST_DISPATCH_IMPLEMENT_(Tag, Site, Seq)                               \
/**/

#define BOOST_DISPATCH_IMPLEMENT(NS, Name, Tag, Site, Types, Seq)              \
BOOST_DISPATCH_REGISTER(NS, Name, Tag, Site, Types, Seq)                       \
BOOST_DISPATCH_IMPLEMENT_BODY(Tag, Site, Types, Seq, BOOST_DISPATCH_TYPE)      \
/**/

#define BOOST_DISPATCH_IMPLEMENT_TPL(NS, Name, Tag, Site, Types, Seq)          \
BOOST_DISPATCH_REGISTER_TPL(NS, Name, Tag, Site, Types, Seq)                   \
BOOST_DISPATCH_IMPLEMENT_BODY(Tag, Site, Types, Seq, BOOST_DISPATCH_TYPE_TPL)  \
/**/

#define BOOST_DISPATCH_IMPLEMENT_IF(NS, Name, Tag, Site, Types, Cond, Seq)     \
BOOST_DISPATCH_REGISTER_IF(NS, Name, Tag, Site, Types, Cond, Seq)              \
BOOST_DISPATCH_IMPLEMENT_BODY(Tag, Site, Types, Seq, BOOST_DISPATCH_TYPE)      \
/**/

#define BOOST_DISPATCH_IMPLEMENT_TPL_IF(NS, Name, Tag, Site, Types, Cond, Seq) \
BOOST_DISPATCH_REGISTER_TPL_IF(NS, Name, Tag, Site, Types, Cond, Seq)          \
BOOST_DISPATCH_IMPLEMENT_BODY(Tag, Site, Types, Seq, BOOST_DISPATCH_TYPE_TPL)  \
/**/


#define BOOST_DISPATCH_IMPLEMENT_GEN(NS, Tag, Site, Types, Seq)                \
BOOST_DISPATCH_REGISTER_GEN(NS, Tag, Site, Types, Seq)                         \
BOOST_DISPATCH_IMPLEMENT_BODY(Tag, Site, Types, Seq, BOOST_DISPATCH_TYPE)      \
/**/

#define BOOST_DISPATCH_IMPLEMENT_TPL_GEN(NS, Tag, Site, Types, Seq)            \
BOOST_DISPATCH_REGISTER_TPL_GEN(NS, Tag, Site, Types, Seq)                     \
BOOST_DISPATCH_IMPLEMENT_BODY(Tag, Site, Types, Seq, BOOST_DISPATCH_TYPE_TPL)  \
/**/

#define BOOST_DISPATCH_IMPLEMENT_IF_GEN(NS, Tag, Site, Types, Cond, Seq)       \
BOOST_DISPATCH_REGISTER_IF_GEN(NS, Tag, Site, Types, Cond, Seq)                \
BOOST_DISPATCH_IMPLEMENT_BODY(Tag, Site, Types, Seq, BOOST_DISPATCH_TYPE)      \
/**/

#define BOOST_DISPATCH_IMPLEMENT_TPL_IF_GEN(NS, Tag, Site, Types, Cond, Seq)   \
BOOST_DISPATCH_REGISTER_TPL_IF_GEN(NS, Tag, Site, Types, Cond, Seq)            \
BOOST_DISPATCH_IMPLEMENT_BODY(Tag, Site, Types, Seq, BOOST_DISPATCH_TYPE_TPL)  \
/**/

#endif
