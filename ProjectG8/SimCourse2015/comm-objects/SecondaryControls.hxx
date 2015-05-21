/* ------------------------------------------------------------------ */
/*      item            : SecondaryControls.hxx
        made by         : tux
        date            : Thu May 21 15:21:14 2015
        category        : header file
        description     : DUECA event/stream data object
        notes           : 
        language        : C++                     */

#ifndef SecondaryControls_hxx
#define SecondaryControls_hxx

#include <dueca_ns.h>
#include <AmorphStore.hxx>
#include <gencodegen.h>
#if GENCODEGEN != 103
#error "Generated SecondaryControls.hxx too old, please clean with 'make mrproper'"
#endif
#include <iostream>

USING_DUECA_NS;

#pragma pack(4)
/** an automatically generated class.
    This class can be used for the transport of data in
    event/stream channels */
class SecondaryControls
{
public:
  /** The name of this class. */
  static const char* const classname;

  /** A single element throttle_left. */
  float throttle_left;

  /** A single element throttle_right. */
  float throttle_right;

  /** A single element flap_setting. */
  float flap_setting;

  /** A single element speedbrake. */
  float speedbrake;
public:
  /** a "magic" number, hashed out of the class definition,
      that will be used to check consistency of the sent objects
      across the dueca nodes. */
  static const uint32_t magic_check_number;

  /** constructor (for use with event data). */
  SecondaryControls(const float& throttle_left,
              const float& throttle_right,
              const float& flap_setting,
              const float& speedbrake);

  /** empty constructor. */
  SecondaryControls();

  /** copy constructor, will in practice not be used. */
  SecondaryControls(const SecondaryControls& o);

  /** constructor to restore an SecondaryControls from amorphous storage. */
  SecondaryControls(AmorphReStore& r);

  /** destructor. */
  ~SecondaryControls();

  /** new operator "new", which places objects not on a
      heap, but in one of the memory arenas. This may prevent
      problems with asymmetric allocation */
  static void* operator new(size_t size);

  /** new operator "delete", to go with the new version
      of operator new. */
  static void operator delete(void* p);

  /** placement "new", needed for stl. */
  inline static void* operator new(size_t size, SecondaryControls  *& o)
  { return reinterpret_cast<void*>(o); }

  /** placement "new", needed for other versions of the stl.*/
  inline static void* operator new(size_t size, void*& o)
  { return o; }


  /** packs the SecondaryControls into amorphous storage. */
  void packData(AmorphStore& s) const;

  /** packs the SecondaryControls into amorphous storage.
      only differences with a previous object are packed. */
  void packDataDiff(AmorphStore& s, const SecondaryControls& ref) const;

  /** unpacks the SecondaryControls from an amorphous storage. */
  void unPackData(AmorphReStore& s);

  /** unpacks the differences for SecondaryControls from an amorphous storage. */
  void unPackDataDiff(AmorphReStore& s);

  /** Test for equality. */
  bool operator == (const SecondaryControls& o) const;

  /** Test for inequality. */
  inline bool operator != (const SecondaryControls& o) const
  { return !(*this == o); }

  /** Assignment operator. */
  SecondaryControls& operator=(const SecondaryControls& o);

  /** prints the SecondaryControls to a stream. */
  ostream & print(ostream& s) const;
};

/** pack the object into amorphous storage. */
inline void packData( DUECA_NS ::AmorphStore& s, const SecondaryControls& o)
{ o.packData(s); }

/** pack the differences between this object and another
    into amorphous storage. */
inline void packDataDiff( DUECA_NS ::AmorphStore& s, const SecondaryControls& o, const SecondaryControls& ref)
{ o.packDataDiff(s, ref); }

/** unpack the object from amorphous storage. */
inline void unPackData( DUECA_NS ::AmorphReStore& s, SecondaryControls& o)
{ o.unPackData(s); }

/** unpack the differences to this object from storage. */
inline void unPackDataDiff( DUECA_NS ::AmorphReStore& s, SecondaryControls& o)
{ o.unPackDataDiff(s); }

PRINT_NS_START;

/** print to a stream. */
inline ostream & operator << (ostream& s, const SecondaryControls& o)
{ return o.print(s); }

PRINT_NS_END;


#pragma pack()
#endif
