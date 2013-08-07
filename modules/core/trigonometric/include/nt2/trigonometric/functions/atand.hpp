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
#ifndef NT2_TRIGONOMETRIC_FUNCTIONS_ATAND_HPP_INCLUDED
#define NT2_TRIGONOMETRIC_FUNCTIONS_ATAND_HPP_INCLUDED
#include <nt2/include/functor.hpp>

/*!
 * \ingroup trigonometric
 * \defgroup trigonometric_atand atand
 *
 * \par Description
 * inverse tangent in degree.
 *
 * \par Header file
 *
 * \code
 * #include <nt2/include/functions/atand.hpp>
 * \endcode
 *
 *
 * \synopsis
 *
 * \code
 * namespace nt2
 * {
 *   template <class A0>
 *     meta::call<tag::atand_(A0)>::type
 *     atand(const A0 & a0);
 * }
 * \endcode
 *
 * \param a0 the unique parameter of atand
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
     * \brief Define the tag atand_ of functor atand
     *        in namespace nt2::tag for toolbox trigonometric
    **/
    struct atand_ : ext::elementwise_<atand_> { typedef ext::elementwise_<atand_> parent; };
    NT2_FUNCTION_DECLARE(atand_)
  }
  NT2_FUNCTION_IMPLEMENTATION(tag::atand_, atand, 1)
}

#endif

// modified by jt the 25/12/2010
