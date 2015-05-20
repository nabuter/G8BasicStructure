/* ------------------------------------------------------------------ */
/*      item            : DynStream.cxx
        made by         : tux
        date            : Wed May 20 18:37:19 2015
        category        : body file
        description     : DUECA event/stream data object
        notes           : 
        language        : C++                     */

#include "DynStream.hxx"
#include <iostream>
#include "Arena.hxx"
#include "ArenaPool.hxx"

USING_DUECA_NS;

const char * const DynStream::classname = "DynStream";

const uint32_t DynStream::magic_check_number=0x6958002b;

DynStream::DynStream()
{
  // empty
}

DynStream::DynStream(const DynStream& o) :
  xpos(o.xpos)
{
}

DynStream::DynStream(AmorphReStore& s) :
  xpos(s)
{
}

DynStream::~DynStream()
{
}


typedef uint8_t MemberIndex;
static const MemberIndex idxend = 0xff;

static inline void DynStream_checkIndex(MemberIndex idx, int& store_idx, AmorphStore& s)
{
  if (store_idx == -1) {
    ::packData(s, idx);
    store_idx = s.getSize(); ::packData(s, idxend);
  }
}

static inline void DynStream_unCheckIndex(MemberIndex idx, int& store_idx, AmorphStore& s)
{
  if (store_idx != -1) {
    int tmp = s.getSize(); s.setSize(store_idx);
    ::packData(s, idx);  s.setSize(tmp);
    store_idx = -1;
  }
}

void DynStream::packDataDiff(AmorphStore& s, const DynStream& ref) const
{
  int store_idx = -1;
  if (this->xpos != ref.xpos) {
    DynStream_checkIndex(0, store_idx, s);
    ::packData(s, this->xpos);
  }
  else {
    DynStream_unCheckIndex(0, store_idx, s);
  }
  ::packData(s, idxend);
}

void DynStream::unPackData(AmorphReStore& s)
{
  ::unPackData(s, this->xpos);
}


void DynStream::unPackDataDiff(AmorphReStore& s)
{
  MemberIndex idx0, idx1;
  ::unPackData(s, idx0);
  while (idx0 != idxend) {
    ::unPackData(s, idx1);
    switch (idx0) {
    case 0:
      ::unPackData(s, this->xpos);
      if (++idx0 == idx1) break;
    }
    ::unPackData(s, idx0);
  }
}

bool DynStream::operator == (const DynStream& o) const
{
  if (this->xpos != o.xpos) return false;
  return true;
}

DynStream&
DynStream::operator=(const DynStream& other)
{
  if (this == &other) return *this;
  this->xpos = other.xpos;
  return *this;
}

void DynStream::packData(AmorphStore& s) const
{
  ::packData(s, this->xpos);
}

ostream & DynStream::print(ostream& s) const
{
  s << "DynStream(xpos=" << this->xpos<< ')';
  return s;
}

