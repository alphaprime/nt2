##############################################################################
###   Copyright 2003 and onward LASMEA UMR 6602 CNRS/U.B.P Clermont-Ferrand
###   Copyright 2009 and onward LRI    UMR 8623 CNRS/Univ Paris Sud XI
###
###          Distributed under the Boost Software License, Version 1.0
###                 See accompanying file LICENSE.txt or copy at
###                     http://www.boost.org/LICENSE_1_0.txt
##############################################################################

SET( SOURCES
  logspace_sub.cpp
  logspace_add.cpp
  sqrt1pm1.cpp
  expx2.cpp
  pow.cpp
  nthroot.cpp
  log2.cpp
  log1p.cpp
  log10.cpp
  log.cpp
  expm1.cpp
  exp2.cpp
  exp10.cpp
  exp.cpp
  iexp2.cpp
  cbrt.cpp
  realsqrt.cpp
  reallog.cpp
  realpow.cpp
  pow2.cpp
# List of simd test files for toolbox exponential
   )

nt2_module_add_tests(core.exponential.simd.unit ${SOURCES})
