/* ------------------------------------------------------------------ */
/*      item            : DynStream.hxx
        made by         : tux
        date            : Wed May 20 18:37:19 2015
        category        : header file
        description     : DUECA stream data object
        notes           : 
        language        : C++                     */

#ifndef DynStream_hxx
#define DynStream_hxx

#include <dueca_ns.h>
#include <AmorphStore.hxx>
#include <gencodegen.h>
#if GENCODEGEN != 103
#error "Generated DynStream.hxx too old, please clean with 'make mrproper'"
#endif
#include <iostream>

USING_DUECA_NS;

#pragma pack(4)
/** an automatically generated class.
    This class can be used for the transport of data in
    stream channels */
class DynStream
{
public:
  /** The name of this class. */
  static const char* const classname;

  /** A single element xpos. */
  float xpos;
public:
  /** a "magic" number, hashed out of the class definition,
      that will be used to check consistency of the sent objects
      across the dueca nodes. */
  static const uint32_t magic_check_number;

  /** empty constructor. */
  DynStream();

  /** copy constructor, will in practice not be used. */
  DynStream(const DynStream& o);

  /** constructor to restore an DynStream from amorphous storage. */
  DynStream(AmorphReStore& r);

  /** destructor. */
  ~DynStream();

  /** packs the DynStream into amorphous storage. */
  void packData(AmorphStore& s) const;

  /** packs the DynStream into amorphous storage.
      only differences with a previous object are packed. */
  void packDataDiff(AmorphStore& s, const DynStream& ref) const;

  /** unpacks the DynStream from an amorphous storage. */
  void unPackData(AmorphReStore& s);

  /** unpacks the differences for DynStream from an amorphous storage. */
  void unPackDataDiff(AmorphReStore& s);

  /** Test for equality. */
  bool operator == (const DynStream& o) const;

  /** Test for inequality. */
  inline bool operator != (const DynStream& o) const
  { return !(*this == o); }

  /** Assignment operator. */
  DynStream& operator=(const DynStream& o);

  /** prints the DynStream to a stream. */
  ostream & print(ostream& s) const;
};

/** pack the object into amorphous storage. */
inline void packData( DUECA_NS ::AmorphStore& s, const DynStream& o)
{ o.packData(s); }

/** pack the differences between this object and another
    into amorphous storage. */
inline void packDataDiff( DUECA_NS ::AmorphStore& s, const DynStream& o, const DynStream& ref)
{ o.packDataDiff(s, ref); }

/** unpack the object from amorphous storage. */
inline void unPackData( DUECA_NS ::AmorphReStore& s, DynStream& o)
{ o.unPackData(s); }

/** unpack the differences to this object from storage. */
inline void unPackDataDiff( DUECA_NS ::AmorphReStore& s, DynStream& o)
{ o.unPackDataDiff(s); }

PRINT_NS_START;

/** print to a stream. */
inline ostream & operator << (ostream& s, const DynStream& o)
{ return o.print(s); }

PRINT_NS_END;


#pragma pack()
#endif
