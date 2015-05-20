/* ------------------------------------------------------------------ */
/*      item            : FeedbackStream.hxx
        made by         : tux
        date            : Wed May 20 19:09:04 2015
        category        : header file
        description     : DUECA stream data object
        notes           : 
        language        : C++                     */

#ifndef FeedbackStream_hxx
#define FeedbackStream_hxx

#include <dueca_ns.h>
#include <AmorphStore.hxx>
#include <gencodegen.h>
#if GENCODEGEN != 103
#error "Generated FeedbackStream.hxx too old, please clean with 'make mrproper'"
#endif
#include <iostream>

USING_DUECA_NS;

#pragma pack(4)
/** an automatically generated class.
    This class can be used for the transport of data in
    stream channels */
class FeedbackStream
{
public:
  /** The name of this class. */
  static const char* const classname;

  /** A single element feedbackx. */
  float feedbackx;
public:
  /** a "magic" number, hashed out of the class definition,
      that will be used to check consistency of the sent objects
      across the dueca nodes. */
  static const uint32_t magic_check_number;

  /** empty constructor. */
  FeedbackStream();

  /** copy constructor, will in practice not be used. */
  FeedbackStream(const FeedbackStream& o);

  /** constructor to restore an FeedbackStream from amorphous storage. */
  FeedbackStream(AmorphReStore& r);

  /** destructor. */
  ~FeedbackStream();

  /** packs the FeedbackStream into amorphous storage. */
  void packData(AmorphStore& s) const;

  /** packs the FeedbackStream into amorphous storage.
      only differences with a previous object are packed. */
  void packDataDiff(AmorphStore& s, const FeedbackStream& ref) const;

  /** unpacks the FeedbackStream from an amorphous storage. */
  void unPackData(AmorphReStore& s);

  /** unpacks the differences for FeedbackStream from an amorphous storage. */
  void unPackDataDiff(AmorphReStore& s);

  /** Test for equality. */
  bool operator == (const FeedbackStream& o) const;

  /** Test for inequality. */
  inline bool operator != (const FeedbackStream& o) const
  { return !(*this == o); }

  /** Assignment operator. */
  FeedbackStream& operator=(const FeedbackStream& o);

  /** prints the FeedbackStream to a stream. */
  ostream & print(ostream& s) const;
};

/** pack the object into amorphous storage. */
inline void packData( DUECA_NS ::AmorphStore& s, const FeedbackStream& o)
{ o.packData(s); }

/** pack the differences between this object and another
    into amorphous storage. */
inline void packDataDiff( DUECA_NS ::AmorphStore& s, const FeedbackStream& o, const FeedbackStream& ref)
{ o.packDataDiff(s, ref); }

/** unpack the object from amorphous storage. */
inline void unPackData( DUECA_NS ::AmorphReStore& s, FeedbackStream& o)
{ o.unPackData(s); }

/** unpack the differences to this object from storage. */
inline void unPackDataDiff( DUECA_NS ::AmorphReStore& s, FeedbackStream& o)
{ o.unPackDataDiff(s); }

PRINT_NS_START;

/** print to a stream. */
inline ostream & operator << (ostream& s, const FeedbackStream& o)
{ return o.print(s); }

PRINT_NS_END;


#pragma pack()
#endif
