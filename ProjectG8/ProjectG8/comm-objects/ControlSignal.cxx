/* ------------------------------------------------------------------ */
/*      item            : ControlSignal.cxx
        made by         : tux
        date            : Wed May 20 18:04:46 2015
        category        : body file
        description     : DUECA event/stream data object
        notes           : 
        language        : C++                     */

#include "ControlSignal.hxx"
#include <iostream>
#include "Arena.hxx"
#include "ArenaPool.hxx"

USING_DUECA_NS;

const char * const ControlSignal::classname = "ControlSignal";

const uint32_t ControlSignal::magic_check_number=0x6b71402b;

ControlSignal::ControlSignal()
{
  // empty
}

ControlSignal::ControlSignal(const ControlSignal& o) :
  uxcontrol(o.uxcontrol)
{
}

ControlSignal::ControlSignal(AmorphReStore& s) :
  uxcontrol(s)
{
}

ControlSignal::~ControlSignal()
{
}


typedef uint8_t MemberIndex;
static const MemberIndex idxend = 0xff;

static inline void ControlSignal_checkIndex(MemberIndex idx, int& store_idx, AmorphStore& s)
{
  if (store_idx == -1) {
    ::packData(s, idx);
    store_idx = s.getSize(); ::packData(s, idxend);
  }
}

static inline void ControlSignal_unCheckIndex(MemberIndex idx, int& store_idx, AmorphStore& s)
{
  if (store_idx != -1) {
    int tmp = s.getSize(); s.setSize(store_idx);
    ::packData(s, idx);  s.setSize(tmp);
    store_idx = -1;
  }
}

void ControlSignal::packDataDiff(AmorphStore& s, const ControlSignal& ref) const
{
  int store_idx = -1;
  if (this->uxcontrol != ref.uxcontrol) {
    ControlSignal_checkIndex(0, store_idx, s);
    ::packData(s, this->uxcontrol);
  }
  else {
    ControlSignal_unCheckIndex(0, store_idx, s);
  }
  ::packData(s, idxend);
}

void ControlSignal::unPackData(AmorphReStore& s)
{
  ::unPackData(s, this->uxcontrol);
}


void ControlSignal::unPackDataDiff(AmorphReStore& s)
{
  MemberIndex idx0, idx1;
  ::unPackData(s, idx0);
  while (idx0 != idxend) {
    ::unPackData(s, idx1);
    switch (idx0) {
    case 0:
      ::unPackData(s, this->uxcontrol);
      if (++idx0 == idx1) break;
    }
    ::unPackData(s, idx0);
  }
}

bool ControlSignal::operator == (const ControlSignal& o) const
{
  if (this->uxcontrol != o.uxcontrol) return false;
  return true;
}

ControlSignal&
ControlSignal::operator=(const ControlSignal& other)
{
  if (this == &other) return *this;
  this->uxcontrol = other.uxcontrol;
  return *this;
}

void ControlSignal::packData(AmorphStore& s) const
{
  ::packData(s, this->uxcontrol);
}

ostream & ControlSignal::print(ostream& s) const
{
  s << "ControlSignal(uxcontrol=" << this->uxcontrol<< ')';
  return s;
}

