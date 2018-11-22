//
// Created by Rodrigo Broggi on 22/11/18.
//
#include <iostream>
#include "../include/PointerLikeData.h"
PointerLikeData::PointerLikeData(const PointerLikeData &init) : ptr(init.ptr), num(init.num), refs(init.refs) {
  ++*refs;
}
PointerLikeData::~PointerLikeData() {
  if ( --*refs == 0 && ptr != nullptr ) {
    std::cout << "Destructing data: " << *ptr << std::endl;
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
const std::string PointerLikeData::getPtr() const {
  return *ptr;
}
int PointerLikeData::getNum() const {
  return num;
}
unsigned  int PointerLikeData::getRefs() const {
  return *refs;
}
