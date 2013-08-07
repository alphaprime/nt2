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
#ifndef BOOST_SIMD_REDUCTION_FUNCTIONS_SUM_HPP_INCLUDED
#define BOOST_SIMD_REDUCTION_FUNCTIONS_SUM_HPP_INCLUDED
#include <boost/simd/include/functor.hpp>
#include <boost/dispatch/include/functor.hpp>
#include <boost/simd/operator/functions/plus.hpp>
#include <boost/simd/constant/constants/zero.hpp>

/*!
 * \ingroup boost_simd_reduction
 * \defgroup boost_simd_reduction_sum sum
 *
 * \par Description
 * Returns the sum of the elements of the SIMD vector
 *
 * \par Header file
 *
 * \code
 * #include <nt2/include/functions/sum.hpp>
 * \endcode
 *
 *
 * \synopsis
 *
 * \code
 * namespace boost::simd
 * {
 *   template <class A0>
 *     meta::call<tag::sum_(A0)>::type
 *     sum(const A0 & a0);
 * }
 * \endcode
 *
 * \param a0 the unique parameter of sum
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

namespace boost { namespace simd { namespace tag
  {
    /*!
     * \brief Define the tag sum_ of functor sum
     *        in namespace boost::simd::tag for toolbox boost.simd.reduction
    **/
    struct sum_ : ext::reduction_<sum_, tag::plus_, tag::Zero>
    {
      typedef ext::reduction_<sum_, tag::plus_, tag::Zero> parent;
    };
    BOOST_SIMD_FUNCTION_DECLARE(sum_)
  }
  BOOST_DISPATCH_FUNCTION_IMPLEMENTATION(tag::sum_, sum, 1)
  BOOST_DISPATCH_FUNCTION_IMPLEMENTATION(tag::sum_, sum, 2)

} }

#endif
