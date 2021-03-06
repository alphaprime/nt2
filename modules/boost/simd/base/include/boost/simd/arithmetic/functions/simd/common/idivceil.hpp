//==============================================================================
//         Copyright 2003 - 2011 LASMEA UMR 6602 CNRS/Univ. Clermont II
//         Copyright 2009 - 2011 LRI    UMR 8623 CNRS/Univ Paris Sud XI
//
//          Distributed under the Boost Software License, Version 1.0.
//                 See accompanying file LICENSE.txt or copy at
//                     http://www.boost.org/LICENSE_1_0.txt
//==============================================================================
#ifndef BOOST_SIMD_ARITHMETIC_FUNCTIONS_SIMD_COMMON_IDIVCEIL_HPP_INCLUDED
#define BOOST_SIMD_ARITHMETIC_FUNCTIONS_SIMD_COMMON_IDIVCEIL_HPP_INCLUDED

#include <boost/simd/arithmetic/functions/idivceil.hpp>
#include <boost/simd/include/functions/simd/iceil.hpp>
#include <boost/simd/include/functions/simd/plus.hpp>
#include <boost/simd/include/functions/simd/tofloat.hpp>
#include <boost/simd/include/functions/simd/divides.hpp>
#include <boost/simd/include/functions/simd/divs.hpp>
#include <boost/simd/include/functions/simd/groups.hpp>
#include <boost/simd/include/functions/simd/split.hpp>
#include <boost/simd/include/functions/simd/minusone.hpp>
#include <boost/dispatch/meta/as_integer.hpp>

namespace boost { namespace simd { namespace ext
{
  BOOST_SIMD_FUNCTOR_IMPLEMENTATION( boost::simd::tag::idivceil_, tag::cpu_
                                   , (A0)(X)
                                   , ((simd_<arithmetic_<A0>,X>))((simd_<arithmetic_<A0>,X>))
                                   )
  {
    typedef A0 result_type;
    BOOST_SIMD_FUNCTOR_CALL_REPEAT(2)
    {
      return boost::simd::iceil(boost::simd::tofloat(a0)/boost::simd::tofloat(a1));
    }
  };

  BOOST_SIMD_FUNCTOR_IMPLEMENTATION( boost::simd::tag::idivceil_, tag::cpu_
                                   , (A0)(X)
                                   , ((simd_<unsigned_<A0>,X>))((simd_<unsigned_<A0>,X>))
                                   )
  {
    typedef A0 result_type;
    BOOST_SIMD_FUNCTOR_CALL_REPEAT(2)
    {
      return boost::simd::rdivide(boost::simd::minusone(a0+a1), a1);
    }
  };

  BOOST_SIMD_FUNCTOR_IMPLEMENTATION( boost::simd::tag::idivceil_, tag::cpu_
                                   , (A0)(X)
                                   , ((simd_<ints16_<A0>,X>))((simd_<int16_<A0>,X>))
                                   )
  {

    typedef A0 result_type;

    BOOST_SIMD_FUNCTOR_CALL_REPEAT(2)
    {
      typedef typename dispatch::meta::upgrade<A0>::type ivtype;
      ivtype a0l, a0h, a1l, a1h;
      boost::simd::split(a0, a0l, a0h);
      boost::simd::split(a1, a1l, a1h);
      return boost::simd::groups(boost::simd::idivceil(a0l, a1l),
                                 boost::simd::idivceil(a0h, a1h));
    }
  };

  BOOST_SIMD_FUNCTOR_IMPLEMENTATION( boost::simd::tag::idivceil_, tag::cpu_
                                   , (A0)(X)
                                   , ((simd_<ints8_<A0>,X>))((simd_<int8_<A0>,X>))
                                   )
  {
    typedef A0 result_type;
    BOOST_SIMD_FUNCTOR_CALL_REPEAT(2)
    {
      typedef typename dispatch::meta::upgrade<A0>::type ivtype;
      ivtype a0l, a0h, a1l, a1h;
      boost::simd::split(a0, a0l, a0h);
      boost::simd::split(a1, a1l, a1h);
      return boost::simd::groups(boost::simd::idivceil(a0l, a1l),
                                 boost::simd::idivceil(a0h, a1h));
    }
  };

  BOOST_SIMD_FUNCTOR_IMPLEMENTATION( boost::simd::tag::idivceil_, tag::cpu_
                                   , (A0)(X)
                                   , ((simd_<floating_<A0>,X>))((simd_<floating_<A0>,X>))
                                   )
  {
    typedef typename dispatch::meta::as_integer<A0>::type result_type;
    BOOST_SIMD_FUNCTOR_CALL_REPEAT(2)
    {
      return boost::simd::iceil(a0/a1);
    }
  };
} } }


#endif
