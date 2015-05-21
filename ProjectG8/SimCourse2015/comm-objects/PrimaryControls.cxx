/* ------------------------------------------------------------------ */
/*      item            : PrimaryControls.cxx
        made by         : tux
        date            : Thu May 21 02:27:50 2015
        category        : body file
        description     : DUECA event/stream data object
        notes           : 
        language        : C++                     */

#include "PrimaryControls.hxx"
#include <iostream>
#include "Arena.hxx"
#include "ArenaPool.hxx"

USING_DUECA_NS;

const char * const PrimaryControls::classname = "PrimaryControls";

const uint32_t PrimaryControls::magic_check_number=0xa56b7124;

PrimaryControls::PrimaryControls() :
  ux(0.0f),
  uy(0.0f),
  uz(0.0f),
  uc(0.0f),
  Sx(0.0f),
  Sy(0.0f),
  Sz(0.0f),
  Sc(0.0f),
  dSx(0.0f),
  dSy(0.0f),
  dSz(0.0f),
  dSc(0.0f),
  Mx(0.0f),
  My(0.0f),
  Mz(0.0f),
  Mc(0.0f),
  fbrake_left(0.0f),
  fbrake_right(0.0f),
  test(0)
{
  // empty
}

PrimaryControls::PrimaryControls(const PrimaryControls& o) :
  ux(o.ux),
  uy(o.uy),
  uz(o.uz),
  uc(o.uc),
  Sx(o.Sx),
  Sy(o.Sy),
  Sz(o.Sz),
  Sc(o.Sc),
  dSx(o.dSx),
  dSy(o.dSy),
  dSz(o.dSz),
  dSc(o.dSc),
  Mx(o.Mx),
  My(o.My),
  Mz(o.Mz),
  Mc(o.Mc),
  fbrake_left(o.fbrake_left),
  fbrake_right(o.fbrake_right),
  test(o.test)
{
}

PrimaryControls::PrimaryControls(AmorphReStore& s) :
  ux(s),
  uy(s),
  uz(s),
  uc(s),
  Sx(s),
  Sy(s),
  Sz(s),
  Sc(s),
  dSx(s),
  dSy(s),
  dSz(s),
  dSc(s),
  Mx(s),
  My(s),
  Mz(s),
  Mc(s),
  fbrake_left(s),
  fbrake_right(s),
  test(s)
{
}

PrimaryControls::~PrimaryControls()
{
}


typedef uint8_t MemberIndex;
static const MemberIndex idxend = 0xff;

static inline void PrimaryControls_checkIndex(MemberIndex idx, int& store_idx, AmorphStore& s)
{
  if (store_idx == -1) {
    ::packData(s, idx);
    store_idx = s.getSize(); ::packData(s, idxend);
  }
}

static inline void PrimaryControls_unCheckIndex(MemberIndex idx, int& store_idx, AmorphStore& s)
{
  if (store_idx != -1) {
    int tmp = s.getSize(); s.setSize(store_idx);
    ::packData(s, idx);  s.setSize(tmp);
    store_idx = -1;
  }
}

void PrimaryControls::packDataDiff(AmorphStore& s, const PrimaryControls& ref) const
{
  int store_idx = -1;
  if (this->ux != ref.ux) {
    PrimaryControls_checkIndex(0, store_idx, s);
    ::packData(s, this->ux);
  }
  else {
    PrimaryControls_unCheckIndex(0, store_idx, s);
  }
  if (this->uy != ref.uy) {
    PrimaryControls_checkIndex(1, store_idx, s);
    ::packData(s, this->uy);
  }
  else {
    PrimaryControls_unCheckIndex(1, store_idx, s);
  }
  if (this->uz != ref.uz) {
    PrimaryControls_checkIndex(2, store_idx, s);
    ::packData(s, this->uz);
  }
  else {
    PrimaryControls_unCheckIndex(2, store_idx, s);
  }
  if (this->uc != ref.uc) {
    PrimaryControls_checkIndex(3, store_idx, s);
    ::packData(s, this->uc);
  }
  else {
    PrimaryControls_unCheckIndex(3, store_idx, s);
  }
  if (this->Sx != ref.Sx) {
    PrimaryControls_checkIndex(4, store_idx, s);
    ::packData(s, this->Sx);
  }
  else {
    PrimaryControls_unCheckIndex(4, store_idx, s);
  }
  if (this->Sy != ref.Sy) {
    PrimaryControls_checkIndex(5, store_idx, s);
    ::packData(s, this->Sy);
  }
  else {
    PrimaryControls_unCheckIndex(5, store_idx, s);
  }
  if (this->Sz != ref.Sz) {
    PrimaryControls_checkIndex(6, store_idx, s);
    ::packData(s, this->Sz);
  }
  else {
    PrimaryControls_unCheckIndex(6, store_idx, s);
  }
  if (this->Sc != ref.Sc) {
    PrimaryControls_checkIndex(7, store_idx, s);
    ::packData(s, this->Sc);
  }
  else {
    PrimaryControls_unCheckIndex(7, store_idx, s);
  }
  if (this->dSx != ref.dSx) {
    PrimaryControls_checkIndex(8, store_idx, s);
    ::packData(s, this->dSx);
  }
  else {
    PrimaryControls_unCheckIndex(8, store_idx, s);
  }
  if (this->dSy != ref.dSy) {
    PrimaryControls_checkIndex(9, store_idx, s);
    ::packData(s, this->dSy);
  }
  else {
    PrimaryControls_unCheckIndex(9, store_idx, s);
  }
  if (this->dSz != ref.dSz) {
    PrimaryControls_checkIndex(10, store_idx, s);
    ::packData(s, this->dSz);
  }
  else {
    PrimaryControls_unCheckIndex(10, store_idx, s);
  }
  if (this->dSc != ref.dSc) {
    PrimaryControls_checkIndex(11, store_idx, s);
    ::packData(s, this->dSc);
  }
  else {
    PrimaryControls_unCheckIndex(11, store_idx, s);
  }
  if (this->Mx != ref.Mx) {
    PrimaryControls_checkIndex(12, store_idx, s);
    ::packData(s, this->Mx);
  }
  else {
    PrimaryControls_unCheckIndex(12, store_idx, s);
  }
  if (this->My != ref.My) {
    PrimaryControls_checkIndex(13, store_idx, s);
    ::packData(s, this->My);
  }
  else {
    PrimaryControls_unCheckIndex(13, store_idx, s);
  }
  if (this->Mz != ref.Mz) {
    PrimaryControls_checkIndex(14, store_idx, s);
    ::packData(s, this->Mz);
  }
  else {
    PrimaryControls_unCheckIndex(14, store_idx, s);
  }
  if (this->Mc != ref.Mc) {
    PrimaryControls_checkIndex(15, store_idx, s);
    ::packData(s, this->Mc);
  }
  else {
    PrimaryControls_unCheckIndex(15, store_idx, s);
  }
  if (this->fbrake_left != ref.fbrake_left) {
    PrimaryControls_checkIndex(16, store_idx, s);
    ::packData(s, this->fbrake_left);
  }
  else {
    PrimaryControls_unCheckIndex(16, store_idx, s);
  }
  if (this->fbrake_right != ref.fbrake_right) {
    PrimaryControls_checkIndex(17, store_idx, s);
    ::packData(s, this->fbrake_right);
  }
  else {
    PrimaryControls_unCheckIndex(17, store_idx, s);
  }
  if (this->test != ref.test) {
    PrimaryControls_checkIndex(18, store_idx, s);
    ::packData(s, this->test);
  }
  else {
    PrimaryControls_unCheckIndex(18, store_idx, s);
  }
  ::packData(s, idxend);
}

void PrimaryControls::unPackData(AmorphReStore& s)
{
  ::unPackData(s, this->ux);
  ::unPackData(s, this->uy);
  ::unPackData(s, this->uz);
  ::unPackData(s, this->uc);
  ::unPackData(s, this->Sx);
  ::unPackData(s, this->Sy);
  ::unPackData(s, this->Sz);
  ::unPackData(s, this->Sc);
  ::unPackData(s, this->dSx);
  ::unPackData(s, this->dSy);
  ::unPackData(s, this->dSz);
  ::unPackData(s, this->dSc);
  ::unPackData(s, this->Mx);
  ::unPackData(s, this->My);
  ::unPackData(s, this->Mz);
  ::unPackData(s, this->Mc);
  ::unPackData(s, this->fbrake_left);
  ::unPackData(s, this->fbrake_right);
  ::unPackData(s, this->test);
}


void PrimaryControls::unPackDataDiff(AmorphReStore& s)
{
  MemberIndex idx0, idx1;
  ::unPackData(s, idx0);
  while (idx0 != idxend) {
    ::unPackData(s, idx1);
    switch (idx0) {
    case 0:
      ::unPackData(s, this->ux);
      if (++idx0 == idx1) break;
    case 1:
      ::unPackData(s, this->uy);
      if (++idx0 == idx1) break;
    case 2:
      ::unPackData(s, this->uz);
      if (++idx0 == idx1) break;
    case 3:
      ::unPackData(s, this->uc);
      if (++idx0 == idx1) break;
    case 4:
      ::unPackData(s, this->Sx);
      if (++idx0 == idx1) break;
    case 5:
      ::unPackData(s, this->Sy);
      if (++idx0 == idx1) break;
    case 6:
      ::unPackData(s, this->Sz);
      if (++idx0 == idx1) break;
    case 7:
      ::unPackData(s, this->Sc);
      if (++idx0 == idx1) break;
    case 8:
      ::unPackData(s, this->dSx);
      if (++idx0 == idx1) break;
    case 9:
      ::unPackData(s, this->dSy);
      if (++idx0 == idx1) break;
    case 10:
      ::unPackData(s, this->dSz);
      if (++idx0 == idx1) break;
    case 11:
      ::unPackData(s, this->dSc);
      if (++idx0 == idx1) break;
    case 12:
      ::unPackData(s, this->Mx);
      if (++idx0 == idx1) break;
    case 13:
      ::unPackData(s, this->My);
      if (++idx0 == idx1) break;
    case 14:
      ::unPackData(s, this->Mz);
      if (++idx0 == idx1) break;
    case 15:
      ::unPackData(s, this->Mc);
      if (++idx0 == idx1) break;
    case 16:
      ::unPackData(s, this->fbrake_left);
      if (++idx0 == idx1) break;
    case 17:
      ::unPackData(s, this->fbrake_right);
      if (++idx0 == idx1) break;
    case 18:
      ::unPackData(s, this->test);
      if (++idx0 == idx1) break;
    }
    ::unPackData(s, idx0);
  }
}

bool PrimaryControls::operator == (const PrimaryControls& o) const
{
  if (this->ux != o.ux) return false;
  if (this->uy != o.uy) return false;
  if (this->uz != o.uz) return false;
  if (this->uc != o.uc) return false;
  if (this->Sx != o.Sx) return false;
  if (this->Sy != o.Sy) return false;
  if (this->Sz != o.Sz) return false;
  if (this->Sc != o.Sc) return false;
  if (this->dSx != o.dSx) return false;
  if (this->dSy != o.dSy) return false;
  if (this->dSz != o.dSz) return false;
  if (this->dSc != o.dSc) return false;
  if (this->Mx != o.Mx) return false;
  if (this->My != o.My) return false;
  if (this->Mz != o.Mz) return false;
  if (this->Mc != o.Mc) return false;
  if (this->fbrake_left != o.fbrake_left) return false;
  if (this->fbrake_right != o.fbrake_right) return false;
  if (this->test != o.test) return false;
  return true;
}

PrimaryControls&
PrimaryControls::operator=(const PrimaryControls& other)
{
  if (this == &other) return *this;
  this->ux = other.ux;
  this->uy = other.uy;
  this->uz = other.uz;
  this->uc = other.uc;
  this->Sx = other.Sx;
  this->Sy = other.Sy;
  this->Sz = other.Sz;
  this->Sc = other.Sc;
  this->dSx = other.dSx;
  this->dSy = other.dSy;
  this->dSz = other.dSz;
  this->dSc = other.dSc;
  this->Mx = other.Mx;
  this->My = other.My;
  this->Mz = other.Mz;
  this->Mc = other.Mc;
  this->fbrake_left = other.fbrake_left;
  this->fbrake_right = other.fbrake_right;
  this->test = other.test;
  return *this;
}

void PrimaryControls::packData(AmorphStore& s) const
{
  ::packData(s, this->ux);
  ::packData(s, this->uy);
  ::packData(s, this->uz);
  ::packData(s, this->uc);
  ::packData(s, this->Sx);
  ::packData(s, this->Sy);
  ::packData(s, this->Sz);
  ::packData(s, this->Sc);
  ::packData(s, this->dSx);
  ::packData(s, this->dSy);
  ::packData(s, this->dSz);
  ::packData(s, this->dSc);
  ::packData(s, this->Mx);
  ::packData(s, this->My);
  ::packData(s, this->Mz);
  ::packData(s, this->Mc);
  ::packData(s, this->fbrake_left);
  ::packData(s, this->fbrake_right);
  ::packData(s, this->test);
}

ostream & PrimaryControls::print(ostream& s) const
{
  s << "PrimaryControls(ux=" << this->ux << ','
    << "uy=" << this->uy << ','
    << "uz=" << this->uz << ','
    << "uc=" << this->uc << ','
    << "Sx=" << this->Sx << ','
    << "Sy=" << this->Sy << ','
    << "Sz=" << this->Sz << ','
    << "Sc=" << this->Sc << ','
    << "dSx=" << this->dSx << ','
    << "dSy=" << this->dSy << ','
    << "dSz=" << this->dSz << ','
    << "dSc=" << this->dSc << ','
    << "Mx=" << this->Mx << ','
    << "My=" << this->My << ','
    << "Mz=" << this->Mz << ','
    << "Mc=" << this->Mc << ','
    << "fbrake_left=" << this->fbrake_left << ','
    << "fbrake_right=" << this->fbrake_right << ','
    << "test=" << this->test<< ')';
  return s;
}

