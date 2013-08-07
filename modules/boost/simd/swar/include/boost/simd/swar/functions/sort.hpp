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
#ifndef BOOST_SIMD_SWAR_FUNCTIONS_SORT_HPP_INCLUDED
#define BOOST_SIMD_SWAR_FUNCTIONS_SORT_HPP_INCLUDED
#include <boost/simd/include/functor.hpp>
#include <boost/dispatch/include/functor.hpp>
#include <boost/dispatch/meta/tieable.hpp>

/*!
 * \ingroup boost_simd_swar
 * \defgroup boost_simd_swar_sort sort
 *
 * \par Description
 * returns the sorted a0 vector in ascending order
 *
 * \par Header file
 *
 * \code
 * #include <nt2/include/functions/sort.hpp>
 * \endcode
 *
 *
 * \synopsis
 *
 * \code
 * namespace boost::simd
 * {
 *   template <class A0>
 *     meta::call<tag::sort_(A0)>::type
 *     sort(const A0 & a0);
 * }
 * \endcode
 *
 * \param a0 the unique parameter of sort
 *
 * \return a value of the same type as the parameter
 *
 * \par Notes
 * \par
 * This is a swar operation. As such it has no real interest outside
 * SIMD mode.
 * \par
 * Such an operation is a transform of an SIMD vector, that will return
 * vectors obtained on a non necessarily elementwise basis from the inputs
 * elements
 * \par
 * If usable and used in scalar mode, it reduces to the operation
 * on a one element vector.
 *
**/

namespace boost { namespace simd
{
  namespace tag
  {
    /*!
     * \brief Define the tag sort_ of functor sort
     *        in namespace boost::simd::tag for toolbox boost.simd.swar
    **/
    struct sort_ : ext::tieable_<sort_> { typedef ext::tieable_<sort_> parent; };
    BOOST_SIMD_FUNCTION_DECLARE(sort_)
  }

  BOOST_DISPATCH_FUNCTION_IMPLEMENTATION(tag::sort_, sort, 1)
  BOOST_DISPATCH_FUNCTION_IMPLEMENTATION(tag::sort_, sort, 2)
  BOOST_DISPATCH_FUNCTION_IMPLEMENTATION(tag::sort_, sort, 3)

} }

#endif
