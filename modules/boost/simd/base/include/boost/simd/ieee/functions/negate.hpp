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
#ifndef BOOST_SIMD_IEEE_FUNCTIONS_NEGATE_HPP_INCLUDED
#define BOOST_SIMD_IEEE_FUNCTIONS_NEGATE_HPP_INCLUDED
#include <boost/simd/include/functor.hpp>
#include <boost/dispatch/include/functor.hpp>

/*!
 * \ingroup boost_simd_ieee
 * \defgroup boost_simd_ieee_negate negate
 *
 * \par Description
 * a1 > 0 ? a0 : ((a1 == 0) 0 : -a0)
 * In other words its a0*sign(a1)
 * With floating numbers,
 * if a0 or a1 is nan the result is nan (even if a1 == 0)
 *
 * \par Header file
 *
 * \code
 * #include <nt2/include/functions/negate.hpp>
 * \endcode
 *
 *
 * \synopsis
 *
 * \code
 * namespace boost::simd
 * {
 *   template <class A0>
 *     meta::call<tag::negate_(A0,A0)>::type
 *     negate(const A0 & a0,const A0 & a1);
 * }
 * \endcode
 *
 * \param a0 the first parameter of negate
 * \param a1 the second parameter of negate
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
     * \brief Define the tag negate_ of functor negate
     *        in namespace boost::simd::tag for toolbox boost.simd.ieee
    **/
    struct negate_ : ext::elementwise_<negate_> { typedef ext::elementwise_<negate_> parent; };
  }
  BOOST_DISPATCH_FUNCTION_IMPLEMENTATION(tag::negate_, negate, 2)
} }

#endif

// modified by jt the 25/12/2010
