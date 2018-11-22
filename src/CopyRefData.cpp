//
// Created by Rodrigo Broggi on 21/11/18.
//

#include "../include/CopyRefData.h"
std::ostream &operator<<(std::ostream &os, const CopyRefData &data) {
  os << "name: " << data.name << "[" << &data.name << "]" << " num: " << data.num << "[" << &data.num << "]";
  return os;
}
CopyRefData::CopyRefData(std::string &name, int num) : name(name), num(num) {}
void CopyRefData::setName(std::string &name) {
  CopyRefData::name = name;
}
