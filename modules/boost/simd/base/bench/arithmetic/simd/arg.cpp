//==============================================================================
//         Copyright 2003 - 2012   LASMEA UMR 6602 CNRS/Univ. Clermont II
//         Copyright 2009 - 2012   LRI    UMR 8623 CNRS/Univ Paris Sud XI
//
//          Distributed under the Boost Software License, Version 1.0.
//                 See accompanying file LICENSE.txt or copy at
//                     http://www.boost.org/LICENSE_1_0.txt
//==============================================================================
#include <boost/simd/arithmetic/include/functions/arg.hpp>
#include <boost/simd/sdk/simd/native.hpp>
#include <nt2/sdk/bench/benchmark.hpp>
#include <nt2/sdk/bench/timing.hpp>
#include <cmath>
typedef NT2_SIMD_DEFAULT_EXTENSION  ext_t;

//////////////////////////////////////////////////////////////////////////////
// simd runtime benchmark for functor<arg_> from boost.simd.arithmetic
//////////////////////////////////////////////////////////////////////////////
using boost::simd::tag::arg_;

//////////////////////////////////////////////////////////////////////////////
// range macro
//////////////////////////////////////////////////////////////////////////////
#define RS(T,V1,V2) (T, (V1) ,(V2))

namespace n1 {
  typedef float T;
  typedef boost::simd::native<T,ext_t> vT;
  NT2_TIMING(arg_,(RS(vT,-10.0f,10.0f)))
}
namespace n2 {
  typedef double T;
  typedef boost::simd::native<T,ext_t> vT;
  NT2_TIMING(arg_,(RS(vT,-10.0,10.0)))
}
namespace n3 {
  typedef boost::simd::int32_t T;
  typedef boost::simd::native<T,ext_t> vT;
  NT2_TIMING(arg_,(RS(vT,-100,100)))
}
namespace n4 {
  typedef boost::simd::int64_t T;
  typedef boost::simd::native<T,ext_t> vT;
  NT2_TIMING(arg_,(RS(vT,-100,100)))
}
namespace n5 {
  typedef boost::simd::int32_t T;
  typedef boost::simd::native<T,ext_t> vT;
  NT2_TIMING(arg_,(RS(vT,-100,100)))
}
namespace n6 {
  typedef boost::simd::int64_t T;
  typedef boost::simd::native<T,ext_t> vT;
  NT2_TIMING(arg_,(RS(vT,-100,100)))
}
#undef RS
