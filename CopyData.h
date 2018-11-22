//
// Created by Rodrigo Broggi on 20/11/18.
//

#ifndef CAP13_COPYDATA_H
#define CAP13_COPYDATA_H
#include <iostream>

class CopyData {
 public:
  CopyData();
  //Explicit copy constructor
  CopyData(const CopyData&);
  ~CopyData();
  friend std::ostream& operator<<(std::ostream&, const CopyData&);
};

#endif //CAP13_COPYDATA_H
