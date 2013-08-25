//==============================================================================
//         Copyright 2003 - 2012   LASMEA UMR 6602 CNRS/Univ. Clermont II
//         Copyright 2009 - 2012   LRI    UMR 8623 CNRS/Univ Paris Sud XI
//
//          Distributed under the Boost Software License, Version 1.0.
//                 See accompanying file LICENSE.txt or copy at
//                     http://www.boost.org/LICENSE_1_0.txt
//==============================================================================
#ifndef BOOST_SIMD_ARITHMETIC_FUNCTIONS_RANDOM_HPP_INCLUDED
#define BOOST_SIMD_ARITHMETIC_FUNCTIONS_RANDOM_HPP_INCLUDED
#include <boost/simd/include/functor.hpp>
#include <boost/dispatch/include/functor.hpp>

/*!
 * \ingroup boost_simd_arithmetic
 * \defgroup boost_simd_arithmetic_random random
 *
 * \par Description
 * return uniform random numbers of the common type of the entries and
 * in the range defined by \f$[\min(a_0,a_1),\max(a0,a1)[\f$
 *
 * \par Header file
 *
 * \code
 * #include <nt2/include/functions/random.hpp>
 * \endcode
 *
 *
 * \synopsis
 *
 * \code
 * namespace boost::simd
 * {
 *   template <class A0>
 *     meta::call<tag::random_(A0,A0)>::type
 *     random(const A0 & a0,const A0 & a1);
 * }
 * \endcode
 *
 * \param a0 the first parameter of random
 * \param a1 the second parameter of random
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
     * \brief Define the tag random_ of functor random
     *        in namespace boost::simd::tag for toolbox boost.simd.arithmetic
    **/
    struct random_ : ext::elementwise_<random_> { typedef ext::elementwise_<random_> parent; };
  }
  BOOST_DISPATCH_FUNCTION_IMPLEMENTATION(tag::random_, random, 2)
} }

#endif


