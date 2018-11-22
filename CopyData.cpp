//
// Created by Rodrigo Broggi on 20/11/18.
//

#include <iostream>
#include "CopyData.h"
CopyData::CopyData() {
  std::cout << typeid(*this).name() << "Object with address " << &(*this) << " default constructed" << std::endl;
}
CopyData::CopyData(const CopyData &copyData) {
  std::cout << "Object with address " << &(*this) << " copied constructed" << std::endl;
}
CopyData::~CopyData() {
  std::cout << typeid(*this).name() << "Object with address " << &(*this) << " destructed!" << std::endl;
}
std::ostream &operator<<(std::ostream &os, const CopyData &copyData) {
  os << "{" << typeid(copyData).name() << "}" << "[" << &copyData << "]";
  return os;
}
