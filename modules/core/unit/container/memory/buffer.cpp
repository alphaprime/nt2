//==============================================================================
//         Copyright 2003 - 2011   LASMEA UMR 6602 CNRS/Univ. Clermont II
//         Copyright 2009 - 2011   LRI    UMR 8623 CNRS/Univ Paris Sud XI
//
//          Distributed under the Boost Software License, Version 1.0.
//                 See accompanying file LICENSE.txt or copy at
//                     http://www.boost.org/LICENSE_1_0.txt
//==============================================================================
#define NT2_UNIT_MODULE "nt2::memory::buffer"

#include <nt2/core/container/memory/buffer.hpp>

#include <boost/array.hpp>
#include <boost/fusion/include/mpl.hpp>
#include <boost/fusion/adapted/array.hpp>
#include <boost/fusion/include/single_view.hpp>

#include <nt2/sdk/unit/module.hpp>
#include <nt2/sdk/unit/tests/basic.hpp>
#include <nt2/sdk/unit/tests/relation.hpp>
#include <nt2/sdk/unit/tests/type_expr.hpp>
#include <nt2/sdk/unit/tests/exceptions.hpp>

#define PADDING                                                                   \
(nt2::memory::no_padding)(nt2::memory::lead_padding)(nt2::memory::global_padding) \

////////////////////////////////////////////////////////////////////////////////
// Test for dynamic default buffer ctor
////////////////////////////////////////////////////////////////////////////////
NT2_TEST_CASE_TPL(buffer_default_ctor, NT2_TYPES )
{
  using nt2::memory::buffer;
  using nt2::memory::size;
  using nt2::memory::lower;
  using nt2::memory::upper;

  typedef          buffer<T>            buffer_type;
  typedef typename buffer_type::size_type size_type;

  buffer_type b;

  NT2_TEST_EQUAL( size<1>(b)  , 0U      );
  NT2_TEST_EQUAL( lower<1>(b) , 0       );
  NT2_TEST_EQUAL( upper<1>(b) , -1      );
  NT2_TEST_EQUAL( b.begin() , b.end() );

  boost::array<size_type,1> s = { 10 };
  b.resize(s);
  
  NT2_TEST_EQUAL( size<1>(b)  , 10U     );
  NT2_TEST_EQUAL( lower<1>(b) , 0       );
  NT2_TEST_EQUAL( upper<1>(b) , 9       );
  NT2_TEST_NOT_EQUAL( b.begin() , b.end() );
}

////////////////////////////////////////////////////////////////////////////////
// Test for dynamic buffer ctor
////////////////////////////////////////////////////////////////////////////////
NT2_TEST_CASE_TPL(buffer_ctor, NT2_TYPES )
{
  using nt2::memory::buffer;
  using nt2::memory::size;
  using nt2::memory::lower;
  using nt2::memory::upper;
  using nt2::memory::dereference;
  
  typedef          buffer<T>              buffer_type;
  typedef typename buffer_type::size_type size_type;

  boost::array<size_type,1> ss = { 5 };
  boost::array<size_type,1> bs = { 0 };

  buffer_type b(ss,bs);

  NT2_TEST_EQUAL( size<1>(b)  , 5U      );
  NT2_TEST_EQUAL( lower<1>(b) , 0       );
  NT2_TEST_EQUAL( upper<1>(b) , 4       );
  NT2_TEST_NOT_EQUAL( b.begin() , b.end() );

  for (typename buffer_type::index_type i = lower<1>(b); i <= upper<1>(b); ++i )
    dereference(b,boost::fusion::single_view<int>(i)) = typename buffer_type::value_type(1+i);

  for (typename buffer_type::index_type i = lower<1>(b); i <= upper<1>(b); ++i )
    NT2_TEST_EQUAL( dereference(b,boost::fusion::single_view<int>(i)), 1+i );
}

////////////////////////////////////////////////////////////////////////////////
// Test for dynamic buffer assignment
////////////////////////////////////////////////////////////////////////////////
NT2_TEST_CASE_TPL(buffer_assignment, NT2_TYPES )
{
  using nt2::memory::buffer;
  using nt2::memory::size;
  using nt2::memory::lower;
  using nt2::memory::upper;
  using nt2::memory::dereference;

  typedef          buffer<T>              buffer_type;
  typedef typename buffer_type::size_type size_type;

  boost::array<size_type,1> ss = { 5 };
  boost::array<size_type,1> bs = { 0 };

  buffer_type b,x(ss,bs);

  NT2_TEST_EQUAL( size<1>(x)  , 5U      );
  NT2_TEST_EQUAL( lower<1>(x) , 0       );
  NT2_TEST_EQUAL( upper<1>(x) , 4       );

  NT2_TEST_EQUAL( size<1>(b)  , 0U      );
  NT2_TEST_EQUAL( lower<1>(b) , 0       );
  NT2_TEST_EQUAL( upper<1>(b) , -1      );
  
  for(typename buffer_type::index_type i = lower<1>(x); i <= upper<1>(x); ++i )
      dereference(x,boost::fusion::single_view<int>(i))
    = typename buffer_type::value_type(1+i);

  b = x;

  NT2_TEST_EQUAL( size<1>(b)  , 5U      );
  NT2_TEST_EQUAL( lower<1>(b) , 0       );
  NT2_TEST_EQUAL( upper<1>(b) , 4       );
  NT2_TEST_NOT_EQUAL( b.begin() , b.end() );

  for (typename buffer_type::index_type i = lower<1>(b); i <= upper<1>(b); ++i )
    NT2_TEST_EQUAL( dereference(b,boost::fusion::single_view<int>(i)), 1+i );
}

////////////////////////////////////////////////////////////////////////////////
// Test for dynamic buffer swap
////////////////////////////////////////////////////////////////////////////////
NT2_TEST_CASE_TPL(buffer_swap, NT2_TYPES )
{
  using nt2::memory::buffer;
  using nt2::memory::size;
  using nt2::memory::lower;
  using nt2::memory::upper;  
  using nt2::memory::dereference;
  
  typedef          buffer<T>              buffer_type;
  typedef typename buffer_type::size_type size_type;

  boost::array<size_type,1> sx = { 5 };
  boost::array<size_type,1> bx = { 0 };

  boost::array<size_type,1> sb = { 3 };
  boost::array<size_type,1> bb = { -1 };

  buffer_type b(sb,bb),x(sx,bx);

  NT2_TEST_EQUAL( size<1>(x)  , 5U  );
  NT2_TEST_EQUAL( lower<1>(x) , 0   );
  NT2_TEST_EQUAL( upper<1>(x) , 4   );

  NT2_TEST_EQUAL( size<1>(b)  , 3U  );
  NT2_TEST_EQUAL( lower<1>(b) , -1  );
  NT2_TEST_EQUAL( upper<1>(b) , 1   );
  
  for (typename buffer_type::index_type i = lower<1>(x); i <= upper<1>(x); ++i )
    dereference(x,boost::fusion::single_view<int>(i)) = typename buffer_type::value_type(1+i);
  for (typename buffer_type::index_type i = lower<1>(b); i <= upper<1>(b); ++i )
    dereference(b,boost::fusion::single_view<int>(i)) = typename buffer_type::value_type(2+i);

  swap(b,x);

  NT2_TEST_EQUAL( size<1>(b)  , 5U  );
  NT2_TEST_EQUAL( lower<1>(b) , 0   );
  NT2_TEST_EQUAL( upper<1>(b) , 4   );

  NT2_TEST_EQUAL( size<1>(x)  , 3U  );
  NT2_TEST_EQUAL( lower<1>(x) , -1  );
  NT2_TEST_EQUAL( upper<1>(x) , 1   );
  
  for (typename buffer_type::index_type i = lower<1>(x); i <= upper<1>(x); ++i )
    NT2_TEST_EQUAL( dereference(x,boost::fusion::single_view<int>(i)), 2+i );

  for (typename buffer_type::index_type i = lower<1>(b); i <= upper<1>(b); ++i )
    NT2_TEST_EQUAL( dereference(b,boost::fusion::single_view<int>(i)), 1+i );
}

////////////////////////////////////////////////////////////////////////////////
// buffer type has some dimensions
////////////////////////////////////////////////////////////////////////////////
NT2_TEST_CASE_TPL( buffer_dimensions, NT2_TYPES)
{
  using nt2::meta::dimensions_of;
  using nt2::memory::buffer;

  NT2_TEST_EQUAL((dimensions_of< buffer<T> >::value), 1UL );
}

// ////////////////////////////////////////////////////////////////////////////////
// // array type has some value
// ////////////////////////////////////////////////////////////////////////////////
NT2_TEST_CASE_TPL( buffer_values, NT2_TYPES)
{
  using boost::is_same;
  using boost::dispatch::meta::value_of;
  using nt2::memory::buffer;
  using boost::mpl::_;

  buffer<T> a0;
  NT2_TEST_EXPR_TYPE(a0, value_of<_>, T );
}

////////////////////////////////////////////////////////////////////////////////
// 1D buffer type has a model
////////////////////////////////////////////////////////////////////////////////
NT2_TEST_CASE_TPL( buffer_models, NT2_TYPES )
{
  using boost::is_same;
  using boost::dispatch::meta::model_of;
  using boost::mpl::apply;
  using nt2::memory::buffer;

  typedef typename model_of< buffer<T> >::type model1d;

  NT2_TEST((is_same < typename apply<model1d,float>::type
                    , buffer<float> >::value
          ));
}

