//==============================================================================
//         Copyright 2003 - 2011   LASMEA UMR 6602 CNRS/Univ. Clermont II
//         Copyright 2009 - 2011   LRI    UMR 8623 CNRS/Univ Paris Sud XI
//
//          Distributed under the Boost Software License, Version 1.0.
//                 See accompanying file LICENSE.txt or copy at
//                     http://www.boost.org/LICENSE_1_0.txt
//==============================================================================
#ifndef BOOST_SIMD_OPERATOR_FUNCTIONS_ASSIGN_HPP_INCLUDED
#define BOOST_SIMD_OPERATOR_FUNCTIONS_ASSIGN_HPP_INCLUDED

#include <boost/simd/include/functor.hpp>
#include <boost/dispatch/include/functor.hpp>
#include <boost/proto/tags.hpp>

namespace boost { namespace simd
{
  namespace tag
  {
    struct assign_ : ext::elementwise_<assign_> { typedef ext::elementwise_<assign_> parent; };
    BOOST_SIMD_FUNCTION_DECLARE(assign_)
  }

  BOOST_DISPATCH_FUNCTION_IMPLEMENTATION_SELF(tag::assign_ , assign , 2 )
  BOOST_DISPATCH_FUNCTION_IMPLEMENTATION_SELF(tag::assign_ , set    , 2 )

  BOOST_DISPATCH_FUNCTION_IMPLEMENTATION_TPL (tag::assign_ , assign, (A0 const&)(A1 const&), 2)
  BOOST_DISPATCH_FUNCTION_IMPLEMENTATION_TPL (tag::assign_ , assign, (A0 const&)(A1&), 2)
  BOOST_DISPATCH_FUNCTION_IMPLEMENTATION_TPL (tag::assign_ , assign, (A0&)(A1&), 2)
} }

namespace boost { namespace dispatch { namespace meta
{
  template<>
  struct hierarchy_of<boost::proto::tag::assign>
  {
    typedef boost::simd::tag::assign_ type;
  };
  template<>
  struct proto_tag<boost::simd::tag::assign_>
  {
    typedef boost::proto::tag::assign type;
  };
} } }

#include <boost/simd/operator/specific/common.hpp>

#endif
