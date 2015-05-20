/* ------------------------------------------------------------------ */
/*      item            : ControlSignal.hxx
        made by         : tux
        date            : Wed May 20 18:04:46 2015
        category        : header file
        description     : DUECA stream data object
        notes           : 
        language        : C++                     */

#ifndef ControlSignal_hxx
#define ControlSignal_hxx

#include <dueca_ns.h>
#include <AmorphStore.hxx>
#include <gencodegen.h>
#if GENCODEGEN != 103
#error "Generated ControlSignal.hxx too old, please clean with 'make mrproper'"
#endif
#include <iostream>

USING_DUECA_NS;

#pragma pack(4)
/** an automatically generated class.
    This class can be used for the transport of data in
    stream channels */
class ControlSignal
{
public:
  /** The name of this class. */
  static const char* const classname;

  /** A single element uxcontrol. */
  float uxcontrol;
public:
  /** a "magic" number, hashed out of the class definition,
      that will be used to check consistency of the sent objects
      across the dueca nodes. */
  static const uint32_t magic_check_number;

  /** empty constructor. */
  ControlSignal();

  /** copy constructor, will in practice not be used. */
  ControlSignal(const ControlSignal& o);

  /** constructor to restore an ControlSignal from amorphous storage. */
  ControlSignal(AmorphReStore& r);

  /** destructor. */
  ~ControlSignal();

  /** packs the ControlSignal into amorphous storage. */
  void packData(AmorphStore& s) const;

  /** packs the ControlSignal into amorphous storage.
      only differences with a previous object are packed. */
  void packDataDiff(AmorphStore& s, const ControlSignal& ref) const;

  /** unpacks the ControlSignal from an amorphous storage. */
  void unPackData(AmorphReStore& s);

  /** unpacks the differences for ControlSignal from an amorphous storage. */
  void unPackDataDiff(AmorphReStore& s);

  /** Test for equality. */
  bool operator == (const ControlSignal& o) const;

  /** Test for inequality. */
  inline bool operator != (const ControlSignal& o) const
  { return !(*this == o); }

  /** Assignment operator. */
  ControlSignal& operator=(const ControlSignal& o);

  /** prints the ControlSignal to a stream. */
  ostream & print(ostream& s) const;
};

/** pack the object into amorphous storage. */
inline void packData( DUECA_NS ::AmorphStore& s, const ControlSignal& o)
{ o.packData(s); }

/** pack the differences between this object and another
    into amorphous storage. */
inline void packDataDiff( DUECA_NS ::AmorphStore& s, const ControlSignal& o, const ControlSignal& ref)
{ o.packDataDiff(s, ref); }

/** unpack the object from amorphous storage. */
inline void unPackData( DUECA_NS ::AmorphReStore& s, ControlSignal& o)
{ o.unPackData(s); }

/** unpack the differences to this object from storage. */
inline void unPackDataDiff( DUECA_NS ::AmorphReStore& s, ControlSignal& o)
{ o.unPackDataDiff(s); }

PRINT_NS_START;

/** print to a stream. */
inline ostream & operator << (ostream& s, const ControlSignal& o)
{ return o.print(s); }

PRINT_NS_END;


#pragma pack()
#endif
