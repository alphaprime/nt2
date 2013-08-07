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
#ifndef NT2_TRIGONOMETRIC_FUNCTIONS_REM_2PI_HPP_INCLUDED
#define NT2_TRIGONOMETRIC_FUNCTIONS_REM_2PI_HPP_INCLUDED
#include <nt2/include/functor.hpp>

/*!
 * \ingroup trigonometric
 * \defgroup trigonometric_rem_2pi rem_2pi
 *
 * \par Description
 * compute the remainder modulo \f$2*\pi\f$.
 * \par
 * the result is in \f$[-\pi, \pi]\f$. If the input
 * is near pi the output can be pi or -pi depending
 * on register disponibility if extended arithmetic is used.
 * \par Header file
 *
 * \code
 * #include <nt2/include/functions/rem_2pi.hpp>
 * \endcode
 *
 *
 * \synopsis
 *
 * \code
 * namespace nt2
 * {
 *   template <class A0>
 *     meta::call<tag::rem_2pi_(A0)>::type
 *     rem_2pi(const A0 & a0);
 * }
 * \endcode
 *
 * \param a0 the unique parameter of rem_2pi
 *
 * \return a value of the same type as the parameter
 *
 * \par Notes
 * In SIMD mode, this function acts elementwise on the inputs vectors elements
 * \par
 *
**/

namespace nt2 { namespace tag
  {
    /*!
     * \brief Define the tag rem_2pi_ of functor rem_2pi
     *        in namespace nt2::tag for toolbox trigonometric
    **/
    struct rem_2pi_ : ext::elementwise_<rem_2pi_> { typedef ext::elementwise_<rem_2pi_> parent; };
    NT2_FUNCTION_DECLARE(rem_2pi_)
  }
  NT2_FUNCTION_IMPLEMENTATION(tag::rem_2pi_, rem_2pi,1)
  NT2_FUNCTION_IMPLEMENTATION(tag::rem_2pi_, rem_2pi,2)
}

#endif

// modified by jt the 25/12/2010
