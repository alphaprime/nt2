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
#ifndef BOOST_SIMD_IEEE_FUNCTIONS_PREV_HPP_INCLUDED
#define BOOST_SIMD_IEEE_FUNCTIONS_PREV_HPP_INCLUDED
#include <boost/simd/include/functor.hpp>
#include <boost/dispatch/include/functor.hpp>

/*!
 * \ingroup boost_simd_ieee
 * \defgroup boost_simd_ieee_prev prev
 *
 * \par Description
 * in the type A0 of a0, the greatest A0 strictly less than a0
 *
 * \par Header file
 *
 * \code
 * #include <nt2/include/functions/prev.hpp>
 * \endcode
 *
 *
 * \synopsis
 *
 * \code
 * namespace boost::simd
 * {
 *   template <class A0>
 *     meta::call<tag::prev_(A0)>::type
 *     prev(const A0 & a0);
 * }
 * \endcode
 *
 * \param a0 the unique parameter of prev
 *
 * \return a value of the same type as the parameter
 *
 * \par Notes
 * In SIMD mode, this function acts elementwise on the inputs vectors elements
 * \par
 *
**/

namespace boost { namespace simd { namespace tag
  {
    /*!
     * \brief Define the tag prev_ of functor prev
     *        in namespace boost::simd::tag for toolbox boost.simd.ieee
    **/
    struct prev_ : ext::elementwise_<prev_> { typedef ext::elementwise_<prev_> parent; };
    BOOST_SIMD_FUNCTION_DECLARE(prev_)
  }
  BOOST_DISPATCH_FUNCTION_IMPLEMENTATION(tag::prev_, prev, 1)
} }

#endif

// modified by jt the 25/12/2010
