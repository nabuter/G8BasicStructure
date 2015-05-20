/* ------------------------------------------------------------------ */
/*      item            : SecondaryControls.cxx
        made by         : tux
        date            : Wed May 20 23:54:05 2015
        category        : body file
        description     : DUECA event/stream data object
        notes           : 
        language        : C++                     */

#include "SecondaryControls.hxx"
#include <iostream>
#include "Arena.hxx"
#include "ArenaPool.hxx"

USING_DUECA_NS;

const char * const SecondaryControls::classname = "SecondaryControls";

const uint32_t SecondaryControls::magic_check_number=0xb6efc1f0;

SecondaryControls::SecondaryControls() :
  throttle_left(0.0f),
  throttle_right(0.0f),
  flap_setting(0.0f),
  speedbrake(0.0f)
{
  // empty
}

SecondaryControls::SecondaryControls(const float& throttle_left,
              const float& throttle_right,
              const float& flap_setting,
              const float& speedbrake) :
  throttle_left(throttle_left),
  throttle_right(throttle_right),
  flap_setting(flap_setting),
  speedbrake(speedbrake)
{
}

SecondaryControls::SecondaryControls(const SecondaryControls& o) :
  throttle_left(o.throttle_left),
  throttle_right(o.throttle_right),
  flap_setting(o.flap_setting),
  speedbrake(o.speedbrake)
{
}

SecondaryControls::SecondaryControls(AmorphReStore& s) :
  throttle_left(s),
  throttle_right(s),
  flap_setting(s),
  speedbrake(s)
{
}

SecondaryControls::~SecondaryControls()
{
}


void* SecondaryControls::operator new(size_t size)
{
  assert(size == sizeof(SecondaryControls));
  static Arena* my_arena = arena_pool.findArena
    (sizeof(SecondaryControls));
  return my_arena->alloc(size);
}

void SecondaryControls::operator delete(void* v)
{
  static Arena* my_arena = arena_pool.findArena
    (sizeof(SecondaryControls));
  my_arena->free(v);
}

typedef uint8_t MemberIndex;
static const MemberIndex idxend = 0xff;

static inline void SecondaryControls_checkIndex(MemberIndex idx, int& store_idx, AmorphStore& s)
{
  if (store_idx == -1) {
    ::packData(s, idx);
    store_idx = s.getSize(); ::packData(s, idxend);
  }
}

static inline void SecondaryControls_unCheckIndex(MemberIndex idx, int& store_idx, AmorphStore& s)
{
  if (store_idx != -1) {
    int tmp = s.getSize(); s.setSize(store_idx);
    ::packData(s, idx);  s.setSize(tmp);
    store_idx = -1;
  }
}

void SecondaryControls::packDataDiff(AmorphStore& s, const SecondaryControls& ref) const
{
  int store_idx = -1;
  if (this->throttle_left != ref.throttle_left) {
    SecondaryControls_checkIndex(0, store_idx, s);
    ::packData(s, this->throttle_left);
  }
  else {
    SecondaryControls_unCheckIndex(0, store_idx, s);
  }
  if (this->throttle_right != ref.throttle_right) {
    SecondaryControls_checkIndex(1, store_idx, s);
    ::packData(s, this->throttle_right);
  }
  else {
    SecondaryControls_unCheckIndex(1, store_idx, s);
  }
  if (this->flap_setting != ref.flap_setting) {
    SecondaryControls_checkIndex(2, store_idx, s);
    ::packData(s, this->flap_setting);
  }
  else {
    SecondaryControls_unCheckIndex(2, store_idx, s);
  }
  if (this->speedbrake != ref.speedbrake) {
    SecondaryControls_checkIndex(3, store_idx, s);
    ::packData(s, this->speedbrake);
  }
  else {
    SecondaryControls_unCheckIndex(3, store_idx, s);
  }
  ::packData(s, idxend);
}

void SecondaryControls::unPackData(AmorphReStore& s)
{
  ::unPackData(s, this->throttle_left);
  ::unPackData(s, this->throttle_right);
  ::unPackData(s, this->flap_setting);
  ::unPackData(s, this->speedbrake);
}


void SecondaryControls::unPackDataDiff(AmorphReStore& s)
{
  MemberIndex idx0, idx1;
  ::unPackData(s, idx0);
  while (idx0 != idxend) {
    ::unPackData(s, idx1);
    switch (idx0) {
    case 0:
      ::unPackData(s, this->throttle_left);
      if (++idx0 == idx1) break;
    case 1:
      ::unPackData(s, this->throttle_right);
      if (++idx0 == idx1) break;
    case 2:
      ::unPackData(s, this->flap_setting);
      if (++idx0 == idx1) break;
    case 3:
      ::unPackData(s, this->speedbrake);
      if (++idx0 == idx1) break;
    }
    ::unPackData(s, idx0);
  }
}

bool SecondaryControls::operator == (const SecondaryControls& o) const
{
  if (this->throttle_left != o.throttle_left) return false;
  if (this->throttle_right != o.throttle_right) return false;
  if (this->flap_setting != o.flap_setting) return false;
  if (this->speedbrake != o.speedbrake) return false;
  return true;
}

SecondaryControls&
SecondaryControls::operator=(const SecondaryControls& other)
{
  if (this == &other) return *this;
  this->throttle_left = other.throttle_left;
  this->throttle_right = other.throttle_right;
  this->flap_setting = other.flap_setting;
  this->speedbrake = other.speedbrake;
  return *this;
}

void SecondaryControls::packData(AmorphStore& s) const
{
  ::packData(s, this->throttle_left);
  ::packData(s, this->throttle_right);
  ::packData(s, this->flap_setting);
  ::packData(s, this->speedbrake);
}

ostream & SecondaryControls::print(ostream& s) const
{
  s << "SecondaryControls(throttle_left=" << this->throttle_left << ','
    << "throttle_right=" << this->throttle_right << ','
    << "flap_setting=" << this->flap_setting << ','
    << "speedbrake=" << this->speedbrake<< ')';
  return s;
}

