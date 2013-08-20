//==============================================================================
//         Copyright 2003 - 2011 LASMEA UMR 6602 CNRS/Univ. Clermont II
//         Copyright 2009 - 2011 LRI    UMR 8623 CNRS/Univ Paris Sud XI
//
//          Distributed under the Boost Software License, Version 1.0.
//                 See accompanying file LICENSE.txt or copy at
//                     http://www.boost.org/LICENSE_1_0.txt
//==============================================================================
#ifndef BOOST_SIMD_REDUCTION_FUNCTIONS_SIMD_SSE_SSE2_FIRST_HPP_INCLUDED
#define BOOST_SIMD_REDUCTION_FUNCTIONS_SIMD_SSE_SSE2_FIRST_HPP_INCLUDED
#ifdef BOOST_SIMD_HAS_SSE2_SUPPORT

#include <boost/simd/reduction/functions/first.hpp>
#include <boost/simd/include/functions/simd/bitwise_cast.hpp>
#include <boost/simd/sdk/meta/scalar_of.hpp>
#include <boost/dispatch/meta/as_floating.hpp>
#include <boost/dispatch/meta/as_integer.hpp>

namespace boost { namespace simd { namespace ext
{
  BOOST_SIMD_FUNCTOR_IMPLEMENTATION ( boost::simd::tag::first_
                                    , boost::simd::tag::sse2_
                                    , (A0)
                                    , ((simd_ < double_<A0>
                                              , boost::simd::tag::sse_
                                              >
                                      ))
                                    )
  {
    typedef typename meta::scalar_of<A0>::type result_type;
    BOOST_FORCEINLINE result_type operator()(__m128d a0) const
    {
      return _mm_cvtsd_f64(a0);
    }
  };

  BOOST_SIMD_FUNCTOR_IMPLEMENTATION ( boost::simd::tag::first_
                                    , boost::simd::tag::sse2_
                                    , (A0)
                                    , ((simd_ < single_<A0>
                                              , boost::simd::tag::sse_
                                              >
                                      ))
                                    )
  {
    typedef typename meta::scalar_of<A0>::type result_type;
    BOOST_FORCEINLINE result_type operator()(__m128 a0) const
    {
      typedef typename dispatch::meta::as_integer<A0>::type type;
      return boost::simd::bitwise_cast<result_type>(_mm_cvtsi128_si32(simd::bitwise_cast<type>(a0)));
    }
  };

  BOOST_SIMD_FUNCTOR_IMPLEMENTATION ( boost::simd::tag::first_
                                    , boost::simd::tag::sse2_
                                    , (A0)
                                    , ((simd_ < ints32_<A0>
                                              , boost::simd::tag::sse_
                                              >
                                      ))
                                    )
  {
    typedef typename meta::scalar_of<A0>::type result_type;
    BOOST_FORCEINLINE result_type operator()(__m128i a0) const
    {
      return _mm_cvtsi128_si32(a0);
    }
  };

  BOOST_SIMD_FUNCTOR_IMPLEMENTATION ( boost::simd::tag::first_
                                    , boost::simd::tag::sse2_
                                    , (A0)
                                    , ((simd_ < ints64_<A0>
                                              , boost::simd::tag::sse_
                                              >
                                      ))
                                    )
  {
    typedef typename meta::scalar_of<A0>::type result_type;
    BOOST_FORCEINLINE result_type operator()(__m128i a0) const
    {
      typedef typename dispatch::meta::as_floating<A0>::type rtype;
      return boost::simd::bitwise_cast<result_type>(_mm_cvtsd_f64(simd::bitwise_cast<rtype>(a0)));
    }
  };

  BOOST_SIMD_FUNCTOR_IMPLEMENTATION ( boost::simd::tag::first_
                                    , boost::simd::tag::sse2_
                                    , (A0)
                                    , ((simd_ < type16_<A0>
                                              , boost::simd::tag::sse_
                                              >
                                      ))
                                    )
  {
    typedef typename meta::scalar_of<A0 > ::type result_type;
    BOOST_FORCEINLINE result_type operator()(__m128i a0) const
    {
      return result_type(_mm_extract_epi16(a0, 0));
    }
  };

  BOOST_SIMD_FUNCTOR_IMPLEMENTATION ( boost::simd::tag::first_
                                    , boost::simd::tag::sse2_
                                    , (A0)
                                    , ((simd_ < type8_<A0>
                                              , boost::simd::tag::sse_
                                              >
                                      ))
                                    )
  {
    typedef typename meta::scalar_of<A0>::type result_type;

    BOOST_FORCEINLINE result_type operator()(__m128i a0) const
    {
      typedef result_type type;
      int that = _mm_extract_epi16(a0, 0);
      return result_type(that & 0xFF);
    }
  };


} } }
#endif
#endif
