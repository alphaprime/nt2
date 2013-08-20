//==============================================================================
//         Copyright 2003 - 2011   LASMEA UMR 6602 CNRS/Univ. Clermont II
//         Copyright 2009 - 2011   LRI    UMR 8623 CNRS/Univ Paris Sud XI
//
//          Distributed under the Boost Software License, Version 1.0.
//                 See accompanying file LICENSE.txt or copy at
//                     http://www.boost.org/LICENSE_1_0.txt
//==============================================================================
#ifndef NT2_CORE_FUNCTIONS_COMMON_LINE_HPP_INCLUDED
#define NT2_CORE_FUNCTIONS_COMMON_LINE_HPP_INCLUDED

#include <nt2/core/functions/line.hpp>
#include <nt2/include/functions/run.hpp>
#include <nt2/include/functions/arith.hpp>
#include <nt2/sdk/meta/as_index.hpp>

namespace nt2 { namespace ext
{
  NT2_FUNCTOR_IMPLEMENTATION( nt2::tag::run_, tag::cpu_
                            , (A0)(State)(Data)(N)
                            , ((node_ < A0, nt2::tag::line_
                                      , N , nt2::container::domain
                                      >
                              ))
                              (generic_< integer_<State> >)
                              ((unspecified_<Data>))
                            )
  {
    typedef typename Data::type                         result_type;
    typedef typename A0::extent_type                    ext_t;
    typedef typename meta::as_index<result_type>::type  id_t;

    BOOST_FORCEINLINE result_type
    operator()(A0 const& a0, State const& p, Data const& t) const
    {
      ext_t ex0    = boost::proto::child_c<0>(a0).extent();
      std::size_t dist  =  boost::proto::child_c<4>(a0);
      std::size_t start =  boost::proto::child_c<3>(a0);

      return nt2::run ( boost::proto::child_c<0>(a0)
                      , nt2::arith<id_t>(start+p*dist, dist)
                      , t
                      );
    }
  };
} }

#endif
