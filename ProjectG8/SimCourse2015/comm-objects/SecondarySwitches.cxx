/* ------------------------------------------------------------------ */
/*      item            : SecondarySwitches.cxx
        made by         : tux
        date            : Wed May 20 23:54:05 2015
        category        : body file
        description     : DUECA event/stream data object
        notes           : 
        language        : C++                     */

#include "SecondarySwitches.hxx"
#include <iostream>
#include "Arena.hxx"
#include "ArenaPool.hxx"

USING_DUECA_NS;

const char * const SecondarySwitches::classname = "SecondarySwitches";

const uint32_t SecondarySwitches::magic_check_number=0x30fa726c;

SecondarySwitches::SecondarySwitches() :
  AT_disconnect(false),
  ignition_left(false),
  ignition_right(false),
  gear_up(false),
  gear_neutral(false),
  gear_down(false)
{
  // empty
}

SecondarySwitches::SecondarySwitches(const bool& AT_disconnect,
              const bool& ignition_left,
              const bool& ignition_right,
              const bool& gear_up,
              const bool& gear_neutral,
              const bool& gear_down) :
  AT_disconnect(AT_disconnect),
  ignition_left(ignition_left),
  ignition_right(ignition_right),
  gear_up(gear_up),
  gear_neutral(gear_neutral),
  gear_down(gear_down)
{
}

SecondarySwitches::SecondarySwitches(const SecondarySwitches& o) :
  AT_disconnect(o.AT_disconnect),
  ignition_left(o.ignition_left),
  ignition_right(o.ignition_right),
  gear_up(o.gear_up),
  gear_neutral(o.gear_neutral),
  gear_down(o.gear_down)
{
}

SecondarySwitches::SecondarySwitches(AmorphReStore& s) :
  AT_disconnect(s),
  ignition_left(s),
  ignition_right(s),
  gear_up(s),
  gear_neutral(s),
  gear_down(s)
{
}

SecondarySwitches::~SecondarySwitches()
{
}


void* SecondarySwitches::operator new(size_t size)
{
  assert(size == sizeof(SecondarySwitches));
  static Arena* my_arena = arena_pool.findArena
    (sizeof(SecondarySwitches));
  return my_arena->alloc(size);
}

void SecondarySwitches::operator delete(void* v)
{
  static Arena* my_arena = arena_pool.findArena
    (sizeof(SecondarySwitches));
  my_arena->free(v);
}

typedef uint8_t MemberIndex;
static const MemberIndex idxend = 0xff;

static inline void SecondarySwitches_checkIndex(MemberIndex idx, int& store_idx, AmorphStore& s)
{
  if (store_idx == -1) {
    ::packData(s, idx);
    store_idx = s.getSize(); ::packData(s, idxend);
  }
}

static inline void SecondarySwitches_unCheckIndex(MemberIndex idx, int& store_idx, AmorphStore& s)
{
  if (store_idx != -1) {
    int tmp = s.getSize(); s.setSize(store_idx);
    ::packData(s, idx);  s.setSize(tmp);
    store_idx = -1;
  }
}

void SecondarySwitches::packDataDiff(AmorphStore& s, const SecondarySwitches& ref) const
{
  int store_idx = -1;
  if (this->AT_disconnect != ref.AT_disconnect) {
    SecondarySwitches_checkIndex(0, store_idx, s);
    ::packData(s, this->AT_disconnect);
  }
  else {
    SecondarySwitches_unCheckIndex(0, store_idx, s);
  }
  if (this->ignition_left != ref.ignition_left) {
    SecondarySwitches_checkIndex(1, store_idx, s);
    ::packData(s, this->ignition_left);
  }
  else {
    SecondarySwitches_unCheckIndex(1, store_idx, s);
  }
  if (this->ignition_right != ref.ignition_right) {
    SecondarySwitches_checkIndex(2, store_idx, s);
    ::packData(s, this->ignition_right);
  }
  else {
    SecondarySwitches_unCheckIndex(2, store_idx, s);
  }
  if (this->gear_up != ref.gear_up) {
    SecondarySwitches_checkIndex(3, store_idx, s);
    ::packData(s, this->gear_up);
  }
  else {
    SecondarySwitches_unCheckIndex(3, store_idx, s);
  }
  if (this->gear_neutral != ref.gear_neutral) {
    SecondarySwitches_checkIndex(4, store_idx, s);
    ::packData(s, this->gear_neutral);
  }
  else {
    SecondarySwitches_unCheckIndex(4, store_idx, s);
  }
  if (this->gear_down != ref.gear_down) {
    SecondarySwitches_checkIndex(5, store_idx, s);
    ::packData(s, this->gear_down);
  }
  else {
    SecondarySwitches_unCheckIndex(5, store_idx, s);
  }
  ::packData(s, idxend);
}

void SecondarySwitches::unPackData(AmorphReStore& s)
{
  ::unPackData(s, this->AT_disconnect);
  ::unPackData(s, this->ignition_left);
  ::unPackData(s, this->ignition_right);
  ::unPackData(s, this->gear_up);
  ::unPackData(s, this->gear_neutral);
  ::unPackData(s, this->gear_down);
}


void SecondarySwitches::unPackDataDiff(AmorphReStore& s)
{
  MemberIndex idx0, idx1;
  ::unPackData(s, idx0);
  while (idx0 != idxend) {
    ::unPackData(s, idx1);
    switch (idx0) {
    case 0:
      ::unPackData(s, this->AT_disconnect);
      if (++idx0 == idx1) break;
    case 1:
      ::unPackData(s, this->ignition_left);
      if (++idx0 == idx1) break;
    case 2:
      ::unPackData(s, this->ignition_right);
      if (++idx0 == idx1) break;
    case 3:
      ::unPackData(s, this->gear_up);
      if (++idx0 == idx1) break;
    case 4:
      ::unPackData(s, this->gear_neutral);
      if (++idx0 == idx1) break;
    case 5:
      ::unPackData(s, this->gear_down);
      if (++idx0 == idx1) break;
    }
    ::unPackData(s, idx0);
  }
}

bool SecondarySwitches::operator == (const SecondarySwitches& o) const
{
  if (this->AT_disconnect != o.AT_disconnect) return false;
  if (this->ignition_left != o.ignition_left) return false;
  if (this->ignition_right != o.ignition_right) return false;
  if (this->gear_up != o.gear_up) return false;
  if (this->gear_neutral != o.gear_neutral) return false;
  if (this->gear_down != o.gear_down) return false;
  return true;
}

SecondarySwitches&
SecondarySwitches::operator=(const SecondarySwitches& other)
{
  if (this == &other) return *this;
  this->AT_disconnect = other.AT_disconnect;
  this->ignition_left = other.ignition_left;
  this->ignition_right = other.ignition_right;
  this->gear_up = other.gear_up;
  this->gear_neutral = other.gear_neutral;
  this->gear_down = other.gear_down;
  return *this;
}

void SecondarySwitches::packData(AmorphStore& s) const
{
  ::packData(s, this->AT_disconnect);
  ::packData(s, this->ignition_left);
  ::packData(s, this->ignition_right);
  ::packData(s, this->gear_up);
  ::packData(s, this->gear_neutral);
  ::packData(s, this->gear_down);
}

ostream & SecondarySwitches::print(ostream& s) const
{
  s << "SecondarySwitches(AT_disconnect=" << this->AT_disconnect << ','
    << "ignition_left=" << this->ignition_left << ','
    << "ignition_right=" << this->ignition_right << ','
    << "gear_up=" << this->gear_up << ','
    << "gear_neutral=" << this->gear_neutral << ','
    << "gear_down=" << this->gear_down<< ')';
  return s;
}

