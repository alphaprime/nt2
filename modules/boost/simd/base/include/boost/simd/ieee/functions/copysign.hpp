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
#ifndef BOOST_SIMD_IEEE_FUNCTIONS_COPYSIGN_HPP_INCLUDED
#define BOOST_SIMD_IEEE_FUNCTIONS_COPYSIGN_HPP_INCLUDED
#include <boost/simd/include/functor.hpp>
#include <boost/dispatch/include/functor.hpp>

/*!
 * \ingroup boost_simd_ieee
 * \defgroup boost_simd_ieee_copysign copysign
 *
 * \par Description
 * Returns a0 with the sign of a1
 * which must be of the same type.
 * For signed integer,  this is a saturated operation
 * every negative (resp positive) element getting the sign of a positive (resp. negative)
 * element will return a positive (respective negative).
 * 0 always stay positive (!)
 * In particular copysign(Valmin<T>(), < anything positive or null > ) returns Valmax<T>()
 *
 * \par Header file
 *
 * \code
 * #include <nt2/include/functions/copysign.hpp>
 * \endcode
 *
 *
 * \synopsis
 *
 * \code
 * namespace boost::simd
 * {
 *   template <class A0>
 *     meta::call<tag::copysign_(A0,A0)>::type
 *     copysign(const A0 & a0,const A0 & a1);
 * }
 * \endcode
 *
 * \param a0 the first parameter of copysign
 * \param a1 the second parameter of copysign
 *
 * \return a value of the common type of the parameters
 *
 * \par Notes
 * In SIMD mode, this function acts elementwise on the inputs vectors elements
 * \par
 *
**/

namespace boost { namespace simd { namespace tag
  {
    /*!
     * \brief Define the tag copysign_ of functor copysign
     *        in namespace boost::simd::tag for toolbox boost.simd.ieee
    **/
    struct copysign_ : ext::elementwise_<copysign_> { typedef ext::elementwise_<copysign_> parent; };
    BOOST_SIMD_FUNCTION_DECLARE(copysign_)
  }
  BOOST_DISPATCH_FUNCTION_IMPLEMENTATION(tag::copysign_, copysign, 2)
} }

#endif

// modified by jt the 25/12/2010
