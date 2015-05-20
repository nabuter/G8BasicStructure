/* ------------------------------------------------------------------ */
/*      item            : FeedbackStream.cxx
        made by         : tux
        date            : Wed May 20 19:09:04 2015
        category        : body file
        description     : DUECA event/stream data object
        notes           : 
        language        : C++                     */

#include "FeedbackStream.hxx"
#include <iostream>
#include "Arena.hxx"
#include "ArenaPool.hxx"

USING_DUECA_NS;

const char * const FeedbackStream::classname = "FeedbackStream";

const uint32_t FeedbackStream::magic_check_number=0x69cf002b;

FeedbackStream::FeedbackStream()
{
  // empty
}

FeedbackStream::FeedbackStream(const FeedbackStream& o) :
  feedbackx(o.feedbackx)
{
}

FeedbackStream::FeedbackStream(AmorphReStore& s) :
  feedbackx(s)
{
}

FeedbackStream::~FeedbackStream()
{
}


typedef uint8_t MemberIndex;
static const MemberIndex idxend = 0xff;

static inline void FeedbackStream_checkIndex(MemberIndex idx, int& store_idx, AmorphStore& s)
{
  if (store_idx == -1) {
    ::packData(s, idx);
    store_idx = s.getSize(); ::packData(s, idxend);
  }
}

static inline void FeedbackStream_unCheckIndex(MemberIndex idx, int& store_idx, AmorphStore& s)
{
  if (store_idx != -1) {
    int tmp = s.getSize(); s.setSize(store_idx);
    ::packData(s, idx);  s.setSize(tmp);
    store_idx = -1;
  }
}

void FeedbackStream::packDataDiff(AmorphStore& s, const FeedbackStream& ref) const
{
  int store_idx = -1;
  if (this->feedbackx != ref.feedbackx) {
    FeedbackStream_checkIndex(0, store_idx, s);
    ::packData(s, this->feedbackx);
  }
  else {
    FeedbackStream_unCheckIndex(0, store_idx, s);
  }
  ::packData(s, idxend);
}

void FeedbackStream::unPackData(AmorphReStore& s)
{
  ::unPackData(s, this->feedbackx);
}


void FeedbackStream::unPackDataDiff(AmorphReStore& s)
{
  MemberIndex idx0, idx1;
  ::unPackData(s, idx0);
  while (idx0 != idxend) {
    ::unPackData(s, idx1);
    switch (idx0) {
    case 0:
      ::unPackData(s, this->feedbackx);
      if (++idx0 == idx1) break;
    }
    ::unPackData(s, idx0);
  }
}

bool FeedbackStream::operator == (const FeedbackStream& o) const
{
  if (this->feedbackx != o.feedbackx) return false;
  return true;
}

FeedbackStream&
FeedbackStream::operator=(const FeedbackStream& other)
{
  if (this == &other) return *this;
  this->feedbackx = other.feedbackx;
  return *this;
}

void FeedbackStream::packData(AmorphStore& s) const
{
  ::packData(s, this->feedbackx);
}

ostream & FeedbackStream::print(ostream& s) const
{
  s << "FeedbackStream(feedbackx=" << this->feedbackx<< ')';
  return s;
}

