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
#ifndef NT2_TRIGONOMETRIC_FUNCTIONS_ASINPI_HPP_INCLUDED
#define NT2_TRIGONOMETRIC_FUNCTIONS_ASINPI_HPP_INCLUDED
#include <nt2/include/functor.hpp>

/*!
 * \ingroup trigonometric
 * \defgroup trigonometric_asinpi asinpi
 *
 * \par Description
 * inverse sine in \f$\pi\f$ multiples.
 *
 * \par Header file
 *
 * \code
 * #include <nt2/include/functions/asinpi.hpp>
 * \endcode
 *
 *
 * \synopsis
 *
 * \code
 * namespace nt2
 * {
 *   template <class A0>
 *     meta::call<tag::asinpi_(A0)>::type
 *     asinpi(const A0 & a0);
 * }
 * \endcode
 *
 * \param a0 the unique parameter of asinpi
 *
 * \return a value of the same type as the parameter
 *
 * \par Notes
 * In SIMD mode, this function acts elementwise on the inputs vectors elements
 * \par
 *
**/

namespace nt2 {
  namespace tag
  {
    /*!
     * \brief Define the tag asinpi_ of functor asinpi
     *        in namespace nt2::tag for toolbox trigonometric
    **/
    struct asinpi_ : ext::elementwise_<asinpi_> { typedef ext::elementwise_<asinpi_> parent; };
    NT2_FUNCTION_DECLARE(asinpi_)
  }
  NT2_FUNCTION_IMPLEMENTATION(tag::asinpi_, asinpi, 1)
}

#endif
