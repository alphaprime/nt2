//==============================================================================
//         Copyright 2003 - 2012   LASMEA UMR 6602 CNRS/Univ. Clermont II
//         Copyright 2009 - 2012   LRI    UMR 8623 CNRS/Univ Paris Sud XI
//
//          Distributed under the Boost Software License, Version 1.0.
//                 See accompanying file LICENSE.txt or copy at
//                     http://www.boost.org/LICENSE_1_0.txt
//==============================================================================
#include <boost/simd/arithmetic/include/functions/adds.hpp>
#include <nt2/sdk/bench/benchmark.hpp>
#include <nt2/sdk/bench/timing.hpp>
#include <boost/simd/include/constants/valmax.hpp>
#include <boost/simd/include/constants/valmin.hpp>
#include <boost/dispatch/meta/as_integer.hpp>
#include <cmath>


//////////////////////////////////////////////////////////////////////////////
// scalar runtime benchmark for functor<adds_> from boost.simd.arithmetic
//////////////////////////////////////////////////////////////////////////////
using boost::simd::tag::adds_;

//////////////////////////////////////////////////////////////////////////////
// range macro
//////////////////////////////////////////////////////////////////////////////
#define RS(T,V1,V2) (T, T(V1) ,T(V2))

namespace n1 {
  typedef boost::simd::int8_t T;
  NT2_TIMING(adds_,(RS(T,3*(boost::simd::Valmin<T>()/4),3*(boost::simd::Valmax<T>()/4)))(RS(T,3*(boost::simd::Valmin<T>()/4),3*(boost::simd::Valmax<T>()/4))))
}
namespace n2 {
  typedef boost::simd::int16_t T;
  NT2_TIMING(adds_,(RS(T,3*(boost::simd::Valmin<T>()/4),3*(boost::simd::Valmax<T>()/4)))(RS(T,3*(boost::simd::Valmin<T>()/4),3*(boost::simd::Valmax<T>()/4))))
}
namespace n3 {
  typedef boost::simd::int32_t T;
  NT2_TIMING(adds_,(RS(T,3*(boost::simd::Valmin<T>()/4),3*(boost::simd::Valmax<T>()/4)))(RS(T,3*(boost::simd::Valmin<T>()/4),3*(boost::simd::Valmax<T>()/4))))
}
namespace n4 {
  typedef boost::simd::int64_t T;
  NT2_TIMING(adds_,(RS(T,3*(boost::simd::Valmin<T>()/4),3*(boost::simd::Valmax<T>()/4)))(RS(T,3*(boost::simd::Valmin<T>()/4),3*(boost::simd::Valmax<T>()/4))))
}
namespace n5 {
  typedef boost::simd::uint8_t T;
  NT2_TIMING(adds_,(RS(T,3*(boost::simd::Valmin<T>()/4),3*(boost::simd::Valmax<T>()/4)))(RS(T,3*(boost::simd::Valmin<T>()/4),3*(boost::simd::Valmax<T>()/4))))
}
namespace n6 {
  typedef boost::simd::uint16_t T;
  NT2_TIMING(adds_,(RS(T,3*(boost::simd::Valmin<T>()/4),3*(boost::simd::Valmax<T>()/4)))(RS(T,3*(boost::simd::Valmin<T>()/4),3*(boost::simd::Valmax<T>()/4))))
}
namespace n7 {
  typedef boost::simd::uint32_t T;
  NT2_TIMING(adds_,(RS(T,3*(boost::simd::Valmin<T>()/4),3*(boost::simd::Valmax<T>()/4)))(RS(T,3*(boost::simd::Valmin<T>()/4),3*(boost::simd::Valmax<T>()/4))))
}
namespace n8 {
  typedef boost::simd::uint64_t T;
  NT2_TIMING(adds_,(RS(T,3*(boost::simd::Valmin<T>()/4),3*(boost::simd::Valmax<T>()/4)))(RS(T,3*(boost::simd::Valmin<T>()/4),3*(boost::simd::Valmax<T>()/4))))
}

#undef RS
