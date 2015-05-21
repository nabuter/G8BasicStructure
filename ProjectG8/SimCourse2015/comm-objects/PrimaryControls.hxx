/* ------------------------------------------------------------------ */
/*      item            : PrimaryControls.hxx
        made by         : tux
        date            : Thu May 21 02:27:50 2015
        category        : header file
        description     : DUECA stream data object
        notes           : 
        language        : C++                     */

#ifndef PrimaryControls_hxx
#define PrimaryControls_hxx

#include <dueca_ns.h>
#include <AmorphStore.hxx>
#include <gencodegen.h>
#if GENCODEGEN != 103
#error "Generated PrimaryControls.hxx too old, please clean with 'make mrproper'"
#endif
#include <iostream>

USING_DUECA_NS;

#pragma pack(4)
/** an automatically generated class.
    This class can be used for the transport of data in
    stream channels */
class PrimaryControls
{
public:
  /** The name of this class. */
  static const char* const classname;

  /** A single element ux. */
  float ux;

  /** A single element uy. */
  float uy;

  /** A single element uz. */
  float uz;

  /** A single element uc. */
  float uc;

  /** A single element Sx. */
  float Sx;

  /** A single element Sy. */
  float Sy;

  /** A single element Sz. */
  float Sz;

  /** A single element Sc. */
  float Sc;

  /** A single element dSx. */
  float dSx;

  /** A single element dSy. */
  float dSy;

  /** A single element dSz. */
  float dSz;

  /** A single element dSc. */
  float dSc;

  /** A single element Mx. */
  float Mx;

  /** A single element My. */
  float My;

  /** A single element Mz. */
  float Mz;

  /** A single element Mc. */
  float Mc;

  /** A single element fbrake_left. */
  float fbrake_left;

  /** A single element fbrake_right. */
  float fbrake_right;

  /** A single element test. */
  int test;
public:
  /** a "magic" number, hashed out of the class definition,
      that will be used to check consistency of the sent objects
      across the dueca nodes. */
  static const uint32_t magic_check_number;

  /** empty constructor. */
  PrimaryControls();

  /** copy constructor, will in practice not be used. */
  PrimaryControls(const PrimaryControls& o);

  /** constructor to restore an PrimaryControls from amorphous storage. */
  PrimaryControls(AmorphReStore& r);

  /** destructor. */
  ~PrimaryControls();

  /** packs the PrimaryControls into amorphous storage. */
  void packData(AmorphStore& s) const;

  /** packs the PrimaryControls into amorphous storage.
      only differences with a previous object are packed. */
  void packDataDiff(AmorphStore& s, const PrimaryControls& ref) const;

  /** unpacks the PrimaryControls from an amorphous storage. */
  void unPackData(AmorphReStore& s);

  /** unpacks the differences for PrimaryControls from an amorphous storage. */
  void unPackDataDiff(AmorphReStore& s);

  /** Test for equality. */
  bool operator == (const PrimaryControls& o) const;

  /** Test for inequality. */
  inline bool operator != (const PrimaryControls& o) const
  { return !(*this == o); }

  /** Assignment operator. */
  PrimaryControls& operator=(const PrimaryControls& o);

  /** prints the PrimaryControls to a stream. */
  ostream & print(ostream& s) const;
};

/** pack the object into amorphous storage. */
inline void packData( DUECA_NS ::AmorphStore& s, const PrimaryControls& o)
{ o.packData(s); }

/** pack the differences between this object and another
    into amorphous storage. */
inline void packDataDiff( DUECA_NS ::AmorphStore& s, const PrimaryControls& o, const PrimaryControls& ref)
{ o.packDataDiff(s, ref); }

/** unpack the object from amorphous storage. */
inline void unPackData( DUECA_NS ::AmorphReStore& s, PrimaryControls& o)
{ o.unPackData(s); }

/** unpack the differences to this object from storage. */
inline void unPackDataDiff( DUECA_NS ::AmorphReStore& s, PrimaryControls& o)
{ o.unPackDataDiff(s); }

PRINT_NS_START;

/** print to a stream. */
inline ostream & operator << (ostream& s, const PrimaryControls& o)
{ return o.print(s); }

PRINT_NS_END;



#pragma pack()
#endif
