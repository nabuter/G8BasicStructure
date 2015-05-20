/* ------------------------------------------------------------------ */
/*      item            : PrimarySwitches.cxx
        made by         : tux
        date            : Wed May 20 23:54:05 2015
        category        : body file
        description     : DUECA event/stream data object
        notes           : 
        language        : C++                     */

#include "PrimarySwitches.hxx"
#include <iostream>
#include "Arena.hxx"
#include "ArenaPool.hxx"

USING_DUECA_NS;

const char * const PrimarySwitches::classname = "PrimarySwitches";

const uint32_t PrimarySwitches::magic_check_number=0x39c92c1d;

PrimarySwitches::PrimarySwitches() :
  xmit(false),
  trim_up(false),
  trim_down(false),
  AP_disconnect(false)
{
  // empty
}

PrimarySwitches::PrimarySwitches(const bool& xmit,
              const bool& trim_up,
              const bool& trim_down,
              const bool& AP_disconnect) :
  xmit(xmit),
  trim_up(trim_up),
  trim_down(trim_down),
  AP_disconnect(AP_disconnect)
{
}

PrimarySwitches::PrimarySwitches(const PrimarySwitches& o) :
  xmit(o.xmit),
  trim_up(o.trim_up),
  trim_down(o.trim_down),
  AP_disconnect(o.AP_disconnect)
{
}

PrimarySwitches::PrimarySwitches(AmorphReStore& s) :
  xmit(s),
  trim_up(s),
  trim_down(s),
  AP_disconnect(s)
{
}

PrimarySwitches::~PrimarySwitches()
{
}


void* PrimarySwitches::operator new(size_t size)
{
  assert(size == sizeof(PrimarySwitches));
  static Arena* my_arena = arena_pool.findArena
    (sizeof(PrimarySwitches));
  return my_arena->alloc(size);
}

void PrimarySwitches::operator delete(void* v)
{
  static Arena* my_arena = arena_pool.findArena
    (sizeof(PrimarySwitches));
  my_arena->free(v);
}

typedef uint8_t MemberIndex;
static const MemberIndex idxend = 0xff;

static inline void PrimarySwitches_checkIndex(MemberIndex idx, int& store_idx, AmorphStore& s)
{
  if (store_idx == -1) {
    ::packData(s, idx);
    store_idx = s.getSize(); ::packData(s, idxend);
  }
}

static inline void PrimarySwitches_unCheckIndex(MemberIndex idx, int& store_idx, AmorphStore& s)
{
  if (store_idx != -1) {
    int tmp = s.getSize(); s.setSize(store_idx);
    ::packData(s, idx);  s.setSize(tmp);
    store_idx = -1;
  }
}

void PrimarySwitches::packDataDiff(AmorphStore& s, const PrimarySwitches& ref) const
{
  int store_idx = -1;
  if (this->xmit != ref.xmit) {
    PrimarySwitches_checkIndex(0, store_idx, s);
    ::packData(s, this->xmit);
  }
  else {
    PrimarySwitches_unCheckIndex(0, store_idx, s);
  }
  if (this->trim_up != ref.trim_up) {
    PrimarySwitches_checkIndex(1, store_idx, s);
    ::packData(s, this->trim_up);
  }
  else {
    PrimarySwitches_unCheckIndex(1, store_idx, s);
  }
  if (this->trim_down != ref.trim_down) {
    PrimarySwitches_checkIndex(2, store_idx, s);
    ::packData(s, this->trim_down);
  }
  else {
    PrimarySwitches_unCheckIndex(2, store_idx, s);
  }
  if (this->AP_disconnect != ref.AP_disconnect) {
    PrimarySwitches_checkIndex(3, store_idx, s);
    ::packData(s, this->AP_disconnect);
  }
  else {
    PrimarySwitches_unCheckIndex(3, store_idx, s);
  }
  ::packData(s, idxend);
}

void PrimarySwitches::unPackData(AmorphReStore& s)
{
  ::unPackData(s, this->xmit);
  ::unPackData(s, this->trim_up);
  ::unPackData(s, this->trim_down);
  ::unPackData(s, this->AP_disconnect);
}


void PrimarySwitches::unPackDataDiff(AmorphReStore& s)
{
  MemberIndex idx0, idx1;
  ::unPackData(s, idx0);
  while (idx0 != idxend) {
    ::unPackData(s, idx1);
    switch (idx0) {
    case 0:
      ::unPackData(s, this->xmit);
      if (++idx0 == idx1) break;
    case 1:
      ::unPackData(s, this->trim_up);
      if (++idx0 == idx1) break;
    case 2:
      ::unPackData(s, this->trim_down);
      if (++idx0 == idx1) break;
    case 3:
      ::unPackData(s, this->AP_disconnect);
      if (++idx0 == idx1) break;
    }
    ::unPackData(s, idx0);
  }
}

bool PrimarySwitches::operator == (const PrimarySwitches& o) const
{
  if (this->xmit != o.xmit) return false;
  if (this->trim_up != o.trim_up) return false;
  if (this->trim_down != o.trim_down) return false;
  if (this->AP_disconnect != o.AP_disconnect) return false;
  return true;
}

PrimarySwitches&
PrimarySwitches::operator=(const PrimarySwitches& other)
{
  if (this == &other) return *this;
  this->xmit = other.xmit;
  this->trim_up = other.trim_up;
  this->trim_down = other.trim_down;
  this->AP_disconnect = other.AP_disconnect;
  return *this;
}

void PrimarySwitches::packData(AmorphStore& s) const
{
  ::packData(s, this->xmit);
  ::packData(s, this->trim_up);
  ::packData(s, this->trim_down);
  ::packData(s, this->AP_disconnect);
}

ostream & PrimarySwitches::print(ostream& s) const
{
  s << "PrimarySwitches(xmit=" << this->xmit << ','
    << "trim_up=" << this->trim_up << ','
    << "trim_down=" << this->trim_down << ','
    << "AP_disconnect=" << this->AP_disconnect<< ')';
  return s;
}

