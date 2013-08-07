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
#ifndef BOOST_SIMD_ARITHMETIC_FUNCTIONS_ROUND_HPP_INCLUDED
#define BOOST_SIMD_ARITHMETIC_FUNCTIONS_ROUND_HPP_INCLUDED
#include <boost/simd/include/functor.hpp>
#include <boost/dispatch/include/functor.hpp>

/*!
 * \ingroup boost_simd_arithmetic
 * \defgroup boost_simd_arithmetic_round round
 *
 * \par Description
 * return a value of the same type of the entry
 * which is the integer nearest to the entry
 *
 * \par Header file
 *
 * \code
 * #include <nt2/include/functions/round.hpp>
 * \endcode
 *
 *
 * \synopsis
 *
 * \code
 * namespace boost::simd
 * {
 *   template <class A0>
 *     meta::call<tag::round_(A0)>::type
 *     round(const A0 & a0);
 * }
 * \endcode
 *
 * \param a0 the unique parameter of round
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
     * \brief Define the tag round_ of functor round
     *        in namespace boost::simd::tag for toolbox boost.simd.arithmetic
    **/
    struct round_ : ext::elementwise_<round_> { typedef ext::elementwise_<round_> parent; };
    BOOST_SIMD_FUNCTION_DECLARE(round_)
  }
  BOOST_DISPATCH_FUNCTION_IMPLEMENTATION(tag::round_, round, 1)
} }

#endif

// modified by jt the 25/12/2010
