//
// Created by Rodrigo Broggi on 21/11/18.
//

#ifndef CAP13_COPYREFDATA_H
#define CAP13_COPYREFDATA_H
#include <string>
#include <ostream>

class CopyRefData {
 public:
  CopyRefData(std::string &name, int num);
  CopyRefData() = default;
  CopyRefData(const CopyRefData&) = default;
  friend std::ostream &operator<<(std::ostream &os, const CopyRefData &data);
  void setName(std::string &name);
 private:
  std::string& name;
  int& num;
};

#endif //CAP13_COPYREFDATA_H
