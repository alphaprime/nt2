/*******************************************************************************
 *         Copyright 2003 & onward LASMEA UMR 6602 CNRS/Univ. Clermont II
 *         Copyright 2009 & onward LRI    UMR 8623 CNRS/Univ Paris Sud XI
 *
 *          Distributed under the Boost Software License, Version 1.0.
 *                 See accompanying file LICENSE.txt or copy at
 *                     http://www.boost.org/LICENSE_1_0.txt
 ******************************************************************************/
#ifndef NT2_SDK_CONFIG_BOOTSTRAP_HPP_INCLUDED
#define NT2_SDK_CONFIG_BOOTSTRAP_HPP_INCLUDED

////////////////////////////////////////////////////////////////////////////////
// Software Support
////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
// OpenMP Support
////////////////////////////////////////////////////////////////////////////////
#define NT2_HAVE_BOOST

////////////////////////////////////////////////////////////////////////////////
// OpenMP Support
////////////////////////////////////////////////////////////////////////////////
#define NT2_HAS_OPENMP_SUPPORT

////////////////////////////////////////////////////////////////////////////////
// Native Threads Support
////////////////////////////////////////////////////////////////////////////////
#define NT2_HAS_THREADS_SUPPORT

////////////////////////////////////////////////////////////////////////////////
// MPI Support
////////////////////////////////////////////////////////////////////////////////
#define NT2_HAS_MPI_SUPPORT

////////////////////////////////////////////////////////////////////////////////
// Python Support
////////////////////////////////////////////////////////////////////////////////
#define NT2_HAS_PYTHON_SUPPORT


////////////////////////////////////////////////////////////////////////////////
// CPU Hardware Specification
////////////////////////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////////////////////////
// Logical Processor Count
////////////////////////////////////////////////////////////////////////////////
#define NT2_CONFIG_CPU_COUNT 2

////////////////////////////////////////////////////////////////////////////////
// Level 1 Cache Size
////////////////////////////////////////////////////////////////////////////////
#define NT2_CONFIG_L1_CACHE_SIZE     32768

////////////////////////////////////////////////////////////////////////////////
// Level 1 Cache Line Size
////////////////////////////////////////////////////////////////////////////////
#define NT2_CONFIG_L1_CACHE_LINESIZE 64

////////////////////////////////////////////////////////////////////////////////
// Level 2 Cache Size
////////////////////////////////////////////////////////////////////////////////
#define NT2_CONFIG_L2_CACHE_SIZE     2097152

////////////////////////////////////////////////////////////////////////////////
// Level 2 Cache Line Size
////////////////////////////////////////////////////////////////////////////////
#define NT2_CONFIG_L2_CACHE_LINESIZE 64

////////////////////////////////////////////////////////////////////////////////
// Level 3 Cache Size
////////////////////////////////////////////////////////////////////////////////
#define NT2_CONFIG_L3_CACHE_SIZE     0

////////////////////////////////////////////////////////////////////////////////
// Level 3 Cache Line Size
////////////////////////////////////////////////////////////////////////////////
#define NT2_CONFIG_L3_CACHE_LINESIZE 0

////////////////////////////////////////////////////////////////////////////////
// SIMD Capabilities
////////////////////////////////////////////////////////////////////////////////
#define NT2_HAS_MMX_SUPPORT
#define NT2_HAS_SSE2_SUPPORT
#define NT2_HAS_SSE3_SUPPORT
#define NT2_HAS_SSSE3_SUPPORT
/* #undef NT2_HAS_SSE4_1_SUPPORT */
/* #undef NT2_HAS_SSE4_2_SUPPORT */
/* #undef NT2_HAS_SSE4A_SUPPORT */
/* #undef NT2_HAS_AVX_SUPPORT */
/* #undef NT2_HAS_ALTIVEC_SUPPORT */

#endif

