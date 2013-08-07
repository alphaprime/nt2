//==============================================================================
//         Copyright 2003 - 2012   LASMEA UMR 6602 CNRS/Univ. Clermont II
//         Copyright 2009 - 2012   LRI    UMR 8623 CNRS/Univ Paris Sud XI
//
//          Distributed under the Boost Software License, Version 1.0.
//                 See accompanying file LICENSE.txt or copy at
//                     http://www.boost.org/LICENSE_1_0.txt
//==============================================================================
/*!
 * \file
**/
#ifndef BOOST_SIMD_BITWISE_FUNCTIONS_FIRSTBITUNSET_HPP_INCLUDED
#define BOOST_SIMD_BITWISE_FUNCTIONS_FIRSTBITUNSET_HPP_INCLUDED
#include <boost/simd/include/functor.hpp>
#include <boost/dispatch/include/functor.hpp>

/*!
 * \ingroup boost_simd_bitwise
 * \defgroup boost_simd_bitwise_firstbitunset firstbitunset
 *
 * \par Description
 * The function  find the first bit unset (beginning with the least
 * significant bit) in a0, and return the bit pattern in which
 * this bit is the only bit set.
 *
 * \par Header file
 *
 * \code
 * #include <nt2/include/functions/firstbitunset.hpp>
 * \endcode
 *
 *
 * \synopsis
 *
 * \code
 * namespace boost::simd
 * {
 *   template <class A0>
 *     meta::call<tag::firstbitunset_(A0)>::type
 *     firstbitunset(const A0 & a0);
 * }
 * \endcode
 *
 * \param a0 the unique parameter of firstbitunset
 *
 * \return always returns an integer value
 *
 * \par Notes
 * In SIMD mode, this function acts elementwise on the inputs vectors elements
 * \par
 *
**/

namespace boost { namespace simd { namespace tag
  {
    /*!
     * \brief Define the tag firstbitunset_ of functor firstbitunset
     *        in namespace boost::simd::tag for toolbox boost.simd.bitwise
    **/
    struct firstbitunset_ : ext::elementwise_<firstbitunset_> { typedef ext::elementwise_<firstbitunset_> parent; };
    BOOST_SIMD_FUNCTION_DECLARE(firstbitunset_)
  }
  BOOST_DISPATCH_FUNCTION_IMPLEMENTATION(tag::firstbitunset_, firstbitunset, 1)
} }

#endif

// modified by jt the 25/12/2010
