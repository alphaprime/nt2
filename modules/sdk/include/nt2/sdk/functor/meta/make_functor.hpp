//==============================================================================
//         Copyright 2003 & onward LASMEA UMR 6602 CNRS/Univ. Clermont II
//         Copyright 2009 & onward LRI    UMR 8623 CNRS/Univ Paris Sud XI
//
//          Distributed under the Boost Software License, Version 1.0.
//                 See accompanying file LICENSE.txt or copy at
//                     http://www.boost.org/LICENSE_1_0.txt
//==============================================================================
#ifndef NT2_SDK_FUNCTOR_META_MAKE_FUNCTOR_HPP_INCLUDED
#define NT2_SDK_FUNCTOR_META_MAKE_FUNCTOR_HPP_INCLUDED

/*!
 * \file
 * Implements a delayed \ref functor type instanciation system
 */

namespace nt2
{
  //============================================================================
  /*!
   * \ingroup functors
   * This meta-function builds a concrete \ref functor type from a given function
   * \c Tag. It's main purpose is to delay the instanciation of \ref functor type
   * in dependant context to satisfy the two-phase look-up rule enforced by
   * clang and g++-4.6 and superior.
   *
   * \param Tag Function tag from which the \ref functor type is instanciated
   *
   * \par Models:
   * \metafunction
   *
   * \par Semantic:
   *
   * For any \c Tag :
   * \code
   * typedef make_functor<Tag>::type type;
   * \endcode
   *
   * is equivalent to
   *
   * \code
   * typedef functor<Tag> type;
   * \endcode
   */
  //============================================================================
  template<typename Tag
#if !defined(DOXYGEN_ONLY)
  , typename Dummy = void
#endif
          >
  struct make_functor
  {
    typedef functor<Tag> type;
  };
}

#endif
