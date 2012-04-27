/*
//@HEADER
// ************************************************************************
// 
//          Kokkos: Node API and Parallel Node Kernels
//              Copyright (2008) Sandia Corporation
// 
// Under the terms of Contract DE-AC04-94AL85000 with Sandia Corporation,
// the U.S. Government retains certain rights in this software.
// 
// Redistribution and use in source and binary forms, with or without
// modification, are permitted provided that the following conditions are
// met:
//
// 1. Redistributions of source code must retain the above copyright
// notice, this list of conditions and the following disclaimer.
//
// 2. Redistributions in binary form must reproduce the above copyright
// notice, this list of conditions and the following disclaimer in the
// documentation and/or other materials provided with the distribution.
//
// 3. Neither the name of the Corporation nor the names of the
// contributors may be used to endorse or promote products derived from
// this software without specific prior written permission.
//
// THIS SOFTWARE IS PROVIDED BY SANDIA CORPORATION "AS IS" AND ANY
// EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
// IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR
// PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL SANDIA CORPORATION OR THE
// CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL,
// EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO,
// PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR
// PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF
// LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING
// NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
// SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
//
// Questions? Contact Michael A. Heroux (maherou@sandia.gov) 
// 
// ************************************************************************
//@HEADER
*/

#if ! defined(KOKKOS_MACRO_DEVICE_TEMPLATE_SPECIALIZATION) || \
    ! defined(KOKKOS_MACRO_DEVICE)                  || \
    ! defined(KOKKOS_MACRO_DEVICE_AND_HOST_FUNCTION)

#error "Including <impl/Kokkos_IndexMapRight_macros.hpp> without macros defined"

#else

#include <impl/Kokkos_IndexMap.hpp>

//----------------------------------------------------------------------------
//----------------------------------------------------------------------------

namespace Kokkos {
namespace Impl {

//----------------------------------------------------------------------------

template<>
struct IndexMapRight< KOKKOS_MACRO_DEVICE::memory_space ,
                      1 , 0 , 0 , 0 , 0 , 0 , 0 , 0 >
{
public:

  typedef KOKKOS_MACRO_DEVICE::size_type size_type ;

private:

  size_type N0 ;

public:

  static const unsigned Rank = 1 ;

  inline
  KOKKOS_MACRO_DEVICE_AND_HOST_FUNCTION
  size_type rank() const { return Rank ; }

  template< typename iType >
  inline
  KOKKOS_MACRO_DEVICE_AND_HOST_FUNCTION
  size_type dimension( const iType & ordinal ) const
  { return 0 == ordinal ? N0 : 0 ; }

  template< typename iType >
  inline
  KOKKOS_MACRO_DEVICE_AND_HOST_FUNCTION
  void dimensions( iType * const dims ) const
  { dims[0] = N0 ; }

  inline
  KOKKOS_MACRO_DEVICE_AND_HOST_FUNCTION
  size_type size() const { return N0 ; }

  inline
  KOKKOS_MACRO_DEVICE_AND_HOST_FUNCTION
  size_type allocation_size() const { return size(); }

  //------------------------------

  template < typename iType0 >
  inline
  KOKKOS_MACRO_DEVICE_AND_HOST_FUNCTION
  size_type offset( const iType0 & i0 ) const
  {
    enum { InputRank = 1 };

    KOKKOS_MACRO_CHECK(
      mdarray_require_dimension( Rank, N0, 0, 0, 0, 0, 0, 0, 0,
                            InputRank, i0, 0, 0, 0, 0, 0, 0, 0 ) );

    return i0 ;
  }

  inline
  KOKKOS_MACRO_DEVICE_AND_HOST_FUNCTION
  IndexMapRight() : N0(0) {}

  template< typename ValueType >
  inline
  void assign( size_t n0 ) { N0 = n0 ; }
};

//----------------------------------------------------------------------------

template< unsigned N1 >
struct IndexMapRight< KOKKOS_MACRO_DEVICE::memory_space ,
                      2 , N1 , 0 , 0 , 0 , 0 , 0 , 0 >
{
public:

  typedef KOKKOS_MACRO_DEVICE::size_type size_type ;

private:

  static const size_type S0 = N1 ;

  size_type N0 ;

public:

  static const unsigned Rank = 2 ;

  inline
  KOKKOS_MACRO_DEVICE_AND_HOST_FUNCTION
  size_type rank() const { return Rank ; }

  template< typename iType >
  inline
  KOKKOS_MACRO_DEVICE_AND_HOST_FUNCTION
  size_type dimension( const iType & ordinal ) const
  {
    return 0 == ordinal ? N0 : (
           1 == ordinal ? N1 : 0 );
  }

  template< typename iType >
  inline
  KOKKOS_MACRO_DEVICE_AND_HOST_FUNCTION
  void dimensions( iType * const dims ) const
  {
    dims[0] = N0 ;
    dims[1] = N1 ;
  }

  inline
  KOKKOS_MACRO_DEVICE_AND_HOST_FUNCTION
  size_type size() const { return N0 * S0 ; }

  inline
  KOKKOS_MACRO_DEVICE_AND_HOST_FUNCTION
  size_type allocation_size() const { return size(); }

  //------------------------------

  template < typename iType0 , typename iType1 >
  inline
  KOKKOS_MACRO_DEVICE_AND_HOST_FUNCTION
  size_type offset( const iType0 & i0 , const iType1 & i1 ) const
  {
    enum { InputRank = 2 };

    KOKKOS_MACRO_CHECK(
      mdarray_require_dimension( Rank, N0, N1, 0, 0, 0, 0, 0, 0,
                            InputRank, i0, i1, 0, 0, 0, 0, 0, 0 ) );

    return i1 + S0 * i0 ;
  }

  inline
  KOKKOS_MACRO_DEVICE_AND_HOST_FUNCTION
  IndexMapRight() : N0(0) {}

  template< typename ValueType >
  inline
  void assign( size_t n0 ) { N0 = n0 ; }
};

//----------------------------------------------------------------------------

template< unsigned N1 , unsigned N2 >
struct IndexMapRight< KOKKOS_MACRO_DEVICE::memory_space ,
                      3 , N1 , N2 , 0 , 0 , 0 , 0 , 0 >
{
public:

  typedef KOKKOS_MACRO_DEVICE::size_type size_type ;

private:

  static const size_type S1 = N2 ;
  static const size_type S0 = N1 * S1 ;

  size_type N0 ;

public:

  static const size_type Rank = 3 ;

  inline
  KOKKOS_MACRO_DEVICE_AND_HOST_FUNCTION
  size_type rank() const { return Rank ; }

  template< typename iType >
  inline
  KOKKOS_MACRO_DEVICE_AND_HOST_FUNCTION
  size_type dimension( const iType & ordinal ) const
  {
    return 0 == ordinal ? N0 : (
           1 == ordinal ? N1 : (
           2 == ordinal ? N2 : 0 ));
  }

  template< typename iType >
  inline
  KOKKOS_MACRO_DEVICE_AND_HOST_FUNCTION
  void dimensions( iType * const dims ) const
  {
    dims[0] = N0 ;
    dims[1] = N1 ;
    dims[2] = N2 ;
  }

  inline
  KOKKOS_MACRO_DEVICE_AND_HOST_FUNCTION
  size_type size() const { return N0 * S0 ; }

  inline
  KOKKOS_MACRO_DEVICE_AND_HOST_FUNCTION
  size_type allocation_size() const { return size(); }

  //------------------------------

  template < typename iType0 , typename iType1 ,
             typename iType2 >
  inline
  KOKKOS_MACRO_DEVICE_AND_HOST_FUNCTION
  size_type offset( const iType0 & i0 , const iType1 & i1 ,
                    const iType2 & i2 ) const
  {
    enum { InputRank = 3 };

    KOKKOS_MACRO_CHECK(
      mdarray_require_dimension( Rank, N0, N1, N2, 0, 0, 0, 0, 0,
                            InputRank, i0, i1, i2, 0, 0, 0, 0, 0 ) );

    return i2 + S1 * i1 + S0 * i0 ;
  }

  inline
  KOKKOS_MACRO_DEVICE_AND_HOST_FUNCTION
  IndexMapRight() : N0(0) {}

  template< typename ValueType >
  inline
  void assign( size_t n0 ) { N0 = n0 ; }
};

//----------------------------------------------------------------------------

template< unsigned N1 , unsigned N2 , unsigned N3 >
struct IndexMapRight< KOKKOS_MACRO_DEVICE::memory_space ,
                      4 , N1 , N2 , N3 , 0 , 0 , 0 , 0 >
{
public:

  typedef KOKKOS_MACRO_DEVICE::size_type size_type ;

private:

  static const size_type S2 = N3 ;
  static const size_type S1 = N2 * S2 ;
  static const size_type S0 = N1 * S1 ;

  size_type N0 ;

public:

  static const size_type Rank = 4 ;

  inline
  KOKKOS_MACRO_DEVICE_AND_HOST_FUNCTION
  size_type rank() const { return Rank ; }

  template< typename iType >
  inline
  KOKKOS_MACRO_DEVICE_AND_HOST_FUNCTION
  size_type dimension( const iType & ordinal ) const
  {
    return 0 == ordinal ? N0 : (
           1 == ordinal ? N1 : (
           2 == ordinal ? N2 : (
           3 == ordinal ? N3 : 0 )));
  }

  template< typename iType >
  inline
  KOKKOS_MACRO_DEVICE_AND_HOST_FUNCTION
  void dimensions( iType * const dims ) const
  {
    dims[0] = N0 ;
    dims[1] = N1 ;
    dims[2] = N2 ;
    dims[3] = N3 ;
  }

  inline
  KOKKOS_MACRO_DEVICE_AND_HOST_FUNCTION
  size_type size() const { return N0 * S0 ; }

  inline
  KOKKOS_MACRO_DEVICE_AND_HOST_FUNCTION
  size_type allocation_size() const { return size(); }

  //------------------------------

  template < typename iType0 , typename iType1 ,
             typename iType2 , typename iType3 >
  inline
  KOKKOS_MACRO_DEVICE_AND_HOST_FUNCTION
  size_type offset( const iType0 & i0 , const iType1 & i1 ,
                    const iType2 & i2 , const iType3 & i3 ) const
  {
    enum { InputRank = 4 };

    KOKKOS_MACRO_CHECK(
      mdarray_require_dimension( Rank, N0, N1, N2, N3, 0, 0, 0, 0,
                            InputRank, i0, i1, i2, i3, 0, 0, 0, 0 ) );

    return i3 + S2 * i2 + S1 * i1 + S0 * i0 ;
  }

  inline
  KOKKOS_MACRO_DEVICE_AND_HOST_FUNCTION
  IndexMapRight() : N0(0) {}

  template< typename ValueType >
  inline
  void assign( size_t n0 ) { N0 = n0 ; }
};

//----------------------------------------------------------------------------

template< unsigned N1 , unsigned N2 , unsigned N3 , unsigned N4 >
struct IndexMapRight< KOKKOS_MACRO_DEVICE::memory_space ,
                      5 , N1 , N2 , N3 , N4 , 0 , 0 , 0 >
{
public:

  typedef KOKKOS_MACRO_DEVICE::size_type size_type ;

private:

  static const size_type S3 = N4 ;
  static const size_type S2 = N3 * S3 ;
  static const size_type S1 = N2 * S2 ;
  static const size_type S0 = N1 * S1 ;

  size_type N0 ;

public:

  static const size_type Rank = 5 ;

  inline
  KOKKOS_MACRO_DEVICE_AND_HOST_FUNCTION
  size_type rank() const { return Rank ; }

  template< typename iType >
  inline
  KOKKOS_MACRO_DEVICE_AND_HOST_FUNCTION
  size_type dimension( const iType & ordinal ) const
  {
    return 0 == ordinal ? N0 : (
           1 == ordinal ? N1 : (
           2 == ordinal ? N2 : (
           3 == ordinal ? N3 : (
           4 == ordinal ? N4 : 0 ))));
  }

  template< typename iType >
  inline
  KOKKOS_MACRO_DEVICE_AND_HOST_FUNCTION
  void dimensions( iType * const dims ) const
  {
    dims[0] = N0 ;
    dims[1] = N1 ;
    dims[2] = N2 ;
    dims[3] = N3 ;
    dims[4] = N4 ;
  }

  inline
  KOKKOS_MACRO_DEVICE_AND_HOST_FUNCTION
  size_type size() const { return N0 * S0 ; }

  inline
  KOKKOS_MACRO_DEVICE_AND_HOST_FUNCTION
  size_type allocation_size() const { return size(); }

  //------------------------------

  template < typename iType0 , typename iType1 ,
             typename iType2 , typename iType3 ,
             typename iType4 , typename iType5 ,
             typename iType6 , typename iType7 >
  inline
  KOKKOS_MACRO_DEVICE_AND_HOST_FUNCTION
  size_type offset( const iType0 & i0 , const iType1 & i1 ,
                    const iType2 & i2 , const iType3 & i3 ,
                    const iType4 & i4 ) const
  {
    enum { InputRank = 5 };

    KOKKOS_MACRO_CHECK(
      mdarray_require_dimension( Rank, N0, N1, N2, N3, N4, 0, 0, 0,
                            InputRank, i0, i1, i2, i3, i4, 0, 0, 0 ) );

    return i4 + S3 * i3 + S2 * i2 + S1 * i1 + S0 * i0 ;
  }

  inline
  KOKKOS_MACRO_DEVICE_AND_HOST_FUNCTION
  IndexMapRight() : N0(0) {}

  template< typename ValueType >
  inline
  void assign( size_t n0 ) { N0 = n0 ; }
};

//----------------------------------------------------------------------------

template< unsigned N1 , unsigned N2 , unsigned N3 ,
          unsigned N4 , unsigned N5 >
struct IndexMapRight< KOKKOS_MACRO_DEVICE::memory_space ,
                      6 , N1 , N2 , N3 , N4 , N5 , 0 , 0 >
{
public:

  typedef KOKKOS_MACRO_DEVICE::size_type size_type ;

private:

  static const size_type S4 = N5 ;
  static const size_type S3 = N4 * S4 ;
  static const size_type S2 = N3 * S3 ;
  static const size_type S1 = N2 * S2 ;
  static const size_type S0 = N1 * S1 ;

  size_type N0 ;

public:

  static const size_type Rank = 6 ;

  inline
  KOKKOS_MACRO_DEVICE_AND_HOST_FUNCTION
  size_type rank() const { return Rank ; }

  template< typename iType >
  inline
  KOKKOS_MACRO_DEVICE_AND_HOST_FUNCTION
  size_type dimension( const iType & ordinal ) const
  {
    return 0 == ordinal ? N0 : (
           1 == ordinal ? N1 : (
           2 == ordinal ? N2 : (
           3 == ordinal ? N3 : (
           4 == ordinal ? N4 : (
           5 == ordinal ? N5 : 0 )))));
  }

  template< typename iType >
  inline
  KOKKOS_MACRO_DEVICE_AND_HOST_FUNCTION
  void dimensions( iType * const dims ) const
  {
    dims[0] = N0 ;
    dims[1] = N1 ;
    dims[2] = N2 ;
    dims[3] = N3 ;
    dims[4] = N4 ;
    dims[5] = N5 ;
  }

  inline
  KOKKOS_MACRO_DEVICE_AND_HOST_FUNCTION
  size_type size() const { return N0 * S0 ; }

  inline
  KOKKOS_MACRO_DEVICE_AND_HOST_FUNCTION
  size_type allocation_size() const { return size(); }

  //------------------------------

  template < typename iType0 , typename iType1 ,
             typename iType2 , typename iType3 ,
             typename iType4 , typename iType5 >
  inline
  KOKKOS_MACRO_DEVICE_AND_HOST_FUNCTION
  size_type offset( const iType0 & i0 , const iType1 & i1 ,
                    const iType2 & i2 , const iType3 & i3 ,
                    const iType4 & i4 , const iType5 & i5 ) const
  {
    enum { InputRank = 6 };

    KOKKOS_MACRO_CHECK(
      mdarray_require_dimension( Rank, N0, N1, N2, N3, N4, N5, 0, 0,
                            InputRank, i0, i1, i2, i3, i4, i5, 0, 0 ) );

    return i5 + S4 * i4 + S3 * i3 + S2 * i2 + S1 * i1 + S0 * i0 ;
  }

  inline
  KOKKOS_MACRO_DEVICE_AND_HOST_FUNCTION
  IndexMapRight() : N0(0) {}

  template< typename ValueType >
  inline
  void assign( size_t n0 ) { N0 = n0 ; }
};

//----------------------------------------------------------------------------

template< unsigned N1 , unsigned N2 , unsigned N3 ,
          unsigned N4 , unsigned N5 , unsigned N6 >
struct IndexMapRight< KOKKOS_MACRO_DEVICE::memory_space ,
                      7 , N1 , N2 , N3 , N4 , N5 , N6 , 0 >
{
public:

  typedef KOKKOS_MACRO_DEVICE::size_type size_type ;

private:

  static const size_type S5 = N6 ;
  static const size_type S4 = N5 * S5 ;
  static const size_type S3 = N4 * S4 ;
  static const size_type S2 = N3 * S3 ;
  static const size_type S1 = N2 * S2 ;
  static const size_type S0 = N1 * S1 ;

  size_type N0 ;

public:

  static const size_type Rank = 7 ;

  inline
  KOKKOS_MACRO_DEVICE_AND_HOST_FUNCTION
  size_type rank() const { return Rank ; }

  template< typename iType >
  inline
  KOKKOS_MACRO_DEVICE_AND_HOST_FUNCTION
  size_type dimension( const iType & ordinal ) const
  {
    return 0 == ordinal ? N0 : (
           1 == ordinal ? N1 : (
           2 == ordinal ? N2 : (
           3 == ordinal ? N3 : (
           4 == ordinal ? N4 : (
           5 == ordinal ? N5 : (
           6 == ordinal ? N6 : 0 ))))));
  }

  template< typename iType >
  inline
  KOKKOS_MACRO_DEVICE_AND_HOST_FUNCTION
  void dimensions( iType * const dims ) const
  {
    dims[0] = N0 ;
    dims[1] = N1 ;
    dims[2] = N2 ;
    dims[3] = N3 ;
    dims[4] = N4 ;
    dims[5] = N5 ;
    dims[6] = N6 ;
  }

  inline
  KOKKOS_MACRO_DEVICE_AND_HOST_FUNCTION
  size_type size() const { return N0 * S0 ; }

  inline
  KOKKOS_MACRO_DEVICE_AND_HOST_FUNCTION
  size_type allocation_size() const { return size(); }

  //------------------------------

  template < typename iType0 , typename iType1 ,
             typename iType2 , typename iType3 ,
             typename iType4 , typename iType5 ,
             typename iType6 >
  inline
  KOKKOS_MACRO_DEVICE_AND_HOST_FUNCTION
  size_type offset( const iType0 & i0 , const iType1 & i1 ,
                    const iType2 & i2 , const iType3 & i3 ,
                    const iType4 & i4 , const iType5 & i5 ,
                    const iType6 & i6 ) const
  {
    enum { InputRank = 7 };

    KOKKOS_MACRO_CHECK(
      mdarray_require_dimension( Rank, N0, N1, N2, N3, N4, N5, N6, 0,
                            InputRank, i0, i1, i2, i3, i4, i5, i6, 0 ) );

    return i6 + S5 * i5 + S4 * i4 + S3 * i3 + S2 * i2 + S1 * i1 + S0 * i0 ;
  }

  inline
  KOKKOS_MACRO_DEVICE_AND_HOST_FUNCTION
  IndexMapRight() : N0(0) {}

  template< typename ValueType >
  inline
  void assign( size_t n0 ) { N0 = n0 ; }
};

//----------------------------------------------------------------------------

template< unsigned N1 , unsigned N2 , unsigned N3 ,
          unsigned N4 , unsigned N5 , unsigned N6 , unsigned N7 >
struct IndexMapRight< KOKKOS_MACRO_DEVICE::memory_space ,
                      8 , N1 , N2 , N3 , N4 , N5 , N6 , N7 >
{
public:

  typedef KOKKOS_MACRO_DEVICE::size_type size_type ;

private:

  static const size_type S6 = N7 ;
  static const size_type S5 = N6 * S6 ;
  static const size_type S4 = N5 * S5 ;
  static const size_type S3 = N4 * S4 ;
  static const size_type S2 = N3 * S3 ;
  static const size_type S1 = N2 * S2 ;
  static const size_type S0 = N1 * S1 ;

  size_type N0 ;

public:

  static const size_type Rank = 8 ;

  inline
  KOKKOS_MACRO_DEVICE_AND_HOST_FUNCTION
  size_type rank() const { return Rank ; }

  template< typename iType >
  inline
  KOKKOS_MACRO_DEVICE_AND_HOST_FUNCTION
  size_type dimension( const iType & ordinal ) const
  {
    return 0 == ordinal ? N0 : (
           1 == ordinal ? N1 : (
           2 == ordinal ? N2 : (
           3 == ordinal ? N3 : (
           4 == ordinal ? N4 : (
           5 == ordinal ? N5 : (
           6 == ordinal ? N6 : (
           7 == ordinal ? N7 : 0 )))))));
  }

  template< typename iType >
  inline
  KOKKOS_MACRO_DEVICE_AND_HOST_FUNCTION
  void dimensions( iType * const dims ) const
  {
    dims[0] = N0 ;
    dims[1] = N1 ;
    dims[2] = N2 ;
    dims[3] = N3 ;
    dims[4] = N4 ;
    dims[5] = N5 ;
    dims[6] = N6 ;
    dims[7] = N7 ;
  }

  inline
  KOKKOS_MACRO_DEVICE_AND_HOST_FUNCTION
  size_type size() const { return N0 * S0 ; }

  inline
  KOKKOS_MACRO_DEVICE_AND_HOST_FUNCTION
  size_type allocation_size() const { return size(); }

  //------------------------------

  template < typename iType0 , typename iType1 ,
             typename iType2 , typename iType3 ,
             typename iType4 , typename iType5 ,
             typename iType6 , typename iType7 >
  inline
  KOKKOS_MACRO_DEVICE_AND_HOST_FUNCTION
  size_type offset( const iType0 & i0 , const iType1 & i1 ,
                    const iType2 & i2 , const iType3 & i3 ,
                    const iType4 & i4 , const iType5 & i5 ,
                    const iType6 & i6 , const iType7 & i7 ) const
  {
    enum { InputRank = 8 };

    KOKKOS_MACRO_CHECK(
      mdarray_require_dimension( Rank, N0, N1, N2, N3, N4, N5, N6, N7,
                            InputRank, i0, i1, i2, i3, i4, i5, i6, i7 ) );

    return i7 + S6 * i6 + S5 * i5 + S4 * i4 + S3 * i3 + S2 * i2 + S1 * i1 + S0 * i0 ;
  }

  inline
  KOKKOS_MACRO_DEVICE_AND_HOST_FUNCTION
  IndexMapRight() : N0(0) {}

  template< typename ValueType >
  inline
  void assign( size_t n0 ) { N0 = n0 ; }
};

//----------------------------------------------------------------------------
//----------------------------------------------------------------------------
/* Runtime defined rank and dimensions */
template<>
class IndexMapRight< KOKKOS_MACRO_DEVICE::memory_space,
                     0, 0,0,0,0,0,0,0 > {
public:

  typedef KOKKOS_MACRO_DEVICE::size_type  size_type ;

private:

  size_type m_rank ;
  size_type m_dims[ IndexMapMaxRank ];

public:

  inline
  KOKKOS_MACRO_DEVICE_AND_HOST_FUNCTION
  size_type rank() const { return m_rank; }

  template< typename iType >
  inline
  KOKKOS_MACRO_DEVICE_AND_HOST_FUNCTION
  size_type dimension( const iType & ordinal ) const
  {
    KOKKOS_MACRO_CHECK( require_less( ordinal , IndexMapMaxRank ) );
    return m_dims[ordinal];
  }

  template< typename iType >
  inline
  KOKKOS_MACRO_DEVICE_AND_HOST_FUNCTION
  void dimensions( iType * const dims ) const
  {
    for ( size_type i = 0 ; i < m_rank ; ++i ) {
      dims[i] = m_dims[i] ;
    }
  }

  inline
  KOKKOS_MACRO_DEVICE_AND_HOST_FUNCTION
  size_type size() const
    {
      size_type n = m_dims[0] ;
      for ( size_type i = 1 ; i < m_rank ; ++i ) { n *= m_dims[i] ; }
      return n ;
    }

  inline
  KOKKOS_MACRO_DEVICE_AND_HOST_FUNCTION
  size_type allocation_size() const
    {
      size_type n = m_dims[0] ;
      for ( size_type i = 1 ; i < m_rank ; ++i ) { n *= m_dims[i] ; }
      return n ;
    }

  //------------------------------------

  template < typename iType0 , typename iType1 ,
             typename iType2 , typename iType3 ,
             typename iType4 , typename iType5 ,
             typename iType6 , typename iType7 >
  inline
  KOKKOS_MACRO_DEVICE_AND_HOST_FUNCTION
  size_type offset( const iType0 & i0 , const iType1 & i1 ,
                    const iType2 & i2 , const iType3 & i3 ,
                    const iType4 & i4 , const iType5 & i5 ,
                    const iType6 & i6 , const iType7 & i7 ) const
  {
    KOKKOS_MACRO_CHECK(
      mdarray_require_dimension( m_rank,
                                 m_dims[0], m_dims[1], m_dims[2], m_dims[3],
                                 m_dims[4], m_dims[5], m_dims[6], m_dims[7],
                                 8, i0, i1, i2, i3, i4, i5, i6, i7 ) );

    return ( i7 + m_dims[7] * ( i6 + m_dims[6] *
           ( i5 + m_dims[5] * ( i4 + m_dims[4] *
           ( i3 + m_dims[3] * ( i2 + m_dims[2] *
           ( i1 + m_dims[1] * ( i0 ))))))));
  }

  template < typename iType0 , typename iType1 ,
             typename iType2 , typename iType3 ,
             typename iType4 , typename iType5 ,
             typename iType6 >
  inline
  KOKKOS_MACRO_DEVICE_AND_HOST_FUNCTION
  size_type offset( const iType0 & i0 , const iType1 & i1 ,
                    const iType2 & i2 , const iType3 & i3 ,
                    const iType4 & i4 , const iType5 & i5 ,
                    const iType6 & i6 ) const
  {
    KOKKOS_MACRO_CHECK(
      mdarray_require_dimension( m_rank,
                                 m_dims[0], m_dims[1], m_dims[2], m_dims[3],
                                 m_dims[4], m_dims[5], m_dims[6], m_dims[7],
                                 7, i0, i1, i2, i3, i4, i5, i6, 0 ) );

    return ( i6 + m_dims[6] *
           ( i5 + m_dims[5] * ( i4 + m_dims[4] *
           ( i3 + m_dims[3] * ( i2 + m_dims[2] *
           ( i1 + m_dims[1] * ( i0 )))))));
  }

  template < typename iType0 , typename iType1 ,
             typename iType2 , typename iType3 ,
             typename iType4 , typename iType5 >
  inline
  KOKKOS_MACRO_DEVICE_AND_HOST_FUNCTION
  size_type offset( const iType0 & i0 , const iType1 & i1 ,
                    const iType2 & i2 , const iType3 & i3 ,
                    const iType4 & i4 , const iType5 & i5 ) const
  {
    KOKKOS_MACRO_CHECK(
      mdarray_require_dimension( m_rank,
                                 m_dims[0], m_dims[1], m_dims[2], m_dims[3],
                                 m_dims[4], m_dims[5], m_dims[6], m_dims[7],
                                 6, i0, i1, i2, i3, i4, i5, 0, 0 ) );

    return ( i5 + m_dims[5] * ( i4 + m_dims[4] *
           ( i3 + m_dims[3] * ( i2 + m_dims[2] *
           ( i1 + m_dims[1] * ( i0 ))))));
  }

  template < typename iType0 , typename iType1 ,
             typename iType2 , typename iType3 ,
             typename iType4 >
  inline
  KOKKOS_MACRO_DEVICE_AND_HOST_FUNCTION
  size_type offset( const iType0 & i0 , const iType1 & i1 ,
                    const iType2 & i2 , const iType3 & i3 ,
                    const iType4 & i4 ) const
  {
    KOKKOS_MACRO_CHECK(
      mdarray_require_dimension( m_rank,
                                 m_dims[0], m_dims[1], m_dims[2], m_dims[3],
                                 m_dims[4], m_dims[5], m_dims[6], m_dims[7],
                                 5, i0, i1, i2, i3, i4, 0, 0, 0 ) );

    return ( i4 + m_dims[4] *
           ( i3 + m_dims[3] * ( i2 + m_dims[2] *
           ( i1 + m_dims[1] * ( i0 )))));
  }

  template < typename iType0 , typename iType1 ,
             typename iType2 , typename iType3 >
  inline
  KOKKOS_MACRO_DEVICE_AND_HOST_FUNCTION
  size_type offset( const iType0 & i0 , const iType1 & i1 ,
                    const iType2 & i2 , const iType3 & i3 ) const
  {
    KOKKOS_MACRO_CHECK(
      mdarray_require_dimension( m_rank,
                                 m_dims[0], m_dims[1], m_dims[2], m_dims[3],
                                 m_dims[4], m_dims[5], m_dims[6], m_dims[7],
                                 4, i0, i1, i2, i3, 0, 0, 0, 0 ) );


    return ( i3 + m_dims[3] * ( i2 + m_dims[2] *
           ( i1 + m_dims[1] * ( i0 ))));
  }

  template < typename iType0 , typename iType1 ,
             typename iType2 >
  inline
  KOKKOS_MACRO_DEVICE_AND_HOST_FUNCTION
  size_type offset( const iType0 & i0 , const iType1 & i1 ,
                    const iType2 & i2 ) const
  {
    KOKKOS_MACRO_CHECK(
      mdarray_require_dimension( m_rank,
                                 m_dims[0], m_dims[1], m_dims[2], m_dims[3],
                                 m_dims[4], m_dims[5], m_dims[6], m_dims[7],
                                 3, i0, i1, i2, 0, 0, 0, 0, 0 ) );

    return ( i2 + m_dims[2] * ( i1 + m_dims[1] * ( i0 )));
  }

  template < typename iType0 , typename iType1 >
  inline
  KOKKOS_MACRO_DEVICE_AND_HOST_FUNCTION
  size_type offset( const iType0 & i0 , const iType1 & i1 ) const
  {
    KOKKOS_MACRO_CHECK(
      mdarray_require_dimension( m_rank,
                                 m_dims[0], m_dims[1], m_dims[2], m_dims[3],
                                 m_dims[4], m_dims[5], m_dims[6], m_dims[7],
                                 2, i0, i1, 0, 0, 0, 0, 0, 0 ) );

    return ( i1 + m_dims[1] * ( i0 ));
  }

  template < typename iType0 >
  inline
  KOKKOS_MACRO_DEVICE_AND_HOST_FUNCTION
  size_type offset( const iType0 & i0 ) const
  {
    KOKKOS_MACRO_CHECK(
      mdarray_require_dimension( m_rank,
                                 m_dims[0], m_dims[1], m_dims[2], m_dims[3],
                                 m_dims[4], m_dims[5], m_dims[6], m_dims[7],
                                 1, i0, 0, 0, 0, 0, 0, 0, 0 ) );

    return ( i0 );
  }

  //------------------------------------

  inline
  KOKKOS_MACRO_DEVICE_AND_HOST_FUNCTION
  void reverse_index( size_type offset, size_type * const indices ) const
  {
    for ( size_type i = m_rank ; 0 < i ; ) {
      --i ;
      indices[i] = offset % m_dims[i] ;
      offset /= m_dims[i] ;
    }
  }

  //--------------------------------------

  inline
  KOKKOS_MACRO_DEVICE_AND_HOST_FUNCTION
  IndexMapRight()
    : m_rank(0)
  {
    m_dims[0] = 0 ; m_dims[1] = 0 ;
    m_dims[2] = 0 ; m_dims[3] = 0 ;
    m_dims[4] = 0 ; m_dims[5] = 0 ;
    m_dims[6] = 0 ; m_dims[7] = 0 ;
  }

  template< typename ValueType >
  inline
  void assign( size_t n0 , size_t n1 , size_t n2 , size_t n3 ,
               size_t n4 , size_t n5 , size_t n6 , size_t n7 )
  {
    typedef  KOKKOS_MACRO_DEVICE::memory_space  memory_space ;
    m_rank = mdarray_deduce_rank( n0, n1, n2, n3, n4, n5, n6, n7 );
    m_dims[0] = n0 ; m_dims[1] = n1 ; m_dims[2] = n2 ; m_dims[3] = n3 ;
    m_dims[4] = n4 ; m_dims[5] = n5 ; m_dims[6] = n6 ; m_dims[7] = n7 ;
  }
};

//----------------------------------------------------------------------------

} // Impl namespace
} // Kokkos namespace


#endif

