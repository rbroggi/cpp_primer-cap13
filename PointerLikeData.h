//
// Created by Rodrigo Broggi on 22/11/18.
//

#ifndef CAP13_POINTERLIKEDATA_H
#define CAP13_POINTERLIKEDATA_H
#include <string>
#include <atomic>

class PointerLikeData {
 public:
  PointerLikeData(const std::string str, int _num) : ptr(new std::string(str)), num(_num), refs(new std::atomic_uint(1)){}
  PointerLikeData(const PointerLikeData&);
  ~PointerLikeData();
  PointerLikeData& operator=(const PointerLikeData&);
  const std::string getPtr() const;
  int getNum() const;
  unsigned  int getRefs() const;

 private:
  std::string* ptr;
  int num;
  std::atomic<unsigned int>* refs;

};

#endif //CAP13_POINTERLIKEDATA_H
