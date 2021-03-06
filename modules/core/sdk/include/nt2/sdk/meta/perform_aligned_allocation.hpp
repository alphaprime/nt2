//==============================================================================
//         Copyright 2003 - 2011   LASMEA UMR 6602 CNRS/Univ. Clermont II
//         Copyright 2009 - 2011   LRI    UMR 8623 CNRS/Univ Paris Sud XI
//
//          Distributed under the Boost Software License, Version 1.0.
//                 See accompanying file LICENSE.txt or copy at
//                     http://www.boost.org/LICENSE_1_0.txt
//==============================================================================
#ifndef NT2_SDK_META_PERFORM_ALIGNED_ALLOCATION_HPP_INCLUDED
#define NT2_SDK_META_PERFORM_ALIGNED_ALLOCATION_HPP_INCLUDED

#include <boost/mpl/bool.hpp>
#include <boost/simd/forward/allocator.hpp>

namespace nt2 {  namespace memory
{
  template<typename T> struct fixed_allocator;
} }

namespace nt2 {  namespace meta
{
  template<typename Allocator>
  struct perform_aligned_allocation : boost::mpl::false_
  {};

  template<typename T>
  struct  perform_aligned_allocation< nt2::memory::fixed_allocator<T> >
        : boost::mpl::true_
  {};

  template<typename T>
  struct  perform_aligned_allocation< boost::simd::allocator<T> >
        : boost::mpl::true_
  {};

  template<typename A>
  struct  perform_aligned_allocation<boost::simd::allocator_adaptor<A> >
        : boost::mpl::true_
  {};
} }

#endif
