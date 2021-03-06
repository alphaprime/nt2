//==============================================================================
//         Copyright 2003 - 2012 LASMEA UMR 6602 CNRS/Univ. Clermont II
//         Copyright 2009 - 2012 LRI    UMR 8623 CNRS/Univ Paris Sud XI
//
//          Distributed under the Boost Software License, Version 1.0.
//                 See accompanying file LICENSE.txt or copy at
//                     http://www.boost.org/LICENSE_1_0.txt
//==============================================================================
#ifndef NT2_SDK_ERROR_EXCEPTION_HPP_INCLUDED
#define NT2_SDK_ERROR_EXCEPTION_HPP_INCLUDED

#include <boost/exception/exception.hpp>
#include <boost/throw_exception.hpp>
#include <boost/config.hpp>
#include <iostream>
#include <stdexcept>
#include <cstdlib>
#include <string>

namespace nt2
{
  //============================================================================
  /*!
   * exception is the base class for all NT2 exceptions. It implements
   * the classical STD compliant interface, and is compatible with
   * boost::exception.
   */
  //============================================================================
  struct BOOST_SYMBOL_VISIBLE exception : boost::exception, std::runtime_error
  {
    exception(const std::string& msg) : boost::exception()
                                      , std::runtime_error(msg)
    {}
  };
}

#ifdef BOOST_NO_EXCEPTIONS
namespace boost
{
  /// INTERNAL ONLY
  /// This is a custom Boost.Exception handler that catch exceptions that were
  /// not caught by any tests inside the test function. This is usually the sign
  /// of something wrong in the test.
  extern inline
  void throw_exception(std::exception const& e)
  {
    std::cout << "uncaught exception: " << e.what() << std::endl;
    std::abort();
  }
}
#endif

#endif
