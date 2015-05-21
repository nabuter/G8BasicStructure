/* ------------------------------------------------------------------ */
/*      item            : SecondarySwitches.hxx
        made by         : tux
        date            : Thu May 21 15:21:15 2015
        category        : header file
        description     : DUECA event/stream data object
        notes           : 
        language        : C++                     */

#ifndef SecondarySwitches_hxx
#define SecondarySwitches_hxx

#include <dueca_ns.h>
#include <AmorphStore.hxx>
#include <gencodegen.h>
#if GENCODEGEN != 103
#error "Generated SecondarySwitches.hxx too old, please clean with 'make mrproper'"
#endif
#include <iostream>

USING_DUECA_NS;

#pragma pack(4)
/** an automatically generated class.
    This class can be used for the transport of data in
    event/stream channels */
class SecondarySwitches
{
public:
  /** The name of this class. */
  static const char* const classname;

  /** A single element AT_disconnect. */
  bool AT_disconnect;

  /** A single element ignition_left. */
  bool ignition_left;

  /** A single element ignition_right. */
  bool ignition_right;

  /** A single element gear_up. */
  bool gear_up;

  /** A single element gear_neutral. */
  bool gear_neutral;

  /** A single element gear_down. */
  bool gear_down;
public:
  /** a "magic" number, hashed out of the class definition,
      that will be used to check consistency of the sent objects
      across the dueca nodes. */
  static const uint32_t magic_check_number;

  /** constructor (for use with event data). */
  SecondarySwitches(const bool& AT_disconnect,
              const bool& ignition_left,
              const bool& ignition_right,
              const bool& gear_up,
              const bool& gear_neutral,
              const bool& gear_down);

  /** empty constructor. */
  SecondarySwitches();

  /** copy constructor, will in practice not be used. */
  SecondarySwitches(const SecondarySwitches& o);

  /** constructor to restore an SecondarySwitches from amorphous storage. */
  SecondarySwitches(AmorphReStore& r);

  /** destructor. */
  ~SecondarySwitches();

  /** new operator "new", which places objects not on a
      heap, but in one of the memory arenas. This may prevent
      problems with asymmetric allocation */
  static void* operator new(size_t size);

  /** new operator "delete", to go with the new version
      of operator new. */
  static void operator delete(void* p);

  /** placement "new", needed for stl. */
  inline static void* operator new(size_t size, SecondarySwitches  *& o)
  { return reinterpret_cast<void*>(o); }

  /** placement "new", needed for other versions of the stl.*/
  inline static void* operator new(size_t size, void*& o)
  { return o; }


  /** packs the SecondarySwitches into amorphous storage. */
  void packData(AmorphStore& s) const;

  /** packs the SecondarySwitches into amorphous storage.
      only differences with a previous object are packed. */
  void packDataDiff(AmorphStore& s, const SecondarySwitches& ref) const;

  /** unpacks the SecondarySwitches from an amorphous storage. */
  void unPackData(AmorphReStore& s);

  /** unpacks the differences for SecondarySwitches from an amorphous storage. */
  void unPackDataDiff(AmorphReStore& s);

  /** Test for equality. */
  bool operator == (const SecondarySwitches& o) const;

  /** Test for inequality. */
  inline bool operator != (const SecondarySwitches& o) const
  { return !(*this == o); }

  /** Assignment operator. */
  SecondarySwitches& operator=(const SecondarySwitches& o);

  /** prints the SecondarySwitches to a stream. */
  ostream & print(ostream& s) const;
};

/** pack the object into amorphous storage. */
inline void packData( DUECA_NS ::AmorphStore& s, const SecondarySwitches& o)
{ o.packData(s); }

/** pack the differences between this object and another
    into amorphous storage. */
inline void packDataDiff( DUECA_NS ::AmorphStore& s, const SecondarySwitches& o, const SecondarySwitches& ref)
{ o.packDataDiff(s, ref); }

/** unpack the object from amorphous storage. */
inline void unPackData( DUECA_NS ::AmorphReStore& s, SecondarySwitches& o)
{ o.unPackData(s); }

/** unpack the differences to this object from storage. */
inline void unPackDataDiff( DUECA_NS ::AmorphReStore& s, SecondarySwitches& o)
{ o.unPackDataDiff(s); }

PRINT_NS_START;

/** print to a stream. */
inline ostream & operator << (ostream& s, const SecondarySwitches& o)
{ return o.print(s); }

PRINT_NS_END;


#pragma pack()
#endif
