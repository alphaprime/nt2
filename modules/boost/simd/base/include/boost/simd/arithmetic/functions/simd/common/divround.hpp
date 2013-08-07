//==============================================================================
//         Copyright 2003 - 2011 LASMEA UMR 6602 CNRS/Univ. Clermont II
//         Copyright 2009 - 2011 LRI    UMR 8623 CNRS/Univ Paris Sud XI
//
//          Distributed under the Boost Software License, Version 1.0.
//                 See accompanying file LICENSE.txt or copy at
//                     http://www.boost.org/LICENSE_1_0.txt
//==============================================================================
#ifndef BOOST_SIMD_ARITHMETIC_FUNCTIONS_SIMD_COMMON_DIVROUND_HPP_INCLUDED
#define BOOST_SIMD_ARITHMETIC_FUNCTIONS_SIMD_COMMON_DIVROUND_HPP_INCLUDED

#include <boost/simd/arithmetic/functions/divround.hpp>
#include <boost/simd/include/functions/simd/iround.hpp>
#include <boost/simd/include/functions/simd/tofloat.hpp>
#include <boost/simd/include/functions/simd/divs.hpp>
#include <boost/simd/include/functions/simd/plus.hpp>
#include <boost/simd/include/functions/simd/divides.hpp>
#include <boost/simd/include/functions/simd/groups.hpp>
#include <boost/simd/include/functions/simd/split.hpp>
#include <boost/simd/include/constants/two.hpp>
#include <boost/dispatch/meta/upgrade.hpp>

namespace boost { namespace simd { namespace ext
{
  BOOST_SIMD_FUNCTOR_IMPLEMENTATION_GEN( boost::simd::tag::divround_, tag::cpu_
                                   , (A0)(X)
                                   , ((simd_<integer_<A0>,X>))((simd_<integer_<A0>,X>))
                                   )
  {
    typedef A0 result_type;
    BOOST_SIMD_FUNCTOR_CALL_REPEAT(2)
    {
      return simd::iround(tofloat(a0)/tofloat(a1));
    }
  };

  BOOST_SIMD_FUNCTOR_IMPLEMENTATION_GEN( boost::simd::tag::divround_, tag::cpu_
                                   , (A0)(X)
                                   , ((simd_<unsigned_<A0>,X>))((simd_<unsigned_<A0>,X>))
                                   )
  {
    typedef A0 result_type;
    BOOST_SIMD_FUNCTOR_CALL_REPEAT(2)
    {
      return simd::rdivide(a0+a1/boost::simd::Two<A0>(), a1);
    }
  };

  BOOST_SIMD_FUNCTOR_IMPLEMENTATION_GEN( boost::simd::tag::divround_, tag::cpu_
                                   , (A0)(X)
                                   , ((simd_<int16_<A0>,X>))((simd_<int16_<A0>,X>))
                                   )
  {
    typedef A0 result_type;
    BOOST_SIMD_FUNCTOR_CALL_REPEAT(2)
    {
      typedef typename dispatch::meta::upgrade<A0>::type ivtype;
      ivtype a0l, a0h, a1l, a1h;
      boost::simd::split(a0, a0l, a0h);
      boost::simd::split(a1, a1l, a1h);
      return groups( divround(a0l, a1l)
                   , divround(a0h, a1h)
                  );
    }
  };

  BOOST_SIMD_FUNCTOR_IMPLEMENTATION_GEN( boost::simd::tag::divround_, tag::cpu_
                                   , (A0)(X)
                                   , ((simd_<int8_<A0>,X>))((simd_<int8_<A0>,X>))
                                   )
  {
    typedef A0 result_type;
    BOOST_SIMD_FUNCTOR_CALL_REPEAT(2)
    {
      typedef typename dispatch::meta::upgrade<A0>::type ivtype;
      ivtype a0l, a0h, a1l, a1h;
      boost::simd::split(a0, a0l, a0h);
      boost::simd::split(a1, a1l, a1h);
      return groups( divround(a0l, a1l)
                   , divround(a0h, a1h)
                   );
    }
  };

  BOOST_SIMD_FUNCTOR_IMPLEMENTATION_GEN( boost::simd::tag::divround_, tag::cpu_
                                   , (A0)(X)
                                   , ((simd_<floating_<A0>,X>))((simd_<floating_<A0>,X>))
                                   )
  {
    typedef A0 result_type;
    BOOST_SIMD_FUNCTOR_CALL_REPEAT(2)
    {
      return simd::round(a0/a1);
    }
  };
} } }


#endif
