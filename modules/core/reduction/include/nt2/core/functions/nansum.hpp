//==============================================================================
//         Copyright 2003 - 2012   LASMEA UMR 6602 CNRS/Univ. Clermont II
//         Copyright 2009 - 2012   LRI    UMR 8623 CNRS/Univ Paris Sud XI
//         Copyright 2011 - 2012   MetaScale SAS
//
//          Distributed under the Boost Software License, Version 1.0.
//                 See accompanying file LICENSE.txt or copy at
//                     http://www.boost.org/LICENSE_1_0.txt
//==============================================================================
#ifndef NT2_CORE_FUNCTIONS_NANSUM_HPP_INCLUDED
#define NT2_CORE_FUNCTIONS_NANSUM_HPP_INCLUDED

#include <nt2/include/functor.hpp>

/*!
 * \ingroup core
 * \defgroup core nansum
 *
 * \par Description
 * Returns the nansum of the elements of the SIMD vector
 *
 * \par Header file
 *
 * \code
 * #include <nt2/include/functions/nansum.hpp>
 * \endcode
 *
 *
 * \synopsis
 *
 * \code
 * namespace boost::simd
 * {
 *   template <class A0>
 *     meta::call<tag::nansum_(A0)>::type
 *     nansum(const A0 & a0);
 * }
 * \endcode
 *
 * \param a0 the unique parameter of nansum
 *
 * \return always a scalar value
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


namespace nt2
{
  namespace tag
  {
    struct nansum_ : boost::dispatch::tag::formal_
    {
      typedef boost::dispatch::tag::formal_ parent;
    };
  }

  //============================================================================
  /*!
   * mean of a table,  suppressing Nans
   *
   * \param xpr  table
   */
  //============================================================================
  NT2_FUNCTION_IMPLEMENTATION(nt2::tag::nansum_       , nansum, 1)
  NT2_FUNCTION_IMPLEMENTATION(nt2::tag::nansum_       , nansum, 2)
}

#endif
