//
// Created by Rodrigo Broggi on 22/11/18.
//

#include "ValueLikeData.h"
ValueLikeData::ValueLikeData(std::string str, int num) : ptr(new std::string (str)), num(num) {}
ValueLikeData::ValueLikeData(const ValueLikeData& copy) : ptr(new std::string(*copy.ptr)), num(copy.num) {}
ValueLikeData::~ValueLikeData() {
  if (ptr != nullptr) {
    delete ptr;
  }
}

//Be very carefull to guard agains self-assinment (this is why the temporary copy ptr)
ValueLikeData &ValueLikeData::operator=(const ValueLikeData &rhs) {
  auto new_ptr = new std::string(*rhs.ptr);
  if (ptr != nullptr) {
    delete ptr;
  }
  ptr = new_ptr;
  num = rhs.num;
  return *this;
}
