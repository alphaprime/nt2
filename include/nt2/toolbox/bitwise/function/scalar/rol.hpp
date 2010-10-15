//////////////////////////////////////////////////////////////////////////////
///   Copyright 2003 and onward LASMEA UMR 6602 CNRS/U.B.P Clermont-Ferrand
///   Copyright 2009 and onward LRI    UMR 8623 CNRS/Univ Paris Sud XI
///
///          Distributed under the Boost Software License, Version 1.0
///                 See accompanying file LICENSE.txt or copy at
///                     http://www.boost.org/LICENSE_1_0.txt
//////////////////////////////////////////////////////////////////////////////
#ifndef NT2_TOOLBOX_BITWISE_FUNCTION_SCALAR_ROL_HPP_INCLUDED
#define NT2_TOOLBOX_BITWISE_FUNCTION_SCALAR_ROL_HPP_INCLUDED
#include <nt2/sdk/meta/as_bits.hpp>
#include <nt2/sdk/meta/adapted_traits.hpp>
#include <nt2/sdk/meta/strip.hpp>
#include <nt2/include/functions/shli.hpp>
#include <nt2/include/functions/shri.hpp>  

namespace nt2 { namespace functors
{

  template<class Info>
  struct validate<rol_,tag::scalar_(tag::arithmetic_),Info>
  {
    template<class Sig> struct result;
    template<class This,class A0,class A1>
    struct result<This(A0,A1)> :
      meta::is_integral<A1>{}; 
  };
  /////////////////////////////////////////////////////////////////////////////
  // Compute rol(const A0& a0, const A1& a1)
  /////////////////////////////////////////////////////////////////////////////
  template<class Info>
  struct call<rol_,tag::scalar_(tag::arithmetic_),Info>
  {
    template<class Sig> struct result;
    template<class This,class A0,class A1>
    struct result<This(A0,A1)> : meta::strip<A0>{};


    NT2_FUNCTOR_CALL_DISPATCH(
      2,
      A0,
      (2, (real_,arithmetic_))
    )

    NT2_FUNCTOR_CALL_EVAL_IF(2,       real_)
    {
      typename meta::as_bits<A0>::type t0 = {a0};
      t0.bits = shli(t0.bits,a1) | shri(t0.bits, (sizeof(A0)*CHAR_BIT-a1));
      return t0.value;
    }
    NT2_FUNCTOR_CALL_EVAL_IF(2, arithmetic_)
    {
      return shli(a0, a1) | shri(a0, (sizeof(A0)*CHAR_BIT-a1));
    }
  };
} }


      
#endif
