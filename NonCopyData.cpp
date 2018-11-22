//
// Created by Rodrigo Broggi on 20/11/18.
//

#include <iostream>
#include "NonCopyData.h"
NonCopyData::NonCopyData(int init) : _noCopyData(new int(init)) {
  std::cout << typeid(*this).name() << " Object with id " << &(*this) << " custom constructed." << std::endl;
}
std::ostream& operator<<(std::ostream &os, const NonCopyData &nonCopyData) {
  os << "{" << typeid(nonCopyData).name() << "}" << "[" << &nonCopyData << "]";
  return os;
}
NonCopyData::~NonCopyData() {
  std::cout << typeid(*this).name() << "Object with id " << &(*this) << " destructed." << std::endl;
}
