/* ------------------------------------------------------------------ */
/*      item            : PrimarySwitches.hxx
        made by         : tux
        date            : Thu May 21 15:21:15 2015
        category        : header file
        description     : DUECA event/stream data object
        notes           : 
        language        : C++                     */

#ifndef PrimarySwitches_hxx
#define PrimarySwitches_hxx

#include <dueca_ns.h>
#include <AmorphStore.hxx>
#include <gencodegen.h>
#if GENCODEGEN != 103
#error "Generated PrimarySwitches.hxx too old, please clean with 'make mrproper'"
#endif
#include <iostream>

USING_DUECA_NS;

#pragma pack(4)
/** an automatically generated class.
    This class can be used for the transport of data in
    event/stream channels */
class PrimarySwitches
{
public:
  /** The name of this class. */
  static const char* const classname;

  /** A single element xmit. */
  bool xmit;

  /** A single element trim_up. */
  bool trim_up;

  /** A single element trim_down. */
  bool trim_down;

  /** A single element AP_disconnect. */
  bool AP_disconnect;
public:
  /** a "magic" number, hashed out of the class definition,
      that will be used to check consistency of the sent objects
      across the dueca nodes. */
  static const uint32_t magic_check_number;

  /** constructor (for use with event data). */
  PrimarySwitches(const bool& xmit,
              const bool& trim_up,
              const bool& trim_down,
              const bool& AP_disconnect);

  /** empty constructor. */
  PrimarySwitches();

  /** copy constructor, will in practice not be used. */
  PrimarySwitches(const PrimarySwitches& o);

  /** constructor to restore an PrimarySwitches from amorphous storage. */
  PrimarySwitches(AmorphReStore& r);

  /** destructor. */
  ~PrimarySwitches();

  /** new operator "new", which places objects not on a
      heap, but in one of the memory arenas. This may prevent
      problems with asymmetric allocation */
  static void* operator new(size_t size);

  /** new operator "delete", to go with the new version
      of operator new. */
  static void operator delete(void* p);

  /** placement "new", needed for stl. */
  inline static void* operator new(size_t size, PrimarySwitches  *& o)
  { return reinterpret_cast<void*>(o); }

  /** placement "new", needed for other versions of the stl.*/
  inline static void* operator new(size_t size, void*& o)
  { return o; }


  /** packs the PrimarySwitches into amorphous storage. */
  void packData(AmorphStore& s) const;

  /** packs the PrimarySwitches into amorphous storage.
      only differences with a previous object are packed. */
  void packDataDiff(AmorphStore& s, const PrimarySwitches& ref) const;

  /** unpacks the PrimarySwitches from an amorphous storage. */
  void unPackData(AmorphReStore& s);

  /** unpacks the differences for PrimarySwitches from an amorphous storage. */
  void unPackDataDiff(AmorphReStore& s);

  /** Test for equality. */
  bool operator == (const PrimarySwitches& o) const;

  /** Test for inequality. */
  inline bool operator != (const PrimarySwitches& o) const
  { return !(*this == o); }

  /** Assignment operator. */
  PrimarySwitches& operator=(const PrimarySwitches& o);

  /** prints the PrimarySwitches to a stream. */
  ostream & print(ostream& s) const;
};

/** pack the object into amorphous storage. */
inline void packData( DUECA_NS ::AmorphStore& s, const PrimarySwitches& o)
{ o.packData(s); }

/** pack the differences between this object and another
    into amorphous storage. */
inline void packDataDiff( DUECA_NS ::AmorphStore& s, const PrimarySwitches& o, const PrimarySwitches& ref)
{ o.packDataDiff(s, ref); }

/** unpack the object from amorphous storage. */
inline void unPackData( DUECA_NS ::AmorphReStore& s, PrimarySwitches& o)
{ o.unPackData(s); }

/** unpack the differences to this object from storage. */
inline void unPackDataDiff( DUECA_NS ::AmorphReStore& s, PrimarySwitches& o)
{ o.unPackDataDiff(s); }

PRINT_NS_START;

/** print to a stream. */
inline ostream & operator << (ostream& s, const PrimarySwitches& o)
{ return o.print(s); }

PRINT_NS_END;


#pragma pack()
#endif
