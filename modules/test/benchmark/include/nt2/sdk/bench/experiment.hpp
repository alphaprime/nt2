//==============================================================================
//         Copyright 2003 - 2012 LASMEA UMR 6602 CNRS/Univ. Clermont II
//         Copyright 2009 - 2012 LRI    UMR 8623 CNRS/Univ Paris Sud XI
//         Copyright 2012        MetaScale SAS
//         Copyright 2012        Domagoj Saric, Little Endian Ltd.
//
//          Distributed under the Boost Software License, Version 1.0.
//                 See accompanying file LICENSE.txt or copy at
//                     http://www.boost.org/LICENSE_1_0.txt
//==============================================================================
#ifndef NT2_SDK_BENCH_EXPERIMENT_HPP_INCLUDED
#define NT2_SDK_BENCH_EXPERIMENT_HPP_INCLUDED

#include <nt2/sdk/bench/config.hpp>
#include <string>

namespace nt2
{
  class measure;

  // Experiment  : code to run
  class BOOST_SYMBOL_VISIBLE experiment
  {
    public:

    NT2_TEST_BENCHMARK_DECL experiment(std::string const&);
    NT2_TEST_BENCHMARK_DECL virtual ~experiment();

    NT2_TEST_BENCHMARK_DECL experiment* add_measure(measure* m);

    virtual void body() = 0;

    std::string name;
  };
}

#endif
