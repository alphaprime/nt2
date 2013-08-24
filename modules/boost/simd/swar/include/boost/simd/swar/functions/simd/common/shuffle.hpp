//==============================================================================
//         Copyright 2003 - 2011 LASMEA UMR 6602 CNRS/Univ. Clermont II
//         Copyright 2009 - 2011 LRI    UMR 8623 CNRS/Univ Paris Sud XI
//
//          Distributed under the Boost Software License, Version 1.0.
//                 See accompanying file LICENSE.txt or copy at
//                     http://www.boost.org/LICENSE_1_0.txt
//==============================================================================
#ifndef BOOST_SIMD_SWAR_FUNCTIONS_SIMD_COMMON_SHUFFLE_HPP_INCLUDED
#define BOOST_SIMD_SWAR_FUNCTIONS_SIMD_COMMON_SHUFFLE_HPP_INCLUDED

#include <boost/simd/swar/functions/shuffle.hpp>
#include <boost/simd/sdk/meta/cardinal_of.hpp>
#include <boost/simd/sdk/meta/as_arithmetic.hpp>
#include <boost/simd/include/functions/bitwise_cast.hpp>
#include <boost/mpl/apply.hpp>
#include <boost/mpl/int.hpp>

namespace boost { namespace simd { namespace ext
{
  BOOST_SIMD_FUNCTOR_IMPLEMENTATION ( boost::simd::tag::shuffle_, tag::cpu_
                                      , (A0)(X)(P)
                                      , ((simd_< logical_<A0>, X>))
                                        (target_< unspecified_<P> >)
                                      )
  {
    typedef A0                        result_type;
    BOOST_FORCEINLINE result_type operator()(A0 const& a0, P const&) const
    {
      typedef typename meta::as_arithmetic<A0>::type type;
      return  bitwise_cast <result_type>
              ( shuffle<typename P::type>( bitwise_cast<type>(a0) ));
    }
  };

  BOOST_SIMD_FUNCTOR_IMPLEMENTATION ( boost::simd::tag::shuffle_, tag::cpu_
                                      , (A0)(X)(P)
                                      , ((simd_< arithmetic_<A0>, X>))
                                        (target_< unspecified_<P> >)
                                      )
  {
    typedef A0                                                  result_type;
    typedef typename P::type                                  permutation_t;
    typedef boost::mpl::int_<meta::cardinal_of<result_type>::value>  card_t;

    BOOST_FORCEINLINE result_type operator()(A0 const& a0, P const&) const
    {
      result_type that;
      eval(a0, that, boost::mpl::int_<card_t::value-1>());
      return that;
    }

    template<class N>
    BOOST_FORCEINLINE void eval(A0 const& a0, result_type& that, N const&) const
    {
      typedef boost::mpl::apply<permutation_t,N,card_t>  idx_t;

      // MSVC warns on impromptu conversion ...
      static const std::ptrdiff_t value = std::ptrdiff_t(idx_t::type::value);

      that[N::value] = (value >= 0) ? a0[ std::size_t(value) ]: 0;
      eval(a0,that,boost::mpl::int_<N::value-1>());
    }

    BOOST_FORCEINLINE void
    eval(A0 const&, result_type&, boost::mpl::int_<-1> const&) const
    {}
  };

  BOOST_SIMD_FUNCTOR_IMPLEMENTATION ( boost::simd::tag::shuffle_, tag::cpu_
                                      , (A0)(X)(P)
                                      , ((simd_< logical_<A0>, X>))
                                        ((simd_< logical_<A0>, X>))
                                        (target_< unspecified_<P> >)
                                      )
  {
    typedef A0                        result_type;
    BOOST_FORCEINLINE
    result_type operator()(A0 const& a0, A0 const& a1, P const&) const
    {
      typedef typename meta::as_arithmetic<A0>::type type;
      return bitwise_cast <result_type>
                          ( shuffle<typename P::type> ( bitwise_cast<type>(a0)
                                                      , bitwise_cast<type>(a1)
                                                      )
                          );
    }
  };

  BOOST_SIMD_FUNCTOR_IMPLEMENTATION ( boost::simd::tag::shuffle_, tag::cpu_
                                    , (A0)(A1)(X)(P)
                                    , ((simd_< arithmetic_<A0>, X>))
                                      ((simd_< arithmetic_<A1>, X>))
                                      (target_< unspecified_<P> >)
                                    )
  {
    typedef A0                                                  result_type;
    typedef typename P::type                                  permutation_t;
    typedef boost::mpl::int_<meta::cardinal_of<result_type>::value>  card_t;

    BOOST_FORCEINLINE result_type operator()(A0 const& a0, A1 const& a1, P const&) const
    {
      result_type that;
      eval(a0, a1, that, boost::mpl::int_<card_t::value-1>());
      return that;
    }

    template<class N> BOOST_FORCEINLINE
    void eval(A0 const& a0, A1 const& a1, result_type& that, N const&) const
    {
      typedef typename boost::mpl::apply<permutation_t,N,card_t>::type idx_t;

      // MSVC warns on impromptu conversion ...
      static const std::ptrdiff_t value = std::ptrdiff_t(idx_t::type::value);
      static const std::ptrdiff_t card  = card_t::value;

      that[N::value]  = (value < 0) ? 0
                                    : ((value<card) ? a0[value]
                                                    : a1[value-card]
                                      );

      eval(a0,a1,that,boost::mpl::int_<N::value-1>());
    }

    BOOST_FORCEINLINE void
    eval(A0 const&, A1 const&, result_type&, boost::mpl::int_<-1> const&) const
    {}
  };
} } }

#endif
