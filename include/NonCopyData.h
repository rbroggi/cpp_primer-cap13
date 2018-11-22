//
// Created by Rodrigo Broggi on 20/11/18.
//

#ifndef CAP13_NONCOPYDATA_H
#define CAP13_NONCOPYDATA_H
#include <iostream>
#include <memory>

class NonCopyData {
 public:
  NonCopyData(int);
  friend std::ostream& operator<<(std::ostream&, const NonCopyData&);

  virtual ~NonCopyData();
 private:
  std::unique_ptr<int> _noCopyData;

};

#endif //CAP13_NONCOPYDATA_H
