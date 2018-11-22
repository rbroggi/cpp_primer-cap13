//
// Created by Rodrigo Broggi on 22/11/18.
//
#include "PointerLikeData.h"
PointerLikeData::PointerLikeData(const PointerLikeData &init) : ptr(init.ptr), num(init.num), refs(init.refs) {
  ++*refs;
}
PointerLikeData::~PointerLikeData() {
  if ( --*refs == 0 && ptr != nullptr ) {
    delete refs;
    delete ptr;
  }
}
PointerLikeData &PointerLikeData::operator=(const PointerLikeData &rhs) {
  ++*rhs.refs;
  if (--*refs == 0 && ptr != nullptr) {
    delete ptr;
    delete refs;
  }
  ptr = rhs.ptr;
  num = num;
  refs = rhs.refs;
  return *this;
}
