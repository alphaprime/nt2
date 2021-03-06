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
#ifndef BOOST_SIMD_REDUCTION_FUNCTIONS_IS_INCLUDED_HPP_INCLUDED
#define BOOST_SIMD_REDUCTION_FUNCTIONS_IS_INCLUDED_HPP_INCLUDED
#include <boost/simd/include/functor.hpp>
#include <boost/dispatch/include/functor.hpp>

/*!
 * \ingroup boost.simd.reduction
 * \defgroup boost.simd.reduction_is_included is_included
 *
 * \par Description
 * The function returns the a bool
 * true is only if all bits set in a0 are also set in a1
 *
 * \par Header file
 *
 * \code
 * #include <nt2/include/functions/is_included.hpp>
 * \endcode
 *
 * \par Alias
 * \arg testz
 *
 * \synopsis
 *
 * \code
 * namespace boost::simd
 * {
 *   template <class A0>
 *     meta::call<tag::is_included_(A0,A0)>::type
 *     is_included(const A0 & a0,const A0 & a1);
 * }
 * \endcode
 *
 * \param a0 the first parameter of is_included
 * \param a1 the second parameter of is_included
 *
 * \return an integer value
 *
 * \par Notes
 * \par
 * This is a reduction operation. As such it has no real interest outside
 * SIMD mode.
 * \par
 * Such an operation always has a scalar result which translate a property
 * of the whole SIMD vector.
 * \par
 * If usable and used in scalar mode, it reduces to the operation as acting
 * on a one element vector.
 *
**/

namespace boost { namespace simd { namespace tag
  {
    /*!
     * \brief Define the tag is_included_ of functor is_included
     *        in namespace boost::simd::tag for toolbox boost.simd.reduction
    **/
    struct is_included_ : ext::unspecified_<is_included_> { typedef ext::unspecified_<is_included_> parent; };
  }
  BOOST_DISPATCH_FUNCTION_IMPLEMENTATION(tag::is_included_, is_included, 2)
  BOOST_DISPATCH_FUNCTION_IMPLEMENTATION(tag::is_included_, testz, 2)
} }

#endif

