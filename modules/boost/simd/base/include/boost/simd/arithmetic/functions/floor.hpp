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
#ifndef BOOST_SIMD_ARITHMETIC_FUNCTIONS_FLOOR_HPP_INCLUDED
#define BOOST_SIMD_ARITHMETIC_FUNCTIONS_FLOOR_HPP_INCLUDED
#include <boost/simd/include/functor.hpp>
#include <boost/dispatch/include/functor.hpp>

/*!
 * \ingroup boost_simd_arithmetic
 * \defgroup boost_simd_arithmetic_floor floor
 *
 * \par Description
 * return a value of the same type of the entry
 * which is the greatest integer less or equal to the entry
 *
 * \par Header file
 *
 * \code
 * #include <nt2/include/functions/floor.hpp>
 * \endcode
 *
 *
 * \synopsis
 *
 * \code
 * namespace boost::simd
 * {
 *   template <class A0>
 *     meta::call<tag::floor_(A0)>::type
 *     floor(const A0 & a0);
 * }
 * \endcode
 *
 * \param a0 the unique parameter of floor
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
     * \brief Define the tag floor_ of functor floor
     *        in namespace boost::simd::tag for toolbox boost.simd.arithmetic
    **/
    struct floor_ : ext::elementwise_<floor_> { typedef ext::elementwise_<floor_> parent; };
    BOOST_SIMD_FUNCTION_DECLARE(floor_)
  }
  BOOST_DISPATCH_FUNCTION_IMPLEMENTATION(tag::floor_, floor, 1)
} }

#endif

// modified by jt the 25/12/2010
